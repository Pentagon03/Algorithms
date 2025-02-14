# Etc/CPP_HACK/multidimensional_vector.cpp

This file defines a template for creating multi-dimensional vectors in C++.

## Multi-Dimensional Vector

*   **Description:** This file defines a template `Vec` that allows you to create multi-dimensional vectors with a specified number of dimensions and a data type. It also provides functions for iterating over and accumulating values in the vector.

*   **Template:**
    *   `Vec<D, T>`: A template for creating a multi-dimensional vector with `D` dimensions and elements of type `T`.
        ```cpp
        template<size_t D, typename T>
        struct Vec : public std::vector<Vec<D - 1, T>> {
            // ...
        };
        ```
        *   **Parameters:**
            *   `D`: The number of dimensions (must be greater than or equal to 2).
            *   `T`: The data type of the elements in the vector.

*   **Constructors:**
    *   `Vec(int n = 0, Args... args)`: Constructor that creates a `D`-dimensional vector with size `n` in the first dimension and recursively calls the constructor for the remaining dimensions.
        ```cpp
        template <typename... Args>
        Vec(int n = 0, Args... args) : std::vector<Vec<D-1, T>>(n, Vec<D - 1, T>(args...)) {}
        ```
        *   **Parameters:**
            *   `n`: The size of the first dimension.
            *   `args...`: The sizes for the remaining dimensions.
    *   `Vec(const DimensionInfo &dim_v, T init = T())`: Constructor that creates a `D`-dimensional vector with dimensions specified in the `dim_v` vector and initializes all elements with `init`.
        ```cpp
        Vec(const DimensionInfo &dim_v, T init = T());
        ```
        *   **Parameters:**
            *   `dim_v`: A vector of `size_t` representing the dimensions of the vector.
            *   `init`: The initial value for all elements (default: `T()`).

*   **Member Functions:**
    *   `T& location_at(const DimensionInfo &location)`: Returns a reference to the element at the specified location in the vector.
        ```cpp
        T& location_at(const DimensionInfo &location);
        ```
        *   **Parameters:**
                    *   `location`: A vector of `size_t` representing the indices for each dimension.
        
        *   **Global Functions:**
            *   `Vec_for_each(Vec<D, T>&v, auto&&f)`: Applies a function `f` to each element in the vector.
                ```cpp
                template<size_t D, typename T>
                void Vec_for_each(Vec<D, T>&v, auto&&f);
                ```
                *   **Parameters:**
                    *   `v`: The multi-dimensional vector.
                    *   `f`: A function that takes an element of type `T` as input.
            *   `Vec_for_each_location(Vec<D, T>&v, auto&&f)`: Applies a function `f` to each element in the vector, passing both the element and its location (indices) to the function.
                ```cpp
                template<size_t D, typename T>
                void Vec_for_each_location(Vec<D, T>&v, auto&&f);
                ```
                *   **Parameters:**
                    *   `v`: The multi-dimensional vector.
                    *   `f`: A function that takes an element of type `T` and a `DimensionInfo` (vector of indices) as input.
            *   `Vec_accumulate(const Vec<D,T>&v, auto&&f)`: Accumulates values from the vector using a function `f`.
                ```cpp
                template<size_t D, typename T>
                T Vec_accumulate(const Vec<D,T>&v, auto&&f);
                ```
                *   **Parameters:**
                    *   `v`: The multi-dimensional vector.
                    *   `f`: A function that takes an element of type `T` as input and returns a value of type `T`.
                *   **Returns:** The accumulated value.
        
        *   **Usage Examples:**
            ```cpp
            Vec<4, int64_t> f(n, k, 2, 2, -3); // = f[n][k][2][2] initialized with -3
            Vec<2, int> adj(n); // graph, adjacent list with n vertices
            
            vector<int> dim = {1, 2, 3, 4, 5};
            Vec<5, int> vec(dim, -1); // = vec[1][2][3][4][5] initialized with -1
        
            vec.location_at({0, 0, 0, 1, 1}) returns  vec[0][0][0][1][1] as reference
            ```