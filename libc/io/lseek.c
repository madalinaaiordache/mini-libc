/* SPDX-License-Identifier: BSD-3-Clause */

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	 off_t new_offset = -1;

    switch (whence) {
        case SEEK_SET:
            new_offset = offset;
            break;
        case SEEK_CUR:
            new_offset = syscall(8, fd, 0, SEEK_CUR) + offset;
            break;
        case SEEK_END:
            new_offset = syscall(8, fd, 0, SEEK_END) + offset;
            break;
        default:
            /* Unsupported whence value */
            errno = EINVAL;
            return -1;
    }

    /* Call the system call to set the file offset */
    new_offset = syscall(8, fd, new_offset, SEEK_SET);

    if (new_offset < -1) {
        /* An error occurred, set errno */
        errno = - new_offset;
        return -1;
    }

    /* Success */
    return new_offset;
}
