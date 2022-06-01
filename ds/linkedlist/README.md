# Singly linked list
## Models
### No-lock
- code: none.c
- note: It doesn't guarantee the atomicity.

### Mutex
- code: mutex.c
- note: It uses a mutex to guarantee the atomicity.

### Lock-free
- code: lockfree.c
- note: It uses the atomic instructions.

## Performance
### Environment
```
Cloud Environment: Google Cloud Platform
Machine Type     : e2-medium (2 vCPUs)
Virtualization   : kvm
Operating System : Ubuntu 18.04.6 LTS
Kernel           : Linux 5.4.0-1069-gcp
Architecture     : x86-64
```

### Program
Enqueue a node to the shared list (tail) multiple times.
Dequeue the head from the shared list multiple times.

### How to run
```
run.sh 1
run.sh 2
run.sh 4
```
### Result
#### No-lock model
```
#Threads: 1
  - Correctness
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance
      time (real): 5.876s
#Threads: 2
  - Correctness: bad
      gcnt after enq: 49795718
      gcnt after deq: 49792236
  - Performance: good
      time (real): 2.775s
#Threads: 4
  - Correctness: bad
      gcnt after enq: 49651438
      gcnt after deq: 49650326
  - Performance: good
      time (real): 2.821s
```

#### Mutex model
```
#Threads: 1
  - Correctness
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance
      time (real): 8.913s
#Threads: 2
  - Correctness: good
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance: bad
      time (real): 27.071s
#Threads: 4
  - Correctness: good
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance: bad
      time (real): 26.551s
```

#### Free-lock model
```
#Threads: 1
  - Correctness
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance
      time (real): 6.595s
#Threads: 2
  - Correctness: good
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance: good
      time (real): 5.031s
#Threads: 4
  - Correctness: good
      gcnt after enq: 50000000
      gcnt after deq: 0
  - Performance: good
      time (real): 5.071s
```
