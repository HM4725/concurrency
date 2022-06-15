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
## 1. Analysis: None
### Number of threads
`2`
### Result
```
Result : 69653626
Expect : 100000000
Time   : 0.863792s
```
### Correctness
☆☆☆☆☆
### Performance
★★★★★

## 2. Analysis: Mutex
### Number of threads
`2`
### Result
```
Result : 100000000
Expect : 100000000
Time   : 27.735758s
```
### Correctness
★★★★★
### Performance
☆☆☆☆☆

## 3. Analysis: Atomic
### Number of threads
`2`
### Result
```
Result : 100000000
Expect : 100000000
Time   : 1.520604s
```
### Correctness
★★★★★
### Performance
★★★★☆

## 4. Analysis: Sloopy
### Number of threads
`2`
### Result
```
Result : 100000000
Expect : 100000000
Time   : 5.860536s
```
### Correctness
★★★★★
### Performance
★★★☆☆
