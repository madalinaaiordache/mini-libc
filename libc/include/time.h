/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STDIO_H__
#define __STDIO_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long int tv_sec;
    long tv_nsec;
};

/* TODO: Add sleep/nanosleep declaration. */
int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int sec);

#ifdef __cplusplus
}
#endif

#endif
