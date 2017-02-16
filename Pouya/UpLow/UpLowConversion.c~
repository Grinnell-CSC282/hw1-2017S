/* Program to convert all uppercase letters to lowercase ones in a standard
*     text file.
*/
#include <stdio.h>
#include <ctype.h>

void
upLowConversion (char * src, char * des);

int
main (int argc, char const *argv[]) {
  upLowConversion("input.txt", "output.txt");
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
upLowConversion (char * src, char * des){
  FILE * input = fopen(src, "r");
  FILE * output = fopen(des, "w");
  char c;
  while ((c = fgetc (input)) != EOF){
    if (isupper(c)){
      c = tolower(c);
    }
    fputc (c, output);
  }
  fclose(input);
  fclose(output);
}
