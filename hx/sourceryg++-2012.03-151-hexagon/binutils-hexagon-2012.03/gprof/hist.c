/* hist.c  -  Histogram related operations.

   Copyright 1999, 2000, 2001, 2002, 2004, 2005, 2007, 2009
   Free Software Foundation, Inc.

   This file is part of GNU Binutils.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include "gprof.h"
#include "libiberty.h"
#include "search_list.h"
#include "source.h"
#include "symtab.h"
#include "corefile.h"
#include "gmon_io.h"
#include "gmon_out.h"
#include "hist.h"
#include "sym_ids.h"
#include "utils.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#define UNITS_TO_CODE (offset_to_code / sizeof(UNIT))

static void scale_and_align_entries (void);
static void print_header (int);
static void print_line (Sym *, double);
static int cmp_time (const PTR, const PTR);

/* Declarations of automatically generated functions to output blurbs.  */
extern void flat_blurb (FILE * fp);
#ifdef HEXAGON_SIM
extern void hexagon_blurb (FILE *fp);
#endif
  
static histogram *find_histogram (bfd_vma lowpc, bfd_vma highpc);
static histogram *find_histogram_for_pc (bfd_vma pc);

histogram * histograms;
unsigned num_histograms;
double hist_scale;
char hist_dimension[16] = "hilleks";
char hist_dimension_abbrev = 's';

static double accum_time;	/* Accumulated time so far for print_line(). */
static double total_time;	/* Total time for all routines.  */

typedef enum { UNKNOWN_TYPE=0, IS_ICMISS, IS_DCMISS, IS_CYCLES, IS_L2CMISS, IS_BACC } typeofgmon;
typeofgmon gmon_type = UNKNOWN_TYPE;

/* Table of SI prefixes for powers of 10 (used to automatically
   scale some of the values in the flat profile).  */
const struct
  {
    char prefix;
    double scale;
  }
SItab[] =
{
  { 'T', 1e-12 },				/* tera */
  { 'G', 1e-09 },				/* giga */
  { 'M', 1e-06 },				/* mega */
  { 'K', 1e-03 },				/* kilo */
  { ' ', 1e-00 },
  { 'm', 1e+03 },				/* milli */
  { 'u', 1e+06 },				/* micro */
  { 'n', 1e+09 },				/* nano */
  { 'p', 1e+12 },				/* pico */
  { 'f', 1e+15 },				/* femto */
  { 'a', 1e+18 }				/* ato */
};

/* Reads just the header part of histogram record into
   *RECORD from IFP.  FILENAME is the name of IFP and
   is provided for formatting error messages only.  

   If FIRST is non-zero, sets global variables HZ, HIST_DIMENSION,
   HIST_DIMENSION_ABBREV, HIST_SCALE.  If FIRST is zero, checks
   that the new histogram is compatible with already-set values
   of those variables and emits an error if that's not so.  */
static void
read_histogram_header (histogram *record,
		       FILE *ifp, const char *filename,
		       int first, float *scale)
{
  unsigned int profrate;
  char n_hist_dimension[15];
  char n_hist_dimension_abbrev;
  double n_hist_scale;

  if (gmon_io_read_vma (ifp, &record->lowpc)
      || gmon_io_read_vma (ifp, &record->highpc)
      || gmon_io_read_32 (ifp, &record->num_bins)
      || gmon_io_read_32 (ifp, &profrate)
      || gmon_io_read (ifp, n_hist_dimension, 15)
      || gmon_io_read (ifp, &n_hist_dimension_abbrev, 1))
    {
      fprintf (stderr, _("%s: %s: unexpected end of file\n"),
	       whoami, filename);

      done (1);
    }

  n_hist_scale = (double)((record->highpc - record->lowpc) / sizeof (UNIT))
    / record->num_bins;

  if (!strncmp(n_hist_dimension, "  i-cache miss", 14))
    {
      if((gmon_type == UNKNOWN_TYPE) || (gmon_type == IS_ICMISS))
        {
          *scale = 1.0f;
          strcpy(n_hist_dimension, _("I$miss"));
          n_hist_dimension_abbrev = 'm';
	  gmon_type = IS_ICMISS;
	}
      else
        {
	  fprintf(stderr, _("%s: I$Miss cannot be mixed with other gmon file types\n"), whoami);
	  done(1);
	}
    }
  else if (!strncmp(n_hist_dimension, "  d-cache miss", 14))
    {
      if ((gmon_type == UNKNOWN_TYPE) || (gmon_type == IS_DCMISS))
        {
          *scale = 1.0;
          strcpy(n_hist_dimension, _("D$miss"));
          n_hist_dimension_abbrev = 'm';
	  gmon_type = IS_DCMISS;
	}
      else
        {
	  fprintf(stderr, _("%s: D$Miss cannot be mixed with other gmon file types\n"), whoami);
	  done(1);
	}
    }
  else if (!strncmp(n_hist_dimension, "  bus accesses", 14))
    {
      if ((gmon_type == UNKNOWN_TYPE) || (gmon_type == IS_BACC))
        {
          *scale = 1.0;
          strcpy(n_hist_dimension, _("BusAcc"));
          n_hist_dimension_abbrev = 'm';
          gmon_type = IS_BACC;
        }
      else
        {
          fprintf(stderr, _("%s: BusAcc cannot be mixed with other gmon file types\n"), whoami);
          done(1);
        }
    }
  else if (!strncmp(n_hist_dimension, "  l2cache miss", 14))
    {
      if ((gmon_type == UNKNOWN_TYPE) || (gmon_type == IS_L2CMISS))
        {
          *scale = 1.0;
          strcpy(n_hist_dimension, _("L2$miss"));
          n_hist_dimension_abbrev = 'm';
	  gmon_type = IS_L2CMISS;
	}
      else
        {
	  fprintf(stderr, _("%s: L2$Miss cannot be mixed with other gmon file types\n"), whoami);
	  done(1);
	}
    }
  else
    {
      if ((gmon_type == UNKNOWN_TYPE) || (gmon_type == IS_CYCLES))
        {
          sscanf (n_hist_dimension, _("%f"), scale);
          strcpy (n_hist_dimension, _("cycle(s)"));
          n_hist_dimension_abbrev = 'c';
	  gmon_type = IS_CYCLES;
	}
      else
        {
	  fprintf(stderr, _("%s: Cycle counts cannot be mixed with other gmon file types\n"), whoami);
	  done(1);
	}
    }

  if (first)
    {
      /* We don't try to verify profrate is the same for all histogram
	 records.  If we have two histogram records for the same
	 address range and profiling samples is done as often
	 as possible as opposed on timer, then the actual profrate will
	 be slightly different.  Most of the time the difference does not
	 matter and insisting that profiling rate is exactly the same
	 will only create inconvenient.  */
      hz_int = profrate;
      memcpy (hist_dimension, n_hist_dimension, 15);
      hist_dimension_abbrev = n_hist_dimension_abbrev;
      hist_scale = n_hist_scale;
    }
  else
    {
      if (strncmp (n_hist_dimension, hist_dimension, 15) != 0)
	{
	  fprintf (stderr,
		   _("%s: dimension unit changed between histogram records\n"
		     "%s: from '%s'\n"
		     "%s: to '%s'\n"),
		   whoami, whoami, hist_dimension, whoami, n_hist_dimension);
	  done (1);
	}

      if (n_hist_dimension_abbrev != hist_dimension_abbrev)
	{
	  fprintf (stderr,
		   _("%s: dimension abbreviation changed between histogram records\n"
		     "%s: from '%c'\n"
		     "%s: to '%c'\n"),
		   whoami, whoami, hist_dimension_abbrev, whoami, n_hist_dimension_abbrev);
	  done (1);
	}

      /* The only reason we require the same scale for histograms is that
	 there's code (notably printing code), that prints units,
	 and it would be very confusing to have one unit mean different
	 things for different functions.  */
      if (fabs (hist_scale - n_hist_scale) > 0.000001)
	{
	  fprintf (stderr,
		   _("%s: different scales in histogram records"),
		   whoami);
	  done (1);
	}
    }
}

/* Read in version 2 compressed data from the file 'fd'. */

unsigned long long
readCompressed (FILE *fd)
{
  unsigned long long val = 0;
  unsigned char c;
  unsigned int count;
  int retval, i;

  retval = fread(&c, 1, 1, fd);   // Read flag byte
  if(retval == 0)
  {
    fprintf(stderr, "Error reading compressed value\n");
    return (unsigned long long) ~0;
  }
  if(!(c & 0x80))         // Short count
  {
    return (unsigned long long) c;
  }

  count = c & ~0x80;

  for(i = 0; i < (int) count; i++)
  {
    retval = fread(&c, 1, 1, fd);
    if(retval == 0)
    {
      fprintf(stderr, "Error reading compressed value\n");
      return (unsigned long long) ~0;
    }
    val |= ((unsigned long long) c) << (i * 8);
  }

  return val;
}


/* Read the histogram from file IFP.  FILENAME is the name of IFP and
   is provided for formatting error messages only.  */

void
hist_read_rec (FILE * ifp, const char *filename)
{
  bfd_vma lowpc, highpc, cur_pc;
  histogram n_record;
  histogram *record, *existing_record;
  unsigned i;
  float scale;
  int bin_scale;
  unsigned int offset;

  /* 1. Read the header and see if there's existing record for the
     same address range and that there are no overlapping records.  */
  read_histogram_header (&n_record, ifp, filename, num_histograms == 0, &scale);

  bin_scale = (n_record.highpc - n_record.lowpc) / n_record.num_bins;

  existing_record = find_histogram (n_record.lowpc, n_record.highpc);
  if (existing_record)
    {
      record = existing_record;
    }
  else
    {
      /* If this record overlaps, but does not completely match an existing
	 record, it's an error.  */
      lowpc = n_record.lowpc;
      highpc = n_record.highpc;
      hist_clip_symbol_address (&lowpc, &highpc);
      if (lowpc != highpc)
	{
    	    if (gmon_file_version == 1)  /* gnu-style gmon.out format */
	    {
		/* If this record overlaps, but does not completely match 
		   an existing record, it's an error.  */
		fprintf (stderr, 
		   _("%s: overlapping histogram records\n"),
		   whoami);
		done (1);      
	    }
  	    else /* gmon_file_version == 2 */
	    {
	        histogram *new_hist, *this;
		int count, j;
		int sz_new_hist = 2 * num_histograms * sizeof(histogram);

		new_hist = xmalloc (sz_new_hist);
		memset (new_hist, 0, sz_new_hist);

		new_hist[0].lowpc = n_record.lowpc;
		new_hist[0].highpc = n_record.highpc;
		count = 1;

		/* Clip the new region with the set of existing histograms
		   to create a new set of regions that only consist of the
		   non-overlapped areas of the new region.  This new set
		   will be added to the existing histograms.  */

		for (i = 0; i < num_histograms; i++)
		{
		    for (j = count-1; j >= 0; j--)
		    {
		        bfd_vma il = histograms[i].lowpc;
		        bfd_vma ih = histograms[i].highpc;
		        bfd_vma jl = new_hist[j].lowpc;
			bfd_vma jh = new_hist[j].highpc;

			if ((jl < ih) && (jh > il))
			{
			    /* The new region overlaps in some way with 
			       this particular histogram region.

			       To clip out the overlap, start by adjusting
			       this new region to reflect only the portion 
			       of the new region that is below the overlap
			       (if any).  Note that this may eliminate the
			       region entirely if no portion of the new
			       region exists below the overlap.  */

			    new_hist[j].highpc = il;

			    if (jh > ih)
			    {
			    	/* The new region extends above the overlap.
				   Create a second region to reflect the
				   only the portion of the new region
				   that extends above the overlap.  */
			        new_hist[count].lowpc = ih;
			        new_hist[count].highpc = jh;
				count++;
			    }
		        }
		    }
		}

		/* Create new histograms that are needed.  */

		for (j = 0; j < count; j++)
		{
		    if (new_hist[j].highpc > new_hist[j].lowpc)
		    {
          		histograms = (struct histogram *)
              			xrealloc (histograms,
				sizeof (histogram) * (num_histograms + 1));

          		this = &histograms[num_histograms];      
			this->lowpc    = new_hist[j].lowpc;
			this->highpc   = new_hist[j].highpc;
			this->num_bins = (this->highpc - this->lowpc)
								/ bin_scale;
          		++num_histograms;
    
          		this->sample = (int *) xmalloc (this->num_bins 
					    * sizeof (this->sample[0]));
          		memset (this->sample, 0,
				this->num_bins * sizeof (this->sample[0]));
		    }
		}

		record = &histograms[0];
		free (new_hist);
	    }
	}
      else
        {

          /* This is new record.  Add it to global array and allocate space for
	     the samples.  */
          histograms = (struct histogram *)
              xrealloc (histograms, sizeof (histogram) * (num_histograms + 1));
          memcpy (histograms + num_histograms,
	          &n_record, sizeof (histogram));
          record = &histograms[num_histograms];      
          ++num_histograms;
    
          record->sample = (int *) xmalloc (record->num_bins 
					    * sizeof (record->sample[0]));
          memset (record->sample, 0, record->num_bins * sizeof (record->sample[0]));
	}
    }

  /* 2. We have either a new record (with zeroed histogram data), or an existing
     record with some data in the histogram already.  Read new data into the
     record, adding hit counts.  */

  DBG (SAMPLEDEBUG,
       printf ("[hist_read_rec] n_lowpc 0x%lx n_highpc 0x%lx ncnt %u\n",
	       (unsigned long) record->lowpc, (unsigned long) record->highpc,
               record->num_bins));

    cur_pc = n_record.lowpc;
    offset = (n_record.lowpc - record->lowpc) / bin_scale;
           
    for (i = 0; i < n_record.num_bins; ++i)
    {
	if (gmon_file_version == 1)  /* gnu-style gmon.out format */
	{
	    UNIT count;

            if (fread (&count[0], sizeof (count), 1, ifp) != 1)
	    {
		fprintf (stderr,
		   _("%s: %s: unexpected EOF after reading %u of %u samples\n"),
		   whoami, filename, i, record->num_bins);
		done (1);
	    }
            record->sample[i] += bfd_get_16 (core_bfd[0], (bfd_byte *) & count[0]);
	}
	else /* gmon_file_version == 2 */
	{
	    unsigned long long val = readCompressed(ifp);

	    if (val == (unsigned long long) ~0)
	    {
		fprintf (stderr,
		_("%s: %s: unexpected EOF after reading %d of %d samples\n"),
		       whoami, filename, i, record->num_bins);
		done (1);
	    }

	    if (num_histograms == 1)
	    {
                record->sample[i+offset] += val * scale;
	    }
	    else
	    {
	        record = find_histogram_for_pc (cur_pc);
                record->sample[(cur_pc - record->lowpc)/bin_scale] += val * scale;
	        cur_pc += bin_scale;
	    }
	}
        DBG (SAMPLEDEBUG,
	       printf ("[hist_read_rec] 0x%lx: %u\n",
		       (unsigned long) (record->lowpc 
                                        + i * (record->highpc - record->lowpc) 
                                        / record->num_bins),
		       record->sample[i]));
    }
}


/* Write all execution histograms file OFP.  FILENAME is the name
   of OFP and is provided for formatting error-messages only.  */

void
hist_write_hist (FILE * ofp, const char *filename)
{
  UNIT count;
  unsigned int i, r;

  for (r = 0; r < num_histograms; ++r)
    {
      histogram *record = &histograms[r];

      /* Write header.  */
      
      if (gmon_io_write_8 (ofp, GMON_TAG_TIME_HIST)
	  || gmon_io_write_vma (ofp, record->lowpc)
	  || gmon_io_write_vma (ofp, record->highpc)
	  || gmon_io_write_32 (ofp, record->num_bins)
	  || gmon_io_write_32 (ofp, hz_int)
	  || gmon_io_write (ofp, hist_dimension, 15)
	  || gmon_io_write (ofp, &hist_dimension_abbrev, 1))
	{
	  perror (filename);
	  done (1);
	}
      
      for (i = 0; i < record->num_bins; ++i)
	{
	  bfd_put_16 (core_bfd[0], (bfd_vma) record->sample[i], (bfd_byte *) &count[0]);
	  
	  if (fwrite (&count[0], sizeof (count), 1, ofp) != 1)
	    {
	      perror (filename);
	      done (1);
	    }
	}
    }
}

/* Calculate scaled entry point addresses (to save time in
   hist_assign_samples), and, on architectures that have procedure
   entry masks at the start of a function, possibly push the scaled
   entry points over the procedure entry mask, if it turns out that
   the entry point is in one bin and the code for a routine is in the
   next bin.  */

static void
scale_and_align_entries ()
{
  Sym *sym;
  bfd_vma bin_of_entry;
  bfd_vma bin_of_code;

  for (sym = symtab.base; sym < symtab.limit; sym++)
    {
      histogram *r = find_histogram_for_pc (sym->addr);

      sym->hist.scaled_addr = sym->addr / sizeof (UNIT);

      if (r)
	{
	  bin_of_entry = (sym->hist.scaled_addr - r->lowpc) / hist_scale;
	  bin_of_code = ((sym->hist.scaled_addr + UNITS_TO_CODE - r->lowpc)
		     / hist_scale);
	  if (bin_of_entry < bin_of_code)
	    {
	      DBG (SAMPLEDEBUG,
		   printf ("[scale_and_align_entries] pushing 0x%lx to 0x%lx\n",
			   (unsigned long) sym->hist.scaled_addr,
			   (unsigned long) (sym->hist.scaled_addr
					    + UNITS_TO_CODE)));
	      sym->hist.scaled_addr += UNITS_TO_CODE;
	    }
	}
    }
}


/* Assign samples to the symbol to which they belong.

   Histogram bin I covers some address range [BIN_LOWPC,BIN_HIGH_PC)
   which may overlap one more symbol address ranges.  If a symbol
   overlaps with the bin's address range by O percent, then O percent
   of the bin's count is credited to that symbol.

   There are three cases as to where BIN_LOW_PC and BIN_HIGH_PC can be
   with respect to the symbol's address range [SYM_LOW_PC,
   SYM_HIGH_PC) as shown in the following diagram.  OVERLAP computes
   the distance (in UNITs) between the arrows, the fraction of the
   sample that is to be credited to the symbol which starts at
   SYM_LOW_PC.

	  sym_low_pc                                      sym_high_pc
	       |                                               |
	       v                                               v

	       +-----------------------------------------------+
	       |                                               |
	  |  ->|    |<-         ->|         |<-         ->|    |<-  |
	  |         |             |         |             |         |
	  +---------+             +---------+             +---------+

	  ^         ^             ^         ^             ^         ^
	  |         |             |         |             |         |
     bin_low_pc bin_high_pc  bin_low_pc bin_high_pc  bin_low_pc bin_high_pc

   For the VAX we assert that samples will never fall in the first two
   bytes of any routine, since that is the entry mask, thus we call
   scale_and_align_entries() to adjust the entry points if the entry
   mask falls in one bin but the code for the routine doesn't start
   until the next bin.  In conjunction with the alignment of routine
   addresses, this should allow us to have only one sample for every
   four bytes of text space and never have any overlap (the two end
   cases, above).  */

static void
hist_assign_samples_1 (histogram *r)
{
  bfd_vma bin_low_pc, bin_high_pc;
  bfd_vma sym_low_pc, sym_high_pc;
  bfd_vma overlap, addr;
  unsigned int bin_count;
  unsigned int i, j;
  double count_time, credit;

  bfd_vma lowpc = r->lowpc / sizeof (UNIT);

  /* Iterate over all sample bins.  */
  for (i = 0, j = 1; i < r->num_bins; ++i)
    {
      bin_count = r->sample[i];
      if (! bin_count)
	continue;

      bin_low_pc = lowpc + (bfd_vma) (hist_scale * i);
      bin_high_pc = lowpc + (bfd_vma) (hist_scale * (i + 1));
      count_time = bin_count;

      DBG (SAMPLEDEBUG,
	   printf (
      "[assign_samples] bin_low_pc=0x%lx, bin_high_pc=0x%lx, bin_count=%u\n",
		    (unsigned long) (sizeof (UNIT) * bin_low_pc),
		    (unsigned long) (sizeof (UNIT) * bin_high_pc),
		    bin_count));
      total_time += count_time;

      /* Credit all symbols that are covered by bin I.  */
      for (j = j - 1; j < symtab.len; ++j)
	{
	  sym_low_pc = symtab.base[j].hist.scaled_addr;
	  sym_high_pc = symtab.base[j + 1].hist.scaled_addr;

	  /* If high end of bin is below entry address,
	     go for next bin.  */
	  if (bin_high_pc < sym_low_pc)
	    break;

	  /* If low end of bin is above high end of symbol,
	     go for next symbol.  */
	  if (bin_low_pc >= sym_high_pc)
	    continue;

	  overlap =
	    MIN (bin_high_pc, sym_high_pc) - MAX (bin_low_pc, sym_low_pc);
	  if (overlap > 0)
	    {
	      DBG (SAMPLEDEBUG,
		   printf (
	       "[assign_samples] [0x%lx,0x%lx) %s gets %f ticks %ld overlap\n",
			   (unsigned long) symtab.base[j].addr,
			   (unsigned long) (sizeof (UNIT) * sym_high_pc),
			   symtab.base[j].name, overlap * count_time / hist_scale,
			   (long) overlap));

	      addr = symtab.base[j].addr;
	      credit = overlap * count_time / hist_scale;

	      /* Credit symbol if it appears in INCL_FLAT or that
		 table is empty and it does not appear it in
		 EXCL_FLAT.  */
	      if (sym_lookup (&syms[INCL_FLAT], addr)
		  || (syms[INCL_FLAT].len == 0
		      && !sym_lookup (&syms[EXCL_FLAT], addr)))
		{
		  symtab.base[j].hist.time += credit;
		}
	      else
		{
		  total_time -= credit;
		}
	    }
	}
    }

  DBG (SAMPLEDEBUG, printf ("[assign_samples] total_time %f\n",
			    total_time));
}

/* Calls 'hist_assign_sampes_1' for all histogram records read so far. */
void
hist_assign_samples ()
{
  unsigned i;

  scale_and_align_entries ();

  for (i = 0; i < num_histograms; ++i)
    hist_assign_samples_1 (&histograms[i]);
  
}

/* Print header for flag histogram profile.  */

static void
print_header (int prefix)
{
  char unit[64];

  sprintf (unit, _("%c%c/call"), prefix, hist_dimension_abbrev);

  if (bsd_style_output)
    {
      printf (_("\ngranularity: each sample hit covers %ld byte(s)"),
	      (long) hist_scale * (long) sizeof (UNIT));
      if (total_time > 0.0)
	{
	  printf (_(" for %.2f%% of %.2f %s\n\n"),
		  100.0 / total_time, total_time / hz, hist_dimension);
	}
    }
  else
    {
      printf (_("\nEach sample counts as %g %s.\n"), 1.0 / hz, hist_dimension);
    }

  if (total_time <= 0.0)
    {
      printf (_(" no time accumulated\n\n"));

      /* This doesn't hurt since all the numerators will be zero.  */
      total_time = 1.0;
    }

  if (total_time / hz_int >= 100000.0 && ! bsd_style_output)
    {
      printf ("%5.5s %13.13s %11.11s %8.8s %8.8s %8.8s  %-8.8s\n",
	      "%  ", _("cumulative"), _("self  "), "", _("self  "),
	      _("total "), "");
      printf ("%5.5s %12.12s  %11.11s %8.8s %8.8s %8.8s  %-8.8s\n",
	      _("time"), hist_dimension, hist_dimension, _("calls"), unit,
	      unit, _("name"));
    }
  else
    {
      printf ("%5.5s %10.10s %8.8s %8.8s %8.8s %8.8s  %-8.8s\n",
	      "%  ", _("cumulative"), _("self  "), "", _("self  "),
	      _("total "), "");
      printf ("%5.5s %9.9s  %8.8s %8.8s %8.8s %8.8s  %-8.8s\n",
	      _("time"), hist_dimension, hist_dimension, _("calls"), unit,
	      unit, _("name"));
    }
}


static void
print_line (Sym *sym, double scale)
{
  if (ignore_zeros && sym->ncalls == 0 && sym->hist.time == 0)
    return;

  accum_time += sym->hist.time;

  if (bsd_style_output)
    printf ("%5.1f %10.2f %8.2f",
	    total_time > 0.0 ? 100 * sym->hist.time / total_time : 0.0,
	    accum_time / hz, sym->hist.time / hz);
  else if (total_time / hz >= 100000.0)
    printf ("%6.2f %12.0f %11.0f",
	    100 * sym->hist.time / total_time,
	    accum_time / hz, sym->hist.time / hz);
  else
    printf ("%6.2f %9.0f %8.0f",
	    total_time > 0.0 ? 100 * sym->hist.time / total_time : 0.0,
	    accum_time / hz, sym->hist.time / hz);

  if (sym->ncalls != 0)
    printf (" %8lu %8.2f %8.2f  ",
	    sym->ncalls, scale * sym->hist.time / hz / sym->ncalls,
	    scale * (sym->hist.time + sym->cg.child_time) / hz / sym->ncalls);
  else
    printf (" %8.8s %8.8s %8.8s  ", "", "", "");

  if (bsd_style_output)
    print_name (sym);
  else
    print_name_only (sym);

  printf ("\n");
}


/* Compare LP and RP.  The primary comparison key is execution time,
   the secondary is number of invocation, and the tertiary is the
   lexicographic order of the function names.  */

static int
cmp_time (const PTR lp, const PTR rp)
{
  const Sym *left = *(const Sym **) lp;
  const Sym *right = *(const Sym **) rp;
  double time_diff;

  time_diff = right->hist.time - left->hist.time;

  if (time_diff > 0.0)
    return 1;

  if (time_diff < 0.0)
    return -1;

  if (right->ncalls > left->ncalls)
    return 1;

  if (right->ncalls < left->ncalls)
    return -1;

  return strcmp (left->name, right->name);
}


/* Print the flat histogram profile.  */

void
hist_print ()
{
  Sym **time_sorted_syms, *top_dog, *sym;
  unsigned int sym_index;
  unsigned log_scale;
  double top_time;
  bfd_vma addr;

  if (first_output)
    first_output = FALSE;
  else
    printf ("\f\n");

  accum_time = 0.0;

  if (bsd_style_output)
    {
      if (print_descriptions)
	{
	  printf (_("\n\n\nflat profile:\n"));
#ifdef HEXAGON_SIM
	  hexagon_blurb (stdout);
#else
	  flat_blurb (stdout);
#endif
	}
    }
  else
    {
      printf (_("Flat profile:\n"));
    }

  /* Sort the symbol table by time (call-count and name as secondary
     and tertiary keys).  */
  time_sorted_syms = (Sym **) xmalloc (symtab.len * sizeof (Sym *));

  for (sym_index = 0; sym_index < symtab.len; ++sym_index)
    time_sorted_syms[sym_index] = &symtab.base[sym_index];

  qsort (time_sorted_syms, symtab.len, sizeof (Sym *), cmp_time);

  if (bsd_style_output)
    {
      log_scale = 5;		/* Milli-seconds is BSD-default.  */
    }
  else
    {
      /* Search for symbol with highest per-call
	 execution time and scale accordingly.  */
      log_scale = 0;
      top_dog = 0;
      top_time = 0.0;

      for (sym_index = 0; sym_index < symtab.len; ++sym_index)
	{
	  sym = time_sorted_syms[sym_index];
	  /* Don't let this symbol affect the scaling if it's not going
	     to be included in the histogram. */
	  if ((syms[INCL_FLAT].len != 0
	       && ! sym_lookup (&syms[INCL_FLAT], sym->addr))
	      || sym_lookup (&syms[EXCL_FLAT], sym->addr))
	    continue;
	  if (sym->ncalls != 0)
	    {
	      double call_time;

	      call_time = (sym->hist.time + sym->cg.child_time) / sym->ncalls;

	      if (call_time > top_time)
		{
		  top_dog = sym;
		  top_time = call_time;
		}
	    }
	}

      if (top_dog && top_dog->ncalls != 0 && top_time > 0.0)
	{
	  top_time /= hz;

	  for (log_scale = 0; log_scale < ARRAY_SIZE (SItab); log_scale ++)
	    {
	      double scaled_value = SItab[log_scale].scale * top_time;

	      if (scaled_value >= 1.0 && scaled_value < 1000.0)
		break;
	    }
	}
    }

  /* For now, the dimension is always seconds.  In the future, we
     may also want to support other (pseudo-)dimensions (such as
     I-cache misses etc.).  */
  print_header (SItab[log_scale].prefix);

  for (sym_index = 0; sym_index < symtab.len; ++sym_index)
    {
      addr = time_sorted_syms[sym_index]->addr;

      /* Print symbol if its in INCL_FLAT table or that table
	is empty and the symbol is not in EXCL_FLAT.  */
      if (sym_lookup (&syms[INCL_FLAT], addr)
	  || (syms[INCL_FLAT].len == 0
	      && !sym_lookup (&syms[EXCL_FLAT], addr)))
	print_line (time_sorted_syms[sym_index], SItab[log_scale].scale);
    }

  free (time_sorted_syms);

  if (print_descriptions && !bsd_style_output)
#ifdef HEXAGON_SIM
    hexagon_blurb (stdout);
#else
    flat_blurb (stdout);
#endif
}

int
hist_check_address (unsigned address)
{
  unsigned i;

  for (i = 0; i < num_histograms; ++i)
    if (histograms[i].lowpc <= address && address < histograms[i].highpc)
      return 1;

  return 0;
}

#if ! defined(min)
#define min(a,b) (((a)<(b)) ? (a) : (b))
#endif
#if ! defined(max)
#define max(a,b) (((a)>(b)) ? (a) : (b))
#endif

void
hist_clip_symbol_address (bfd_vma *p_lowpc, bfd_vma *p_highpc)
{
  unsigned i;
  int found = 0;

  if (num_histograms == 0)
    {
      *p_highpc = *p_lowpc;
      return;
    }

  for (i = 0; i < num_histograms; ++i)
    {
      bfd_vma common_low, common_high;
      common_low = max (histograms[i].lowpc, *p_lowpc);
      common_high = min (histograms[i].highpc, *p_highpc);

      if (common_low < common_high)
	{
	  if (found)
	    {
	      fprintf (stderr,
		       _("%s: found a symbol that covers "
			 "several histogram records"),
			 whoami);
	      done (1);
	    }

	  found = 1;
	  *p_lowpc = common_low;
	  *p_highpc = common_high;
	}
    }

  if (!found)
    *p_highpc = *p_lowpc;
}

/* Find and return exising histogram record having the same lowpc and
   highpc as passed via the parameters.  Return NULL if nothing is found.
   The return value is valid until any new histogram is read.  */
static histogram *
find_histogram (bfd_vma lowpc, bfd_vma highpc)
{
  unsigned i;
  for (i = 0; i < num_histograms; ++i)
    {
      if (histograms[i].lowpc == lowpc && histograms[i].highpc == highpc)
	return &histograms[i];
    }
  return 0;
}

/* Given a PC, return histogram record which address range include this PC.
   Return NULL if there's no such record.  */
static histogram *
find_histogram_for_pc (bfd_vma pc)
{
  unsigned i;
  for (i = 0; i < num_histograms; ++i)
    {
      if (histograms[i].lowpc <= pc && pc < histograms[i].highpc)
	return &histograms[i];
    }
  return 0;
}