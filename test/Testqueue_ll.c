
#include "../unity/src/unity.h"
#include "queue_ll.h"

QUEUE(int, Node, Queue);

Queue *q;

void test_queue_initialize() {
  TEST_ASSERT_EQUAL_INT(1, q->size);
  TEST_ASSERT_EQUAL_INT(10, q->head->data);
  TEST_ASSERT_EQUAL_INT(10, q->tail->data);
  TEST_ASSERT_NULL(q->head->next);
  TEST_ASSERT_NULL(q->tail->next);
}

void setUp() {
  int value = 10;
  q = init_Queue(&value);
}

void tearDown() { free_Queue(q); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_queue_initialize);

  UNITY_END();

  return 0;
}
