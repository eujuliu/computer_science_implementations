#ifndef VECTOR_H
#define VECTOR_H

#define INITIAL_CAPACITY 16  /**< Default initial capacity for a new vector */

/**
 * @brief Dynamic array structure for integers.
 */
typedef struct {
  int size;      /**< Number of elements currently in the vector */
  int capacity;  /**< Allocated capacity of the vector */
  int *data;     /**< Pointer to the array of elements */
} Vector;

/**
 * @brief Returns the element at the specified index.
 * @param vec Pointer to the vector.
 * @param index Index of the element to retrieve.
 * @return The element at the given index, or -1 if out of bounds.
 */
int at(Vector *vec, int index);

/**
 * @brief Adds an item to the end of the vector.
 * @param vec Pointer to the vector.
 * @param value The value to add.
 * @return 0 on success, -1 on failure.
 */
int push(Vector *vec, int value);

/**
 * @brief Removes and returns the last element of the vector.
 * @param vec Pointer to the vector.
 * @return The removed element, or -1 if the vector is empty.
 */
int pop(Vector *vec);

/**
 * @brief Inserts an item at the specified index.
 * @param vec Pointer to the vector.
 * @param index Index at which to insert the item.
 * @param item The value to insert.
 * @return 0 on success, -1 on failure.
 */
int insert(Vector *vec, int index, int item);

/**
 * @brief Inserts an item at the beginning of the vector.
 * @param vec Pointer to the vector.
 * @param item The value to insert.
 * @return 0 on success, -1 on failure.
 */
int prepend(Vector *vec, int item);

/**
 * @brief Deletes the item at the specified index.
 * @param vec Pointer to the vector.
 * @param index Index of the item to delete.
 * @return 0 on success, -1 on failure.
 */
int delete_it(Vector *vec, int index);

/**
 * @brief Removes the first occurrence of the specified item.
 * @param vec Pointer to the vector.
 * @param item The value to remove.
 * @return 0 on success, -1 if the item was not found.
 */
int remove_it(Vector *vec, int item);

/**
 * @brief Finds the index of the first occurrence of the specified item.
 * @param vec Pointer to the vector.
 * @param item The value to find.
 * @return The index of the item, or -1 if not found.
 */
int find(Vector *vec, int item);

/**
 * @brief Resizes the vector to the specified new size.
 * @param vec Pointer to the vector.
 * @param new_size The new capacity for the vector.
 * @return Pointer to the resized vector, or NULL on failure.
 */
Vector *resize(Vector *vec, int new_size);

#endif
