#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>

struct vector {

	void **arr;
	unsigned int size;
	unsigned int capacity;
};

// no ctor, just an init since we 
// typically know when we're going 
// to be using a vector, and don't 
// need to be creating one on the 
// heap. 
//
// Obviously, if things get too 
// hairy, and we're creating 
// lots of vectors left and right, 
// we can switch the implementation 
// to be a ctor with putting stuff
// on the heap instead of the stack.

void 
vector_init
(struct vector *v);

// Can set the errno when out of range.
void *
vector_at
(struct vector *v, unsigned int pos);


// We will want to implement something like;
// operator[] at some point.
// TODO

void *
vector_front
(struct vector *v);

void *
vector_back
(struct vector *v);

bool
vector_empty
(struct vector *v);

unsigned int
vector_size
(struct vector *v);

// Later implement more of nice to have vector features like: 
// reserve, capacity, shrink_to_fit, etc. 

void
vector_push_back
(struct vector *v, void *value);

void
vector_pop_back
(struct vector *b);

void 
vector_uninitialize
(struct vector *v);

#endif
