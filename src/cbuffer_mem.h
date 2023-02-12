//
// Created by xuzaixiang on 2023/2/10.
//

#ifndef CBUFFER_CBUFFER_MEM_H
#define CBUFFER_CBUFFER_MEM_H

#include "cbuffer_array.h"
#include <stdint.h>

typedef struct cbuffer {
    uint8_t index;
    uint8_t count;
    void *offset;
    cbuffer_array_t data;
} cbuffer_t;

void *cbuffer_malloc(size_t size);
void *cbuffer_realloc(void *ptr, size_t size);
void cbuffer_free(void *ptr);

#endif//CBUFFER_CBUFFER_MEM_H
