CC=gcc
OPTS=-g -Wall -pthread
BIN=./bin
MAIN=main.c

all: none mutex atomic
 
none: none.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^

mutex: mutex.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^

atomic: atomic.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^
