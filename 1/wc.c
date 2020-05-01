#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Expected usage:
 * ./wc <words | lines> <file>
 *
 * If argv[1] is "words", then you should count the number of words. If it
 * is "lines", then you should count the number of lines.
 *
 * For example:
 * $ cat a.txt
 * a b c d
 * $ ./wc words a.txt
 * 4
 * $ ./wc lines a.txt
 * 1
 *
 * YOUR PROGRAM MUST COMPILE CLEANLY WITH: gcc -o wc wc.c -Wall -pedantic
 */

/*
 * This should return the number of spaces in the buffer using the isspace
 * function.
 */
static size_t
words(const char *buffer, size_t length)
{
	/* Also I need to mention that the number of spaces in a program
	 * is not the same as the number of words in a program.
	 */ 
	size_t sum = 0;
	_Bool in_space = false;// if true, then the loop below is within a space region
	for(size_t i = 0; i < length; i++){
		if(isspace(buffer[i]))
			in_space = true;
		else if(in_space == true){
			in_space = false;
			sum++;
		}
	}

	return sum;
}

/*
 * This should return the number of lines in the buffer by checking for the
 * existence of '\n' characters in the buffer.
 */
static size_t
lines(const char *buffer, size_t length)
{
	size_t sum = 0;

	const char* end = buffer + length;
	for(const char *char_p = buffer; char_p != end; char_p++){
		if(*char_p == '\n')
			sum++;
	}
	return sum;
}

int
main(int argc, const char *argv[])
{
	char buffer[256];
	FILE *fp;
	size_t bytes_read;
	size_t sum = 0;
	enum {
		MODE_LINES,
		MODE_WORDS
	} mode;
	bool middle = false;

	if (argc != 3) {
		printf("Usage: ./wc <words | lines> <file>\n");
		exit(EXIT_FAILURE);
	}

	/*
	 * Set mode here based on the value of argv[1]. Use the
	 * strcmp function for string comparison.
	 */

	if(strcmp(argv[1],"words")){
		mode = MODE_LINES;
	} else if (strcmp(argv[1], "lines")){
		mode = MODE_WORDS;
	}

	fp = fopen(argv[2], "r");
	if (fp == NULL) {
		printf("error: could not open %s: %s\n",
		    argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}

	for (;;) {
		bytes_read = fread(buffer, 1, sizeof(buffer), fp);
		if (bytes_read == 0)
			break;

		if (mode == MODE_LINES) {
			sum += lines(buffer, bytes_read);
		} else if (mode == MODE_WORDS) {
			sum += words(buffer, bytes_read);
		}
	}

	/*
	 * You need to increment sum if you were in the middle of a line or word and end of
	 * file was hit.
	 */
	printf("%zu\n", sum + middle);
	return 0;
}
