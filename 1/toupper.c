#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Expected usage:
 * ./toupper <file>
 *
 * Output should be the file contents in uppercase.
 * For example:
 * $ cat a.txt
 * a b c d
 * $ ./toupper a.txt
 * A B C D
 *
 * YOUR PROGRAM MUST COMPILE CLEANLY WITH: gcc -o wc wc.c -Wall -pedantic
 */

/* You must implement this function. */
static void
transform(const char *buffer, size_t length)
{

	/*
	 * Make use of the toupper function (refer to manual page) to transform
	 * the input string (which is up to length bytes to upper-case.
	 */
	const char *end = buffer + length; 
	for(char* char_ptr = (char*)buffer; char_ptr != end; char_ptr++){
		*char_ptr = toupper(*char_ptr);	
	}

	return;
}

int
main(int argc, const char *argv[])
{
	char buffer[256];
	FILE *fp;
	size_t bytes_read;
	//unsigned int counter = 0;

	if (argc != 2) {
		printf("Usage: ./toupper <file>\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("error: could not open %s: %s\n",
		    argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}

	for (;;) {
		bytes_read = fread(buffer, 1, sizeof(buffer), fp);
		if (bytes_read == 0)
			break;

		transform(buffer, sizeof buffer);
		printf("%.*s", (int)bytes_read, buffer);
	}

	return 0;
}
