#include "bitwise.h"

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

uint8_t is_power_of_two(uint n) {}
uint unique(uint *nums) {}
void swap(int *a, int *b) {}
int reverse(int n) {}
int highest_bit(int n) {}
int lowest_bit(int n) {}
uint popcount_bkt(uint n) {}
uint next_pw_2(int n) {}

int set_bitset(int bs, int pos) {}
int clear_bitset(int bs, int pos) {}
int test_bitset(int bs, int pos) {}

uint *two_unique(int *nums) {}
