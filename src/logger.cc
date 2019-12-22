#include <stdarg.h>
#include <sys/time.h>
#include <time.h>
#include <stdarg.h>

#include "logger.h"

loglevel_map_t loglevel_map[LOG_TRACE + 1] = {
	{LOG_EMERG, "emerg"},
	{LOG_ALERT, "alert"},
	{LOG_CRIT, "crit"},
	{LOG_ERROR, "error"},
	{LOG_WARNING, "warning"},
	{LOG_NOTICE, "notice"},
	{LOG_INFO, "info"},
	{LOG_DEBUG, "debug"},
	{LOG_TRACE, "trace"},
};

char* log_level_str(loglevel_t l)
{
	if (l > LOG_TRACE) return loglevel_map[LOG_TRACE].name;
	return loglevel_map[l].name;
};


char* timestr()
{
	static char now_str[128]={0};
	struct timeval now = {0};
	struct tm pnow;
	gettimeofday(&now, NULL);
	localtime_r(&now.tv_sec, &pnow);
	snprintf(now_str, sizeof(now_str) - 1, "%d-%d-%d %02d:%02d:%02d.%06ld",pnow.tm_year + 1900, pnow.tm_mon + 1, pnow.tm_mday, pnow.tm_hour, pnow.tm_min, pnow.tm_sec, now.tv_usec);

	return now_str;
}

int screen_print(FILE *fp, const char *format, ...)  
{
	va_list args;
	va_start(args, format);
	int ret = vfprintf(fp, format, args);
	va_end(args);
	return ret;
}

int record(const char *format, ...) 
{
	va_list args;
	va_start(args, format);
	int ret = vfprintf(stdout, format, args);
	va_end(args);
	return ret;
}
