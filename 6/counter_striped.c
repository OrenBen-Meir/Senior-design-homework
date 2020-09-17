#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <ck_pr.h>

struct counter_handle {
	uint64_t value;
	struct counter_handle *next;
};

struct counter {
	struct counter_handle *counters;
	pthread_mutex_t mutex;
};

struct counter *
counter_create(void)
{
}

void
counter_inc(struct counter_handle *counter)
{
}

unsigned long
counter_read(struct counter *counter)
{
}

struct counter_handle *
counter_handle_create(struct counter *counter)
{
}
