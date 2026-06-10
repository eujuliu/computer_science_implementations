
#include "../unity/src/unity.h"
#include "queue_a.h"

QUEUE_A(int, Queue, 10);

Queue *q;

void test_queue_initialize() {
  TEST_ASSERT_EQUAL_INT(1, q->size);
  TEST_ASSERT_EQUAL_INT(10, q->data[0]);
}

void test_queue_empty() { TEST_ASSERT_EQUAL_INT(0, empty_Queue(q)); }

void test_queue_enqueue() {
  TEST_ASSERT_EQUAL_INT(1, q->size);

  enqueue_Queue(q, 20);

  TEST_ASSERT_EQUAL_INT(20, q->data[1]);
  TEST_ASSERT_EQUAL_INT(2, q->size);
}

void test_queue_dequeue() {
  TEST_ASSERT_EQUAL_INT(1, q->size);

  enqueue_Queue(q, 20);
  enqueue_Queue(q, 30);
  enqueue_Queue(q, 40);
  enqueue_Queue(q, 50);

  TEST_ASSERT_EQUAL_INT(5, q->size);

  int dequeue1 = dequeue_Queue(q);
  int dequeue2 = dequeue_Queue(q);
  int dequeue3 = dequeue_Queue(q);

  TEST_ASSERT_EQUAL_INT(2, q->size);

  int dequeue4 = dequeue_Queue(q);
  int dequeue5 = dequeue_Queue(q);

  TEST_ASSERT_EQUAL_INT(10, dequeue1);
  TEST_ASSERT_EQUAL_INT(20, dequeue2);
  TEST_ASSERT_EQUAL_INT(30, dequeue3);
  TEST_ASSERT_EQUAL_INT(40, dequeue4);
  TEST_ASSERT_EQUAL_INT(50, dequeue5);
  TEST_ASSERT_EQUAL_INT(0, q->size);
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
  RUN_TEST(test_queue_dequeue);

  UNITY_END();

  return 0;
}
