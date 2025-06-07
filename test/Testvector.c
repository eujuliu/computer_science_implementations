#include "../src/vector.h"
#include "../unity/src/unity.h"
#include <stdlib.h>

Vector vector;

void test_at() {
  int output1 = at(&vector, 2);

  for (int i = 0; i < vector.capacity; i++) {
    vector.data[i] = i + 1;
    vector.size++;
  }

  int output2 = at(&vector, vector.capacity / 2 - 1);
  int output3 = at(&vector, -2);

  TEST_ASSERT_EQUAL_INT(-1, output1);
  TEST_ASSERT_EQUAL_INT(8, output2);
  TEST_ASSERT_EQUAL_INT(15, output3);
}

void test_push() {
  TEST_ASSERT_EQUAL_INT(0, vector.size);

  int output1 = push(&vector, 1);
  int output2 = push(&vector, 2);
  int output3 = push(&vector, 3);
  int output4 = push(&vector, 4);
  int outputs[] = {output1, output2, output3, output4};

  TEST_ASSERT_EQUAL_INT(4, vector.size);

  for (int i = 0; i < vector.size; i++) {
    TEST_ASSERT_EQUAL_INT(i + 1, outputs[i]);
    TEST_ASSERT_EQUAL_INT(i + 1, vector.data[i]);
  }
}

void test_pop() {
  int push_outputs[4];

  for (int i = 0; i < 4; i++) {
    push_outputs[i] = push(&vector, i + 1);
  }

  int output1 = pop(&vector);
  int output2 = pop(&vector);
  int output3 = pop(&vector);
  int output4 = pop(&vector);

  TEST_ASSERT_EQUAL_INT(0, vector.size);

  for (int i = 0; i < 4; i++) {
    TEST_ASSERT_EQUAL_INT(0, vector.data[i]);
  }
}

void test_resize() {
  TEST_ASSERT_EQUAL_INT(0, vector.size);
  TEST_ASSERT_EQUAL_INT(16, vector.capacity);

  for (int i = 0; i < vector.capacity - 1; i++) {
    push(&vector, i + 1);
  }

  push(&vector, 16);

  TEST_ASSERT_EQUAL_INT(16, vector.size);
  TEST_ASSERT_EQUAL_INT(32, vector.capacity);
}

void test_insert() {
  for (int i = 0; i < 6; i++) {
    push(&vector, i + 1);
  }

  int output1 = insert(&vector, 4, 8);
  int output2 = insert(&vector, -1, 10);
  int output3 = insert(&vector, 20, 10);
  int output4 = insert(&vector, 6, 23);

  TEST_ASSERT_EQUAL_INT(8, output1);
  TEST_ASSERT_EQUAL_INT(-1, output2);
  TEST_ASSERT_EQUAL_INT(-1, output3);
  TEST_ASSERT_EQUAL_INT(23, output4);
  TEST_ASSERT_EQUAL_INT(4, vector.data[3]);
  TEST_ASSERT_EQUAL_INT(8, vector.data[4]);
  TEST_ASSERT_EQUAL_INT(5, vector.data[5]);
  TEST_ASSERT_EQUAL_INT(23, vector.data[6]);
  TEST_ASSERT_EQUAL_INT(6, vector.data[7]);
  TEST_ASSERT_EQUAL_INT(8, vector.size);
  TEST_ASSERT_EQUAL_INT(16, vector.capacity);
}

void test_prepend() {
  for (int i = 0; i < 6; i++) {
    push(&vector, i + 1);
  }

  int output1 = prepend(&vector, 12);

  TEST_ASSERT_EQUAL_INT(12, output1);
  TEST_ASSERT_EQUAL_INT(12, *(vector.data));
  TEST_ASSERT_EQUAL_INT(7, vector.size);
  TEST_ASSERT_EQUAL_INT(16, vector.capacity);

  for (int i = 1; i < 7; i++) {
    TEST_ASSERT_EQUAL_INT(i, *(vector.data + i));
  }
}

void test_delete_it() {
  for (int i = 0; i < 6; i++) {
    push(&vector, i + 1);
  }

  int output1 = delete_it(&vector, 0);

  TEST_ASSERT_EQUAL_INT(1, output1);

  for (int i = 0; i < vector.size; i++) {
    TEST_ASSERT_EQUAL_INT(i + 2, vector.data[i]);
  }

  int output2 = delete_it(&vector, 4);

  TEST_ASSERT_EQUAL_INT(6, output2);
  TEST_ASSERT_EQUAL_INT(4, vector.size);
}

void test_remove_it() {
  int length = 10;
  int items[] = {10, 23, 42, 23, 10, 23, 54, 10, 22, 10};
  int items_without_tens[] = {23, 42, 23, 23, 54, 22};

  for (int i = 0; i < length; i++) {
    push(&vector, items[i]);
  }

  int output1 = remove_it(&vector, 10);
  int output2 = remove_it(&vector, 2);

  for (int i = 0; i < length - 4; i++) {
    TEST_ASSERT_EQUAL_INT(items_without_tens[i], vector.data[i]);
  }

  TEST_ASSERT_EQUAL_INT(4, output1);
  TEST_ASSERT_EQUAL_INT(0, output2);
  TEST_ASSERT_EQUAL_INT(6, vector.size);
}

void test_find() {
  for (int i = 0; i < 16; i++) {
    push(&vector, i + 1);
  }

  int output1 = find(&vector, 5);
  int output2 = find(&vector, 7);
  int output3 = find(&vector, 3);
  int output4 = find(&vector, 12);
  int output5 = find(&vector, 16);
  int output6 = find(&vector, 20);

  TEST_ASSERT_EQUAL_INT(4, output1);
  TEST_ASSERT_EQUAL_INT(6, output2);
  TEST_ASSERT_EQUAL_INT(2, output3);
  TEST_ASSERT_EQUAL_INT(11, output4);
  TEST_ASSERT_EQUAL_INT(15, output5);
  TEST_ASSERT_EQUAL_INT(-1, output6);
}

void setUp() {
  int *ptr = (int *)malloc(INITIAL_CAPACITY * sizeof(int));

  if (ptr == NULL) {
    perror("Error in vector allocation of memory");
    return;
  }

  vector.data = ptr;
  vector.size = 0;
  vector.capacity = INITIAL_CAPACITY;
}

void tearDown() {
  free(vector.data);
  vector.size = 0;
  vector.capacity = INITIAL_CAPACITY;
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_at);
  RUN_TEST(test_push);
  RUN_TEST(test_pop);
  RUN_TEST(test_resize);
  RUN_TEST(test_insert);
  RUN_TEST(test_prepend);
  RUN_TEST(test_delete_it);
  RUN_TEST(test_remove_it);
  RUN_TEST(test_find);

  UNITY_END();

  return 0;
}
