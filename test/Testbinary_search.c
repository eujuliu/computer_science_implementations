#include "../unity/src/unity.h"
#include "binary_search.h"

int arr[] = {1, 4, 5, 7, 9, 12, 15, 18, 19, 22, 25, 29, 40, 50};
size_t len = ARRAY_SIZE(arr);

void test_should_get_target() {
  int index = binary_search(arr, len, 12);

  TEST_ASSERT_EQUAL_INT(5, index);
}

void test_should_get_target_with_recursion() {
  int index = binary_search_recursion(arr, 12, 0, len - 1);

  TEST_ASSERT_EQUAL_INT(5, index);
}

void test_should_not_get_target() {
  int index = binary_search(arr, len, 13);

  TEST_ASSERT_EQUAL_INT(-1, index);
}

void test_should_not_get_target_with_recursion() {
  int index = binary_search_recursion(arr, 13, 0, len - 1);

  TEST_ASSERT_EQUAL_INT(-1, index);
}

void setUp() {}

void tearDown() {}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_should_get_target);
  RUN_TEST(test_should_get_target_with_recursion);
  RUN_TEST(test_should_not_get_target);
  RUN_TEST(test_should_not_get_target_with_recursion);

  UNITY_END();

  return 0;
}
