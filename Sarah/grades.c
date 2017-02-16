#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find the current lowest grade in the top 5 grades
int
get_lowest_grade (int highest_grades[])
{
	int lowest = 110; // grades cannot be higher than 100
	for (int i = 0; i < 5; i++) {
		if(highest_grades[i] < lowest) {
			lowest = highest_grades[i];
		}
	}
	return lowest;
}

// Updates the 5 highest grades with the new grade
void
update_highest_grades (int grade, int highest_grades[])
{
	int lowest = get_lowest_grade (highest_grades);
	int flag = 1;
	for (int i = 0; i < 5; i++) {
		if(grade < highest_grades[i]) {
			flag = 0;
		}
	}
}

// Splits input string into parts
void split_student_string (char *student, char student_split[])
{
	char *token;
	int i = 0;
	token = strtok(student,",");
	while(token != NULL) {
		student_split[i++] = *token;
		token = strtok(NULL,",");
	}
}

// Processes file and finds the highest grades
int
main()
{
	char *student = (char*)malloc (1024);
	char *assignment = (char*)malloc (1024);
	int highest_grades[5] = {0,0,0,0,0};
	char *student_split = (char*)malloc (sizeof(char*)*4);

	FILE* input = fopen ("input", "r");
	while(fgets (student, 1024, input))
	{
		printf("%s\n", student);
		split_student_string (student, student_split);
		if (strcmp (&student_split[2], "homework 2") == 0) {
			update_highest_grades (student_split[3], highest_grades);
		}
	}

	printf ("The five highest grades on homework 2 are: %d, %d, %d, %d, %d\n",
			highest_grades[0], highest_grades[1], highest_grades[2],
			highest_grades[3], highest_grades[4]);

	free (student);
	free (assignment);
	free (student_split);
	fclose (input);
	return 0;
}
