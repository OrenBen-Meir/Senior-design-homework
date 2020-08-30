#include <stdlib.h>
#include <pthread.h>

struct counter {
	unsigned long counter;
	pthread_mutex_t mutex;
};

struct counter *
counter_create(void)
{
	struct counter *r = calloc(sizeof *r, 1);

	if (pthread_mutex_init(&r->mutex, NULL) != 0)
		return NULL;

	return r;
}

void
counter_inc(struct counter *counter)
{

	pthread_mutex_lock(&counter->mutex);
	counter->counter++;
	pthread_mutex_unlock(&counter->mutex);
	return;
}

unsigned long
counter_read(struct counter *counter)
{
	unsigned long snapshot;

	pthread_mutex_lock(&counter->mutex);
	snapshot = counter->counter;
	pthread_mutex_unlock(&counter->mutex);
	return snapshot;
}
