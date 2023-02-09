//
// Created by xuzaixiang on 2023/2/10.
//

#ifndef CBUFFER_CB_STRUCT_H
#define CBUFFER_CB_STRUCT_H

#include "cb_key.h"
#include <stdint.h>

typedef struct cb {
    uint16_t count;
    cb_key_t key;
} cbuffer_t;

#endif//CBUFFER_CB_STRUCT_H
