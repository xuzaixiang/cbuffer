//
// Created by xuzaixiang on 2023/2/10.
//

#include "cbuffer_mem.h"
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
    uint32_t position = cbuffer_array_append(&buffer->data, data, len);
    if (position <= 0) {
        return -1;
    }
    uint32_t *dest = (uint32_t *) ((char *) buffer->offset + buffer->index * 8);
    *dest = count;
    *(dest + 4) = position - len;
    buffer->index += 1;
    return 0;
}
int cbuffer_append_cbuffer(cbuffer_t *buffer, cbuffer_t *value, uint32_t num) {
    if (buffer->index >= buffer->count) {
        return -1;
    }
    uint32_t offset_size = value->count * 8;
    uint32_t size = 4 + offset_size + value->data.size;
    void *ptr = cbuffer_array_map(&buffer->data, size);
    if (NULL == ptr) {
        return -1;
    }
    memcpy(ptr, &value->count, 4);
    memcpy((char *) ptr + 4, value->offset, offset_size);
    memcpy((char *) ptr + 4 + offset_size, value->data.buffer, value->data.size);

    uint32_t *dest = (uint32_t *) ((char *) buffer->offset + buffer->index * 8);
    *dest = num;
    *(dest + 4) = (char *) ptr - (char *) buffer->data.buffer;
    buffer->index += 1;
    return 0;
}