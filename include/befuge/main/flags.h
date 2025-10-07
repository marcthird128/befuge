// befuge/include/befuge/main/flags.h

#ifndef _BEFUGE_MAIN_FLAGS_H
#define _BEFUGE_MAIN_FLAGS_H

#include <stdio.h>
#include <string.h>
#include <befuge/main/error.h>

#define FLAGS_STATE_NONE 0

#define FLAGS_MODE_INTERPRETER 0
#define FLAGS_MODE_DEBUGGER 1`

struct Flags {
	int mode;
	const char* src;
};

int Flags_init(struct Flags* self);

void Flags_free(struct Flags* self);

int Flags_parse_args(struct Flags* self, int argc, char** argv);

#endif
