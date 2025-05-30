#ifndef VECTOR_H
#define VECTOR_H

#define INITIAL_CAPACITY 16

typedef struct {
  int size;
  int capacity;
  int *data;
} Vector;

int at(Vector *vec, int index);
int push(Vector *vec, int value);
int pop(Vector *vec);
int insert(Vector *vec, int index, int item);
int prepend(Vector *vec, int item);
// int delete(Vector *vec, int index);
// int remove(Vector *vec, int item);
// int find(Vector *vec, int item);
Vector *resize(Vector *vec, int new_size);

#endif
