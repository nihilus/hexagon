/* ==> This file as been derived from flat_bl.c.  Modifed to 
   suit the Hexagon simulator <== */

#include <stdio.h>
#include "ansidecl.h"

extern char hist_dimension[16];
extern char hist_dimension_abbrev;

void
hexagon_blurb (FILE *file)
{
  fputs ("\n", file);
  fprintf (file, " %%\t\tthe percentage of the total running %s of the\n",
	   hist_dimension);
  fputs ("time\t\tprogram used by this function.\n", file);
  fputs ("\n", file);
  fprintf (file, "cumulative\ta running sum of the number of %s accounted\n",
	   hist_dimension);
  fprintf (file, " %s\t\tfor by this function and those listed above it.\n",
	   hist_dimension);
  fputs ("\n", file);
  fprintf (file, " self\t\tthe number of %s accounted for by this\n",
	   hist_dimension);
  fprintf (file, "%s\t\tfunction alone.  This is the major sort for this\n",
	   hist_dimension);
  fputs ("\t\tlisting.\n", file);
  fputs ("\n", file);
  fputs ("calls\t\tthe number of times this function was invoked, if\n",
	 file);
  fputs ("\t\tthis function is profiled, else blank.\n", file);
  fputs (" \n", file);
  fprintf (file, " self\t\tthe average number of %s spent in this\n",
	   hist_dimension);
  fprintf (file,
	   " %c/call\t\tfunction per call, if this function is profiled,\n",
	   hist_dimension_abbrev);
  fputs ("\t\telse blank.\n", file);
  fputs ("\n", file);
  fprintf (file, " total\t\tthe average number of %s spent in this\n",
	   hist_dimension);
  fprintf (file,
	   " %c/call\t\tfunction and its descendents per call, if this \n",
	   hist_dimension_abbrev);
  fputs ("\t\tfunction is profiled, else blank.\n", file);
  fputs ("\n", file);
  fputs ("name\t\tthe name of the function.  This is the minor sort\n", file);
  fputs ("\t\tfor this listing. The index shows the location of\n", file);
  fputs ("\t\tthe function in the gprof listing. If the index is\n", file);
  fputs ("\t\tin parenthesis it shows where it would appear in\n", file);
  fputs ("\t\tthe gprof listing if it were to be printed.\n", file);
}
