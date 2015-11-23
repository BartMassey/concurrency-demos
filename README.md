# Concurrency Demos
Copyright (c) 2015 Bart Massey

These toy programs were written for a two-hour lecture on
concurrency in an introductory software engineering course.
They are not particularly exemplary, but they are at least
examples.

The demos are built around a generate-and-test framework
for printing pseudorandom primes. Each demo prints 10
pseudorandom primes by concurrently generating pseudorandom
numbers using a supplied generator and testing those
pseudorandom numbers for primality using trial
division. Because the generator generates the same
pseudorandom numbers in the same order, independent of
implementation language and run, all demos should output
the same sequence of primes.

* `callbacks.5c`: Demonstrates concurrency using callbacks in
  [Nickle](http://nickle.org).

* `generators.py`: Demonstrates concurrency using generators
  in Python 3.

* `mut.5c`: Demonstrates concurrency and mutexes in Nickle.
  This does not follow the given example problem, since
  mutexes can't easily be used to block in such a way that
  races are avoided.

* `threads.5c`: Demonstrates concurrency using threads and
  mailboxes in Nickle.

  * `sem.5c`: Nickle semaphore demo code.

  * `mailbox.5c`: Nickle implementation of "mailbox
    variables" for thread synchronization and communication.
    This will be upstreamed into Nickle soon.

* `processes.c`: Demonstrates concurrency using processes
  and pipes in C.

This work is licensed under the "MIT License".  Please see
the file COPYING in the source distribution of this work for
license terms.
