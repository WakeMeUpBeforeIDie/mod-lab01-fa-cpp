// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
using namespace std;

int main() {
    const* char test_str = "Hello World 123 damn l0v3 d1e r1s3 fr0m th3 Ashes Again. Malevola Invisigal RimmiR .! oOoOoOo";

    cout << "Result of first func: " << faStr1(test_str) << endl;
    cout << "Result of second func: " << faStr2(test_str) << endl;
    cout << "Result of third func: " << faStr3(test_str) << endl;

    return 0;
}
