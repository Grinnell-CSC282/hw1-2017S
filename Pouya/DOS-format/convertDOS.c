#include <stdio.h>

//change /r in DOS file to nothing
void
convertDOS (char *src, char *des)
{
  FILE *input = fopen (src, "r");   	// file to read from
  FILE *output = fopen (des, "w");  	// file to print out to
  char c;		                         	// a charachter to save the read char
  // read the input file until EOF comes up.
  while ((c = fgetc (input)) != EOF)
  {
    // incase c is escape char \r
    if (c != '\r')
	  {
	    fputc (c, output);
    } // if
  } // while
  fclose (input);
  fclose (output);
}
