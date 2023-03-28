// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return NULL;
	mem_list_add(ptr, size);
	if (ptr == NULL) {
		exit(1);
	}
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return NULL;
	mem_list_add(ptr, nmemb * size);
	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
		return;
	munmap(ptr, mem_list_find(ptr)->len);
	mem_list_del(ptr);

	
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL) {
        /* ptr does not belong to any memory region that was allocated by us */
        return NULL;
    }

    if (size <= item->len) {
        /* We can just shrink the existing memory region */
        return ptr;
    }

    void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_ptr == MAP_FAILED) {
        return NULL;
    }

    /* Copy the old data to the new region */
    memcpy(new_ptr, ptr, item->len);

    /* Free the old memory region */
    mem_list_del(ptr);

    /* Add the new memory region to our list */
    mem_list_add(new_ptr, size);

    return new_ptr;
}


void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb == 0 || size == 0)
		return NULL;
	size_t new_size = nmemb * size;
	if (new_size / nmemb != size)
		return NULL;
	return realloc(ptr, new_size);
}
