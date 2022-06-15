CC=gcc
OPTS=-g -Wall -pthread
BIN=./bin
MAIN=main.c
MKDIR=mkdir -p
RM=rm -rf
ifndef NTHRD
NTHRD:=2
endif
OPTS+=-D NTHRD=$(NTHRD)

all: mkdir none mutex atomic sloppy

mkdir:
	$(MKDIR) $(BIN)
 
none: none.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^

mutex: mutex.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^

atomic: atomic.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^

sloppy: sloppy.c $(MAIN)
	$(CC) $(OPTS) -o $(BIN)/$@ $^

clean:
	$(RM) $(BIN)
