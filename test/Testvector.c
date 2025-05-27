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

  TEST_ASSERT_EQUAL(-1, output1);
  TEST_ASSERT_EQUAL(8, output2);
  TEST_ASSERT_EQUAL(15, output3);
}

void test_push() {
  TEST_ASSERT_EQUAL(0, vector.size);

  int output1 = push(&vector, 1);
  int output2 = push(&vector, 2);
  int output3 = push(&vector, 3);
  int output4 = push(&vector, 4);
  int outputs[] = {output1, output2, output3, output4};

  TEST_ASSERT_EQUAL(4, vector.size);

  for (int i = 0; i < vector.size; i++) {
    TEST_ASSERT_EQUAL(i + 1, outputs[i]);
    TEST_ASSERT_EQUAL(i + 1, vector.data[i]);
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

  TEST_ASSERT_EQUAL(0, vector.size);

  for (int i = 0; i < 4; i++) {
    TEST_ASSERT_EQUAL(0, vector.data[i]);
  }
}

void test_resize() {
  TEST_ASSERT_EQUAL(0, vector.size);
  TEST_ASSERT_EQUAL(16, vector.capacity);

  for (int i = 0; i < vector.capacity - 1; i++) {
    push(&vector, i + 1);
  }

  push(&vector, 16);

  TEST_ASSERT_EQUAL(16, vector.size);
  TEST_ASSERT_EQUAL(32, vector.capacity);
}

void setUp() {
  int *ptr = (int *)malloc(INITIAL_CAPACITY * sizeof(int));

  if (ptr == NULL) {
    perror("Error in vector allocation of memory");
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

  UNITY_END();

  return 0;
}
