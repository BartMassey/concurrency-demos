#!/usr/bin/python3
# Copyright © 2015 Bart Massey
# [This program is licensed under the "MIT License"]
# Please see the file COPYING in the source
# distribution of this software for license terms.

# Generate-and-test random prime numbers using a generator

# Generator
# Produces random numbers in the range 0..49.
# See http://www.ams.org/journals/mcom/1999-68-225/
#      S0025-5718-99-00996-5/S0025-5718-99-00996-5.pdf
def randint():
    s = 4000000
    while True:
        yield s % 50
        s = (s * 914334) % 4194301

# Tester
def is_prime(n):
    if n < 2:
        return False
    i = 2
    while i*i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

# Generate-and-test driver
def rand_primes():
    for pc in randint():
        if is_prime(pc):
            yield pc

# Run the whole system
ps = rand_primes()
for i in range(10):
    print(ps.__next__())
