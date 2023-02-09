#include <cbuffer/cbuffer.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct cb *buffer = cbuffer_create();
    cbuffer_destroy(&buffer);
    return 0;
}
