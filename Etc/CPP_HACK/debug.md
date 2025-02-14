# Etc/CPP_HACK/debug.h

This file defines a comprehensive debugging template for C++.

## Debugging Template

*   **Description:** This file defines a set of macros and utilities for debugging C++ code, including printing variables, arrays, and iterables.

*   **Macros and Utilities:**
    *   `debug(...)`: A macro that prints the values of the given expressions to `std::cerr` along with the line number. It is enabled when `_DEBUG` is defined.
        ```cpp
        #ifdef _DEBUG
        #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
        #else
        #define debug(...)
        #endif
        ```
        *   **Usage:** `debug(var1, var2, ...)` will print the names and values of the variables to the standard error stream.
    *   `debugArr(...)`: A macro that prints the elements of an array to `std::cerr` along with the line number. It is enabled when `_DEBUG` is defined.
        ```cpp
        #ifdef _DEBUG
        #define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
        #else
        #define debugArr(...)
        #endif
        ```
        *   **Usage:** `debugArr(arr, size)` will print the elements of the array `arr` to the standard error stream.
    *   `dbg(...)`: A macro similar to `debug(...)` but includes the test case number (`cur_tc`) in the output. It is enabled when `Pentagon03` is defined.
        ```cpp
        #ifdef Pentagon03
        #define dbg(...) std::cerr<<"tc"<<cur_tc<<" > "; debug(__VA_ARGS__)
        #else
        #define dbg(...) debug(__VA_ARGS__)
        #endif
        ```
    *   `dbg_n(...)`: A macro similar to `debugArr(...)` but includes the test case number (`cur_tc`) in the output. It is enabled when `Pentagon03` is defined.
        ```cpp
        #ifdef Pentagon03
        #define dbg_n(...) std::cerr<<"tc"<<cur_tc<<" > "; debugArr(__VA_ARGS__)
        #else
        #define dbg_n(...) debugArr(__VA_ARGS__)
        #endif
        ```
    *   `__DEBUG_UTIL__` namespace: Contains utility functions for printing different data types, including iterables, pairs, and tuples.