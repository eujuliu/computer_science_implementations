
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

void test_queue_empty() { TEST_ASSERT_EQUAL_INT(0, empty_Queue(q)); }

void test_queue_enqueue() {
  TEST_ASSERT_EQUAL_INT(1, q->size);

  enqueue_Queue(q, 20);

  TEST_ASSERT_EQUAL_INT(20, q->tail->data);
  TEST_ASSERT_EQUAL_INT(2, q->size);
}

void setUp() {
  int value = 10;
  q = init_Queue(&value);
}

void tearDown() { free_Queue(q); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_queue_initialize);
  RUN_TEST(test_queue_empty);
  RUN_TEST(test_queue_enqueue);

  UNITY_END();

  return 0;
}
