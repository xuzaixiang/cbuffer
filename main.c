#include <assert.h>
#include <cbuffer/cbuffer.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    cbuffer_t *buffer = cbuffer_create(20);
    uint32_t num = 0;

    // uint8
    uint8_t *u8ptr = NULL;
    uint8_t u8_1 = 255;
    assert(cbuffer_append_uint8(buffer, &u8_1, 1) == 0);
    cbuffer_get_uint8(buffer, 0, &u8ptr, &num);
    assert(num == 1);
    assert(*u8ptr == u8_1);

    uint8_t u8_2[2] = {1, 2};
    assert(cbuffer_append_uint8(buffer, u8_2, 2) == 0);
    cbuffer_get_uint8(buffer, 1, &u8ptr, &num);
    assert(num == 2);
    assert(*u8ptr == 1);
    assert(*(u8ptr + 1) == 2);

    // uint16
    uint16_t *u16ptr = NULL;
    uint16_t u16_1 = 255;
    assert(cbuffer_append_uint16(buffer, &u16_1, 1) == 0);
    cbuffer_get_uint16(buffer, 2, &u16ptr, &num);
    assert(num == 1);
    assert(*u16ptr == u16_1);

    uint16_t u16_2[2] = {1, 2};
    assert(cbuffer_append_uint16(buffer, u16_2, 2) == 0);
    cbuffer_get_uint16(buffer, 3, &u16ptr, &num);
    assert(num == 2);
    assert(*u16ptr == 1);
    assert(*(u16ptr + 1) == 2);

    // uint32
    uint32_t *u32ptr = NULL;
    uint32_t u32_1 = 255;
    assert(cbuffer_append_uint32(buffer, &u32_1, 1) == 0);
    cbuffer_get_uint32(buffer, 4, &u32ptr, &num);
    assert(num == 1);
    assert(*u32ptr == u32_1);

    uint32_t u32_2[2] = {1, 2};
    assert(cbuffer_append_uint32(buffer, u32_2, 2) == 0);
    cbuffer_get_uint32(buffer, 5, &u32ptr, &num);
    assert(num == 2);
    assert(*u32ptr == 1);
    assert(*(u32ptr + 1) == 2);

    // uint64
    uint64_t *u64ptr = NULL;
    uint64_t u64_1 = 255;
    assert(cbuffer_append_uint64(buffer, &u64_1, 1) == 0);
    cbuffer_get_uint64(buffer, 6, &u64ptr, &num);
    assert(num == 1);
    assert(*u64ptr == u64_1);

    uint64_t u64_2[2] = {1, 2};
    assert(cbuffer_append_uint64(buffer, u64_2, 2) == 0);
    cbuffer_get_uint64(buffer, 7, &u64ptr, &num);
    assert(num == 2);
    assert(*u64ptr == 1);
    assert(*(u64ptr + 1) == 2);

    // float
    float *f_ptr = NULL;
    float f_1 = 255;
    assert(cbuffer_append_float(buffer, &f_1, 1) == 0);
    cbuffer_get_float(buffer, 8, &f_ptr, &num);
    assert(num == 1);
    assert(*f_ptr == f_1);

    // double
    double *d_ptr = NULL;
    double d_1 = 255;
    assert(cbuffer_append_double(buffer, &d_1, 1) == 0);
    cbuffer_get_double(buffer, 9, &d_ptr, &num);
    assert(num == 1);
    assert(*d_ptr == d_1);

    // char*
    char *char_ptr = NULL;
    char *char_1 = "12";
    assert(cbuffer_append_string(buffer, char_1, 0) == 0);
    cbuffer_get_string(buffer, 10, &char_ptr, &num);
    assert(num == 2);
    assert(*char_ptr == *char_1);
    assert(*(char_ptr + 1) == *(char_1 + 1));

    // cbuffer
    cbuffer_t *child = cbuffer_create(1);
    cbuffer_append_uint8(child, &u8_1, 1);
    cbuffer_append_cbuffer(buffer, child, 1);
    cbuffer_destroy(&child);
    child = NULL;
    cbuffer_get_cbuffer(buffer, 11, &child, &num);
    uint8_t *temp = NULL;
    uint32_t temp_num = 0;
    cbuffer_get_uint8(child, 0, &temp, &temp_num);
    assert(*temp == u8_1);

    cbuffer_destroy(&buffer);
    return 0;
}
