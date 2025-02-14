# Adhoc/lis.cpp

This file defines functions for finding the Longest Increasing Subsequence (LIS).

## Longest Increasing Subsequence Functions

*   **Description:** This file defines functions `lis` and `lis_recover` for finding the length and recovering the elements of the Longest Increasing Subsequence (LIS) in a given vector.

*   **Functions:**
    *   `lis(const vector<T> &v)`: Finds the length of the LIS in a given vector.
        ```cpp
        template<typename T = int, typename cmp = less<T>>
        int lis(const vector<T> &v);
        ```
        *   **Parameters:**
            *   `v`: The input vector.
        *   **Returns:** The length of the LIS.
    *   `lis_recover(const vector<T> &v)`: Finds the elements of the LIS in a given vector.
        ```cpp
        template<typename T = int, typename cmp = less<T>>
        vector<int> lis_recover(const vector<T> &v);
        ```
        *   **Parameters:**
            *   `v`: The input vector.
        *   **Returns:** A vector containing the elements of the LIS.
