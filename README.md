# hermes-crypto

This project contains the security layer of the HERMES stack.

This is a work in progress.

Proposal:  Each HERMES station contains a 256 bit ChaCha20 key. The authentication
hand-shake involves a comparisson between the SHA-3 hash of ChaCha20 key.

# What is here

## ChaCha20

ChaCha20 is a stream cipher created by Daniel Bernstein (http://cr.yp.to/chacha.html).
The implementation presented in this repository focuses on simplicity and correctness.
Tests are included in chacha20-test. Source
code from:  http://chacha20.insanecoding.org/

## SHA-3

SHA-3 is a subset of the broader cryptographic primitive family Keccak, designed by Guido Bertoni, Joan Daemen, Michaël Peeters, and Gilles Van Assche, building upon RadioGatún.
The implementation presented in this repository focuses on size and readability of the FIPS 202 and SHA3 hash function. Tests are included in sha3-test. Source code from:
https://github.com/mjosaarinen/tiny_sha3

