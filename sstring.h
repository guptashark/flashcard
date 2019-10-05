#ifndef __SSTRING_H__
#define __SSTRING_H__

#include <stdint.h>
#include <stdbool.h>

// smart string library
// doing some fun things with the types - 
// guarantee that it's exactly a byte, 
// or a 4 byte int. 

// TODO : should we... fix this? And use standard types? 

struct string { 

	// the 	
	uint32_t size;
	uint32_t capacity;
	char *arr;
};

// the headers are going to be largely similar to string.h

void 
string_init
(struct string *s);

void
string_init_literal
(struct string *s, const char *str);

void
string_init_copy
(struct string *s, const struct string *src);

// Can set the errno when out of range.
void *
string_at
(struct string *s, unsigned int pos);


// We will want to implement something like;
// operator[] at some point.
// TODO

void *
string_front
(struct string *s);

void *
string_back
(struct string *s);

bool
string_empty
(struct string *s);

unsigned int
string_size
(struct string *s);

// Later implement more of nice to have string features like: 
// reserve, capacity, shrink_to_fit, etc. 

void
string_push_back
(struct string *s, void *value);

void
string_pop_back
(struct string *s);

int
string_fprintf
(struct string *s, FILE *f);

int
string_printf
(struct string *s);

void 
string_uninitialize
(struct string *s);

#endif
