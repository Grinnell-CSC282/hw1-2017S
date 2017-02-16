/* Input is a csv file, the home work assignment, and the number
*   of studetns with the highest grade. The program prtints out the
*   highest grades.
*   Later editions will add abiltiy to also print student name.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define FIRSTNAME 32
#define LASTNAME 64
#define ASSIGNMENT 32
#define BUFFER 150

typedef struct {
  char firstName[FIRSTNAME];
  char lastName[LASTNAME];
  char assignment[ASSIGNMENT];
  int score;
} student;

// from input, reads a line, and saves the appropriate data to a student struct.
// returns 1 if successful, 0 if not.
int
readStudent (student * s, FILE * input);

// finds the highest n grades from a csv file regarding assignment number assignment
void
highestGrade (char * src, char * assignment, int n);

// finds the min number in an array with its index, saves those to dest.
// first member of dest is the min number, the second one is its indes
// returns 0 if len == 0, 1 if successful
int
minFinder (int * arr, int len, int dest[2]);


int
main(int argc, char const *argv[])
{
  highestGrade(argv[1], argv[2], (atoi argv[3]));
  return 0;
}


void
highestGrade(char * src, char * assignment, int n)
{
  FILE * input = fopen(src , "r");       // file to read from
  int grades[n];                         // array ot save highest grades
  // initilizes array
  for (int i = 0; i < n; i++)
  {
    grades[i] = 0;
  } // for
  int min[2] = {0, 0};                  // initilizes min array
  student * s = malloc(sizeof(student));// a student struct to save the read Student
  // reads until it hits EOF
  while(readStudent(s, input))
  {
    // checks to see if homework matches, then checks to see if it's bigger than min
    if ((strcmp (s->assignment, assignment) == 0) && min[0] < s->score)
    {
      grades[min[1]] = s->score;
      min[0] = s->score;
      minFinder(grades, n, min);
    } // if
  } // while
  // prints every grade out
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", grades[i]);
  } // for
  printf("\n");
  fclose(input);
  free(s);
}



int
readStudent(student * sarr, FILE * input)
{
  char str[BUFFER];                // a place to temporarily save the read line
  // makes sure we're not in the end of the line
  if (fgets (str, BUFFER, input))
  {
    strcpy (sarr->firstName, strtok (str, ","));
    strcpy (sarr->lastName, strtok (NULL, ","));
    strcpy (sarr->assignment, strtok (NULL, ","));
    sarr->score = atoi (strtok (NULL, ","));
    return 1;
  } // if
  return 0;
}

int
minFinder (int * arr, int len, int dest[2])
{
  // checks to see if lenght of the array is 0 or not.
  if (len == 0)
  {
    return 0;
  } // if
  else
  {
    // goes throug the array
    for (int i = 0; i < len; i++)
    {
      // checks to see whether the number we think is min is bigger than
      //  a memeber of the array
      if (dest[0] > arr[i])
      {
        dest[0] = arr[i];
        dest[1] = i;

      } // if
    } // for
    return 1;
  } // else
}
