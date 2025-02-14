# Etc/CPP_HACK/nor_enumerate_zip.cpp

This file defines templates for `zip` and `enumerate` functionalities, similar to Python's.

## zip and enumerate Templates

*   **Description:** This file defines templates `zip` and `enumerate` that provide functionalities similar to Python's `zip` and `enumerate` for iterating over multiple iterables or with an index.

*   **Templates:**
    *   `zip<T...>`: A template that takes multiple iterables and allows iterating over them in parallel, yielding tuples of corresponding elements.
        ```cpp
        template <typename... T>
        struct zip {
            // ...
        };
        ```
        *   **Parameters:**
            *   `T...`: The types of the iterables to zip.
    *   `enumerate<T>`: A template that takes an iterable and allows iterating over it with an index, yielding pairs of index and element.
        ```cpp
        template <typename T>
        struct enumerate {
            // ...
        };
        ```
        *   **Parameters:**
            *   `T`: The type of the iterable to enumerate.

*   **Usage Examples:**
    ```cpp
    vector<int> a = {1, 2, 3};
    vector<double> b = {4, 5, 6};
    for (auto&& [x, y] : zip(a, b)) cout << x++ << ' ' << y++ << '\n';
    for (auto&& [i, x] : enumerate(a)) cout << i++ << ' ' << x++ << '\n';
    for (auto&& [x, y] : zip(vector{1, 2, 3}, array{3, 4, 5})) cout << x++ << ' ' << y++ << '\n';