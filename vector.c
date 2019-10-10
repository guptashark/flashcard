#include <stdlib.h>

#include "vector.h"

struct vector {

	void **arr;
	size_t size;
	size_t capacity;
};

struct vector * 
vector_ctor
(void) {

	struct vector *v = malloc(sizeof(struct vector));
	v->size = 0;
	// calculate a good capacity;
	v->capacity = 16;
	v->arr = malloc(sizeof(void *) * v->capacity);
	return v;
}

// Can set the errno when out of range.
void *
vector_at
(struct vector *v, size_t pos) {
	return v->arr[pos];
}

// We will want to implement something like;
// operator[] at some point.
// TODO

void *
vector_front
(struct vector *v) {
	return v->arr[0];
}

void *
vector_back
(struct vector *v) {
	return v->arr[v->size - 1];
}

bool
vector_empty
(struct vector *v) {
	return (0 == v->size);
}

size_t
vector_size
(struct vector *v) {
	return v->size;
}

// Later implement more of nice to have vector features like:
// reserve, capacity, shrink_to_fit, etc.

void
vector_push_back
(struct vector *v, void *value) {
	
	if(v->size == v->capacity) {

		void **old_arr = v->arr;
		for(unsigned int i = 0; i < v->size; i++) {
			old_arr[i] = v->arr[i];
		}

		v->capacity += 16;
		v->arr = malloc(sizeof(void *) * v->capacity);
		
		for(unsigned int i = 0; i < v->size; i++) {
			v->arr[i] = old_arr[i];
		}
	}

	v->arr[v->size] = value;
	v->size++;
}

// has undefined behavior, in the sense that if you 
// pop back an empty vector, then it's pretty bad, 
// and the array is rendered completely useless, since
// the size less than 0 is intmax. 
void
vector_pop_back
(struct vector *v) {
	v->size--;	
}

void 
vector_dtor
(struct vector *v) {
	free(v->arr);
	free(v);
}
