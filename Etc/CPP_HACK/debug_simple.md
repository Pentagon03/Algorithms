# Etc/CPP_HACK/debug_simple.cpp

This file defines a simple debugging macro for C++.

## Debugging Macro

*   **Description:** This file defines a macro `gg` that can be used for simple debugging output. It only works when `ONLINE_JUDGE` is not defined.

*   **Macro:**
    *   `gg(...)`: A debugging macro that prints the values of the given expressions to `cerr`.
        ```cpp
        #ifndef ONLINE_JUDGE
        #define gg(...) [](const auto&...x){ \
        char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl;\
        }(__VA_ARGS__);
        #else
        #define gg(...)
        #endif
        ```
        *   **Usage:** `gg(var1, var2, ...)` will print the names and values of the variables to the standard error stream.
        *   This macro is disabled when compiling in `ONLINE_JUDGE` mode.