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

  int *ptr = (int *)realloc(vec->data, new_capacity * sizeof(int));

  if (ptr == NULL) {
    perror("Error resizing array data");
    free(ptr);
    return vec;
  }

  vec->data = ptr;
  vec->capacity = new_capacity;

  return vec;
}

int at(Vector *vec, int index) {
  if (vec == NULL) {
    perror("Vector have no data");

    return -1;
  }

  if (vec != NULL &&
      (index > vec->size - 1 || index < vec->capacity - vec->capacity * 2)) {
    return -1;
  }

  if (index < 0) {
    return vec->data[vec->capacity + (index)];
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

int insert(Vector *vec, int index, int item) {
  if (index < 0 || index > vec->size - 1) {
    perror("Index out of the range");
    return -1;
  }

  if (vec->size + 1 >= vec->capacity) {
    vec = resize(vec, vec->capacity);
  }

  int new = item;
  int old = *(vec->data + index);

  for (int i = index; i <= vec->size; i++) {
    old = *(vec->data + index);
    *(vec->data + index) = new;
    new = old;
  }

  vec->size++;

  return *(vec->data + index);
}

int prepend(Vector *vec, int item) {
  insert(vec, 0, item);

  return *(vec->data);
}
