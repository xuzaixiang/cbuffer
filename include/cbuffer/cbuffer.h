//
// Created by xuzaixiang on 2023/2/10.
//

#ifndef CBUFFER_CBUFFER_H
#define CBUFFER_CBUFFER_H

#include <stdint.h>

typedef struct cbuffer cbuffer_t;
cbuffer_t *cbuffer_create(uint8_t count);
cbuffer_t *cbuffer_from(void *data);
void cbuffer_destroy(cbuffer_t **buffer);
uint32_t cbuffer_size(cbuffer_t* buffer);

int cbuffer_append_uint8(cbuffer_t *buffer, uint8_t *value, uint32_t num);
int cbuffer_append_uint16(cbuffer_t *buffer, uint16_t *value, uint32_t num);
int cbuffer_append_uint32(cbuffer_t *buffer, uint32_t *value, uint32_t num);
int cbuffer_append_uint64(cbuffer_t *buffer, uint64_t *value, uint32_t num);
int cbuffer_append_float(cbuffer_t *buffer, float *value, uint32_t num);
int cbuffer_append_double(cbuffer_t *buffer, double *value, uint32_t num);
int cbuffer_append_string(cbuffer_t *buffer, char *value, uint32_t num);
int cbuffer_append_cbuffer(cbuffer_t *buffer, cbuffer_t *value);

int cbuffer_get_uint8(cbuffer_t *buffer, uint8_t index, uint8_t **data, uint32_t *num);
int cbuffer_get_uint16(cbuffer_t *buffer, uint8_t index, uint16_t **data, uint32_t *num);
int cbuffer_get_uint32(cbuffer_t *buffer, uint8_t index, uint32_t **data, uint32_t *num);
int cbuffer_get_uint64(cbuffer_t *buffer, uint8_t index, uint64_t **data, uint32_t *num);
int cbuffer_get_float(cbuffer_t *buffer, uint8_t index, float **data, uint32_t *num);
int cbuffer_get_double(cbuffer_t *buffer, uint8_t index, double **data, uint32_t *num);
int cbuffer_get_string(cbuffer_t *buffer, uint8_t index, char **data, uint32_t *num);
int cbuffer_get_cbuffer(cbuffer_t *buffer, uint8_t index, cbuffer_t **data, uint32_t *num);

void cbuffer_mem_malloc(void *(*malloc)(size_t));
void cbuffer_mem_realloc(void *(*realloc)(void *, size_t));
void cbuffer_mem_free(void (*free)(void *));

#endif//CBUFFER_CBUFFER_H
