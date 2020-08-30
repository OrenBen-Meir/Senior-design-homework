#!/bin/sh

for i in serial mutex atomic; do
	gcc -o benchmark_${i} benchmark.c counter_${i}.c -O2 -pthread -D__x86_64__
done

gcc -o benchmark_striped benchmark_striped.c counter_striped.c -O2 -pthread -D__x86_64__
