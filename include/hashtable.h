#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <string.h>

#define H_MEMORY_ERROR "Error allocating memory to hashtable"

#define HASHTABLE(T, HashTableName, M)                                         \
  typedef struct {                                                             \
    const char *key;                                                           \
    T value;                                                                   \
  } Data##HashTableName;                                                       \
                                                                               \
  typedef struct {                                                             \
    Data##HashTableName *buckets[M];                                           \
  } HashTableName;                                                             \
                                                                               \
  HashTableName *init_##HashTableName() {                                      \
    HashTableName *hashtable = calloc(1, sizeof(HashTableName));               \
    if (hashtable == NULL) {                                                   \
      perror(H_MEMORY_ERROR);                                                  \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    return hashtable;                                                          \
  }                                                                            \
                                                                               \
  void free_##HashTableName(HashTableName *ht) {                               \
    for (int i = 0; i < M; i++) {                                              \
      Data##HashTableName *d = ht->buckets[i];                                 \
      if (d == NULL) {                                                         \
        continue;                                                              \
      }                                                                        \
      free(ht->buckets[i]);                                                    \
    }                                                                          \
    free(ht);                                                                  \
  }                                                                            \
                                                                               \
  uint hash_##HashTableName(const char *key, size_t m) {                       \
    uint hash = 0;                                                             \
    uint8_t multipler = 37;                                                    \
    size_t len = strlen(key);                                                  \
    for (size_t i = 0; i < len; i++) {                                         \
      hash = (hash * multipler + key[i]) % m;                                  \
    }                                                                          \
    return hash;                                                               \
  }                                                                            \
                                                                               \
  void add_##HashTableName(HashTableName *ht, const char *key, T value) {      \
    uint idx = hash_##HashTableName(key, M);                                   \
    Data##HashTableName *data = ht->buckets[idx];                              \
    for (int i = 0; i < M; i++) {                                              \
      idx = (idx + i) % M;                                                     \
      data = ht->buckets[idx];                                                 \
      if (data == NULL) {                                                      \
        data = calloc(1, sizeof(Data##HashTableName));                         \
        if (data == NULL) {                                                    \
          perror(H_MEMORY_ERROR);                                              \
          return;                                                              \
        }                                                                      \
        data->key = key;                                                       \
        data->value = value;                                                   \
        ht->buckets[idx] = data;                                               \
        return;                                                                \
      }                                                                        \
      if (data->key == key) {                                                  \
        data->value = value;                                                   \
      }                                                                        \
    }                                                                          \
  }                                                                            \
  \

#endif // !HASHTABLE_H
