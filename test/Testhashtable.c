#include "../unity/src/unity.h"
#include "hashtable.h"

HASHTABLE(int, HashTable, 10);

HashTable *ht;

void test_hashtable_hash_function_return_different_values() {
  uint hash1 = hash_HashTable("abc");
  uint hash2 = hash_HashTable("cab");
  uint hash3 = hash_HashTable("bca");

  TEST_ASSERT_NOT_EQUAL_UINT(hash1, hash2);
  TEST_ASSERT_NOT_EQUAL_UINT(hash2, hash3);
}

void test_hashtable_get_index_return_equal_index() {
  uint hash1 = hash_HashTable("abc");
  uint hash2 = hash_HashTable("abc");

  uint idx1 = get_indexHashTable(hash1);
  uint idx2 = get_indexHashTable(hash2);

  TEST_ASSERT_EQUAL_UINT(idx1, idx2);
}

void setUp() { ht = init_HashTable(); }

void tearDown() { free_HashTable(ht); }

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_hashtable_hash_function_return_different_values);
  RUN_TEST(test_hashtable_get_index_return_equal_index);

  UNITY_END();

  return 0;
}
