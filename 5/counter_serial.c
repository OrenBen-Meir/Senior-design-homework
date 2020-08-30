#include <stdlib.h>

struct counter {
	unsigned long counter;
};

struct counter *
counter_create(void)
{
	struct counter *r = calloc(sizeof *r, 1);

	return r;
}

void
counter_inc(struct counter *counter)
{

	counter->counter++;
	return;
}

unsigned long
counter_read(struct counter *counter)
{

	return counter->counter;
}
