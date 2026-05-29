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

#define FREE_SLL(list)                                                         \
  do {                                                                         \
    IS_SLL(list);                                                              \
    __typeof__((list)->head) _n = list->head;                                  \
    while (_n != NULL) {                                                       \
      Node *nxt = _n->next;                                                    \
      free(_n);                                                                \
      _n = nxt;                                                                \
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
    IS_SLL(list);                                                              \
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
    IS_SLL(list);                                                              \
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
    IS_SLL(list);                                                              \
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

#define front(list)                                                            \
  ({                                                                           \
    IS_SLL(list);                                                              \
    (list)->head;                                                              \
  })

#define back(list)                                                             \
  ({                                                                           \
    IS_SLL(list);                                                              \
    __typeof__((list)->head) _n = (list)->head;                                \
    while (_n->next != NULL) {                                                 \
      _n = _n->next;                                                           \
    }                                                                          \
    _n;                                                                        \
  })

#define insert(list, index, value)                                             \
  do {                                                                         \
    IS_SLL(list);                                                              \
    IS_NODE(value);                                                            \
    if (index > (list)->size || index < 0) {                                   \
      break;                                                                   \
    }                                                                          \
    if (index == 0) {                                                          \
      (value)->next = (list)->head;                                            \
      (list)->head = (value);                                                  \
    } else {                                                                   \
      int i = 0;                                                               \
      __typeof__((list)->head) _n = (list)->head;                              \
      while (_n->next != NULL) {                                               \
        if (i == index - 1) {                                                  \
          (value)->next = _n->next;                                            \
          _n->next = (value);                                                  \
          break;                                                               \
        }                                                                      \
        _n = _n->next;                                                         \
        i++;                                                                   \
      }                                                                        \
    }                                                                          \
    (list)->size += 1;                                                         \
  } while (0)

#define erase(list, index)                                                     \
  do {                                                                         \
    IS_SLL(list);                                                              \
    if (index > (list)->size || index < 0) {                                   \
      break;                                                                   \
    }                                                                          \
    __typeof__((list)->head) _r = NULL;                                        \
    if (index == 0) {                                                          \
      _r = (list)->head;                                                       \
      (list)->head = (list)->head ? (list)->head->next : NULL;                 \
    } else {                                                                   \
      int i = 0;                                                               \
      __typeof__((list)->head) _n = (list)->head;                              \
      while (_n != NULL) {                                                     \
        if (i == index - 1) {                                                  \
          _r = _n->next;                                                       \
          _n->next = _n->next->next;                                           \
          break;                                                               \
        }                                                                      \
        i++;                                                                   \
        _n = _n->next;                                                         \
      }                                                                        \
    }                                                                          \
    free(_r);                                                                  \
    (list)->size -= 1;                                                         \
  } while (0)

#define value_n_from_end(list, n)                                              \
  ({                                                                           \
    IS_SLL(list);                                                              \
    __typeof__((list)->head) _n = (list)->head;                                \
    if ((list)->size - n >= 0) {                                               \
      int _idx = (list)->size - n;                                             \
      while (_idx != 0) {                                                      \
        _n = _n->next;                                                         \
        _idx--;                                                                \
      }                                                                        \
    }                                                                          \
    _n;                                                                        \
  })

#define reverse(list)                                                          \
  do {                                                                         \
    IS_SLL(list);                                                              \
    __typeof__((list)->head) _reverted = NULL;                                 \
    __typeof__((list)->head) _node = (list)->head;                             \
    while (_node != NULL) {                                                    \
      __typeof__((list)->head) _path = _node->next;                            \
      _node->next = _reverted;                                                 \
      _reverted = _node;                                                       \
      _node = _path;                                                           \
    }                                                                          \
    (list)->head = _reverted;                                                  \
  } while (0)

#endif // ! SINGLY_LINKED_LIST_H
