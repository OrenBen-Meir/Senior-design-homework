Implement counter_mutex.c using the mcs lock from Concurrency Kit.

You'll want to #include <spinlock/mcs.h>
See /usr/local/include/spinlock/mcs.h for the implementation.

Update a README comparing and contrasting the stock counter_mutex to your implementation
that uses the mcs lock.

Compare and contrast. Why is the performance different? And how?

The performance of the mcs lock is actually worse than the pthread variant. 
The most likely reason is that the while loop wastes cpu cycles for a spinlock causing performance overhead while pthread is an adaptive mutex so it avoids it.
