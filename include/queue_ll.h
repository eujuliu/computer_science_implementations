#ifndef QUEUE_LL_H
#define QUEUE_LL_H

#include <stdint.h>
#include <stdlib.h>

#define Q_MEMORY_ERROR "Error allocating memory to queue"

#define QUEUE(type, node_name, queue_name)                                     \
  typedef struct node_name {                                                   \
    type data;                                                                 \
    struct node_name *next;                                                    \
  } node_name;                                                                 \
                                                                               \
  typedef struct {                                                             \
    size_t size;                                                               \
    node_name *head;                                                           \
    node_name *tail;                                                           \
  } queue_name;                                                                \
                                                                               \
  uint8_t empty_##queue_name(queue_name *q) { return q->size > 0; }            \
                                                                               \
  queue_name *init_##queue_name(type *value) {                                 \
    queue_name *queue = malloc(sizeof(queue_name));                            \
    if (queue == NULL) {                                                       \
      perror(Q_MEMORY_ERROR);                                                  \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    if (value != NULL) {                                                       \
      node_name *node = malloc(sizeof(node_name));                             \
      node->data = *value;                                                     \
      node->next = NULL;                                                       \
      queue->head = node;                                                      \
      queue->tail = node;                                                      \
      queue->size = 1;                                                         \
    }                                                                          \
    return queue;                                                              \
  }                                                                            \
                                                                               \
  void free_##queue_name(queue_name *q) {                                      \
    if (q->size > 0) {                                                         \
      node_name *node = q->head;                                               \
      q->head = NULL;                                                          \
      q->tail = NULL;                                                          \
      while (node != NULL) {                                                   \
        node_name *nxt = node->next;                                           \
        free(node);                                                            \
        node = nxt;                                                            \
      }                                                                        \
    }                                                                          \
    free(q);                                                                   \
  }

#endif // !QUEUE_LL_H
