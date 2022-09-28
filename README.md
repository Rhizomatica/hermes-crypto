# hermes-crypto

This project contains the security layer of the HERMES stack.

This is a work in progress.

Proposal:  Each HERMES station contains a 128 bit AES-128 key, which is know to the gateway station... TODO

SHA-3 for HMAC?

# What is here

## ChaCha20

ChaCha20 is a stream cipher created by Daniel Bernstein (http://cr.yp.to/chacha.html).
The implementation presented in this repository focuses on simplicity and correctness.
Test vectors with a battery of unit tests are included in chacha20_simple-test. Source
code from:  http://chacha20.insanecoding.org/
