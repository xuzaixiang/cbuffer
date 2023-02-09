//
// Created by xuzaixiang on 2023/2/10.
//

#ifndef CBUFFER_CBUFFER_H
#define CBUFFER_CBUFFER_H

#include <stdint.h>

typedef struct cb cbuffer_t;
cbuffer_t *cbuffer_create();
void cbuffer_destroy(cbuffer_t **buffer);
void cbuffer_fun_malloc(void *(*malloc)(size_t));
void cbuffer_fun_realloc(void *(*realloc)(void *, size_t));
void cbuffer_fun_free(void (*free)(void *));
void cbuffer_append_char(cbuffer_t *buffer, const char *key, char value);
void cbuffer_append_uint32(cbuffer_t *buffer, const char *key, uint32_t value);
void cbuffer_append_uint64(cbuffer_t *buffer, const char *key, uint64_t value);
void cbuffer_append_float(cbuffer_t *buffer, const char *key, float value);
void cbuffer_append_double(cbuffer_t *buffer, const char *key, double value);

#endif//CBUFFER_CBUFFER_H
