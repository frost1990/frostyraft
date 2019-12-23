#ifndef _RAFT_H_
#define _RAFT_H_

/* Definition for a raft endpoint */
typedef struct raft {
	uint64_t id;
	char ifname[16];
	char ipv4[16];
	char uuid[37];
} raft_t;

int init_raft(raft_t *r);

#endif 
