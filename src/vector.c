#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int at(Vector *vec, int index) {
  if (vec == NULL || (vec != NULL && index > vec->size - 1)) {
    return -1;
  }

  return vec->data[index];
}

int push(Vector *vec, int value) {
  if (vec->size + 1 >= vec->capacity) {
    int new_capacity = vec->capacity * 2;
    int *new_ptr = (int *)malloc(new_capacity * sizeof(int));

    if (new_ptr == NULL) {
      perror("Error when extending memory for new item");

      return -1;
    }

    for (int i = 0; i < vec->size; i++) {
      *(new_ptr + i) = *(vec->data + i);
    }

    free(vec->data);

    vec->data = new_ptr;
    vec->capacity = new_capacity;
  }

  *(vec->data + vec->size) = value;
  vec->size += 1;

  return *(vec->data + vec->size -1);
}

int pop(Vector *vec) {
  int index = vec->size - 1;
  int *value = (int *)malloc(sizeof(int));
  *value = *(vec->data + index);

  *(vec->data + index) = 0;
  vec->size = index;

  if (vec->size / 4 < vec->capacity / 2 && vec->capacity > 16) {
    int new_capacity = vec->capacity / 2;
    int *new_ptr = (int *)malloc(new_capacity * sizeof(int));

    if (new_ptr == NULL) {
      perror("Error when shrinking memory for pop item");

      return -1;
    }

    for (int i = 0; i < vec->size; i++) {
      *(new_ptr + i) = *(vec->data + i);
    }

    free(vec->data);

    vec->data = new_ptr;
    vec->capacity = new_capacity;
  }

  return *value;
}
