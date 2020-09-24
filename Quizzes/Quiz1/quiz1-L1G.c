/*
File:           quiz1-L1G.c
Purpose:        Implementation of submissible functions for CPSC259 in-lab quiz 1
                COMPLETE THE IMPLEMENTATIONS IN THIS FILE
Author:         Pedro Leite 
Student Number: 61981213
CS Account:      q8i2b
Date:           Add the date here
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "quiz1-L1G.h"

#define BUFFERLINESIZE      32    // maximum length of line in file
#define VALUES_PER_LINE     4
#define VALUES_IN_FILE      24

/*
Runs the steps of the main program logic.
PRE:       NULL (no pre-conditions)
POST:      NULL (no side-effects)
PARAMS:    filename is the name of a file in the same directory
RETURN:    the average computed from get_average
*/
double process(char* filename)
{
    /* Variables */
    int    readings[VALUES_IN_FILE];
    char   line_buffer[BUFFERLINESIZE];
    FILE* file_pointer = NULL;
    int    i = 0;
    double  average = 0.0;
    int values_per_line;

    /* Opens data file for reading */
    //fopen_s(&file_pointer, filename, "r"); // USE THIS LINE FOR VISUAL STUDIO
     file_pointer = fopen(filename, "r"); // USE THIS LINE FOR GRADESCOPE

    /* Copies the file, one line at a time, to a line buffer using fgets in a while loop */
    while (fgets(line_buffer, BUFFERLINESIZE, file_pointer))
    {

        /* Uses sscanf inside the loop to copy the integer in each line to a cell in the readings array */
        sscanf(line_buffer, "%d %d %d %d", &readings[i], &readings[i+1], &readings[i+2], &readings[i+3]);
        i+=4;
    }
  /* If the file pointer does not equal NULL THEN closes the pointer */
      if (file_pointer != NULL)
        fclose(file_pointer);

  /* Finds the average of the integers in the readings array */
      average = get_average(readings, VALUES_IN_FILE);

  /* Prints your result here */
    printf("%f", average);
  
  /* Return the computed average */
  return average;
}

/*
Returns the average value of the elements in the array
PRE:       array_length is the correct length of the array
POST:      NULL (no side-effects)
RETURN:    the average (a double) of the elements in the array
*/
double get_average(int array[], int array_length)
{
    int i = 0;
    double sum = 0;
    for (i = 0; i < array_length; i++) {
        sum = sum + array[i];
    }

  return ((double)sum/array_length);
}