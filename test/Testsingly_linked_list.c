#include "../unity/src/unity.h"
#include "singly_linked_list.h"

typedef struct Node {
  SllNode(int, Node)
} Node;

typedef struct {
  Sll(Node)
} SinglyLinkedList;

SinglyLinkedList *sll;

void test_singly_linked_list_push_front() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);

  Node *n = CREATE_SLL_NODE(Node, 11, NULL);

  push_front(sll, n);

  TEST_ASSERT_EQUAL_INT(11, sll->head->value);
  TEST_ASSERT_NOT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(10, sll->head->next->value);
  TEST_ASSERT_NULL(sll->head->next->next);
}

void setUp() {
  Node *n = CREATE_SLL_NODE(Node, 10, NULL);
  sll = CREATE_SLL(SinglyLinkedList, n);
}

void tearDown() { FREE_SLL(sll, Node); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_singly_linked_list_push_front);

  UNITY_END();

  return 0;
}
