#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ck_pr.h>

#include <inttypes.h>


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
	struct counter *ctr = malloc(sizeof *ctr);
	if (pthread_mutex_init(&ctr->mutex, NULL) != 0)
		return NULL;
	ctr->counters = NULL;
	return ctr;
}

void
counter_inc(struct counter_handle *counter)
{
	counter->value++;
}

unsigned long
counter_read(struct counter *counter)
{
	if (counter == NULL) {
		fprintf(stderr, "error: *counter can't  be null.\n");
		abort();
	}
	struct counter_handle *ch = counter->counters;
	unsigned long sum = 0;
	while(ch != NULL) {
		sum += ch->value;
		ch = ch->next;
	}
	return sum;
}

struct counter_handle *
counter_handle_create(struct counter *counter)
{
	if (counter == NULL) {
		fprintf(stderr, "error: *counter can't  be null.\n");
		abort();
	}
	struct counter_handle *ch = malloc(sizeof *ch);
	ch->value = 0;
	pthread_mutex_lock(&counter->mutex);
	ch->next = counter->counters;
	counter->counters = ch;
	pthread_mutex_unlock(&counter->mutex);
	return ch;
}
