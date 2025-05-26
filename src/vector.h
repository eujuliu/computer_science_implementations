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

#endif
