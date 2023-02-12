//
// Created by xuzaixiang on 2023/2/10.
//

#include "cbuffer_mem.h"
#include <cbuffer/cbuffer.h>
#include <string.h>

void cbuffer_destroy(cbuffer_t **buffer) {
    if (buffer && *buffer) {
        cbuffer_free(*buffer);
        *buffer = NULL;
    }
}
cbuffer_t *cbuffer_create(uint8_t count) {
    cbuffer_t *buffer = cbuffer_malloc(sizeof(cbuffer_t));
    if (NULL == buffer) {
        return NULL;
    }
    memset(buffer, 0, sizeof(cbuffer_t));
    buffer->count = count;
    void *index = cbuffer_malloc(8 * count);
    if (NULL == index) {
        cbuffer_free(buffer);
        return NULL;
    }
    buffer->offset = index;
    return buffer;
}
cbuffer_t *cbuffer_from(void *data) {
    cbuffer_t *buffer = cbuffer_malloc(sizeof(cbuffer_t));
    if (NULL == buffer) {
        return NULL;
    }
    memset(buffer, 0, sizeof(cbuffer_t));
    buffer->count = *(uint8_t *) data;
    uint32_t size = 4 * buffer->count;
    void *index = cbuffer_malloc(size);
    if (NULL == index) {
        cbuffer_free(buffer);
        return NULL;
    }
    memcpy(index, (char *) data + 1, size);
    buffer->offset = index;
    //    buffer->data = (char *) data + 1 + size;
    return buffer;
}
