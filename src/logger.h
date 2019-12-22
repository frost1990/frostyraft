#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sys.h"

#define SCREEN_LOGSIZE 2048
#define LOG_MAX_LINE 2048

/* Font color */
#define SCREEN_BLACK 			"30m"
#define SCREEN_RED				"31m"
#define SCREEN_GREEN 			"32m"
#define SCREEN_YELLOW 			"33m"
#define SCREEN_BLUE 			"34m"
#define SCREEN_PURPLE 			"35m"
#define SCREEN_DARK_GREEN 		"36m"
#define SCREEN_WHITE 			"37m"

/* Background color */
#define SCREEN_BG_BLACK 		"40"
#define SCREEN_BG_RED 			"41"
#define SCREEN_BG_GREEN 		"42"
#define SCREEN_BG_BLUE 			"43"
#define SCREEN_BG_YELLOW 		"44"
#define SCREEN_BG_PURPLE 		"45"
#define SCREEN_BG_DARK_GREEN 	"46"
#define SCREEN_BG_WHITE 		"47"

#define CONCAT(a, b)  a b 

#define COLOR_SET(color) CONCAT("\033[", color)
#define COLOR_DISABLE "\033[0m"

int screen_print(const char *color, FILE *fp, const char *format, ...); 
int record(const char *format, ...);
char* timestr();

typedef enum {
	LOG_EMERG = 0,
	LOG_ALERT,
	LOG_CRIT,
	LOG_ERROR,
	LOG_WARNING,
	LOG_NOTICE,
	LOG_INFO,
	LOG_DEBUG,
	LOG_TRACE,
} loglevel_t;

typedef struct {
	loglevel_t level;
	const char *name;
} loglevel_map_t;


#define SCREEN(color, fp, format, vargs...) do { \
	char fmt[SCREEN_LOGSIZE] = {0}; \
	snprintf(fmt, SCREEN_LOGSIZE - 1, "%s%s %s %s:%d %s%s\n",  COLOR_SET(color), timestr(), __FILE__, __func__, __LINE__, format, COLOR_DISABLE);\
	screen_print(color, fp, fmt, ##vargs); \
} while (0);

#define info(format, vargs...) do { \
	if (LOG_INFO < LOG_INFO) break; \
	char logfmt[LOG_MAX_LINE] = {0};\
	snprintf(logfmt, LOG_MAX_LINE- 1, "%s %s %s:%d %d %s\n", timestr(), __FILE__, __func__, __LINE__, gettid(), format);\
	record(logfmt, ##vargs); \
} while (0);

#endif
