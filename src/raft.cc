#include <string.h>
#include <uuid/uuid.h>

#include "raft.h"
#include "sknet.h"
#include "logger.h"

int init_raft(raft_t *r) 
{
	/* Use eth0's first ip by default */
	strncpy(r->ifname, "eth0", sizeof(r->ifname) - 1);
	if (sk_get_local_ipv4(r->ifname, r->ipv4) != 0) {
		error("cannot get local ipv4 address %m");
		return -1;
	}

	/* Generate uuid for a raft endpoint */
	uuid_t binuuid;
    uuid_generate_random(binuuid);
    uuid_unparse_lower(binuuid, r->uuid);
    uuid_unparse(binuuid, r->uuid);

	return 0;
}
