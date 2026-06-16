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
  uint hash_##HashTableName(const char *key) {                                 \
    uint hash = 0;                                                             \
    uint8_t multipler = 37;                                                    \
    size_t len = strlen(key);                                                  \
    for (size_t i = 0; i < len; i++) {                                         \
      hash = (hash * multipler + key[i]) % M;                                  \
    }                                                                          \
    return hash;                                                               \
  }                                                                            \
                                                                               \
  DataHashTable *add_##HashTableName(HashTableName *ht, const char *key,       \
                                     T value) {                                \
    uint idx = hash_##HashTableName(key);                                      \
    Data##HashTableName *data = ht->buckets[idx];                              \
    for (int probe = 0; probe < M; probe++) {                                  \
      idx = (idx + probe) % M;                                                 \
      data = ht->buckets[idx];                                                 \
      if (data == NULL) {                                                      \
        data = calloc(1, sizeof(Data##HashTableName));                         \
        if (data == NULL) {                                                    \
          perror(H_MEMORY_ERROR);                                              \
          return NULL;                                                         \
        }                                                                      \
        data->key = key;                                                       \
        data->value = value;                                                   \
        ht->buckets[idx] = data;                                               \
        return data;                                                           \
      }                                                                        \
      if (data->key == key) {                                                  \
        data->value = value;                                                   \
        return data;                                                           \
      }                                                                        \
    }                                                                          \
    return data;                                                               \
  }                                                                            \
                                                                               \
  Data##HashTableName *get_##HashTableName(HashTableName *ht,                  \
                                           const char *key) {                  \
    int idx = hash_##HashTableName(key);                                       \
    Data##HashTableName *data = ht->buckets[idx];                              \
    for (int probe = 0; probe < M; probe++) {                                  \
      idx = (idx + probe) % M;                                                 \
      data = ht->buckets[idx];                                                 \
      if (data != NULL && data->key == key) {                                  \
        return data;                                                           \
      }                                                                        \
    }                                                                          \
    return NULL;                                                               \
  }                                                                            \
                                                                               \
  int8_t exists_##HashTableName(HashTableName *ht, const char *key) {          \
    return get_##HashTableName(ht, key) != NULL ? 1 : 0;                       \
  }

#endif // !HASHTABLE_H
