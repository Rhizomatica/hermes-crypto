/* HERMES-crypto
 * Copyright (C) 2022 Rhizomatica
 * Author: Rafael Diniz <rafael@riseup.net>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 *
 * HERMES cryptography layer
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "sha3.h"
#include "chacha20.h"

// auxiliary functions
static void bin_to_hex(char *xp, const uint8_t *bb, int n)
{
    const char xx[]= "0123456789ABCDEF"; xp[n] = 0;
    while (--n >= 0) xp[n] = xx[(bb[n>>1] >> ((1 - (n&1)) << 2)) & 0xF];
}

static int hexdigit(char ch)
{
    if (ch >= '0' && ch <= '9') return  ch - '0';
    if (ch >= 'A' && ch <= 'F') return  ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f') return  ch - 'a' + 10;
    return -1;
}

static int hex_to_bin(uint8_t *buf, const char *str, int maxbytes)
{
    int i, h, l;

    for (i = 0; i < maxbytes; i++) {
        h = hexdigit(str[2 * i]);
        if (h < 0)
            return i;
        l = hexdigit(str[2 * i + 1]);
        if (l < 0)
            return i;
        buf[i] = (h << 4) + l;
    }

    return i;
}

// adopted key length for ChaCha20: 128bit (16 bytes)
int main(int argc, char *argv[])
{
  int chacha20_key_len = 16, sha_len = 16;

  uint8_t sha3_hash[sha_len];
  char chacha20_key_ascii[] = "358F336D03AE18F666C7573D55C4FD71"; // 128-bits
  uint8_t chacha20_key[chacha20_key_len];

  int msg_len = hex_to_bin(chacha20_key, chacha20_key_ascii, chacha20_key_len);
  assert(msg_len == chacha20_key_len);

  // we get a 16 bytes hash from the 16 bytes chacha20 key
  sha3(chacha20_key, chacha20_key_len, sha3_hash, sha_len);

  int sha3_ascii_len = 2 * sha_len + 1;
  char sha3_ascii[sha3_ascii_len];

  bin_to_hex(sha3_ascii, sha3_hash, sha_len * 2);

  printf("chacha20 key = %s\n", chacha20_key_ascii);
  printf("sha3 hash    = %s\n", sha3_ascii);

  return EXIT_SUCCESS;
}
