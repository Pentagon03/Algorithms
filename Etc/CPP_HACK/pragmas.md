# Etc/CPP_HACK/pragmas.cpp

This file contains compiler pragmas for optimization.

## Compiler Pragmas

*   **Description:** This file contains pragmas that can be used to optimize the compilation of C++ code.

*   **Pragmas:**
    *   `#pragma comment(linker, "/stack:102400000,102400000")`: Increases the stack size for the linker.
    *   `#pragma GCC optimize("Ofast,unroll-loops")`: Enables aggressive optimizations and loop unrolling.
    *   `#pragma GCC target("avx2,popcnt")`: Enables specific CPU instructions for better performance.