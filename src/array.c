#include "array.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void shrink_array(Array *arr, int size) {
  if (size > (int)arr->capacity / 4) {
    return;
  }

  int new_capacity = (int)arr->capacity;

  while (size <= new_capacity / 4 && new_capacity > INITIAL_CAPACITY) {
    new_capacity >>= 1;
  }

  arr->data = (int *)realloc(arr->data, new_capacity * sizeof(int));

  arr->capacity = (unsigned int)new_capacity;
}

static void grow_array(Array *arr, int size) {
  if (size < (int)arr->capacity) {
    return;
  }

  int new_capacity = (int)arr->capacity;

  while (size >= new_capacity) {
    new_capacity <<= 1;
  }

  arr->data = (int *)realloc(arr->data, new_capacity * sizeof(int));

  arr->capacity = (unsigned int)new_capacity;
}

unsigned int is_empty(Array *arr) { return arr->size == 0; }

int at(Array *arr, int index) {
  int size = (int)arr->size;

  if (index >= size || size == 0) {
    return -1;
  }

  if (index < 0) {
    return *(arr->data + size + index);
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

unsigned int prepend(Array *arr, int value) { return insert(arr, 0, value); }

int pop(Array *arr) {
  if (arr->size == 0) {
    return 0;
  }

  unsigned int new_size = arr->size - 1;

  int item = *(arr->data + new_size);

  shrink_array(arr, new_size);

  arr->size = new_size;

  return item;
}

unsigned int delete_item(Array *arr, int index) {
  if (arr->size == 0 || index >= (int)arr->size) {
    return 0;
  }

  int item = *(arr->data + index);
  int size = arr->size - 1;

  if (index < 0) {
    index = arr->size + index;
  }

  for (int i = index; i < arr->size; i++) {
    if (i + 1 > (int)arr->size) {
      continue;
    }

    int *dest = arr->data + i;
    int *src = arr->data + i + 1;

    memmove(dest, src, sizeof(*src));
  }

  shrink_array(arr, size);
  arr->size = size;

  return item;
}
