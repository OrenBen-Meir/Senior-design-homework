#include <stdio.h>
#include <stdbool.h>
#include <string.h>

extern size_t your_strlen(const char *);

int
main(void)
{
	const char *strings[] = { "apple", "bapple", "1", "\0", "12", "333", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaa" };
	size_t i = 0;
	bool r = true;

	for (i = 0; i < sizeof(strings) / sizeof(*strings); i++) {
		size_t a = strlen(strings[i]);
		size_t b = your_strlen(strings[i]);

		printf("[%s] %zu == %zu?\n", strings[i], a, b);

		r &= a == b;
	}

	if (r == true)
		puts("Success");
	else
		puts("Failure");
	return 0;	
}
