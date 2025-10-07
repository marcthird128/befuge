// befuge/src/main/flags.c
// Handles Flags struct and parsing arguments

#include <befuge/main/flags.h>

int Flags_init(struct Flags* self) {
	self->mode = FLAGS_MODE_INTERPRETER;
	self->src = "main.bf";

	return ERROR_CODE_SUCCESS;
}

void Flags_free(struct Flags* self) {
	return;
}

int Flags_parse_args(struct Flags* self, int argc, char** argv) {
	int state = FLAGS_STATE_NONE;

	for (int i=1; i<argc; i++) {
		const char* arg = argv[i];

		// Handle the current state
		if (state == FLAGS_STATE_NONE) {
			if (arg[0] == '-') {
				arg++; // Skip the option indicator
				
				// Handle options
			} else {
				// Source file
				if (self->src != NULL) {
					printf("error: multiple input files\n");
					return set_error_code(ERROR_CODE_INVALID_ARGUMENT);
				} else {
					self->src = arg;
				}
			}
		} else {
			return ERROR_CODE_INVALID_STATE;
		}
	}

	return ERROR_CODE_SUCCESS;
}
