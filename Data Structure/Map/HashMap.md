# Data Structure/Map/HashMap.cpp

This file contains a struct. You need to create an object of the struct to use it.

## HashMap

```cpp
template <typename K = u64, typename V = int, int LG = 22, bool KEEP_IS = false>
struct HashMap {
    // ...
};
```

*   **Description:** A struct for implementing a hash map.
*   **Template Parameters:**
    *   `K`: The type of the key (default: u64).
    *   `V`: The type of the value (default: int).
    *   `LG`: The logarithm base 2 of the bucket size (default: 22).
    *   `KEEP_IS`: Whether to keep track of the insertion order (default: false).
*   **Usage:** Create an object of the `HashMap` struct and then call the member functions.

*   **Functions:**
    *   `operator[](K k)`: Accesses the value associated with the key `k`. If the key is not present, it inserts a new key-value pair with a default value.
    *   `get(K k, V d = {}) const`: Returns the value associated with the key `k`. If the key is not present, it returns the default value `d`.
    *   `contains(K k) const`: Checks if the hash map contains the key `k`.
    *   `clear()`: Clears the hash map.
    *   `enumerate(auto&& f) const`: Enumerates the key-value pairs in the hash map (only if `KEEP_IS` is true).
