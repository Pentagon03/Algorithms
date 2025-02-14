# Etc/CPP_HACK/array_assign.cpp

This file contains a function.

## assign

```cpp
void assign(auto&A, auto n, auto...v);
```

*   **Description:** A function to assign a value to an array or vector of arbitrary dimensions.
*   **Usage:** Call the `assign` function with the array/vector, dimensions, and the value to assign.

*   **Parameters:**
    *   `A`: The array or vector to assign the value to.
    *   `n`: The size of the first dimension.
    *   `v...`: The sizes of the remaining dimensions, followed by the value to assign.

*   **Example:**
    ```cpp
    vector<vector<int>> arr(3, vector<int>(4));
    assign(arr, 3, 4, 0); // Assigns 0 to all elements of arr