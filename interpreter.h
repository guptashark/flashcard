#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

struct interpreter *
interpreter_ctor(void);

void
interpreter_run
(struct interpreter *inptr);

void
interpreter_dtor
(struct interpreter *inptr);

#endif
