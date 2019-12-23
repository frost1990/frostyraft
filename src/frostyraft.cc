#include <stdio.h>

#include "logger.h"
#include "raft.h"


int main(int argc, char** argv) 
{
	raft_t r;
	init_raft(&r);
	
	info("%s %s start frostyraft now", r.ipv4, r.uuid);
	return 0;
}
