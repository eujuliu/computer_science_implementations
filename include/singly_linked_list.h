#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>

#define SllNode(type, name)                                                    \
  type value;                                                                  \
  struct name *next;

#define Sll(Node)                                                              \
  size_t size;                                                                 \
  Node *head;

#define IS_SLL(list)                                                           \
  do {                                                                         \
    (void)((list)->size);                                                      \
    (void)((list)->head);                                                      \
  } while (0)

#define IS_NODE(node)                                                          \
  do {                                                                         \
    (void)((node)->value);                                                     \
    (void)((node)->next);                                                      \
  } while (0)

#define CREATE_SLL_NODE(name, Val, Next)                                       \
  ({                                                                           \
    name *_n = malloc(sizeof(name));                                           \
    if (_n) {                                                                  \
      _n->value = (Val);                                                       \
      _n->next = (Next);                                                       \
    }                                                                          \
    _n;                                                                        \
  })

#define CREATE_SLL(name, initial_value)                                        \
  ({                                                                           \
    name *_sll = malloc(sizeof(name));                                         \
    if (_sll) {                                                                \
      _sll->size = 0;                                                          \
      _sll->head = NULL;                                                       \
      if (initial_value) {                                                     \
        _sll->head = (initial_value);                                          \
        _sll->size += 1;                                                       \
      }                                                                        \
    }                                                                          \
    _sll;                                                                      \
  })

#define FREE_SLL(list, Node)                                                   \
  do {                                                                         \
    IS_SLL(list);                                                              \
    Node *n = list->head;                                                      \
    while (n != NULL) {                                                        \
      Node *nxt = n->next;                                                     \
      free(n);                                                                 \
      n = nxt;                                                                 \
    }                                                                          \
    free(list);                                                                \
  } while (0)

#define push_front(list, value)                                                \
  do {                                                                         \
    IS_SLL(list);                                                              \
    IS_NODE(value);                                                            \
    (value)->next = (list)->head;                                              \
    (list)->head = (value);                                                    \
    (list)->size += 1;                                                         \
  } while (0)

#endif // ! SINGLY_LINKED_LIST_H
