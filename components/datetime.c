/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

#define SECONDS_IN_AN_HOUR 3600

const char *
datetime(const char *fmt)
{
	time_t t;

	t = time(NULL);
	if (!strftime(buf, sizeof(buf), fmt, localtime(&t))) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}

const char *
datetime_hour(const char * hdiff)
{
	time_t t;

	t = time(NULL) + (time_t) atoi(hdiff) * SECONDS_IN_AN_HOUR;

	if (!strftime(buf, sizeof(buf), "%H:%M", localtime(&t))) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}