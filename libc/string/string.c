/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	// return if no memory is allocated to the destination
    if (destination == NULL) {
        return NULL;
    }
 
    // take a pointer pointing to the beginning of the destination string
    char *ptr = destination;
 
    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    // include the terminating null character
    *destination = '\0';
 
    // the destination is returned by standard `strcpy()`
    return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

    size_t i = 0;
	/* Copy up to len characters from source to destination */
    for (i = 0; i < len && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    /* Pad the remaining space with null characters */
    for (; i < len; i++) {
        destination[i] = '\0';
    }

    return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	 // make `ptr` point to the end of the destination string
    char* ptr = destination + strlen(destination);
 
    // appends characters of the source to the destination string
    while (*source != '\0') {
        *ptr++ = *source++;
    }
 
    // null terminate destination string
    *ptr = '\0';
 
    // the destination is returned by standard `strcat()`
    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	// make `ptr` point to the end of the destination string
    char* ptr = destination + strlen(destination);
 
    // Appends characters of the source to the destination string
    while (*source != '\0' && len--) {
        *ptr++ = *source++;
    }
 
    // null terminate destination string
    *ptr = '\0';
 
    // destination string is returned by standard `strncat()`
    return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
    while (*str1)
    {
        // if characters differ, or end of the second string is reached
        if (*str1 != *str2) {
            break;
        }
 
        // move to the next pair of characters
        str1++;
        str2++;
    }
 
    // return the ASCII difference after converting `char*` to `unsigned char*`
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while ( len && *str1 && ( *str1 == *str2 ) )
    {
        ++str1;
        ++str2;
        --len;
    }
    if ( len == 0 )
    {
        return 0;
    }
    else
    {
        return ( *(unsigned char *)str1 - *(unsigned char *)str2 );
    }
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	 const char *last = NULL;
    while (*str != '\0') {
        if (*str == c) {
            last = str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return (char *)last;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    /* If str2 is empty, return str1 */
    if (len2 == 0) {
        return (char *) str1;
    }

    /* Search for str2 in str1 */
    for (size_t i = 0; i <= len1 - len2; i++) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            return (char *) str1 + i;
        }
    }

    /* If str2 is not found in str1, return NULL */
    return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	const char *p1, *p2;
    size_t len2 = strlen(str2);
    if (!len2) {
        return (char *)str1;
    }
    char *last_occurrence = NULL;
    for (p1 = str1; *p1 != '\0'; p1++) {
        if (*p1 == *str2) {
            for (p2 = str2; ; p1++, p2++) {
                if (*p2 == '\0') {
                    last_occurrence = (char *)(p1 - len2);
                }
                if (*p1 != *p2) {
                    break;
                }
            }
            p1 -= p2 - str2;
        }
    }
    return last_occurrence;
}


void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	char *dst = (char *)destination;
    const char *src = (const char *)source;
    while (num--) {
        *dst++ = *src++;
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
 	char *dst = (char *)destination;
    const char *src = (const char *)source;
    if (src < dst) {
        for (src += num, dst += num; num--; ) {
            *--dst = *--src;
        }
    } else {
        while (num--) {
            *dst++ = *src++;
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;
    while (num--) {
        if (*p1 != *p2) {
            return (*p1 < *p2) ? -1 : 1;
        }
        p1++;
        p2++;
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *p = (unsigned char *)source;
    while (num--) {
        *p++ = (unsigned char)value;
    }
    return source;
}
