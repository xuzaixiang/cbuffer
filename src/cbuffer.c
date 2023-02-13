//
// Created by xuzaixiang on 2023/2/10.
//

#include "cbuffer_mem.h"
#include <cbuffer/cbuffer.h>
#include <string.h>

void cbuffer_destroy(cbuffer_t **buffer) {
    if (buffer && *buffer) {
        cbuffer_t *r = *buffer;
        cbuffer_free(r->offset);
        cbuffer_free(r);
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
    // count
    buffer->count = *(uint8_t *) data;
    buffer->index = buffer->count; // not allow append
    // offset
    uint32_t size = 8 * buffer->count;
    void *offset = cbuffer_malloc(size);
    if (NULL == offset) {
        cbuffer_free(buffer);
        return NULL;
    }
    memcpy(offset, (char *) data + 1, size);
    buffer->offset = offset;
    buffer->data.buffer = (char *) data + 1 + size;
    return buffer;
}
