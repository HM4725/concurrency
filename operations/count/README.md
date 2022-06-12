# How To Build
```
make all
```

# How To Run
```
time ./bin/none
time ./bin/mutex
time ./bin/atmoic
```

# Evaluation
## None
### Result
```
Expect: 100000000
Result: 66873597
Correct: no
./none  0.79s user 0.04s system 196% cpu 0.423 total
```
### Correctness
bad
### Performance
good

## Mutex
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
bad

## Atomic
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
good
