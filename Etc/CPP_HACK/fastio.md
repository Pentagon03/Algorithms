# Etc/CPP_HACK/fastio.cpp

This file defines a comprehensive fast I/O implementation for C++.

## Fast I/O

*   **Description:** This file defines classes `_IN` and `_OUT` to provide faster input and output operations in C++ compared to the standard `cin` and `cout`. It also includes support for `__int128_t` and convenient input/output for vectors and pairs.

*   **Classes:**
    *   `_IN`: A class for fast input.
        *   `scan(char &c)`: Reads a character from the input stream, skipping whitespace.
        *   `scan(string &s)`: Reads a string from the input stream.
        *   `scan(float &f)`: Reads a float from the input stream.
        *   `scan(double &f)`: Reads a double from the input stream.
        *   `scan(long double &f)`: Reads a long double from the input stream.
        *   `geti<T>()`: Reads an integer of type `T` from the input stream.
        *   `getline()`: Reads a line from the input stream.
        *   `scan(pair<T1, T2> &p)`: Reads a pair from the input stream.
        *   `scan(vector<T> &v)`: Reads a vector from the input stream.
    *   `_OUT`: A class for fast output.
        *   `flush()`: Flushes the output buffer to the standard output.
        *   `print(const char c)`: Prints a character to the output buffer.
        *   `print(const char* s)`: Prints a C-style string to the output buffer.
        *   `print(const string& s)`: Prints a string to the output buffer.
        *   `setprecision(int precision)`: Sets the precision for floating-point output.
        *   `print(const long double f)`: Prints a long double to the output buffer.
        *   `print(const double f)`: Prints a double to the output buffer.
        *   `print(const float f)`: Prints a float to the output buffer.
        *   `print(const vector<T>& v)`: Prints a vector to the output buffer.
        *   `print(const pair<T1, T2>& p)`: Prints a pair to the output buffer.
        *   `print(T ans)`: Prints an integer of type `T` to the output buffer.

*   **Usage:**
    *   Define `FASTIO` to enable the fast I/O.
    *   Replace `cin` with `_in` and `cout` with `_out` to use the fast I/O.
    *   Example:
        ```cpp
        #define FASTIO 1
        #include "fastio.cpp"
        int main() {
            int n;
            cin >> n;
            cout << n << '\n';
        }
        ```
    *   The file also defines macros `#define cin _in` and `#define cout _out` for convenience.