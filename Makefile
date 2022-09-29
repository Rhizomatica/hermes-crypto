##
# HERMES cryptography
#
# @Makefile
# @version 0.1

CC=gcc
CFLAGS=-Wall -O3
LDFLAGS=-s

all: chacha20-test sha3-test hermes-crypto

chacha20.o: chacha20.c
	$(CC) $(CFLAGS) -o chacha20.o -c chacha20.c

chacha20-test.o: chacha20-test.c
	$(CC) $(CFLAGS) -o chacha20-test.o -c chacha20-test.c

chacha20-test: chacha20-test.o chacha20.o
	$(CC) -o chacha20-test chacha20-test.o chacha20.o $(LDFLAGS)


sha3.o: sha3.c
	$(CC) $(CFLAGS) -o sha3.o -c sha3.c

sha3-test.o: sha3-test.c
	$(CC) $(CFLAGS) -o sha3-test.o -c sha3-test.c

sha3-test: sha3-test.o sha3.o
	$(CC) -o sha3-test sha3-test.o sha3.o $(LDFLAGS)


hermes-crypto.o: hermes-crypto.c
	$(CC) $(CFLAGS) -o hermes-crypto.o -c hermes-crypto.c

hermes-crypto: hermes-crypto.o sha3.o chacha20.o
	$(CC) -o hermes-crypto hermes-crypto.o sha3.o chacha20.o $(LDFLAGS)

.PHONY: clean
clean:
	rm -f chacha20-test chacha20.o chacha20-test.o sha3-test sha3.o sha3-test.o hermes-crypto hermes-crypto.o
