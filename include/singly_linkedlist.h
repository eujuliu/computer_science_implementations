#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  int size;
  Node *head;
  Node *tail;
} LinkedList;

char * to_string(LinkedList *ll);
int push_back(LinkedList *ll, int value);
int push_front(LinkedList *ll, int value);

// int value_at(LinkedList *ll, int index);
// int pop_front(LinkedList *ll);
// int pop_back(LinkedList *ll);
// int front(LinkedList *ll);
// int back(LinkedList *ll);
// int insert(LinkedList *ll, int index, int value);
// int erase(LinkedList *ll, int index);
// int value_n_from_end(LinkedList *ll, int n);
// int reverse(LinkedList *ll);
// int remove_value(LinkedList *ll, int value);

#endif
