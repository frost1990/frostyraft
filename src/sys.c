#include <sys/syscall.h>

#include "sys.h"

pid_t gettid() {
	return syscall(SYS_gettid);
}

