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
`TODO`

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
make all
```
## How To Run
```
time ./bin/none
time ./bin/mutex
time ./bin/atmoic
```
## Analysis: None
```
Expect: 100000000
Result: 66873597
Correct: no
./none  0.79s user 0.04s system 196% cpu 0.423 total
```
### Correctness
bad
### Performance
good (0.79s)

## Analysis: Mutex
### Result
```
Expect: 100000000
Result: 100000000
Correct: yes
./mutex  21.49s user 11.93s system 199% cpu 16.753 total
```
### Correctness
good
### Performance
bad (21.49s)

## Analysis: Atomic
### Result
```
Expect: 100000000
Result: 100000000
Correct: yes
./atomic  1.44s user 0.08s system 198% cpu 0.769 total
```
### Correctness
good
### Performance
good (1.44s)
