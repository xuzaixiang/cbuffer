//
// Created by xuzaixiang on 2023/2/10.
//

#include "cbuffer_array.h"
#include "cbuffer_mem.h"
#include <string.h>

int cbuffer_array_expand(cbuffer_array_t *array) {
    uint32_t cap = array->cap == 0 ? 16 : (array->cap << 1);
    if (cap < array->cap) {
        return -1;
    }
    void *ptr = cbuffer_malloc(cap);
    if (NULL == ptr) {
        return -1;
    }
    memcpy(ptr, array->buffer, array->size);
    cbuffer_free(array->buffer);
    array->buffer = ptr;
    array->cap = cap;
    return 0;
}

int cbuffer_array_append(cbuffer_array_t *array, void *data, uint32_t len) {
    while (array->size + len > array->cap) {
        if (cbuffer_array_expand(array) != 0) {
            return -1;
        }
    }
    if (NULL != data) {
        memcpy((char *) array->buffer + array->size, data, len);
    }
    array->size += len;
    return 0;
}

void *cbuffer_array_get(cbuffer_array_t *array, uint32_t offset) {
    return (char *) array->buffer + offset;
}

void *cbuffer_array_map(cbuffer_array_t *array, uint32_t size) {
    while (array->size + size > array->cap) {
        if (cbuffer_array_expand(array) != 0) {
            return NULL;
        }
    }
    char *buffer = (char *) array->buffer + array->size;
    array->size += size;
    return buffer;
}