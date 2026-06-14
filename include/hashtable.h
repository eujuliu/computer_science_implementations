#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

#define H_MEMORY_ERROR "Error allocating memory to hashtable"

#define HASHTABLE(T, hashtable_name, max_buckets)                              \
  typedef struct {                                                             \
    char *key;                                                                 \
    T value;                                                                   \
  } Data##hashtable_name;                                                      \
                                                                               \
  typedef struct {                                                             \
    Data##hashtable_name buckets[max_buckets];                                 \
  } hashtable_name;                                                            \
                                                                               \
  hashtable_name *init_##hashtable_name() {                                    \
    hashtable_name *hashtable = calloc(1, sizeof(hashtable_name));             \
    if (hashtable == NULL) {                                                   \
      perror(H_MEMORY_ERROR);                                                  \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    return hashtable;                                                          \
  }                                                                            \
                                                                               \
  void free_##hashtable_name(hashtable_name *ht) { free(ht); }                 \
                                                                               \
  uint hash_##hashtable_name(const char *key) {                                \
    uint hash = 0;                                                             \
    uint8_t A = 31;                                                            \
    size_t len = strlen(key);                                                  \
    for (size_t i = 0; i < len; i++) {                                         \
      hash = hash * A + key[i];                                                \
    }                                                                          \
    return hash;                                                               \
  }                                                                            \
                                                                               \
  uint get_index##hashtable_name(uint hash) { return hash % max_buckets; }

#endif // !HASHTABLE_H
