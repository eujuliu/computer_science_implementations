#include "../unity/src/unity.h"
#include "hashtable.h"

#define CAPACITY 10

HASHTABLE(int, HashTable, CAPACITY);

HashTable *ht;

void test_should_return_idx_from_key() {
  uint hash = hash_HashTable("abc");

  TEST_ASSERT_LESS_THAN_UINT(CAPACITY, hash);
}

void test_should_add_value() {
  int idx = hash_HashTable("abc");
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

  int idx1 = hash_HashTable(key1);
  int idx2 = hash_HashTable(key2);
  int idx3 = hash_HashTable(key3);

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

  int idx1 = hash_HashTable(key1);

  TEST_ASSERT_NULL(ht->buckets[idx1]);
  TEST_ASSERT_NULL(ht->buckets[idx1 + 1]);

  add_HashTable(ht, key1, 10);
  add_HashTable(ht, key2, 10);

  DataHashTable *data1 = ht->buckets[idx1];
  DataHashTable *data2 = ht->buckets[idx1 + 1];

  TEST_ASSERT_NOT_NULL(data1);
  TEST_ASSERT_NOT_NULL(data2);

  TEST_ASSERT_EQUAL(key1, data1->key);
  TEST_ASSERT_EQUAL(key2, data2->key);

  TEST_ASSERT_EQUAL_INT(10, data1->value);
  TEST_ASSERT_EQUAL_INT(10, data2->value);
}

void test_should_get_value() {
  char *key1 = "a";

  add_HashTable(ht, key1, 10);

  DataHashTable *data = get_HashTable(ht, key1);

  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(key1, data->key, 1);
  TEST_ASSERT_EQUAL_INT(10, data->value);
}

void test_should_get_value_on_next_position() {
  char *key1 = "a";
  char *key2 = "k";

  add_HashTable(ht, key1, 10);
  add_HashTable(ht, key2, 10);

  DataHashTable *data1 = get_HashTable(ht, key1);
  DataHashTable *data2 = get_HashTable(ht, key2);

  TEST_ASSERT_NOT_NULL(data1);
  TEST_ASSERT_NOT_NULL(data2);

  TEST_ASSERT_EQUAL(key1, data1->key);
  TEST_ASSERT_EQUAL(key2, data2->key);

  TEST_ASSERT_EQUAL_INT(10, data1->value);
  TEST_ASSERT_EQUAL_INT(10, data2->value);
}

void test_should_value_exists() {
  char *key1 = "a";

  add_HashTable(ht, key1, 10);

  TEST_ASSERT_EQUAL_INT(1, exists_HashTable(ht, key1));
}

void test_should_remove_value() {
  char *key1 = "a";

  add_HashTable(ht, key1, 10);

  TEST_ASSERT_EQUAL_INT(1, exists_HashTable(ht, key1));

  int8_t removed = remove_HashTable(ht, key1);

  TEST_ASSERT_EQUAL_INT(1, removed);
}

void test_should_remove_value_on_next_position() {
  char *key1 = "a";
  char *key2 = "k";

  add_HashTable(ht, key1, 10);
  add_HashTable(ht, key2, 10);

  int8_t removed = remove_HashTable(ht, key2);

  TEST_ASSERT_EQUAL_INT(1, removed);

  int idx1 = hash_HashTable(key1);

  TEST_ASSERT_NULL(ht->buckets[idx1 + 1]);
}

void setUp() { ht = init_HashTable(); }

void tearDown() { free_HashTable(ht); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_should_return_idx_from_key);
  RUN_TEST(test_should_add_value);
  RUN_TEST(test_should_add_multiple_values);
  RUN_TEST(test_should_add_to_next_available);
  RUN_TEST(test_should_get_value);
  RUN_TEST(test_should_get_value);
  RUN_TEST(test_should_get_value_on_next_position);
  RUN_TEST(test_should_value_exists);
  RUN_TEST(test_should_remove_value);
  RUN_TEST(test_should_remove_value_on_next_position);

  UNITY_END();

  return 0;
}
