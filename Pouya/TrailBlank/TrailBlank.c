/* Program to remove all blank spaces at the end of lines.
*/

#include <stdio.h>
#include <ctype.h>

#define BUFFERSIZE 1000
#define GO 1
#define STOP 0


int static STATE = GO;
int static BUFFER = GO;

int static getLine (char *str, FILE * src);

void cleanBlank (char *str, int index);

void cleanUp (FILE * src, FILE * des);

int
main (int argc, char const *argv[])
{
  FILE *input = fopen ("Input.txt", "r");
  FILE *output = fopen ("Output.txt", "w");
  cleanUp (input, output);
  fclose (input);
  fclose (output);
  return 0;
}

// note: in case space runs out, I have no idea what's gonna happen, I'll
//    get there later.
// this funtion reads each line, and saves it in a buffer.
int static
getLine (char *str, FILE * src)
{
  int i;              // index
  char c;             // read char is saved here
  //function reads line until it meets new line, EOF or runs out.
  for (i = 0; i < BUFFERSIZE && (c = fgetc (src)) != '\n' && c != EOF; i++)
    {
      str[i] = c;
    } // for
  // checks to see if c is EOF
  if (c == EOF)
    {
      STATE = STOP;
    } // if

  if (i == BUFFERSIZE)
  {
    BUFFER = STOP;
  } // if
  return i;
}

//function clears blank space in the end of str
void
cleanBlank (char *str, int index)
{
  //while the end of str is blank, keep going back
  while (isblank (str[--index]))
  ;
  str[index + 1] = '\0';
}

//this function combines getLine and cleanBlank. Also prints out our line
//  into output file.
void
cleanUp (FILE * src, FILE * des)
{
  char str[BUFFERSIZE];                 //the str we save our line in
  int index = getLine (str, src);
  cleanBlank (str, index);
  // loops until EOF comes up
  while (STATE)
    {
      if (BUFFER)
      {
          fprintf (des, "%s", str);
          BUFFER = GO;
      }
      else
      {
        fprintf (des, "%s\n", str);
      }
      index = getLine (str, src);
      cleanBlank (str, index);
    } // while

}
