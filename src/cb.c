//
// Created by xuzaixiang on 2023/2/10.
//

#include "cb_struct.h"
#include <cbuffer/cbuffer.h>
#include <malloc.h>
#include <string.h>

void *(*cbuffer_malloc)(size_t) = malloc;
void (*cbuffer_free)(void *) = free;
void *(*cbuffer_realloc)(void *, size_t) = realloc;

void cbuffer_fun_malloc(void *(*malloc)(size_t)) {
    cbuffer_malloc = malloc;
}

void cbuffer_fun_free(void (*free)(void *)) {
    cbuffer_free = free;
}

void cbuffer_fun_realloc(void *(*realloc)(void *, size_t)) {
    cbuffer_realloc = realloc;
}

cbuffer_t *cbuffer_create() {
    cbuffer_t *buffer = cbuffer_malloc(sizeof(cbuffer_t));
    memset(buffer, 0, sizeof(cbuffer_t));
    return buffer;
}

void cbuffer_destroy(cbuffer_t **buffer) {
    if (buffer && *buffer) {
        cbuffer_free(*buffer);
        *buffer = NULL;
    }
}