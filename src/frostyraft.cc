#include <stdio.h>

#include "logger.h"
#include "sknet.h"

static char myipv4[16];

int main(int argc, char** argv) 
{
	sk_get_local_ipv4("eth0", myipv4);
	SCREEN(SCREEN_GREEN, stdout, "%s start frostyraft now", myipv4);
	info("%s start frostyraft now", myipv4);
	return 0;
}
