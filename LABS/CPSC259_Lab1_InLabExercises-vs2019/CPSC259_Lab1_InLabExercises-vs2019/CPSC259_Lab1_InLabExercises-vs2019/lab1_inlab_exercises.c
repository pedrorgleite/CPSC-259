/*
File:         lab1_inlab_exercises.c
Purpose:      Exercises for lab 1
Author:       Pedro Leite
Student #s:   61981213 and 12345678
CS Accounts:  a1a1 and b2b2
Date:         Add the date here
*/

/* Preprocessor directives */
#include "lab1_inlab_exercises.h"
#include <stdlib.h> // For system command

/* See main.c for additional practices for C programming */

/*
Reverses the order of an array of integers
For example,
{ 1, 2, 3, 4 } -> {4, 3, 2, 1 }
{ 1, 2, 3 } -> { 3, 2, 1 }
{1} -> {1}
{} -> {}
PARAM:  array, an array of integers
PARAM:  length, the number of elements in array
PRE:    array is an array of integers
PRE:    length is the correct length of the array
POST:   the elements in array have been reversed in order
RETURN: N/A
*/
void reverse_array(int array[], int length) {
	int indx_1 = 0, indx_2 = length - 1;
	while (1) {
		int temp = array[indx_2];
		array[indx_2] = array[indx_1];
		array[indx_1] = temp;

		indx_1++;
		indx_2--;

		if (indx_2 <= indx_1)
			break;
	}
}

/*
Returns the length of the specified C string (an array of
characters that ends with the null character '\0')
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of char (excluding the terminating null) in string
*/
int length(const char string[])
{
	int count = 0;
	while (string[count] != '\0') {
		count++;
	}
	return count;
}

/*
Returns the number of occurrences of the specified char in the specified
char array (string)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PARAM:  letter_sought, a char
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of occurences of letter_sought in string
*/
int count_letters(const char string[], char letter)
{
	int count=0;
	int len;
	len = length(string);
	for (int i = 0; i < len; i++) {
		if (string[i] == letter) {
			count++;
		}
	}
	return count;
}

/*
Determines if a string is a palindrome.  Skips spaces.
For example,
""     -> returns 1 (an empty string is a palindrome)
"the"  -> returns 0
"abba" -> returns 1
"Abba" -> returns 0
"never odd or even"
-> returns 1 ("neveroddoreven" reversed is the same!)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   no side-effects, e.g., nothing is printed or changed
RETURN: IF string is a palindrome THEN 1
ELSE IF string is not a palindrome THEN 0
*/
int is_palindrome(const char string[]) {

	// This implementation is only partly correct
	int i = 0;
	int k = 0;
	char string_no_spaces[100];
	while (string[i] != '\0') {
		if (string[i] != ' ') {
			string_no_spaces[k] = string[i];
			k++;
		}
		i++;
	}
	string_no_spaces[k] = '\0';
	int string_no_spaces_len = length(string_no_spaces);
	int i2 = 0, j2 = string_no_spaces_len - 1;
	for (i2 = 0; i2 < j2; ++i2, --j2) {
		if (string_no_spaces[i2] != string_no_spaces[j2]) {
			return 0;
		}
	}
	return 1;

}