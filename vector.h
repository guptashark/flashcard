#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>
#include <stdlib.h>

struct vector *
vector_ctor
(void);

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

size_t
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
vector_dtor
(struct vector *v);

#endif
