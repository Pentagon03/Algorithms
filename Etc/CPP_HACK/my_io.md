# Etc/CPP_HACK/my_io.cpp

This file defines custom input and output functions for C++.

## Custom I/O Functions

*   **Description:** This file defines functions `input` and `print` that can handle various data types, including iterables. It allows for easy input and output of complex data structures.

*   **Constants:**
    *   `debug_`: A boolean constant that determines whether the output should be directed to `cerr` (if `true`) or `cout` (if `false`). Default value is `0`.
        ```cpp
        constexpr bool debug_ = 0;
        ```

*   **Functions:**
    *   `input(auto &x)`: Reads input from `cin` into the variable `x`.
        ```cpp
        void input(auto &x);
        ```
        *   **Parameters:**
            *   `x`: The variable to read input into.
    *   `print(auto &&x)`: Prints the value of `x` to either `cerr` or `cout` based on the value of `debug_`.
        ```cpp
        void print(auto &&x);
        ```
        *   **Parameters:**
            *   `x`: The value to print.
    *   `input(T &container)`: Reads input into each element of an iterable container.
        ```cpp
        template<is_iterable T>
        void input(T &container);
        ```
        *   **Parameters:**
            *   `container`: The iterable container to read input into.
    *   `input(auto &...x)`: Reads input into multiple variables.
        ```cpp
        void input(auto &...x);
        ```
        *   **Parameters:**
            *   `x...`: The variables to read input into.
    *   `print(T &&container)`: Prints the elements of an iterable container, adding a newline character after each iterable element.
        ```cpp
        template<is_iterable T>
        void print(T &&container);
        ```
        *   **Parameters:**
            *   `container`: The iterable container to print.
    *   `print(T &&x, Args &&...args)`: Prints multiple values, adding a space between them and a newline character at the end if there is only one argument.
        ```cpp
        template<class T, class... Args>
        void print(T &&x, Args &&...args);
        ```
        *   **Parameters:**
            *   `x`: The first value to print.
            *   `args...`: The remaining values to print.

*   **Usage Examples:**
    ```cpp
    vector<int> A(5), B(3); input(A, B);
    vector<vector<int>> v = {{1,2,3}, {3,4,5}, {5,6,7}};
    int a = 3; double b = 3.14; string c = "asdf";
    print("wow", v, a, b, c);