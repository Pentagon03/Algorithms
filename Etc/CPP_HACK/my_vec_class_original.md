# Etc/CPP_HACK/my_vec_class_original.cpp

This file defines a template for creating multi-dimensional vectors in C++.

## Multi-Dimensional Vector (Original)

*   **Description:** This file defines a template `Vec` that allows you to create multi-dimensional vectors with a specified number of dimensions and a data type. This is a simpler, original version of the multi-dimensional vector implementation.

*   **Template:**
    *   `Vec<D, T>`: A template for creating a multi-dimensional vector with `D` dimensions and elements of type `T`.
        ```cpp
        template<size_t D, typename T>
        struct Vec : public vector<Vec<D - 1, T>> {
            static_assert(D >= 1, "Dimension must be positive");
            template <typename... Args>
            Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
        };
        ```
        *   **Parameters:**
            *   `D`: The number of dimensions (must be positive).
            *   `T`: The data type of the elements in the vector.

*   **Specialization for 1D Vectors:**
    *   `Vec<1, T>`: A specialization of the `Vec` template for creating one-dimensional vectors.
        ```cpp
        template <typename T>
        struct Vec<1, T> : public vector<T> {
            Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
        };
        ```

*   **Usage Examples:**
    ```cpp
    Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
    Vec<2, int> adj(n); // graph