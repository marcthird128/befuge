// befuge/include/befuge/main/error.h

#ifndef _BEFUGE_MAIN_ERROR_H
#define _BEFUGE_MAIN_ERROR_H

#define ERROR_CODE_SUCCESS 0
#define ERROR_CODE_INVALID_STATE 1
#define ERROR_CODE_INVALID_ARGUMENT 2

int get_error_code(void);
int set_error_code(int code);

#endif
