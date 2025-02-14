# Data Structure/Map/pbds_tourist.cpp

This file contains template aliases.

## ordered_map

```cpp
template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;
```

*   **Description:** A template alias for an ordered map using policy-based data structures.
*   **Template Parameters:**
    *   `K`: The key type.
    *   `V`: The value type.
    *   `Comp`: The comparison function (default: `std::less<K>`).
*   **Supports:**
    *   `auto iterator = ordered_map().find_by_order(idx); // (0-indexed)`
    *   `int num_strictly_smaller = ordered_map().order_of_key(key);`

## ordered_set

```cpp
template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;
```

*   **Description:** A template alias for an ordered set using policy-based data structures.
*   **Template Parameters:**
    *   `K`: The key type.
    *   `Comp`: The comparison function (default: `std::less<K>`).
*   **Supports:**
    *   `auto iterator = ordered_set().find_by_order(idx); // (0-indexed)`
    *   `int num_strictly_smaller = ordered_set().order_of_key(key);`
