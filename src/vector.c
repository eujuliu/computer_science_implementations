#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *resize(Vector *vec, int new_size) {
  int new_capacity = vec->capacity;

  if (new_size <= vec->capacity / 4 && vec->capacity > 16) {
    new_capacity = vec->capacity / 2;
  } else if (new_size >= vec->capacity) {
    new_capacity = vec->capacity * 2;
  } else {
    return vec;
  }

  int *new_ptr = (int *)malloc(new_capacity * sizeof(int));

  if (new_ptr == NULL) {
    perror("Error trying to shrink array capacity");

    return vec;
  }

  for (int i = 0; i < vec->size; i++) {
    *(new_ptr + i) = *(vec->data + i);
  }

  free(vec->data);

  vec->data = new_ptr;
  vec->capacity = new_capacity;

  return vec;
}

int at(Vector *vec, int index) {
  if (vec == NULL || (vec != NULL && index > vec->size - 1)) {
    return -1;
  }

  return vec->data[index];
}

int push(Vector *vec, int value) {
  vec = resize(vec, vec->size + 1);

  *(vec->data + vec->size) = value;
  vec->size += 1;

  return *(vec->data + vec->size - 1);
}

int pop(Vector *vec) {
  int index = vec->size - 1;
  int *value = (int *)malloc(sizeof(int));
  *value = *(vec->data + index);

  *(vec->data + index) = 0;
  vec->size = index;

  vec = resize(vec, vec->size);

  return *value;
}
