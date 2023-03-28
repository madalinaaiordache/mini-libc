/* SPDX-License-Identifier: BSD-3-Clause */

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

int open(const char *filename, int flags, ...)
{
	// /* TODO: Implement open system call. */
	int r;

    /* Use the variadic version of open if O_CREAT is set */
    if (flags & O_CREAT) {
        /* Extract the mode argument from the variable argument list */
        va_list ap;
        mode_t mode;

        va_start(ap, flags);
        mode = va_arg(ap, mode_t);
        va_end(ap);

        r = syscall(2, filename, flags, mode);
    } else {
        r = syscall(2, filename, flags);
    }

    if (r< 0) {
        // Set errno on error and return -1
        errno = -r;
        return -1;
    }

    return r;
}
