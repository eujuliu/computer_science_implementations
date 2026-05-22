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

#define push_back(list, value)                                                 \
  do {                                                                         \
    IS_SLL(list);                                                              \
    IS_NODE(value);                                                            \
    if ((list)->head == NULL) {                                                \
      (list)->head = (value);                                                  \
    } else {                                                                   \
      __typeof__((list)->head) _n = (list)->head;                              \
      while (_n->next != NULL) {                                               \
        _n = _n->next;                                                         \
      }                                                                        \
      _n->next = (value);                                                      \
    }                                                                          \
    (list)->size += 1;                                                         \
  } while (0)

#define pop_front(list)                                                        \
  ({                                                                           \
    __typeof__((list)->head->value) _result = {0};                             \
    if ((list)->head) {                                                        \
      _result = (list)->head->value;                                           \
      __typeof__((list)->head) _r = (list)->head;                              \
      (list)->head = (list)->head->next;                                       \
      (list)->size -= 1;                                                       \
      free(_r);                                                                \
    }                                                                          \
    _result;                                                                   \
  })

#define pop_back(list)                                                         \
  ({                                                                           \
    __typeof__((list)->head->value) _result = {0};                             \
    if ((list)->head) {                                                        \
      __typeof__((list)->head) _p = NULL;                                      \
      __typeof__((list)->head) _n = (list)->head;                              \
      while (_n->next != NULL) {                                               \
        _p = _n;                                                               \
        _n = _n->next;                                                         \
      }                                                                        \
      _result = _n->value;                                                     \
      _p->next = NULL;                                                         \
      (list)->size -= 1;                                                       \
      free(_n);                                                                \
    }                                                                          \
    _result;                                                                   \
  })

#define value_at(list, index)                                                  \
  ({                                                                           \
    size_t size = (list)->size;                                                \
    __typeof__((list)->head->value) _result = {0};                             \
    if (index <= size) {                                                       \
      int i = 0;                                                               \
      __typeof__((list)->head) _n = (list)->head;                              \
      while (_n != NULL) {                                                     \
        if (i == index) {                                                      \
          _result = _n->value;                                                 \
          break;                                                               \
        }                                                                      \
        i++;                                                                   \
        _n = _n->next;                                                         \
      }                                                                        \
    }                                                                          \
    _result;                                                                   \
  })
#endif // ! SINGLY_LINKED_LIST_H
