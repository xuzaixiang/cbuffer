//
// Created by xuzaixiang on 2023/2/12.
//

#include "cbuffer_mem.h"
#include <malloc.h>

void *(*s_cbuffer_malloc)(size_t) = malloc;
void (*s_cbuffer_free)(void *) = free;
void *(*s_cbuffer_realloc)(void *, size_t) = realloc;

void cbuffer_mem_malloc(void *(*malloc)(size_t)) {
    if (NULL != malloc) {
        s_cbuffer_malloc = malloc;
    }
}
void cbuffer_mem_free(void (*free)(void *)) {
    if (NULL != free) {
        s_cbuffer_free = free;
    }
}
void cbuffer_mem_realloc(void *(*realloc)(void *, size_t)) {
    if (NULL != realloc) {
        s_cbuffer_realloc = realloc;
    }
}
void *cbuffer_malloc(size_t size) {
    return s_cbuffer_malloc(size);
}
void *cbuffer_realloc(void *ptr, size_t size) {
    return s_cbuffer_realloc(ptr, size);
}
void cbuffer_free(void *ptr) {
    s_cbuffer_free(ptr);
}