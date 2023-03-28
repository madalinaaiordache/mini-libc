/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement lseek(). */
	 int r;

    r = syscall(3, fd);

    if (r == -1)
        errno = EBADF;

    return r;
}
