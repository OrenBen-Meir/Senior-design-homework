#include <stdlib.h>
#include <spinlock/mcs.h>

struct counter {
	unsigned long counter;
	ck_spinlock_mcs_t spinlock;
};

struct counter *
counter_create(void)
{
	struct counter *r = calloc(sizeof *r, 1);
	ck_spinlock_mcs_init(&r->spinlock);

	return r;
}

void
counter_inc(struct counter *counter)
{

	ck_spinlock_mcs_context_t node;
	ck_spinlock_mcs_lock(&counter->spinlock, &node);
	counter->counter++;
	ck_spinlock_mcs_unlock(&counter->spinlock, &node);
	return;
}

unsigned long
counter_read(struct counter *counter)
{
	unsigned long snapshot;
	ck_spinlock_mcs_context_t node;
	
	ck_spinlock_mcs_lock(&counter->spinlock, &node);
	snapshot = counter->counter;
	ck_spinlock_mcs_unlock(&counter->spinlock, &node);
	return snapshot;
}
