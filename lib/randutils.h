#include <stdlib.h>
#include <time.h>

typedef void *jawn;

unsigned float roll();
// roll random float [0, 1]

bool check(unsigned float thresh);
// return true if you roll <= thresh
//@requires 0 <= thresh && thresh <= 1;


jawn choice(jawn* jawns, unsigned float *weights, unsigned int n);
// pick a jawn from the array of jawns, where the ith jawn, jawns[i]
// has a probability scaled by weights[i]
// n is the size of the array
//@requires n == len(jawns) && n == len(weights);
