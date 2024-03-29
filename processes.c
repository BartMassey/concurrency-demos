/*
 * Copyright © 2015 Bart Massey
 * [This program is licensed under the "MIT License"]
 * Please see the file COPYING in the source
 * distribution of this software for license terms.
 */

/* Generate-and-test concurrency via processes */

#include <assert.h>
#ifndef __USE_POSIX
#define __USE_POSIX
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

FILE *pf;

/* Generator
   Produces random numbers in the range 0..49.
   See http://www.ams.org/journals/mcom/1999-68-225/
        S0025-5718-99-00996-5/S0025-5718-99-00996-5.pdf */
uint64_t s = 4000000;
void randint(void) {
    while (1) {
        fprintf(pf, "%d\n", (int) (s % 50));
        s = (s * 914334LL) % 4194301LL;
    }
}

/* Tester */
int is_prime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

/* Generate-and-test driver */
int next_rand_prime(void) {
    while (1) {
        int pc;
        assert(fscanf(pf, "%d\n", &pc) == 1);
        if (is_prime(pc))
            return pc;
    }
}

int main(void) {
    /* Set up the processes */
    int pipefd[2];
    assert(pipe(pipefd) != -1);
    int pid = fork();
    assert(pid != -1);

    /* If child, run the generator */
    if (pid == 0) {
        pf = fdopen(pipefd[1], "w");
        assert(pf);
        randint();
        assert(0);
    }

    /* Run the tester */
    pf = fdopen(pipefd[0], "r");
    assert(pf);
    for (int i = 0; i < 10; i++)
        printf("%d\n", next_rand_prime()); 
    exit(0);
}
