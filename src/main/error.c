// befuge/src/main/error.c
// Error code handling

#include <befuge/main/error.h>

// Store the error code
static int error_code = 0;

// Get it
int get_error_code(void) {
	return error_code;
}

// Set it, and return the code
int set_error_code(int code) {
	error_code = code;
	return code;
}
