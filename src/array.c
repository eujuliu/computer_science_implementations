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

void shrink_array(Array *arr, int size) {
  if (size > arr->capacity / 3) {
    return;
  }

  int new_capacity = arr->capacity;

  while (size <= new_capacity / 3 && new_capacity > 8) {
    new_capacity >>= 1;
  }

  arr->data = (int *)realloc(arr->data, new_capacity * sizeof(int));

  arr->capacity = new_capacity;
  arr->size = size;
}

void grow_array(Array *arr, int size) {
  if (size < arr->capacity) {
    return;
  }

  int new_capacity = arr->capacity;

  while (size >= new_capacity) {
    new_capacity <<= 1;
  }

  arr->data = (int *)realloc(arr->data, new_capacity * sizeof(int));

  arr->capacity = new_capacity;
  arr->size = size;
}

unsigned int is_empty(Array *arr) { return arr->size == 0; }

int at(Array *arr, unsigned int index) {
  if (index >= arr->size) {
    return -1;
  }

  return *(arr->data + index);
}

unsigned int set(Array *arr, unsigned int index, int value) {
  if (index >= arr->size) {
    return 0;
  }

  *(arr->data + index) = value;

  return 1;
}

void push(Array *arr, int value) {
  grow_array(arr, arr->size + 1);

  *(arr->data + arr->size) = value;
  arr->size += 1;
}

unsigned int insert(Array *arr, unsigned int index, int value) {
  if (index >= arr->size + 1) {
    return 0;
  }

  grow_array(arr, arr->size + 1);

  if (index == arr->size) {
    push(arr, value);
    return 1;
  }

  int new_value = value;

  for (int i = index; i < arr->size + 1; i++) {
    int old_value = *(arr->data + i);
    *(arr->data + i) = new_value;
    new_value = old_value;
  }

  arr->size += 1;

  return 1;
}

unsigned int prepend(Array *arr, int value) { insert(arr, 0, value); }
