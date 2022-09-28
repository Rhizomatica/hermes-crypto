##
# HERMES cryptography
#
# @Makefile
# @version 0.1

CC=gcc
CFLAGS=-Wall -O3 -I.
LDFLAGS=-s

all: chacha20_simple-test

chacha20_simple.o: chacha20_simple.c
	$(CC) $(CFLAGS) -o chacha20_simple.o -c chacha20_simple.c

chacha20_simple-test.o: chacha20_simple-test.c
	$(CC) $(CFLAGS) -o chacha20_simple-test.o -c chacha20_simple-test.c

chacha20_simple-test: chacha20_simple-test.o chacha20_simple.o
	$(CC) -o chacha20_simple-test chacha20_simple-test.o chacha20_simple.o $(LDFLAGS)

.PHONY: clean
clean:
	rm -f chacha20_simple-test chacha20_simple.o chacha20_simple-test.o
