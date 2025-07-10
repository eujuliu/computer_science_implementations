#include "../include/singly_linkedlist.h"
#include "../unity/src/unity.h"
#include <stdlib.h>
#include <string.h>

LinkedList linked_list;

void test_to_string() {
  TEST_ASSERT_EQUAL(0, linked_list.size);
  linked_list.size += 5;
  char *expected = "1 -> 2 -> 3 -> 4 -> 5";

  for (int i = 0; i < 5; i++) {
    Node *node = (Node *)malloc(sizeof(Node));
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

  char *output = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(output, expected));
}

void test_push_back() {
  TEST_ASSERT_EQUAL(0, linked_list.size);
  char *expected = "10 -> 11 -> 12 -> 13 -> 14";

  push_back(&linked_list, 10);
  push_back(&linked_list, 11);
  push_back(&linked_list, 12);
  push_back(&linked_list, 13);
  push_back(&linked_list, 14);

  char *llstr = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(llstr, expected));
  TEST_ASSERT_EQUAL_INT(5, linked_list.size);
}

void test_push_front() {
  TEST_ASSERT_EQUAL_INT(0, linked_list.size);
  char *expected = "24 -> 23 -> 22 -> 21 -> 20";

  push_front(&linked_list, 20);
  push_front(&linked_list, 21);
  push_front(&linked_list, 22);
  push_front(&linked_list, 23);
  push_front(&linked_list, 24);

  char *llstr = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(llstr, expected));
  TEST_ASSERT_EQUAL_INT(5, linked_list.size);
}

void test_value_at() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  TEST_ASSERT_EQUAL_INT(4, value_at(&linked_list, 3));
  TEST_ASSERT_EQUAL_INT(1, value_at(&linked_list, 0));
  TEST_ASSERT_EQUAL_INT(5, value_at(&linked_list, 4));
  TEST_ASSERT_EQUAL_INT(5, linked_list.size);
}

void test_pop_front() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  TEST_ASSERT_EQUAL_INT(5, linked_list.size);

  TEST_ASSERT_EQUAL_INT(1, pop_front(&linked_list));
  TEST_ASSERT_EQUAL_INT(4, linked_list.size);

  TEST_ASSERT_EQUAL_INT(2, pop_front(&linked_list));
  TEST_ASSERT_EQUAL_INT(3, linked_list.size);

  TEST_ASSERT_EQUAL_INT(3, pop_front(&linked_list));
  TEST_ASSERT_EQUAL_INT(2, linked_list.size);

  TEST_ASSERT_EQUAL_INT(4, pop_front(&linked_list));
  TEST_ASSERT_EQUAL_INT(1, linked_list.size);

  TEST_ASSERT_EQUAL_INT(5, pop_front(&linked_list));
  TEST_ASSERT_EQUAL_INT(0, linked_list.size);

  TEST_ASSERT_EQUAL_INT(-1, pop_front(&linked_list));
  TEST_ASSERT_NULL(linked_list.head);
  TEST_ASSERT_NULL(linked_list.tail);
}

void test_pop_back() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  TEST_ASSERT_EQUAL_INT(5, linked_list.size);

  TEST_ASSERT_EQUAL_INT(5, pop_back(&linked_list));
  TEST_ASSERT_EQUAL_INT(4, linked_list.size);

  TEST_ASSERT_EQUAL_INT(4, pop_back(&linked_list));
  TEST_ASSERT_EQUAL_INT(3, linked_list.size);

  TEST_ASSERT_EQUAL_INT(3, pop_back(&linked_list));
  TEST_ASSERT_EQUAL_INT(2, linked_list.size);

  TEST_ASSERT_EQUAL_INT(2, pop_back(&linked_list));
  TEST_ASSERT_EQUAL_INT(1, linked_list.size);

  TEST_ASSERT_EQUAL_INT(1, pop_back(&linked_list));
  TEST_ASSERT_EQUAL_INT(0, linked_list.size);

  TEST_ASSERT_EQUAL_INT(-1, pop_back(&linked_list));
  TEST_ASSERT_NULL(linked_list.head);
  TEST_ASSERT_NULL(linked_list.tail);
}

void test_insert() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 3);
  push_back(&linked_list, 5);
  push_back(&linked_list, 7);
  push_back(&linked_list, 9);

  TEST_ASSERT_EQUAL_INT(5, linked_list.size);


  TEST_ASSERT_EQUAL(1, linked_list.head->value);
  TEST_ASSERT_EQUAL(9, linked_list.tail->value);

  TEST_ASSERT_EQUAL_INT(0, insert(&linked_list, 0, 0));
  TEST_ASSERT_EQUAL_INT(6, linked_list.size);


  TEST_ASSERT_EQUAL_INT(2, insert(&linked_list, 1, 2));
  TEST_ASSERT_EQUAL_INT(7, linked_list.size);


  TEST_ASSERT_EQUAL_INT(10, insert(&linked_list, -1, 10));
  TEST_ASSERT_EQUAL_INT(8, linked_list.size);


  TEST_ASSERT_EQUAL_INT(11, insert(&linked_list, linked_list.size -1, 11));
  TEST_ASSERT_EQUAL_INT(9, linked_list.size);

  TEST_ASSERT_EQUAL(0, linked_list.head->value);
  TEST_ASSERT_EQUAL(11, linked_list.tail->value);
}

void test_erase() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  TEST_ASSERT_EQUAL(5, linked_list.tail->value);

  TEST_ASSERT_EQUAL_INT(1, erase(&linked_list, 0));
  TEST_ASSERT_EQUAL_INT(4, linked_list.size);
  TEST_ASSERT_EQUAL(2, linked_list.head->value);

  TEST_ASSERT_EQUAL_INT(4, erase(&linked_list, 2));
  TEST_ASSERT_EQUAL_INT(3, linked_list.size);

  TEST_ASSERT_EQUAL_INT(5, erase(&linked_list, 2));
  TEST_ASSERT_EQUAL_INT(2, linked_list.size);
  TEST_ASSERT_EQUAL(3, linked_list.tail->value);
}

void test_value_n_from() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  TEST_ASSERT_EQUAL(5, value_n_from_end(&linked_list, 1));
  TEST_ASSERT_EQUAL(4, value_n_from_end(&linked_list, 2));
  TEST_ASSERT_EQUAL(3, value_n_from_end(&linked_list, 3));
  TEST_ASSERT_EQUAL(2, value_n_from_end(&linked_list, 4));
  TEST_ASSERT_EQUAL(1, value_n_from_end(&linked_list, 5));
}

void test_reverse() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  char *initial = "1 -> 2 -> 3 -> 4 -> 5";
  char *expected = "5 -> 4 -> 3 -> 2 -> 1";

  char *llstr_old = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(llstr_old, initial));

  reverse(&linked_list);

  char *llstr = to_string(&linked_list);

  TEST_ASSERT_EQUAL(0, strcmp(llstr, expected));
  TEST_ASSERT_EQUAL(5, linked_list.size);
}

void test_remove_value() {
  push_back(&linked_list, 1);
  push_back(&linked_list, 2);
  push_back(&linked_list, 3);
  push_back(&linked_list, 4);
  push_back(&linked_list, 5);

  TEST_ASSERT_EQUAL_INT(5, linked_list.size);

  TEST_ASSERT_EQUAL(0, remove_value(&linked_list, 1));
  TEST_ASSERT_EQUAL_INT(4, linked_list.size);


  TEST_ASSERT_EQUAL(1, remove_value(&linked_list, 3));
  TEST_ASSERT_EQUAL_INT(3, linked_list.size);
  TEST_ASSERT_EQUAL_INT(2, linked_list.head->value);

  TEST_ASSERT_EQUAL(2, remove_value(&linked_list, 5));
  TEST_ASSERT_EQUAL_INT(2, linked_list.size);
  TEST_ASSERT_EQUAL_INT(4, linked_list.tail->value);
}

void setUp() {
  linked_list.head = NULL;
  linked_list.tail = NULL;
  linked_list.size = 0;
}

void tearDown() {
  Node *crr = linked_list.head;

  while (crr != NULL) {
    Node *next = crr->next;

    free(crr);
    crr = next;
  }
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_to_string);
  RUN_TEST(test_push_back);
  RUN_TEST(test_push_front);
  RUN_TEST(test_value_at);
  RUN_TEST(test_pop_front);
  RUN_TEST(test_pop_back);
  RUN_TEST(test_insert);
  RUN_TEST(test_erase);
  RUN_TEST(test_value_n_from);
  RUN_TEST(test_reverse);
  RUN_TEST(test_remove_value);

  UNITY_END();

  return 0;
}
