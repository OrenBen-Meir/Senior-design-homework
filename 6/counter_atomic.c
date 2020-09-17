#include <ck_pr.h>
#include <stdlib.h>
#include <pthread.h>

struct counter {
	uint64_t counter;
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

	ck_pr_inc_64(&counter->counter);
	return;
}

unsigned long
counter_read(struct counter *counter)
{
	return (unsigned long)ck_pr_load_64(&counter->counter);
}
