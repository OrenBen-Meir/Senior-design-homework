#pragma once

struct counter;
typedef struct counter counter_t;

struct counter_handle;
typedef struct counter_handle counter_handle_t;

/* Returns a counter data structure. */
counter_t *counter_create(void);

/* Returns a thread-local handler to a counter. */
counter_handle_t *counter_handle_create(counter_t *);

/* Increments the value in the counter by 1. */
void counter_inc(counter_handle_t *);

/* Reads the current value of the counter. */
unsigned long counter_read(counter_t *);


