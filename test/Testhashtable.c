#include "../unity/src/unity.h"
#include "hashtable.h"

#define CAPACITY 10

HASHTABLE(int, HashTable, CAPACITY);

HashTable *ht;

void test_should_return_idx_from_key() {
  uint hash = hash_HashTable("abc", CAPACITY);

  TEST_ASSERT_LESS_THAN_UINT(CAPACITY, hash);
}

void test_should_add_value() {
  int idx = hash_HashTable("abc", CAPACITY);
  TEST_ASSERT_NULL(ht->buckets[idx]);

  add_HashTable(ht, "abc", 10);

  TEST_ASSERT_NOT_NULL(ht->buckets[idx]);
  TEST_ASSERT_EQUAL("abc", ht->buckets[idx]->key);
  TEST_ASSERT_EQUAL_INT(10, ht->buckets[idx]->value);
}

void test_should_add_multiple_values() {
  char *key1 = "banana";
  char *key2 = "apple";
  char *key3 = "mango";

  int idx1 = hash_HashTable(key1, CAPACITY);
  int idx2 = hash_HashTable(key2, CAPACITY);
  int idx3 = hash_HashTable(key3, CAPACITY);

  TEST_ASSERT_NULL(ht->buckets[idx1]);
  TEST_ASSERT_NULL(ht->buckets[idx2]);
  TEST_ASSERT_NULL(ht->buckets[idx3]);

  add_HashTable(ht, key1, 10);
  add_HashTable(ht, key2, 10);
  add_HashTable(ht, key3, 10);

  DataHashTable *data1 = ht->buckets[idx1];
  DataHashTable *data2 = ht->buckets[idx2];
  DataHashTable *data3 = ht->buckets[idx3];

  TEST_ASSERT_NOT_NULL(data1);
  TEST_ASSERT_NOT_NULL(data2);
  TEST_ASSERT_NOT_NULL(data3);

  TEST_ASSERT_EQUAL(key1, data1->key);
  TEST_ASSERT_EQUAL(key2, data2->key);
  TEST_ASSERT_EQUAL(key3, data3->key);

  TEST_ASSERT_EQUAL_INT(10, data1->value);
  TEST_ASSERT_EQUAL_INT(10, data2->value);
  TEST_ASSERT_EQUAL_INT(10, data3->value);
}

void test_should_add_to_next_available() {
  char *key1 = "a";
  char *key2 = "k";

  int idx1 = hash_HashTable(key1, CAPACITY);
  int idx2 = hash_HashTable(key2, CAPACITY);

  TEST_ASSERT_NULL(ht->buckets[idx1]);
  TEST_ASSERT_NULL(ht->buckets[idx2 + 1]);

  add_HashTable(ht, key1, 10);
  add_HashTable(ht, key2, 10);

  DataHashTable *data1 = ht->buckets[idx1];
  DataHashTable *data2 = ht->buckets[idx2 + 1];

  TEST_ASSERT_NOT_NULL(data1);
  TEST_ASSERT_NOT_NULL(data2);

  TEST_ASSERT_EQUAL(key1, data1->key);
  TEST_ASSERT_EQUAL(key2, data2->key);

  TEST_ASSERT_EQUAL_INT(10, data1->value);
  TEST_ASSERT_EQUAL_INT(10, data2->value);
}

void setUp() { ht = init_HashTable(); }

void tearDown() { free_HashTable(ht); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_should_return_idx_from_key);
  RUN_TEST(test_should_add_value);
  RUN_TEST(test_should_add_multiple_values);
  RUN_TEST(test_should_add_to_next_available);

  UNITY_END();

  return 0;
}
