//
// Created by xuzaixiang on 2023/2/12.
//

#include "cbuffer_mem.h"
#include <cbuffer/cbuffer.h>

static int cbuffer_get(cbuffer_t *buffer, uint8_t index, void **data, uint32_t *num);

int cbuffer_get_uint8(cbuffer_t *buffer, uint8_t index, uint8_t **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
int cbuffer_get_uint16(cbuffer_t *buffer, uint8_t index, uint16_t **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
int cbuffer_get_uint32(cbuffer_t *buffer, uint8_t index, uint32_t **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
int cbuffer_get_uint64(cbuffer_t *buffer, uint8_t index, uint64_t **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
int cbuffer_get_float(cbuffer_t *buffer, uint8_t index, float **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
int cbuffer_get_double(cbuffer_t *buffer, uint8_t index, double **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
int cbuffer_get_string(cbuffer_t *buffer, uint8_t index, char **data, uint32_t *num) {
    return cbuffer_get(buffer, index, (void **) data, num);
}
static int cbuffer_get(cbuffer_t *buffer, uint8_t index, void **data, uint32_t *num) {
    if (index >= buffer->count) {
        return -1;
    }
    uint32_t *buffer_offset = (uint32_t *) ((char *) buffer->offset + index * 8);
    uint32_t count = *buffer_offset;
    *num = count;
    uint32_t offset = *(buffer_offset + 1);
    *data = cbuffer_array_get(&buffer->data, offset);
    return 0;
}
int cbuffer_get_cbuffer(cbuffer_t *buffer, uint8_t index, cbuffer_t **data, uint32_t *num) {
    void *temp = NULL;
    if (cbuffer_get(buffer, index, &temp, num)) {
        return -1;
    }
    cbuffer_t *dest = cbuffer_from(temp);
    *data = dest;
    return 0;
}
