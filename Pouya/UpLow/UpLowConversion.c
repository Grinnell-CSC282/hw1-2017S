/* Program to convert all uppercase letters to lowercase ones in a standard
*     text file.
*/
#include <stdio.h>
#include <ctype.h>

void upLowConversion (char *src, char *des);

int
main (int argc, char const *argv[])
{
  upLowConversion ("input.txt", "output.txt");
  return 0;
}

/*
*   Parameters:
*       src, a valid input file
*       des, a valid adress to an output file, fopen will creat file if
*             it does not exist.
*   Postcondition:
*       output.txt will change as a side effect.
*       All upper case chars will become lowercase.
*/
void
upLowConversion (char *src, char *des)
{
  FILE *input = fopen (src, "r");     // file to read from
  FILE *output = fopen (des, "w");    // file to print out to
  char c;                             // a character to save the read char
  // reads the input file untill it hits EOF
  while ((c = fgetc (input)) != EOF)
    {
      // checks to see if c is upper case, if yes, turns it into lower case
      if (isupper (c))
	    {
	     c = tolower (c);
      } // if
      fputc (c, output);
    } // while
  fclose (input);
  fclose (output);
}
