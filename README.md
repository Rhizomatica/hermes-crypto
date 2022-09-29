# hermes-crypto

This project contains the security layer of the HERMES stack.

This is a work in progress.


# Proposal 1

Uses ChaCha20 and SHA-3. Robust to replay attack.

Total T/R switches: 3
Total payload in success: 32 + 35 + 19 + 3: 89 bytes 

Proposal Each HERMES remove station contains a 128-bit key. All keys of the remote stations are available in the gateway. The authentication
hand-shake involves SHA-3, ChaCha20 and the creation of a session key (SK).



STEP 1. Agent 1 sends (32 bytes):
16-bytes own ChaCha20 SHA3 Hash + 16-bytes Random Number Session Key (SK1)

STEP 2. Agent 2 responds (4 or 35 bytes):
NACK if ChaCha20 SHA3 Hash does not match an authorized host
ACK if ChaCha20 SHA3 Hash matches an authorized host + 16-bytes of the encrypted SK1 with the Agent 1 ChaCha20 key + 16-bytes Random Number (SK2)

STEP 3. Agent 1 decrypt SK1 and compares to SK1 in memory - authenticates Agent 2 and responds (4 or 19 bytes):
NACK if authentication failed
ACK if authentication is ok + 16-bytes of the encrypted SK2 with Agent 1 ChaCha2 key

STEP 4. Agent 2 decripts SK2 and compares to SK2 in memory - authenticates Agent 1 and responds (4 or 3 bytes):
NACK if authentication failed
ACK

The 256-bit ChaCha20 key SK = SK1 + SK2

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

