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
int reverse(int n);
int highest_bit(int n);
int lowest_bit(int n);
uint popcount_bkt(uint n);
uint next_pw_2(int n);

int set_bitset(int bs, int pos);
int clear_bitset(int bs, int pos);
int test_bitset(int bs, int pos);

uint *two_unique(int *nums);

#endif // BITWISE_H!
