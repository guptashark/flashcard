#ifndef __SSTRING_H__
#define __SSTRING_H__

#include <stdint.h>
#include <stdbool.h>

// make visible a string pointer, and not much else.
struct string;

// the headers are going to be largely similar to
// string.h for C++

///////////////////////////////////
// constructors and destructors
///////////////////////////////////

// 1: default constructor
struct string *
string_ctor_default
(void);

// 5: literal constructor
struct string *
string_ctor_literal
(const char *lit);

// 7: copy constructor
// TODO is the const right? should there be more?
struct string *
string_ctor_copy
(const struct string *t);

void
string_dtor
(struct string *s);

// it's weird that in the C++ stl the return type
// is the string itself. Perhaps to maintain
// consistency with the operator= function?
struct string *
string_assign_literal
(struct string *s, const char *lit);

//////////////////////
// element access
//////////////////////

//////////////////////
// capacity
//////////////////////

// empty
bool
string_empty
(struct string *s);

// size
size_t
string_size
(struct string *s);

// length
size_t
string_length
(struct string *s);

//////////////////////
// operations
//////////////////////

// compare
int
string_compare_string
(struct string *s, struct string *t);

int
string_compare_literal
(struct string *s, const char *t);

//////////////////////
// file ops
//////////////////////

// we're using C style vs C++ style output.

int
string_fprintf
(FILE *f, struct string *s);

int
string_printf
(struct string *s);

// As of right now, we're fine with not having
// the stdin and stdout versions, since we want
// some basic working functionality

#endif
