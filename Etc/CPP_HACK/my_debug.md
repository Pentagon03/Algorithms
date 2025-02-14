# Etc/CPP_HACK/my_debug.cpp

This file configures debugging macros based on the compilation environment.

## Debugging Configuration

*   **Description:** This file defines debugging macros `dbg` and `dbgArr` that are enabled when the code is compiled in debug mode (`_DEBUG` is defined). It includes a custom debug header from `Pentagon03/debug.h` if available.

*   **Macros:**
    *   `dbg(...)`: A debugging macro that prints the values of the given expressions. It is enabled when `_DEBUG` is defined and includes the `Pentagon03` debug header.
        ```cpp
        #ifdef _DEBUG
        #define Pentagon03
        #include<Pentagon03/debug.h>
        #else
        #define dbg(...) 
        #define dbgArr(...)
        #endif
        ```
        *   **Usage:** `dbg(var1, var2, ...)` will print the names and values of the variables to the standard error stream if debugging is enabled.
    *   `dbgArr(...)`: A debugging macro that prints the elements of an array. It is enabled when `_DEBUG` is defined and includes the `Pentagon03` debug header.
        *   **Usage:** `dbgArr(arr, size)` will print the elements of the array `arr` to the standard error stream if debugging is enabled.