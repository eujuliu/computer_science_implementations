#include "../unity/src/unity.h"
#include "bitwise.h"

void test_should_return_even() {
  int even = is_even(2);
  TEST_ASSERT_EQUAL_INT(1, even);
}

void test_should_return_odd() {
  int even = is_even(5);
  TEST_ASSERT_EQUAL_INT(0, even);
}

void test_should_be_mutiple_of_2() {
  uint8_t is_multiply = mul2(12);

  TEST_ASSERT_EQUAL_UINT8(1, is_multiply);
}

void test_should_not_be_mutiple_of_2() {
  uint8_t is_multiply = mul2(11);

  TEST_ASSERT_EQUAL_UINT8(1, is_multiply);
}

void test_should_be_divisible_by_2() {
  uint8_t is_divisible = div2(12);

  TEST_ASSERT_EQUAL_UINT8(1, is_divisible);
}

void test_should_not_be_divisible_by_2() {
  uint8_t is_divisible = div2(11);

  TEST_ASSERT_EQUAL_UINT8(1, is_divisible);
}

void setUp() {}

void tearDown() {}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_should_return_even);
  RUN_TEST(test_should_return_odd);
  // RUN_TEST(test_should_be_mutiple_of_2);
  // RUN_TEST(test_should_not_be_mutiple_of_2);
  // RUN_TEST(test_should_be_divisible_by_2);
  // RUN_TEST(test_should_not_be_divisible_by_2);

  UNITY_END();

  return 0;
}
