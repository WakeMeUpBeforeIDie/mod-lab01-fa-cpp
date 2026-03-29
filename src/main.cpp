// Copyright 2022 UNN-IASR
#include <stdio.h>
#include "fun.h"
int main() {
    const char* test_str = "Hello World idk k1ll l0v3 fr0m The ASHES Why Tell";
    printf("First res: %u\n", faStr1(test_str));
    printf("Second res: %u\n", faStr2(test_str));
    printf("First res: %u\n", faStr3(test_str));
    return 0;
}
