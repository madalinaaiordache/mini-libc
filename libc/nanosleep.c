#include <time.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long result;
    do {
        result = syscall(__NR_nanosleep, req, rem);
    } while (result == -1 && errno == EINTR);

    return result;
}
