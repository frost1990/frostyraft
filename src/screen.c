#include <stdarg.h>
#include <sys/time.h>
#include <time.h>

#include "screen.h"

char* timestr()
{
	static char now_str[128]={0};
	struct timeval now = {0};
	struct tm pnow;
	gettimeofday(&now, NULL);
	localtime_r(&now.tv_sec, &pnow);
	snprintf(now_str, sizeof(now_str) - 1, "%d-%d-%d %02d:%02d:%02d %06ld",pnow.tm_year + 1900, pnow.tm_mon + 1, pnow.tm_mday, pnow.tm_hour, pnow.tm_min, pnow.tm_sec, now.tv_usec);

	return now_str;
}

int screen_print(const char *color, FILE *fp, const char *format, ...)  
{
	va_list args;
	va_start(args, format);
	int ret = vfprintf(fp, format, args);
	va_end(args);
	return ret;
}
