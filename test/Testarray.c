#include "../unity/src/unity.h"
#include "array.h"

Array *arr;

void test_new_array() {
  int data[] = {50, 40, 30, 20, 10};
  int size = 5;

  free_array(arr);

  arr = new_array(data, size);

  for (int i = 0; i < size; i++) {
    TEST_ASSERT_EQUAL_INT(data[i], *(arr->data + i));
  }

  TEST_ASSERT_EQUAL_INT(size, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);
}

void test_array_is_empty() {
  TEST_ASSERT_EQUAL_INT(0, is_empty(arr));

  free_array(arr);

  int data[0];

  arr = new_array(data, 0);

  TEST_ASSERT_EQUAL_INT(1, is_empty(arr));
}

void test_array_at() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));
}

void setUp() {
  int data[] = {10, 20, 30, 40, 50};

  arr = new_array(data, 5);
}

void tearDown() { free_array(arr); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_new_array);
  RUN_TEST(test_array_is_empty);
  RUN_TEST(test_array_at);

  UNITY_END();

  return 0;
}
