/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement lseek(). */
	 int result = syscall(5, fd, st);
    if (result < 0) {
        // The system call failed, so set errno appropriately and return -1.
        errno = EBADF;  // or another appropriate error code
        return -1;
    }
    // The system call succeeded, so return 0 to indicate success.
    return 0;
}