#include "array.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

Array *new_array(int *values, unsigned int size) {
  size_t ic = INITIAL_CAPACITY;

  while (ic < size) {
    ic <<= 1;
  }

  int *data = (int *)malloc(ic * sizeof(int));

  if (data == NULL) {
    perror(DATA_POINTER_ERROR);
    return NULL;
  }

  Array *arr = (Array *)malloc(sizeof(Array));

  if (arr == NULL) {
    free(data);
    perror(ARRAY_POINTER_ERROR);
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    *(data + i) = *(values + i);
  }

  arr->capacity = INITIAL_CAPACITY;
  arr->size = size;
  arr->data = data;

  return arr;
}

void free_array(Array *arr) {
  free(arr->data);
  free(arr);
}

unsigned int is_empty(Array *arr) { return arr->size == 0; }
