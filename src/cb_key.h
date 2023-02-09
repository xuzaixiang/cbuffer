//
// Created by xuzaixiang on 2023/2/10.
//

#ifndef CBUFFER_CB_KEY_H
#define CBUFFER_CB_KEY_H

#include <stdint.h>

typedef struct cb_key {
    void *buffer;
    uint32_t size;
    uint32_t cap;
} cb_key_t;

uint32_t cb_key_append(cb_key_t *cb_key, const char *key);

#endif//CBUFFER_CB_KEY_H
