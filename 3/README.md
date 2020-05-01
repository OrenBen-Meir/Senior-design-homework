This homework assignment is due May 7th.

# REQUIRED READING 

Please read sections 1-4 at http://www.cs.kent.edu/~ruttan/sysprog/lectures/multi-thread/multi-thread.html

Corrections to the reading above:
* Use `-pthread` as the compiler flag and not `-lpthread`. `-lpthread` is
  incorrect for modern compilers and may lead to subtle breakage or other
  failures.
* A mutex does not guarantee non-busy wait. It is possible for a mutex
  implementation to busy-wait. This can lead to interesting problems
  such as starvation.



# INSTRUCTIONS

Make a copy of this folder and modify the programs in this folder for homework.
You must make this copy in your home directory with the following command:
You can make a copy with:
cp -r /shared/homework/3 $HOME/homework/3

The source files themselves contain a description of the problem. There are
3 problems you must solve. One is inside hello, one is inside stack and another
is inside sum.
