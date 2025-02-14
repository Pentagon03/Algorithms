# Data Structure/bisect.cpp

This file provides a template for binary search.

## Binary Search Template

*   **Description:** This file provides a template for performing binary search within a range.

*   **Variables:**
    *   `lo`: The lower bound of the search range.
    *   `hi`: The upper bound of the search range.
    *   `mid`: The midpoint of the search range.
    *   `chk`: A lambda function that checks if a value satisfies the search condition.

*   **Usage:**
    *   Initialize `lo` and `hi` such that `chk(lo)` is true and `chk(hi)` is false.
    *   Define the `chk` lambda function to evaluate the search condition.
    *   The `while` loop performs the binary search, narrowing the range until `lo + 1 == hi`.

*   **Example:**
    ```cpp
    int lo = 0, hi = n, mid;
    // chk(lo) = true, chk(hi) = false
    auto chk = [&](auto x)->bool{
        // Your condition here
    };
    while(lo + 1 < hi) chk(mid = midpoint(lo, hi)) ? lo = mid : hi = mid;
