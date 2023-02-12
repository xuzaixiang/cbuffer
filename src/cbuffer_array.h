//
// Created by xuzaixiang on 2023/2/10.
//

#ifndef CBUFFER_CBUFFER_ARRAY_H
#define CBUFFER_CBUFFER_ARRAY_H

#include <stdint.h>

typedef struct cbuffer_array {
    void *buffer;
    uint32_t size;
    uint32_t cap;
} cbuffer_array_t;

uint32_t cbuffer_array_append(cbuffer_array_t *array, void *data, uint32_t len);

void *cbuffer_array_map(cbuffer_array_t *array, uint32_t size);

void *cbuffer_array_get(cbuffer_array_t *array, uint32_t offset);

#endif//CBUFFER_CBUFFER_ARRAY_H
