//
// Created by xuzaixiang on 2023/2/10.
//

#include "cbuffer_mem.h"
#include <cbuffer/cbuffer.h>
#include <string.h>

static int cbuffer_append(cbuffer_t *buffer, void *data, uint32_t size, uint32_t count);
int cbuffer_append_uint8(cbuffer_t *buffer, uint8_t *value, uint32_t num) {
    return cbuffer_append(buffer, value, 1, num);
}
int cbuffer_append_uint16(cbuffer_t *buffer, uint16_t *value, uint32_t num) {
    return cbuffer_append(buffer, value, 2, num);
}
int cbuffer_append_uint32(cbuffer_t *buffer, uint32_t *value, uint32_t num) {
    return cbuffer_append(buffer, value, 4, num);
}
int cbuffer_append_uint64(cbuffer_t *buffer, uint64_t *value, uint32_t num) {
    return cbuffer_append(buffer, value, 8, num);
}
int cbuffer_append_float(cbuffer_t *buffer, float *value, uint32_t num) {
    return cbuffer_append(buffer, value, 4, num);
}
int cbuffer_append_double(cbuffer_t *buffer, double *value, uint32_t num) {
    return cbuffer_append(buffer, value, 8, num);
}
int cbuffer_append_string(cbuffer_t *buffer, char *value, uint32_t num) {
    return cbuffer_append(buffer, value, 1, num > 0 ? num : strlen(value));
}
static int cbuffer_append(cbuffer_t *buffer, void *data, uint32_t size, uint32_t count) {
    if (buffer->index >= buffer->count) {
        return -1;
    }
    uint32_t len = size * count;
    if (cbuffer_array_append(&buffer->data, data, len)) {
        return -1;
    }
    uint32_t *dest = (uint32_t *) ((char *) buffer->offset + buffer->index * 8);
    *dest = count;
    *(dest + 1) = buffer->data.size - len;
    buffer->index += 1;
    return 0;
}
int cbuffer_append_cbuffer(cbuffer_t *buffer, cbuffer_t *value) {
    if (buffer->index >= buffer->count) {
        return -1;
    }
    uint32_t size = cbuffer_size(value);
    if (cbuffer_array_append(&buffer->data, NULL, size)) {
        return -1;
    }
    char *ptr = (char *) buffer->data.buffer + buffer->data.size - size;
    memcpy(ptr, &value->count, 1);
    uint32_t offset_size = value->count * 8;
    memcpy(ptr + 1, value->offset, offset_size);
    memcpy(ptr + 1 + offset_size, value->data.buffer, value->data.size);

    uint32_t *dest = (uint32_t *) ((char *) buffer->offset + buffer->index * 8);
    *dest = 1;
    *(dest + 1) = buffer->data.size - size;
    buffer->index += 1;
    return 0;
}