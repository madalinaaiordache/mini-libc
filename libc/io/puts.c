#include <stdio.h>

int puts(const char *s) {
    int n = 0;
    while (*s != '\0') {
        if (write(1, s, 1) == -1) {
            return -1;
        }
        n++;
        s++;
    }
    if (write(1, "\n", 1) == -1) {
        return -1;
    }
    n++;
    return n;
}