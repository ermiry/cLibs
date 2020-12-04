#ifndef _UTILS_LOG_H_
#define _UTILS_LOG_H_

#include <stdio.h>

#define LOG_COLOR_RED       "\x1b[31m"
#define LOG_COLOR_GREEN     "\x1b[32m"
#define LOG_COLOR_YELLOW    "\x1b[33m"
#define LOG_COLOR_BLUE      "\x1b[34m"
#define LOG_COLOR_MAGENTA   "\x1b[35m"
#define LOG_COLOR_CYAN      "\x1b[36m"
#define LOG_COLOR_RESET     "\x1b[0m"

typedef enum LogType {

	LOG_NO_TYPE             = 0,

	LOG_ERROR               = 1,
	LOG_WARNING             = 2,
	LOG_SUCCESS             = 3,
	LOG_DEBUG               = 4,
	LOG_TEST                = 5,

} LogType;

extern void log_msg (FILE *__restrict __stream, LogType first_type, LogType second_type,
	const char *msg);

// prints a red error message to stderr
extern void log_error (const char *msg);

// prints a yellow warning message to stderr
extern void log_warning (const char *msg);

// prints a green success message to stdout
extern void log_success (const char *msg);

// prints a debug message to stdout
extern void log_debug (const char *msg);

#endif