#include "../include/singly_linkedlist.h"
#include "../unity/src/unity.h"
#include <stdlib.h>
#include <string.h>

LinkedList linked_list;

void test_to_string() {
  TEST_ASSERT_EQUAL(0, linked_list.size);
  linked_list.size += 5;
  char * expected = "1 -> 2 -> 3 -> 4 -> 5";

  for (int i = 0; i < 5; i++) {
    Node * node = (Node *)malloc(sizeof(Node));
    node->value = i + 1;
    node->next = NULL;

    if (linked_list.tail != NULL) {
      linked_list.tail->next = node;
      linked_list.tail = node;
    } else {
      linked_list.head = node;
      linked_list.tail = node;
    }
  }

  char * output = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(output, expected));
}

void test_push_back() {
  TEST_ASSERT_EQUAL(0, linked_list.size);
  char * expected = "10 -> 11 -> 12 -> 13 -> 14";

  int output1 = push_back(&linked_list, 10);
  int output2 = push_back(&linked_list, 11);
  int output3 = push_back(&linked_list, 12);
  int output4 = push_back(&linked_list, 13);
  int output5 = push_back(&linked_list, 14);

  char * llstr = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(llstr, expected));
  TEST_ASSERT_EQUAL_INT(5, linked_list.size);
}

void test_push_front() {
  TEST_ASSERT_EQUAL_INT(0, linked_list.size);
  char * expected = "24 -> 23 -> 22 -> 21 -> 20";

  int output1 = push_front(&linked_list, 20);
  int output2 = push_front(&linked_list, 21);
  int output3 = push_front(&linked_list, 22);
  int output4 = push_front(&linked_list, 23);
  int output5 = push_front(&linked_list, 24);

  char * llstr = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(llstr, expected));
  TEST_ASSERT_EQUAL_INT(5, linked_list.size);
}

void setUp() {
  linked_list.head = NULL;
  linked_list.tail = NULL;
  linked_list.size = 0;
}

void tearDown() {
  Node *crr = linked_list.head;

  while (crr != NULL) {
    Node * next = crr->next;

    free(crr);
    crr = next;
  }
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_to_string);
  RUN_TEST(test_push_back);
  RUN_TEST(test_push_front);

  UNITY_END();

  return 0;
}
