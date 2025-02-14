# Etc/CPP_HACK/bit_header.cpp

This file demonstrates the usage of various bit manipulation functions in C++.

## Bit Manipulation Functions

*   **Description:** This file provides examples of how to use bit manipulation functions in C++ for various operations.

*   **Functions:**
    *   `rotl(u32 x, int k)`: Rotates the bits of `x` to the left by `k` positions.
        ```cpp
        // rotl
        cout << "rotl 1: " << bset(rotl((u32)i, 1)) << '\n';
        ```
    *   `rotr(u32 x, int k)`: Rotates the bits of `x` to the right by `k` positions.
        ```cpp
        // rotr
        cout << "rotr 1: " << bset(rotr((u32)i, 1)) << '\n';
        ```
    *   `bit_width(u32 x)`: Returns the minimum number of bits required to represent `x`.
        ```cpp
        // bit_width (이 수를 표현하기 위한 최소 너비)
        cout << "bit_width: " << bit_width((u32)i) << '\n';
        ```
    *   `popcount(u32 x)`: Returns the number of set bits (1s) in `x`.
        ```cpp
        // popcount (1의 개수)
        cout << "popcount: " << popcount((u32)i) << '\n';
        ```
    *   `has_single_bit(u32 x)`: Checks if `x` is a power of 2 (has only one bit set).
        ```cpp
        // has_single_bit (2의 거듭제곱인지 검사)
        cout << "has_single_bit: " << has_single_bit((u32)i) << '\n';
        ```
    *   `bit_ceil(u32 x)`: Returns the smallest power of 2 greater than or equal to `x`.
        ```cpp
        // bit_ceil (N 이상의 최소 2의 거듭제곱)
        cout << "bit_ceil: " << bit_ceil((u32)i) << '\n';
        ```
    *   `bit_floor(u32 x)`: Returns the largest power of 2 less than or equal to `x`.
        ```cpp
        // bit_floor (N 이하의 최대 2의 거듭제곱)
        cout << "bit_floor: " << bit_floor((u32)i) << '\n';
        ```
    *   `countl_zero(u32 x)`: Returns the number of leading zero bits in `x`.
        ```cpp
        // countl_zero (clz)
        cout << "countl_zero: " << countl_zero((u32)i) << '\n';
        ```
    *   `countl_one(u32 x)`: Returns the number of leading one bits in `x`.
        ```cpp
        // countl_one
        cout << "countl_one: " << countl_one((u32)i) << '\n';
        ```
    *   `countr_zero(u32 x)`: Returns the number of trailing zero bits in `x`.
        ```cpp
        // countr_zero (crz)
        cout << "countr_zero: " << countr_zero((u32)i) << '\n';
        ```
    *   `countr_one(u32 x)`: Returns the number of trailing one bits in `x`.
        ```cpp
        // countr_one
        cout << "countr_one: " << countr_one((u32)i) << '\n';