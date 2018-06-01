#include <randutils.h>

unsigned float roll() {
    unsigned int r = rand();
    return (unsigned float)((unsigned double r)/(unsigned double)RAND_MAX);
}

bool check(unsigned float thresh) {
    return roll() <= thresh;
}

jawn choice(jawn* jawns, unsigned float *weights, unsigned int n) {
    unsigned float sum_weights = 0;
    for (int i = 0; i < n; i++) {
        sum_weights += weights[i];
    }
    // roll, then check every weight until you find which bucket
    // the roll fell in
    unsigned float r = roll();
    unsigned float sweeper = 0;
    for (int i = 0; i < n; i++) {
        sweeper += weights[i]/sum_weights;
        if (r <= sweeper) return jawns[i];
    }
    return jawns[n-1]; // if it gets here, float precision => sweeper !=  1
}
