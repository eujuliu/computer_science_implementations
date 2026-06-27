#include "../unity/src/unity.h"
#include "bitwise.h"
#include <stdint.h>

void test_should_return_even() {
  int even = is_even(2);
  TEST_ASSERT_EQUAL_INT(1, even);
}

void test_should_return_odd() {
  int even = is_even(5);
  TEST_ASSERT_EQUAL_INT(0, even);
}

void test_should_multiply_by_2() {
  int result = mul2(5);

  TEST_ASSERT_EQUAL_INT(10, result);
}

void test_should_not_multiply_by_2_cause_is_0() {
  int result = mul2(0);

  TEST_ASSERT_EQUAL_INT(0, result);
}

void test_should_divide_by_2() {
  int result = div2(16);

  TEST_ASSERT_EQUAL_INT(8, result);
}

void test_should_not_divide_by_2_cause_is_0() {
  int result = div2(0);

  TEST_ASSERT_EQUAL_INT(0, result);
}

void test_should_get_bit() {
  int result = get_bit(14, 2);
  int result1 = get_bit(14, 0);

  TEST_ASSERT_EQUAL_INT(1, result);
  TEST_ASSERT_EQUAL_INT(0, result1);
}

void test_should_set_bit() {
  int result = set_bit(14, 4);
  int result1 = set_bit(14, 0);

  TEST_ASSERT_EQUAL_INT(30, result);
  TEST_ASSERT_EQUAL_INT(15, result1);
}

void test_should_clear_bit() {
  int result = clear_bit(14, 2);
  int result1 = clear_bit(14, 0);

  TEST_ASSERT_EQUAL_INT(10, result);
  TEST_ASSERT_EQUAL_INT(14, result1);
}

void test_should_count() {
  int result = popcount(14);
  int result1 = popcount(30);

  TEST_ASSERT_EQUAL_INT(3, result);
  TEST_ASSERT_EQUAL_INT(4, result1);
}

void test_should_be_power_of_two() {
  int result = is_power_of_two(0);
  int result1 = is_power_of_two(1);
  int result2 = is_power_of_two(2);
  int result3 = is_power_of_two(4);
  int result4 = is_power_of_two(8);
  int result5 = is_power_of_two(10);
  int result6 = is_power_of_two(11);

  TEST_ASSERT_EQUAL_INT(1, result);
  TEST_ASSERT_EQUAL_INT(1, result1);
  TEST_ASSERT_EQUAL_INT(1, result2);
  TEST_ASSERT_EQUAL_INT(1, result3);
  TEST_ASSERT_EQUAL_INT(1, result4);
  TEST_ASSERT_EQUAL_INT(0, result5);
  TEST_ASSERT_EQUAL_INT(0, result6);
}

void test_should_find_unique_int() {
  uint nums[] = {5, 1, 1, 3, 4, 3, 5};
  size_t len = sizeof(nums) / sizeof(nums[0]);
  uint num = unique(nums, len);

  TEST_ASSERT_EQUAL_UINT(4, num);
}

void test_should_not_find_unique_int() {
  uint nums[] = {4, 1, 3, 1, 3, 4, 5, 5};
  size_t len = sizeof(nums) / sizeof(nums[0]);

  uint num = unique(nums, len);

  TEST_ASSERT_EQUAL_UINT(0, num);
}

void test_should_not_find_unique_cause_is_empty() {
  uint nums[] = {};
  size_t len = sizeof(nums) / sizeof(nums[0]);

  uint num = unique(nums, len);

  TEST_ASSERT_EQUAL_UINT(0, num);
}

void test_should_swap_values() {
  int a = 5;
  int b = 9;
  swap(&a, &b);

  TEST_ASSERT_EQUAL_INT(b, 5);
  TEST_ASSERT_EQUAL_INT(a, 9);
}

void setUp() {}

void tearDown() {}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_should_return_even);
  RUN_TEST(test_should_return_odd);
  RUN_TEST(test_should_multiply_by_2);
  RUN_TEST(test_should_not_multiply_by_2_cause_is_0);
  RUN_TEST(test_should_divide_by_2);
  RUN_TEST(test_should_not_divide_by_2_cause_is_0);
  RUN_TEST(test_should_get_bit);
  RUN_TEST(test_should_set_bit);
  RUN_TEST(test_should_clear_bit);
  RUN_TEST(test_should_count);
  RUN_TEST(test_should_be_power_of_two);
  RUN_TEST(test_should_find_unique_int);
  RUN_TEST(test_should_not_find_unique_int);
  RUN_TEST(test_should_not_find_unique_cause_is_empty);
  RUN_TEST(test_should_swap_values);

  UNITY_END();

  return 0;
}
