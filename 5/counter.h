#pragma once

struct counter;
typedef struct counter counter_t;

/* Returns a counter data structure. */
counter_t *counter_create(void);

/* Increments the value in the counter by 1. */
void counter_inc(counter_t *);

/* Reads the current value of the counter. */
unsigned long counter_read(counter_t *);
