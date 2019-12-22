#include <stdio.h>

#include "screen.h"
#include "sknet.h"

static char myipv4[16];

int main(int argc, char** argv) 
{
	sk_get_local_ipv4("eth0", myipv4);
	SCREEN(SCREEN_GREEN, stdout, "%s start frostyraft nows", myipv4);
	return 0;
}
