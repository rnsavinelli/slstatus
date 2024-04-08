/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

static const char *
__datetime_formatter(const char *fmt, struct tm * converter()){	
	time_t t = time(NULL);

	if (!strftime(buf, sizeof(buf), fmt, converter(&t))) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}

static struct tm * artime(const time_t *_t){
	const time_t art = *_t + ((-3) * 3600);
	return gmtime(&art);
}

const char *
datetime(const char *fmt)
{
	return __datetime_formatter(fmt, localtime);
}

const char *
datetime_utc(const char *fmt)
{
	return __datetime_formatter(fmt, gmtime);
}

const char *
datetime_arg(const char *fmt)
{
	return __datetime_formatter(fmt, artime);
}