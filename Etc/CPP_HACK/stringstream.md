# Etc/CPP_HACK/stringstream.cpp

This file provides examples of using `stringstream` in C++.

## stringstream Examples

*   **Description:** This file demonstrates how to use `stringstream` for reading and writing strings in C++.

*   **Examples:**
    *   Reading from a stringstream:
        ```cpp
        std::stringstream iss("1 2 3"); // iss << "1 2 3";
        int a, b, c;
        iss >> a >> b >> c; // 1 2 3
        std::cout << a << ' ' << b << ' ' << c << std::endl;
        ```
    *   Writing to a stringstream:
        ```cpp
        std::stringstream oss;
        oss << "Hello " << "World\n";
        std::string res = oss.str(); // getline(oss, res);
        std::cout << res << std::endl; // Hello World