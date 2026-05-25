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
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n = CREATE_SLL_NODE(Node, 11, NULL);

  push_front(sll, n);

  TEST_ASSERT_EQUAL_INT(11, sll->head->value);
  TEST_ASSERT_NOT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(10, sll->head->next->value);
  TEST_ASSERT_NULL(sll->head->next->next);
  TEST_ASSERT_EQUAL_INT(2, sll->size);
}

void test_singly_linked_list_push_front_multiple() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_front(sll, n1);
  push_front(sll, n2);
  push_front(sll, n3);

  Node *i1 = sll->head->next;
  Node *i2 = i1->next;
  Node *i3 = i2->next;

  TEST_ASSERT_EQUAL_INT(13, sll->head->value);
  TEST_ASSERT_EQUAL_INT(12, i1->value);
  TEST_ASSERT_EQUAL_INT(11, i2->value);
  TEST_ASSERT_EQUAL_INT(10, i3->value);
  TEST_ASSERT_NULL(i3->next);
  TEST_ASSERT_EQUAL_INT(4, sll->size);
}

void test_singly_linked_list_push_back() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n = CREATE_SLL_NODE(Node, 11, NULL);

  push_back(sll, n);

  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_NOT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(11, sll->head->next->value);
  TEST_ASSERT_NULL(sll->head->next->next);
  TEST_ASSERT_EQUAL_INT(2, sll->size);
}

void test_singly_linked_list_push_back_multiple() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  Node *i1 = sll->head->next;
  Node *i2 = i1->next;
  Node *i3 = i2->next;

  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_EQUAL_INT(11, i1->value);
  TEST_ASSERT_EQUAL_INT(12, i2->value);
  TEST_ASSERT_EQUAL_INT(13, i3->value);
  TEST_ASSERT_NULL(i3->next);
  TEST_ASSERT_EQUAL_INT(4, sll->size);
}

void test_singly_linked_list_pop_front() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  Node *i1 = sll->head->next;
  Node *i2 = i1->next;
  Node *i3 = i2->next;

  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_EQUAL_INT(11, i1->value);
  TEST_ASSERT_EQUAL_INT(12, i2->value);
  TEST_ASSERT_EQUAL_INT(13, i3->value);
  TEST_ASSERT_NULL(i3->next);
  TEST_ASSERT_EQUAL_INT(4, sll->size);

  int r1 = pop_front(sll);

  i1 = sll->head->next;
  i2 = i1->next;

  TEST_ASSERT_EQUAL_INT(10, r1);
  TEST_ASSERT_EQUAL_INT(11, sll->head->value);
  TEST_ASSERT_EQUAL_INT(12, i1->value);
  TEST_ASSERT_EQUAL_INT(13, i2->value);
  TEST_ASSERT_NULL(i2->next);
  TEST_ASSERT_EQUAL_INT(3, sll->size);
}

void test_singly_linked_list_pop_front_multiple() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  Node *i1 = sll->head->next;
  Node *i2 = i1->next;
  Node *i3 = i2->next;

  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_EQUAL_INT(11, i1->value);
  TEST_ASSERT_EQUAL_INT(12, i2->value);
  TEST_ASSERT_EQUAL_INT(13, i3->value);
  TEST_ASSERT_NULL(i3->next);
  TEST_ASSERT_EQUAL_INT(4, sll->size);

  int r1 = pop_front(sll);
  int r2 = pop_front(sll);
  int r3 = pop_front(sll);

  TEST_ASSERT_EQUAL_INT(10, r1);
  TEST_ASSERT_EQUAL_INT(11, r2);
  TEST_ASSERT_EQUAL_INT(12, r3);
  TEST_ASSERT_EQUAL_INT(13, sll->head->value);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);
}

void test_singly_linked_list_pop_back() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  Node *i1 = sll->head->next;
  Node *i2 = i1->next;
  Node *i3 = i2->next;

  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_EQUAL_INT(11, i1->value);
  TEST_ASSERT_EQUAL_INT(12, i2->value);
  TEST_ASSERT_EQUAL_INT(13, i3->value);
  TEST_ASSERT_NULL(i3->next);
  TEST_ASSERT_EQUAL_INT(4, sll->size);

  int r1 = pop_back(sll);

  i1 = sll->head->next;
  i2 = i1->next;

  TEST_ASSERT_EQUAL_INT(13, r1);
  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_EQUAL_INT(11, i1->value);
  TEST_ASSERT_EQUAL_INT(12, i2->value);
  TEST_ASSERT_NULL(i2->next);
  TEST_ASSERT_EQUAL_INT(3, sll->size);
}

void test_singly_linked_list_pop_back_multiple() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  Node *i1 = sll->head->next;
  Node *i2 = i1->next;
  Node *i3 = i2->next;

  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_EQUAL_INT(11, i1->value);
  TEST_ASSERT_EQUAL_INT(12, i2->value);
  TEST_ASSERT_EQUAL_INT(13, i3->value);
  TEST_ASSERT_NULL(i3->next);
  TEST_ASSERT_EQUAL_INT(4, sll->size);

  int r1 = pop_back(sll);
  int r2 = pop_back(sll);
  int r3 = pop_back(sll);

  TEST_ASSERT_EQUAL_INT(13, r1);
  TEST_ASSERT_EQUAL_INT(12, r2);
  TEST_ASSERT_EQUAL_INT(11, r3);
  TEST_ASSERT_EQUAL_INT(10, sll->head->value);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);
}

void test_singly_linked_list_value_at() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  TEST_ASSERT_EQUAL_INT(10, value_at(sll, 0));
  TEST_ASSERT_EQUAL_INT(11, value_at(sll, 1));
  TEST_ASSERT_EQUAL_INT(12, value_at(sll, 2));
  TEST_ASSERT_EQUAL_INT(13, value_at(sll, 3));
  TEST_ASSERT_EQUAL_INT(0, value_at(sll, 4));
  TEST_ASSERT_EQUAL_INT(4, sll->size);
}

void test_singly_linked_list_front() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  TEST_ASSERT_EQUAL_INT(10, front(sll)->value);
  TEST_ASSERT_EQUAL_INT(4, sll->size);
}

void test_singly_linked_list_back() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  push_back(sll, n1);
  push_back(sll, n2);
  push_back(sll, n3);

  TEST_ASSERT_EQUAL_INT(13, back(sll)->value);
  TEST_ASSERT_EQUAL_INT(4, sll->size);
}

void test_singly_linked_list_insert() {
  TEST_ASSERT_EQUAL_INT(sll->head->value, 10);
  TEST_ASSERT_NULL(sll->head->next);
  TEST_ASSERT_EQUAL_INT(1, sll->size);

  Node *n1 = CREATE_SLL_NODE(Node, 11, NULL);
  Node *n2 = CREATE_SLL_NODE(Node, 12, NULL);
  Node *n3 = CREATE_SLL_NODE(Node, 13, NULL);

  insert(sll, 0, n1);
  insert(sll, 1, n2);
  insert(sll, 2, n3);

  TEST_ASSERT_EQUAL_INT(11, value_at(sll, 0));
  TEST_ASSERT_EQUAL_INT(12, value_at(sll, 1));
  TEST_ASSERT_EQUAL_INT(13, value_at(sll, 2));
  TEST_ASSERT_EQUAL_INT(10, value_at(sll, 3));
  TEST_ASSERT_EQUAL_INT(4, sll->size);
}

void setUp() {
  Node *n = CREATE_SLL_NODE(Node, 10, NULL);
  sll = CREATE_SLL(SinglyLinkedList, n);
}

void tearDown() { FREE_SLL(sll); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_singly_linked_list_push_front);
  RUN_TEST(test_singly_linked_list_push_front_multiple);
  RUN_TEST(test_singly_linked_list_push_back);
  RUN_TEST(test_singly_linked_list_push_back_multiple);
  RUN_TEST(test_singly_linked_list_pop_front);
  RUN_TEST(test_singly_linked_list_pop_front_multiple);
  RUN_TEST(test_singly_linked_list_pop_back);
  RUN_TEST(test_singly_linked_list_pop_back_multiple);
  RUN_TEST(test_singly_linked_list_value_at);
  RUN_TEST(test_singly_linked_list_front);
  RUN_TEST(test_singly_linked_list_back);
  RUN_TEST(test_singly_linked_list_insert);

  UNITY_END();

  return 0;
}
