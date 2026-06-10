
#ifndef QUEUE_A_H
#define QUEUE_A_H

#include <stdint.h>
#include <stdlib.h>

#define Q_MEMORY_ERROR "Error allocating memory to queue"

#define QUEUE_A(type, queue_name, max)                                         \
  typedef struct {                                                             \
    size_t size;                                                               \
    size_t capacity;                                                           \
    type data[max];                                                            \
  } queue_name;                                                                \
                                                                               \
  uint8_t empty_##queue_name(queue_name *q) { return q->size > 0 ? 0 : 1; }    \
                                                                               \
  queue_name *init_##queue_name(type *value) {                                 \
    queue_name *queue = malloc(sizeof(queue_name));                            \
    if (queue == NULL) {                                                       \
      perror(Q_MEMORY_ERROR);                                                  \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    if (value != NULL) {                                                       \
      queue->data[0] = *value;                                                 \
      queue->size = 1;                                                         \
    }                                                                          \
    queue->capacity = max;                                                     \
    return queue;                                                              \
  }                                                                            \
                                                                               \
  void free_##queue_name(queue_name *q) { free(q); }                           \
                                                                               \
  void enqueue_##queue_name(queue_name *q, type value) {                       \
    if (q->size == q->capacity) {                                              \
      return;                                                                  \
    }                                                                          \
    q->data[q->size] = value;                                                  \
    q->size += 1;                                                              \
  }                                                                            \
                                                                               \
  type dequeue_##queue_name(queue_name *q) {                                   \
    if (q->size < 1) {                                                         \
      return (type){0};                                                        \
    }                                                                          \
    type value = q->data[0];                                                   \
    for (int i = 1; i < q->size; i++) {                                        \
      q->data[i - 1] = q->data[i];                                             \
    }                                                                          \
    q->size -= 1;                                                              \
    return value;                                                              \
  }

#endif // !QUEUE_A_H
