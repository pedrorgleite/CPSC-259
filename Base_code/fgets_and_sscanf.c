/*
 File:           fgets_and_sscanf.c
 Author:         CPSC 259
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERLINESIZE      128    
#define VALUES_PER_LINE     2
#define FILE_NAME           "data.txt"

/*
 Main function drives the program.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    IF the program exits correctly THEN 0 ELSE 1
 */
int main(void) {

    /* Variables */
	char   line_buffer[BUFFERLINESIZE];
	char first_string[BUFFERLINESIZE];
	char second_string[BUFFERLINESIZE];
	FILE * file_pointer = NULL;
	int i = 0;

	/* Opens data file for reading */
	fopen_s( &file_pointer, FILE_NAME, "r" );

	/* Copies the file, one line at a time, to line buffer using fgets in a while loop.
    If the file_poiter is NULL the while loop will break */
	while( fgets ( line_buffer, BUFFERLINESIZE, file_pointer ) ) {

		/* Uses sscanf inside the loop to copy the float in each line to the readings array */
		++i;
        /* I have some text followed by a space and then another 
        text*/
		sscanf( line_buffer, "%s %s", first_string, second_string); 
        /* sscanf var are passed by reference so var need & but since
        first_string and second_string are already a adress so it does no need & 
        */
		printf("Line %d of the file %s contains strings %s and %s\n", 
			i, FILE_NAME, first_string, second_string);
	}

	system("pause");
	return 0;

}

