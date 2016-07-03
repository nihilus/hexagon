/* path.cc

   Copyright 2001, 2002, 2003, 2005, 2006, 2007, 2008 Red Hat, Inc.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

/* The functions in this file attempt to resolve a windows shortcut file
   or directory name */


#include <windows.h>
#include <lmcons.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <wchar.h>
#include "win_realpath.h"


#define true 1
#define false 0
#define MAX_FILE_SIZE  8192


#define EXE_MAGIC ((int)*(unsigned short *)"MZ")
#define SHORTCUT_MAGIC ((int)*(unsigned short *)"L\0")
#define SYMLINK_COOKIE "!<symlink>"
#define SYMLINK_MAGIC ((int)*(unsigned short *)SYMLINK_COOKIE)
    
#ifndef ushort_t
typedef unsigned short ushort_t;
#endif

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

#define USHORT_SZ       (sizeof(ushort_t))
#define USHORT_PVAL(x)  (*(ushort_t*)(x))
#define UINT32_PVAL(x)  (*(uint32_t*)(x))
#define WCHAR_SZ        2
#define MAX_TRIES       10


/****************************************************************************
WINDOWS SHORTCUT FILE FORMAT:
Header (in the data structure below)

The flags in the header mean the following
Bit 0 => If 1 (0) means that the shell item id list is present (absent)
Bit 1 => If 1 (0) means that shortcut points to file or dir ( something else)
Bit 2 => If 1 (0) has description string (no description string)
Bit 3 => If 1 (0) has a relative path string (no relative path string)
Bit 4 => If 1 (0) has a working directory (no working dir)
Bit 5 => If 1 (0) has command-line args (no command-line args)
Bit 6 => If 1 (0) has custom icon (no custom icon)


The header is followed by 0 or more item id list. The item id list contents
are variable


The item id list, if present, is followed by file location info, whose 
structure is below
(dw = 4 bytes)

Offset  Size    Contents
0h      1dw     Total length of this structure 
4h      1dw     Pointer to the first offset after this structure (1Ch)
8h      1dw     Flags 
                Bit 0: Available on local volume
                Bit 1: Available on network volume
        
Ch      1dw     Offset of local volume (valid only if bit 0 in flags set)
10h     1dw     Offset of base pathname on local system (valid if bit 0 set)
14h     1dw     Offset of network volume info (valid if bit 1 set)
18h     1dw     Offset of remaining pathname

Local volume table follows file location info

Offset  Size    Contents
0h      1dw     Length of this structure
4h      1dw     Type of volume (removable, fixed, remote etc)
8h      1dw     Volume serial numner
Ch      1dw     Offset of volume name (always 10h)
10h     ASCIZ   volume label (ASCIZ=> Null terminated ascii string)

Next is network volume table

Offset  Size    Contents
0h      1dw     Length of this structure
4h      1dw     Unknown, always 2h?
8h      1dw     Offset of network share name (Always 14h)
Ch      1dw     Unknown, always zero?
10h     1dw     Unknown, always 20000h?
14h     ASCIZ   Network share name

Followed by Description string (if bit 2 in shortcut header flag is set)
The first unsigned short indicates size of the description string. The actual
description string follows the size

Followed by Relative path string (if bit 3 in shortcut header flag is set)
The first unsigned short indicates the length of the string. The actual 
relative path string follows this.

The rest of the fields (working dir, command-line string and icon filename
string) follow this and are not described here since they are of no interest
to us.

*****************************************************************************/
    
    /* Short offset macros */ 
#define VOL_FLAG_OFFSET         8
#define BASE_PATHNAME_OFFSET    16
#define NETWORK_VOL_OFFSET      20
#define NETSHARE_NAME_OFFSET    20
#define LAST_PATH_COMP_OFFSET   24

#define LOCAL_VOLUME            0x1
#define NET_SHARE               0x2

static const GUID GUID_shortcut =
  {0x00021401L, 0, 0, {0xc0, 0, 0, 0, 0, 0, 0, 0x46}};

enum {
  WSH_FLAG_IDLIST = 0x01,       /* Contains an ITEMIDLIST. */
  WSH_FLAG_FILE = 0x02,         /* Contains a file locator element. */
  WSH_FLAG_DESC = 0x04,         /* Contains a description. */
  WSH_FLAG_RELPATH = 0x08,      /* Contains a relative path. */
  WSH_FLAG_WD = 0x10,           /* Contains a working dir. */
  WSH_FLAG_CMDLINE = 0x20,      /* Contains command line args. */
  WSH_FLAG_ICON = 0x40          /* Contains a custom icon. */
};

typedef struct win_shortcut_hdr
  {
    DWORD size;         /* Header size in bytes.  Must contain 0x4c. */
    GUID magic;         /* GUID of shortcut files. */
    DWORD flags;        /* Content flags.  See above. */

    DWORD attr;         /* Target file attributes. */
    FILETIME ctime;     /* These filetime items are never touched by the */
    FILETIME mtime;     /* system, apparently. Values don't matter. */
    FILETIME atime;
    DWORD filesize;     /* Target filesize. */
    DWORD icon_no;      /* Icon number. */

    DWORD run;          /* Values defined in winuser.h. Use SW_NORMAL. */
    DWORD hotkey;       /* Hotkey value. Set to 0.  */
    DWORD dummy[2];     /* Future extension probably. Always 0. */
} win_shortcut_hdr;




static int
cmp_shortcut_header (win_shortcut_hdr *file_header)
{
    /*----------------------------------------------------------------------*/
    /* A Windows shortcut only contains a description and a relpath.  The   */
    /* run type is always set to SW_NORMAL.                                 */
    /*----------------------------------------------------------------------*/
    return file_header->size == sizeof (win_shortcut_hdr)
        && !memcmp (&file_header->magic, &GUID_shortcut, sizeof GUID_shortcut)
        && file_header->run == SW_NORMAL;
}

int
get_word (HANDLE fh, int offset)
{
  unsigned short rv;
  DWORD r;

  SetLastError(NO_ERROR);

  if (SetFilePointer (fh, offset, 0, FILE_BEGIN) == INVALID_SET_FILE_POINTER
      && GetLastError () != NO_ERROR)
    return -1;

  if (!ReadFile (fh, &rv, 2,  &r, 0))
    return -1;

  return (int) rv;
}


int
is_shortcut (HANDLE fh)
{
  DWORD got;
  DWORD size;
  static char buf[MAX_FILE_SIZE];

  int magic = get_word (fh, 0x0);

  if (magic != SHORTCUT_MAGIC)
    return false;

  if ((size = GetFileSize (fh, NULL)) > MAX_FILE_SIZE)
      return false; /* Not a shortcut */
  if (SetFilePointer (fh, 0, 0, FILE_BEGIN) == INVALID_SET_FILE_POINTER &&
      GetLastError () != NO_ERROR)
      return false;
  if (!ReadFile (fh, buf, size, &got, 0))
      return false;
  if (got != size || !cmp_shortcut_header ((win_shortcut_hdr *) buf))
      return false; /* Not a shortcut */
  return true;
}


/* Assumes is_shortcut(fh) is true. */
int
readlink (HANDLE fh, char *path, int *has_relpath, unsigned int maxpath)
{
  DWORD rv;
  char *buf, *cp;
  unsigned short len;
  win_shortcut_hdr *file_header;
  int vol_flag = 0;

  BY_HANDLE_FILE_INFORMATION fi;

  if (!GetFileInformationByHandle (fh, &fi)
      || fi.nFileSizeHigh != 0
      || fi.nFileSizeLow > MAX_FILE_SIZE) 
    return false;

  buf = (char *) alloca (fi.nFileSizeLow + 1);
  file_header = (win_shortcut_hdr *) buf;


  if (SetFilePointer (fh, 0L, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER
      || !ReadFile (fh, buf, fi.nFileSizeLow, &rv, NULL)
      || rv != fi.nFileSizeLow)
    return false;

  /* Set the has_realpath out arg */
  *has_relpath = ((file_header->flags & WSH_FLAG_RELPATH) != 0);

  /* Not a shortcut if the header doesn't match */
  if (fi.nFileSizeLow <= sizeof (file_header) || 
      !cmp_shortcut_header (file_header))
      return false;


  cp = buf + sizeof (win_shortcut_hdr);

  if (file_header->flags & WSH_FLAG_IDLIST) /* Skip ITEMIDLIST */
  {
      len = USHORT_PVAL(cp);
      cp += len + USHORT_SZ; 
  }
  
  /* Get the volume flags (local or net volume info indicator) */
  vol_flag =  UINT32_PVAL (cp + VOL_FLAG_OFFSET);
  
  /* Zero out the outpath */
  memset(path, maxpath, 0);
  
  /* If there is no relpath in the shortcut, use local or network full path
     name */
  if (!*has_relpath)
  {
      if (vol_flag & LOCAL_VOLUME)
      {
	  char *local_base = cp + UINT32_PVAL(cp + BASE_PATHNAME_OFFSET);
	  if (strlen(local_base) >= maxpath) return false;
	  strcpy(path, local_base);
      }
      else if (vol_flag & NET_SHARE)
      {
	  uint32_t nvt_off = UINT32_PVAL(cp + NETWORK_VOL_OFFSET);
	  char *net_share = cp + nvt_off + NETSHARE_NAME_OFFSET;
	  if (strlen(net_share)  + strlen("\\") >= maxpath) return false;
	  sprintf(path, "%s\\", net_share);
      }
      else /* No relpath, local volume of net volume info. Give up */
	  return false;
      
      {
          /* Attach the final part of the path */
	  uint32_t final_off = UINT32_PVAL(cp + LAST_PATH_COMP_OFFSET);
	  char *final_base = cp +  final_off;
	  if (strlen(path) + strlen(final_base) >= maxpath) return false;
	  strcpy(path+strlen(path), final_base);
      }
  }
  else /* Relative path */
  {
      /* Get the length of the file location info structure*/
      if (!(len = UINT32_PVAL(cp)))       return false;
      
      cp += len ;
      
      if (file_header->flags & WSH_FLAG_DESC) 
      {
	  len = USHORT_PVAL(cp);
	  
	  /* Wide chars are used for every name. Multiply length by 
	     wide-char size */
	  cp += len * WCHAR_SZ + USHORT_SZ;
      }
      
      /* Read the relative path data */
      {
	  unsigned short relpath_len = USHORT_PVAL(cp);
	  cp +=  USHORT_SZ;
	  
	  if (relpath_len >= maxpath) return false;
	  
	  /* The relpath is in wide-char format */
	  wcstombs(path, (wchar_t*)cp, relpath_len);
      }
  }

  return true;

}


/****************************************************************************/
/*                                                                          */
/* WIN_REALPATH()=> The user interface to the shortcut resolution           */
/* logic. If the function returns true, outfl will have the resolved        */
/* pathname of the file pointed to by shortcut (and is not a shortcut)      */
/*                                                                          */
/****************************************************************************/
int win_realpath(char *filename, char *outfl, unsigned int path_max)
{
   HANDLE fh;
   int has_relpath=false;
   int i;
   int shortcut_found = false;
   int done = false;
   char *newfl = (char*)calloc(sizeof(char), path_max);
   char *lbuffer = (char*)calloc(sizeof(char), path_max);
   char *p = outfl;


   strcpy(outfl, filename); 

   /* Convert all forward slashes to backslash first */
   while (*p) { if (*p == '/') *p = '\\';  p++; }

   /*-----------------------------------------------------------------------*/
   /* Exit from loop early if not shortcut or error in reading shortcut or  */
   /* if path too long. The loop checks to see if the resolved shortcut is  */
   /* a shortcut and if so resolve it again. DO not do this more than       */
   /* MAX_TRIES times                                                       */
   /*-----------------------------------------------------------------------*/

   for (i = 0; i < MAX_TRIES; i++)
   {
       /*-------------------------------------------------------------------*/
       /* Do not use OpenFile since the filename arg to OpenFile cannot be  */
       /* more than 128 chars. Use CreateFile instead which will accept     */
       /* 32k chars. But any handle opened using CreateFile() must be       */
       /* properly closed by CloseHandle(); otherwise the resource will be  */
       /* tied up and other processes/same process cannot open it           */
       /*-------------------------------------------------------------------*/
       fh = (HANDLE)CreateFile(outfl, GENERIC_READ, FILE_SHARE_READ, NULL, 
			       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

       if (!is_shortcut(fh))
       { 
	   done = true; 
	   CloseHandle(fh); 
	   break;
       }
       
       if (!readlink(fh, newfl, &has_relpath, path_max-1)) 
       {
	   done = true; 
	   CloseHandle(fh); 
	   break;
       }
       
       CloseHandle(fh);  

       /* If relpath, append outfl to filename */
       if (has_relpath)
       {
	   char *fname_part;

           /* Check if the file is a dir (fname_part will be null)*/
           GetFullPathName(outfl, path_max-1, lbuffer, &fname_part);

           /*---------------------------------------------------------------*/
           /* If the file is not a dir, truncate the file part before	    */
           /* constructing the pathname to prepend			    */
           /*---------------------------------------------------------------*/
           if (fname_part != NULL) 
           {
	       char *c = outfl, *d = lbuffer;
	       while (d != fname_part) *c++ = *d++;
	       *c = 0;
           }
	   
           /* Give up if path too long */
           if (strlen(newfl) + strlen(outfl) + strlen("\\") >= path_max) 
           { done = true; shortcut_found = false; break; }
           sprintf(outfl, "%s\\%s",outfl, newfl);

       }
       else /* Otherwise, overwirte outfl with full pathname */
           strcpy(outfl, newfl);

       shortcut_found = true;
   } 

   if (!done && i == MAX_TRIES) shortcut_found = false;

#if 0
   if (shortcut_found)
       fprintf(stderr, "Resolving %s to %s\n", filename, outfl);
#endif	      

   free(newfl);
   free(lbuffer);
   return shortcut_found;
}

