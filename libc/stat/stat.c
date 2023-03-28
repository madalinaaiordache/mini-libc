/* SPDX-License-Identifier: BSD-3-Clause */

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	/* Use the stat system call to retrieve the file information */
    int r = syscall(4, path, buf);

    /* If the system call fails, set errno appropriately and return -1 */
    if (r == -1) {
        switch (errno) {
            case EACCES:
            case EBADF:
            case EFAULT:
            case EINVAL:
            case ENAMETOOLONG:
            case ENOENT:
            case ENOMEM:
            case ENOTDIR:
                break;
            default:
                errno = EIO;
                break;
        }
        return -1;
    }

    if (r < -1) {
        /* An error occurred, set errno */
        errno = - r;
        return -1;
    }

    return 0;
}
