#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>
#include <sys/types.h>

uint8_t is_even(int n);
int mul2(int n);
int div2(int n);

int get_bit(int n, int pos);
int set_bit(int n, int pos);
uint8_t clear_bit(int n, int pos);

uint8_t popcount(uint n);
uint8_t is_power_of_two(uint n);

uint unique(uint *nums, size_t len);
void swap(int *a, int *b);
uint8_t reverse(uint8_t n);
uint highest_bit(uint n);
uint8_t lowest_bit(uint n);
uint popcount_bkt(uint n);
uint next_pw_2(int n);

int set_bitset(int bs, int pos);
int clear_bitset(int bs, int pos);
int test_bitset(int bs, int pos);

uint *two_unique(int *nums);

uint32_t rol(uint32_t n, int k); // rotate left
uint32_t ror(uint32_t n, int k); // rotate right
uint8_t parity(
    uint32_t n); // Returns whether there are an odd or even number of set bits.
uint8_t ctz(uint32_t n); // Count Trailing Zeros
uint8_t clz(uint32_t n); // Count Leading Zeros
uint32_t next_same_popcount(uint32_t n);

#endif // BITWISE_H!
