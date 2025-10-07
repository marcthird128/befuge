// befuge/src/main/main.c
// Main Befuge entrypoint

#include <befuge/main/main.h>

int main(int argc, char** argv) {
	// Create a flags struct
	struct Flags flags;
	if (Flags_init(&flags) != ERROR_CODE_SUCCESS) {
		Flags_free(&flags);
		return get_error_code();
	}
	
	// Parse args
	if (Flags_parse_args(&flags, argc, argv) != ERROR_CODE_SUCCESS) {
		Flags_free(&flags);
		return get_error_code();
	}

	// Create the right engine
	if (flags.mode == FLAGS_MODE_INTERPRETER) {
		struct Interpreter interpreter;
		if (Interpreter_init(&interpreter, flags) != ERROR_CODE_SUCCESS) {
			Interpreter_free(&interpreter);
			return get_error_code();
		}
		
		if (Interpreter_run(&interpreter) != ERROR_CODE_SUCCESS) {
			Interpreter_free(&interpreter);
			return get_error_code();
		}

		Interpreter_free(&interpreter);
	} else {
		return ERROR_CODE_INVALID_STATE;
	}

	Flags_free(&flags);

	// Success
	return ERROR_CODE_SUCCESS;
}
