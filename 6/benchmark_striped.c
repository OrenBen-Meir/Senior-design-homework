#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "counter_striped.h"

static counter_t *counter;
static sig_atomic_t leave = 0;

#define INTERVAL	5

static void *
thread(void *unused)
{
	counter_handle_t *handle = counter_handle_create(counter);

	(void)unused;

	for (;;) {
		counter_inc(handle);
		counter_inc(handle);
		counter_inc(handle);
		counter_inc(handle);
		if (leave == 1)
			break;
	}

	return NULL;
}

static void
alarm_handler(int unused)
{

	(void)unused;
	leave = 1;
	return;
}

int
main(int argc, const char *argv[])
{
	int n_threads;
	pthread_t *threads;
	unsigned long value;

	if (argc != 2) {
		fprintf(stderr, "Usage: counter <number of threads>\n");
		exit(EXIT_FAILURE);
	}

	counter = counter_create();
	assert(counter != NULL);

	n_threads = atoi(argv[1]);
	if (n_threads <= 0 || n_threads > 16) {
		fprintf(stderr, "error: number of threads must be > 0 and < 16.\n");
		return 0;
	}

	threads = malloc(sizeof(*threads) * n_threads);
	assert(threads != NULL);

	/* Send a signal in INTERVAL seconds to stop the test. */
	alarm(INTERVAL);

	/* Call alarm_handler. */
	if (signal(SIGALRM, alarm_handler) == SIG_ERR)
		abort();

	for (int i = 0; i < n_threads; i++) {
		if (pthread_create(&threads[i], NULL, thread, NULL) != 0)
			abort();
	}

	for (int i = 0; i < n_threads; i++) {
		pthread_join(threads[i], NULL);
	}

	value = counter_read(counter);
	printf("%15lu\n", value / INTERVAL);
	return 0;
}
