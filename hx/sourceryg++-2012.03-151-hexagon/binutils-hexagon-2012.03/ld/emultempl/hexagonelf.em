##################################################################

# This file is sourced from elf32.em, and defines extra
# Hexagon-specific routines.

case "${target_alias}" in
  hexagon*-linux*)
    HEXAGON_IS_LINUX=" "
    # The SDA is not supported in Linux.
    HEXAGON_LINUX_G_SWITCH=$'
      else
        {
          g_switch_value = 0;
          einfo (_("%P: small data size reset to zero\\n"));
        }
    '
    HEXAGON_LINUX_G_RESET=$'
    /* Default to no SDA. */
    g_switch_value = 0;
    '
    # The TCM is not supported in Linux.
    HEXAGON_LINUX_USE_TCM=$'
      else
        einfo (_("%P%F: `-tcm\\\' not supported\\n"));
    '
    ;;
  hexagon*)
    ;;
esac

cat >>e${EMULATION_NAME}.c <<EOF

#include "elf/internal.h"
#include "elf32-hexagon.h"
#include "elf/hexagon.h"
#include "elf-bfd.h"
#include "hexagon-isa.h"

#define EMUL_HEXAGON

/* If TRUE, tcm will be used.  */
static bfd_boolean use_tcm = FALSE;

/* TRUE (default) if trampolines are enabled.  */
static bfd_boolean use_trampolines = TRUE;

/* TRUE if dynamic sections are always emitted.  */
static bfd_boolean force_dynamic = FALSE;

static char* hexagon_arch_name;
static int hexagon_cmdline_set_arch;

struct hexagon_march
{
  char *march_name_fe, *march_alt_fe, *march_short_fe;
  char *march_name_be;
};

static const struct hexagon_march hexagon_marchs[] =
{
  {"hexagonv2", "qdsp6v2", "v2", "hexagonv2"},
  {"hexagonv3", "qdsp6v3", "v3", "hexagonv3"},
  {"hexagonv4", "qdsp6v4", "v4", "hexagonv4"},
  {"hexagonv5", "qdsp6v5", "v5", "hexagonv5"},
  {"hexagonv55", "qdsp6v55", "v55", "hexagonv55"}
};

static void
hexagon_after_open (void)
{
  lang_output_section_statement_type *os;
  
  /* Call the standard routine.  */
  gld${EMULATION_NAME}_after_open ();

  hexagon_isa_init (bfd_get_mach (link_info.output_bfd), NULL, NULL);

  if (force_dynamic
      && link_info.input_bfds
      && !_bfd_elf_link_create_dynamic_sections
	    (link_info.input_bfds, &link_info))
    einfo ("%X%P: Cannot create dynamic sections %E\n");

  /* Align the VMA of the .sdata section.  Note that we do not want to
     set the alignment attribute of the section, because that affects
     the alignment in the executable file as well as the VMA.  Instead,
     we want to do the equivalent of putting
       .sdata ALIGN(0x80000) : { ... }
     in the linker script.  */
  os = lang_output_section_find (".sdata");
  if (os && !os->addr_tree)
    {
      bfd_vma align = hexagon_sda_base_align (link_info.output_bfd);
      os->addr_tree = exp_unop (ALIGN_K, exp_intop (align));
    }
}

static void
hexagon_after_parse (void)
{
  /* For Hexagon, --export-dynamic implies --force-dynamic. */
  if (link_info.export_dynamic)
    force_dynamic = TRUE;

  /* Do not try to relax to add trampolines with -r. */
  if (use_trampolines)
    {
      use_trampolines = !link_info.relocatable;
      if (use_trampolines)
	ENABLE_RELAXATION;
      else
        DISABLE_RELAXATION;
    }

  /* It likely does not make sense to have a DSO using the TCM. */
  if (use_tcm)
    {
      if (link_info.shared)
        einfo (_("%P%F: \`-tcm\' not supported with \`-shared\'\\n"));
      ${HEXAGON_LINUX_USE_TCM}
    }

  if (g_switch_value)
    {
      /* The compiler doesn't set up the GP register, which precludes the SDA
         in some situations. */
      if (link_info.shared)
        {
          g_switch_value = 0;
          einfo (_("%P: small data size set to zero with \`-shared\'\\n"));
        }
      ${HEXAGON_LINUX_G_SWITCH}
    }

  after_parse_default ();
}

static void
hexagon_before_parse (void)
{
  gld${EMULATION_NAME}_before_parse ();

  ${HEXAGON_LINUX_G_RESET}
}
EOF

source_em ${srcdir}/emultempl/needrelax.em

fragment <<EOF

static void
hexagon_before_allocation (void)
{
  /* Pass the use_trampolines flag on to the back end.  */
  if (use_trampolines)
    hexagon_use_trampolines (&link_info);

  /* Call main function; we're just extending it.  */
  need_relax_${EMULATION_NAME}_before_allocation ();
}
EOF

# Put these extra routines in ld_${EMULATION_NAME}_emulation
LDEMUL_AFTER_OPEN=hexagon_after_open
LDEMUL_AFTER_PARSE=hexagon_after_parse
LDEMUL_BEFORE_PARSE=hexagon_before_parse
LDEMUL_BEFORE_ALLOCATION=hexagon_before_allocation

# Hexagon option values (between 300 and 399). Note OPTION_MV* must be
# numbered consecutively.
PARSE_AND_LIST_PROLOGUE=$'
#define OPTION_MV2		301
#define OPTION_MV3		302
#define OPTION_MV4		303
#define OPTION_MV5		304
#define OPTION_MV55		305
#define OPTION_MARCH		306
#define OPTION_MCPU		307
#define OPTION_TCM		308
#define OPTION_TRAMPOLINES	309
#define OPTION_NO_TRAMPOLINES	310
#define OPTION_FORCE_DYNAMIC	311
'

# Hexagon options.
# Because the option `-m' is overloaded here, proper code must be added to get_emulation ().
PARSE_AND_LIST_LONGOPTS=$'
    {"mv2",         no_argument,       NULL, OPTION_MV2},
    {"mv3",         no_argument,       NULL, OPTION_MV3},
    {"mv4",         no_argument,       NULL, OPTION_MV4},
    {"mv5",         no_argument,       NULL, OPTION_MV5},
    {"mv55",	    no_argument,       NULL, OPTION_MV55},
    {"march",       required_argument, NULL, OPTION_MARCH},
    {"mcpu",        required_argument, NULL, OPTION_MCPU},
    {"tcm",         no_argument,       NULL, OPTION_TCM},
    {"trampolines", no_argument,       NULL, OPTION_TRAMPOLINES},
    {"no-trampolines", no_argument,    NULL, OPTION_NO_TRAMPOLINES},
    {"force-dynamic", no_argument,     NULL, OPTION_FORCE_DYNAMIC},
'

# Hexagon target help.
PARSE_AND_LIST_OPTIONS=$'
  fprintf (file, _("  --force-dynamic                Always create dynamic sections\\n"));
  fprintf (file, _("  --march={v2|v3|v4|v5|v55}      Link for the specified Hexagon architecture\\n"));
  fprintf (file, _("  --mcpu={v2|v3|v4|v5|v55}       Equivalent to `--march\'\\n"));
  fprintf (file, _("  -m{v2|v3|v4|v5|v55}            Equivalent to `--march\'\\n"));
'
test -z "$HEXAGON_IS_LINUX" && PARSE_AND_LIST_OPTIONS=$PARSE_AND_LIST_OPTIONS$'
  fprintf (file, _("  --tcm                       Use the TCM\\n"));
'
PARSE_AND_LIST_OPTIONS=$PARSE_AND_LIST_OPTIONS$'
  fprintf (file, _("  --trampolines               Add trampolines when necessary (default)\\n"));
  fprintf (file, _("  --no-trampolines            Don\'t add trampolines\\n"));
'

# Hexagon option processing.
PARSE_AND_LIST_ARGS_CASES=$'
    case 1: /* File name. */
      /* Unless the output architecture is specified, then it is determined by
         the input files according to hexagon_bfd_compatible (). */
      if (!hexagon_cmdline_set_arch)
        {
          static const struct bfd_arch_info *arch_info = NULL;
          bfd *in_bfd;
          char *in_bfd_name;
          char **matching;
          size_t i;

          in_bfd = bfd_openr (optarg, NULL);
          if (in_bfd == NULL)
            {
              einfo (_("%P%F: Cannot read file `%s\'\\n"), optarg);
              xexit (1);
            }

          if (bfd_check_format_matches (in_bfd, bfd_object, &matching))
            {
              in_bfd_name = (char*) bfd_printable_name (in_bfd);
              if (!in_bfd_name)
                {
                  einfo (_("%P%F: Does not recognize the architecture of file `%s\'.\\n"), optarg);
                  xexit (1);
                }

              arch_info = bfd_lookup_arch
                (ldfile_output_architecture, ldfile_output_machine);
              arch_info = (bfd_get_arch_info (in_bfd))->compatible
                (bfd_get_arch_info (in_bfd), arch_info);
              if (arch_info)
                {
                  ldfile_output_machine      = arch_info->mach;
                  ldfile_output_machine_name = arch_info->printable_name;
                }

              for (i = 0; i < ARRAY_SIZE (hexagon_marchs); i++)
                if (!strcmp (in_bfd_name, hexagon_marchs[i].march_name_be))
                  {
                    /* Only set if the cmdline has not set the type yet. */
                    ldfile_set_output_arch (hexagon_marchs[i].march_name_be, bfd_arch_hexagon);

                    break;
                  }

              bfd_close (in_bfd);
            }
        }
      return FALSE;

    case OPTION_TCM:
      use_tcm = TRUE;
      break;

    case OPTION_TRAMPOLINES:
      use_trampolines = TRUE;
      break;

    case OPTION_NO_TRAMPOLINES:
      use_trampolines = FALSE;
      break;

    case OPTION_FORCE_DYNAMIC:
      force_dynamic = TRUE;
      break;

    case OPTION_MV2:
    case OPTION_MV3:
    case OPTION_MV4:
    case OPTION_MV5:
    case OPTION_MV55:
    case OPTION_MARCH:
    case OPTION_MCPU:
      /* The output architecture is specified. */
        {
          char *temp_hexagon_arch_name = NULL;
          size_t i;

          switch (optc)
            {
              case OPTION_MV2:
              case OPTION_MV3:
              case OPTION_MV4:
              case OPTION_MV5:
	      case OPTION_MV55:
                /* -mv* options. */
                temp_hexagon_arch_name
                  = hexagon_marchs[optc - OPTION_MV2].march_name_be;
                break;

              default:
                /* -march and- mcpu options. */
                for (i = 0; i < ARRAY_SIZE (hexagon_marchs); i++)
                  if (!strcmp (optarg, hexagon_marchs[i].march_name_fe)
                      || !strcmp (optarg, hexagon_marchs[i].march_alt_fe)
                      || !strcmp (optarg, hexagon_marchs[i].march_short_fe))
                    {
                      temp_hexagon_arch_name = hexagon_marchs [i].march_name_be;
                      break;
                    }

                if (i == ARRAY_SIZE (hexagon_marchs))
                  {
                    einfo (_("invalid architecture `%s\'.\\n"));
                    xexit (1);
                  }

                break;
            }

          if (hexagon_cmdline_set_arch)
            if (strcmp (temp_hexagon_arch_name, hexagon_arch_name) != 0)
              {
                einfo (_("conflicting architectures specified.\\n"));
                xexit (1);
              }

          hexagon_arch_name = temp_hexagon_arch_name;
          hexagon_cmdline_set_arch = TRUE;
          ldfile_set_output_arch (hexagon_arch_name, bfd_arch_hexagon);
        }
      break;
'

