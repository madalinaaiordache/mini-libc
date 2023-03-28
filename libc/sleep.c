#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int sec)
{
    struct timespec req = { sec, 0 };
    struct timespec rem = { 0, 0 };

    while (nanosleep(&req, &rem) == -1)
        req = rem;

    return 0;
}