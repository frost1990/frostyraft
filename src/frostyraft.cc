#include <stdio.h>
#include <unistd.h>

#include "logger.h"
#include "raft.h"


int main(int argc, char** argv) 
{
	raft_t r;
	if (init_raft(&r) != 0) exit(EXIT_FAILURE);
	
	info("%s %s start frostyraft now", r.ipv4, r.uuid);
	return 0;
}
