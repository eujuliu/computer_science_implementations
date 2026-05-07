#include "../unity/src/unity.h"
#include "array.h"
#include <stdio.h>

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

void test_array_set() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  set(arr, 0, 50);
  set(arr, 1, 40);
  set(arr, 2, 30);
  set(arr, 3, 20);
  set(arr, 4, 10);

  TEST_ASSERT_EQUAL_INT(50, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(10, at(arr, 4));
}

void test_array_push() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  push(arr, 60);

  TEST_ASSERT_EQUAL_INT(60, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(-1, at(arr, 6));

  TEST_ASSERT_EQUAL_INT(6, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);
}

void test_array_insert() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  insert(arr, 1, 15);

  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(15, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(6, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);
}

void test_array_insert_capacity_grow() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  insert(arr, 1, 15);
  insert(arr, 2, 16);
  insert(arr, 3, 17);
  insert(arr, 4, 18);

  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(15, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(16, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(17, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(18, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 6));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 7));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 8));
  TEST_ASSERT_EQUAL_INT(9, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);
}

void test_array_prepend() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(5, arr->size);

  prepend(arr, 9);

  TEST_ASSERT_EQUAL_INT(9, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(10, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(6, arr->size);
}

void test_array_prepend_capacity_grow() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  prepend(arr, 9);
  prepend(arr, 8);
  prepend(arr, 7);

  TEST_ASSERT_EQUAL_INT(7, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(8, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(10, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 6));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 7));

  TEST_ASSERT_EQUAL_INT(8, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);
}

void test_array_pop() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  pop(arr);

  TEST_ASSERT_EQUAL_INT(4, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  TEST_ASSERT_EQUAL_INT(40, at(arr, -1));
}

void test_array_pop_capacity_shrink() {
  prepend(arr, 9);
  prepend(arr, 8);
  prepend(arr, 7);

  TEST_ASSERT_EQUAL_INT(7, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(8, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(10, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 6));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 7));

  TEST_ASSERT_EQUAL_INT(8, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);

  pop(arr);
  pop(arr);
  pop(arr);
  pop(arr);

  TEST_ASSERT_EQUAL_INT(4, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  TEST_ASSERT_EQUAL_INT(10, at(arr, -1));
}

void test_array_pop_capacity_shrink_not_less_than_initial() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  pop(arr);
  pop(arr);
  pop(arr);
  pop(arr);
  pop(arr);

  TEST_ASSERT_EQUAL_INT(0, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  TEST_ASSERT_EQUAL_INT(-1, at(arr, -1));
}

void test_array_delete() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  delete_item(arr, 2);

  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 3));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(4, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);
}

void test_array_delete_capacity_shrink() {
  prepend(arr, 9);
  prepend(arr, 8);
  prepend(arr, 7);

  TEST_ASSERT_EQUAL_INT(7, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(8, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(10, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 6));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 7));

  TEST_ASSERT_EQUAL_INT(8, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);

  delete_item(arr, 0);
  delete_item(arr, 0);
  delete_item(arr, 0);
  delete_item(arr, 0);

  TEST_ASSERT_EQUAL_INT(4, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  TEST_ASSERT_EQUAL_INT(20, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 3));
}

void test_array_delete_last() {
  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 5));

  TEST_ASSERT_EQUAL_INT(5, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);

  delete_item(arr, -1);

  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(4, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);
}

void test_array_remove() {
  prepend(arr, 9);
  prepend(arr, 8);

  prepend(arr, 9);
  prepend(arr, 8);

  push(arr, 8);
  push(arr, 9);

  push(arr, 8);
  push(arr, 9);

  TEST_ASSERT_EQUAL_INT(8, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 1));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 3));

  TEST_ASSERT_EQUAL_INT(10, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 6));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 7));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 8));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 9));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 10));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 11));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 12));

  TEST_ASSERT_EQUAL_INT(13, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);

  remove_item(arr, 9);

  TEST_ASSERT_EQUAL_INT(8, at(arr, 0));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 1));

  TEST_ASSERT_EQUAL_INT(10, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 3));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 6));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 7));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 8));

  TEST_ASSERT_EQUAL_INT(9, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);
}

void test_array_remove_capacity_shrink() {
  prepend(arr, 9);
  prepend(arr, 8);

  prepend(arr, 9);
  prepend(arr, 8);

  push(arr, 8);
  push(arr, 9);

  push(arr, 8);
  push(arr, 9);

  TEST_ASSERT_EQUAL_INT(8, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 1));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 3));

  TEST_ASSERT_EQUAL_INT(10, at(arr, 4));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 5));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 6));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 7));
  TEST_ASSERT_EQUAL_INT(50, at(arr, 8));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 9));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 10));

  TEST_ASSERT_EQUAL_INT(8, at(arr, 11));
  TEST_ASSERT_EQUAL_INT(9, at(arr, 12));

  TEST_ASSERT_EQUAL_INT(13, arr->size);
  TEST_ASSERT_EQUAL_INT(16, arr->capacity);

  remove_item(arr, 9);
  remove_item(arr, 8);
  remove_item(arr, 50);

  TEST_ASSERT_EQUAL_INT(10, at(arr, 0));
  TEST_ASSERT_EQUAL_INT(20, at(arr, 1));
  TEST_ASSERT_EQUAL_INT(30, at(arr, 2));
  TEST_ASSERT_EQUAL_INT(40, at(arr, 3));

  TEST_ASSERT_EQUAL_INT(-1, at(arr, 4));

  TEST_ASSERT_EQUAL_INT(4, arr->size);
  TEST_ASSERT_EQUAL_INT(8, arr->capacity);
}

void test_array_find() {
  TEST_ASSERT_EQUAL_INT(0, find(arr, 10));
  TEST_ASSERT_EQUAL_INT(1, find(arr, 20));
  TEST_ASSERT_EQUAL_INT(2, find(arr, 30));
  TEST_ASSERT_EQUAL_INT(3, find(arr, 40));
  TEST_ASSERT_EQUAL_INT(4, find(arr, 50));
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
  RUN_TEST(test_array_set);
  RUN_TEST(test_array_push);
  RUN_TEST(test_array_insert);
  RUN_TEST(test_array_insert_capacity_grow);
  RUN_TEST(test_array_prepend);
  RUN_TEST(test_array_prepend_capacity_grow);
  RUN_TEST(test_array_pop);
  RUN_TEST(test_array_pop_capacity_shrink);
  RUN_TEST(test_array_pop_capacity_shrink_not_less_than_initial);
  RUN_TEST(test_array_delete);
  RUN_TEST(test_array_delete_capacity_shrink);
  RUN_TEST(test_array_delete_last);
  RUN_TEST(test_array_remove);
  RUN_TEST(test_array_remove_capacity_shrink);
  RUN_TEST(test_array_find);

  UNITY_END();

  return 0;
}
