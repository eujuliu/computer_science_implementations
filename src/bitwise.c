#include "bitwise.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

uint8_t is_even(int n) {
  if ((n & 1) == 0) {
    return 1;
  }
  return 0;
}

int mul2(int n) { return n << 1; }

int div2(int n) { return n >> 1; }

int get_bit(int n, int pos) { return (n & (1 << pos)) >> pos; }

int set_bit(int n, int pos) { return n | (1 << pos); }

uint8_t clear_bit(int n, int pos) {
  uint mask = ~(1 << pos);
  return n & mask;
}

uint8_t popcount(uint n) {
  uint8_t count = 0;
  while (n) {
    count += (n & 1);
    n >>= 1;
  }
  return count;
}

uint8_t is_power_of_two(uint n) { return (n & (n - 1)) == 0; }

uint unique(uint *nums, size_t len) {
  // What happens if I do (3 ? 7) ? 3 (change ? By &, |, or ^)
  // Then, do the same with (3 ? 3) ? 7, same result? The order matters?
  // What happens if I have tripled numbers? Like 3, 3, 3, 4, 4, 7

  uint acc = 0;
  for (int i = 0; i < len; i++) {
    acc ^= nums[i];
  }

  return acc;
}

void swap(int *a, int *b) {
  // Change ? to some of the operators (&, |, ^)
  // Try (a ? b), then (result ? a), then (result ? b)
  // This is better than using tmp variable?

  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

uint8_t reverse(uint8_t n) {
  // You need to mirror (00001110 = 01110000)
  // Try with 8 bits only
  // Similar logic at get_bit and set_bit
  // If bit 7 is set then bit ? is set

  // uint8_t result = 0;
  // uint8_t l = (sizeof(n) * CHAR_BIT) - 1;
  // for (uint8_t r = 0; l >= r; r++) {
  //   if ((n >> r) & 1) {
  //     result |= (1 << l);
  //   }
  //   if ((n >> l) & 1) {
  //     result |= (1 << r);
  //   }
  //   l--;
  // }
  // return result;

  if (!n) {
    return n;
  }

  uint8_t result = 0;
  uint8_t len = (sizeof(n) * CHAR_BIT) - 1;
  for (int l = len; l >= 0; l--) {
    result |= (((n >> l) & 1) << (len - l));
  }
  return result;
}

uint highest_bit(uint n) {
  // What is the highest (left most?)
  // Which power of two fits inside the number?
  // How many bits are necessary to store 44? 101100? 6?
  // If instead of 44 (101100) I have 63 (111111)?

  n |= (n >> 1);
  n |= (n >> 2);
  n |= (n >> 4);
  n |= (n >> 8);
  n |= (n >> 16);

  return n - (n >> 1);
}

uint8_t lowest_bit(uint n) {
  //   44  &  43   =   40 what disappeared?
  // 101100 101011 = 101000

  return n ^ (n & n - 1);
}

uint popcount_bkt(uint n) {
  // 44 & 43, how many set bits disappeared?
  // then 43 & 42, how many now?

  uint count = 0;
  while (n) {
    count += 1;
    n &= n - 1;
  }
  return count;
}

uint next_pw_2(int n) {
  n |= (n >> 1);
  n |= (n >> 2);
  n |= (n >> 4);
  n |= (n >> 8);
  n |= (n >> 16);

  return (n - (n >> 1)) << 1;
}

uint *two_unique(uint nums[], size_t len) {}
