# Data Structure/Map/ordered_set,multiset.cpp

This file contains structs. You need to create an object of the struct to use it.

## ordered_set

```cpp
template <typename Typename = int, class Parent = tree<Typename, null_type, less<Typename>, rb_tree_tag,tree_order_statistics_node_update>>
struct ordered_set : Parent{
    // ...
};
```

*   **Description:** A struct for implementing an ordered set using policy-based data structures from GNU libstdc++.
*   **Template Parameters:**
    *   `Typename`: The type of the elements in the set (default: int).
    *   `Parent`: The underlying tree structure (default: `tree<Typename, null_type, less<Typename>, rb_tree_tag,tree_order_statistics_node_update>`).
*   **Usage:** Create an object of the `ordered_set` struct and then call the member functions.

*Functions:*
    *   `kth_element(int idx)`: Returns an iterator to the element at the given index.
    *   `index(Typename val)`: Returns the index of the first element that is not less than the given value.
    *   `index(iterator it)`: Returns the index of the given iterator.

## ordered_multiset

```cpp
template <typename Typename = int, class Parent = tree<Typename, null_type, less_equal<Typename>, rb_tree_tag,tree_order_statistics_node_update>>
struct ordered_multiset : Parent{
    // ...
};
```

*   **Description:** A struct for implementing an ordered multiset using policy-based data structures from GNU libstdc++.
*   *Template Parameters:*
    *   `Typename`: The type of the elements in the multiset (default: int).
    *   `Parent`: The underlying tree structure (default: `tree<Typename, null_type, less_equal<Typename>, rb_tree_tag,tree_order_statistics_node_update>`).
*   **Usage:** Create an object of the `ordered_multiset` struct and then call the member functions.

*Functions:*
    *   `lower_bound(Typename val)`: Returns an iterator to the first element that is not less than the given value.
    *   `upper_bound(Typename val)`: Returns an iterator to the first element that is greater than the given value.
    *   `erase(iterator it)`: Erases the element pointed to by the given iterator.
    *   `erase(Typename val)`: Erases a single instance of the given value.
    *   `kth_element(int idx)`: Returns an iterator to the element at the given index.
    *   `index(Typename val)`: Returns the index of the first element that is not less than the given value.
    *   `index(iterator it)`: Returns the index of the given iterator.
