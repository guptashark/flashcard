#ifndef __FC_SHELL_H__
#define __FC_SHELL_H__

#include <stdio.h>

#include "sstring.h"

struct fc_shell;

struct fc_shell *
fc_shell_ctor
(FILE *input, FILE *output);

int
fc_shell_insert
(struct fc_shell *fcs, struct string* s);

void
fc_shell_dtor
(struct fc_shell *sh);

#endif
