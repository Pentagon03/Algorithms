# Data Structure/RangeQuery/RMQ.cpp

This file contains a struct. You need to create an object of the struct to use it.

## RMQ (Range Minimum Query)

```cpp
template<typename T, class Func = function<T(const T&, const T&)>>
struct RMQ {
    vector<vector<T>> jmp;
    Func f;
    RMQ(){}
    RMQ(const vector<T>& V, Func g);
    T query(int a, int b);
};
```

*   **Description:** A struct for implementing Range Minimum Query.
*   **Template Parameters:**
    *   `T`: The type of the elements in the range.
    *   `Func`: The function used to compare elements (default: `ranges::min`).
*   **Usage:** Create an object of the `RMQ` struct and then call the member functions.

*   **Functions:**
    *   `RMQ(const vector<T>& V, Func g)`: Constructor that builds the RMQ structure from a given vector and a comparison function.
        ```cpp
        RMQ(const vector<T>& V, Func g);
        ```
        *   **Parameters:**
            *   `V`: The input vector.
            *   `g`: The comparison function (e.g., `ranges::min`).
    *   `T query(int a, int b)`: Queries the range `[a, b]` and returns the minimum element.
        ```cpp
        T query(int a, int b);
        ```
        *   **Parameters:**
            *   `a`: The left boundary of the range.
            *   `b`: The right boundary of the range.
        *   **Returns:** The minimum element in the range `[a, b]`.