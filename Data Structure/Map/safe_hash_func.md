# Data Structure/Map/safe_hash_func.cpp

This file contains a struct. You need to create an object of the struct to use it.

## safe_hash

```cpp
struct safe_hash {
    // ...
};
```

*   **Description:** A struct for implementing a safe hash function to be used with unordered maps and other hash-based data structures.
*   **Usage:** Create an object of the `safe_hash` struct and then use it as the third template argument for `unordered_map` or `__gnu_pbds::gp_hash_table`.

*   **Functions:**
    *   `operator()(u64 x) const`: Hashes a 64-bit unsigned integer.
    *   `operator()(pair<u64, u64> x) const`: Hashes a pair of 64-bit unsigned integers.
