#include <stdio.h>

extern unsigned long long sum(unsigned int *array, size_t n);

int
main(void)
{
	unsigned int array[] = { 1, 1, 1, 3 };
	unsigned long long r = sum(array, sizeof(array) / sizeof(*array));

	printf("Result is: %llu (%s)\n", r, r == 6 ? "correct" : "incorrect");
	return 0;	
}
