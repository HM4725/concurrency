# Count up
## Models
### 1. None
- code: none.c
- note: It doesn't guarantee the atomicity.
### 2. Mutex
- code: mutex.c
- note: It uses a mutex for the atomicity.
### 3. Atmoic
- code: atomic.c
- note: It uses the atomic instructions.
### 4. Sloppy
- code: sloppy.c
- note: It is the sloppy counter.

# Evaluation
## Environment
```
Cloud Environment: Google Cloud Platform
Machine Type     : e2-medium (2 vCPUs)
Virtualization   : kvm
Operating System : Ubuntu 18.04.6 LTS
Kernel           : Linux 5.4.0-1069-gcp
Architecture     : x86-64
```
## How To Build
```
make NTHRD={# of threads}
```
## How To Run
```
./bin/none
./bin/mutex
./bin/atomic
./bin/sloppy
```
## Analysis: None
### Number of threads
`2`
### Result
```
Expect : 100000000
Result : 69529088
Correct: no
Time   : 0.862253s
```
### Correctness
☆☆☆☆☆
### Performance
★★★★★

## Analysis: Mutex
### Number of threads
`2`
### Result
```
Expect : 100000000
Result : 100000000
Correct: yes
Time   : 27.242784s
```
### Correctness
★★★★★
### Performance
☆☆☆☆☆

## Analysis: Atomic
### Number of threads
`2`
### Result
```
Expect : 100000000
Result : 100000000
Correct: yes
Time   : 1.526992s
```
### Correctness
★★★★★
### Performance
★★★★☆

## Analysis: Sloopy
### Number of threads
`2`
### Result
```
Expect : 100000000
Result : 100000000
Correct: yes
Time   : 5.779796s
```
### Correctness
★★★★★
### Performance
★★★☆☆
