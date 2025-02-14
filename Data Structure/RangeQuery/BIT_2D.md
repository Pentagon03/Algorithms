# Data Structure/RangeQuery/BIT_2D.cpp

This file contains a struct. You need to create an object of the struct to use it.

## BIT_2D

```cpp
template<typename T>
struct BIT_2D{
	// ...
};
```

*   **Description:** A struct for implementing a 2D Binary Indexed Tree (Fenwick Tree).
*   **Template Parameters:**
    *   `T`: The type of the elements in the BIT.
*   **Usage:** Create an object of the `BIT_2D` struct and then call the member functions.

*   **Functions:**
    *   `upd(int x, int y, T val)`: Updates the value at index (x, y) by adding `val`.
    *   `qry(int x, int y) const`: Queries the sum of the range from (1, 1) to (x, y).
    *   `qry(int a, int b, int c, int d)`: Queries the sum of the range from (a, b) to (c, d).
