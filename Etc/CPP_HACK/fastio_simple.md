# Etc/CPP_HACK/fastio_simple.cpp

This file defines a simple fast I/O implementation for C++.

## Fast I/O

*   **Description:** This file defines structures `IN` and `OUT` to provide faster input and output operations in C++ compared to the standard `cin` and `cout`.

*   **Structures:**
    *   `IN`: A structure for fast input.
        *   `scan(char &x)`: Reads a character from the input stream, skipping whitespace.
        *   `scan(string &s)`: Reads a string from the input stream.
        *   `scan(T &x)`: Reads a value of type `T` (integer) from the input stream.
    *   `OUT`: A structure for fast output.
        *   `flush()`: Flushes the output buffer to the standard output.
        *   `print(char c)`: Prints a character to the output buffer.
        *   `print(const string& s)`: Prints a string to the output buffer.
        *   `print(T x)`: Prints a value of type `T` (integer) to the output buffer.

*   **Usage:**
    *   Replace `cin` with `_in` and `cout` with `_out` to use the fast I/O.
    *   Example:
        ```cpp
        IN _in;
        OUT _out;
        int n;
        _in >> n;
        _out << n << '\n';
        ```
    *   The file also defines macros `#define cin _in` and `#define cout _out` for convenience.