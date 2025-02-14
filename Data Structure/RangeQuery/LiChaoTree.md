# Data Structure/RangeQuery/LiChaoTree.cpp

This file contains a struct. You need to create an object of the struct to use it.

## LCT (Li Chao Tree)

```cpp
struct LCT {
	ll s, e;
	Line line;
	LCT *l=0, *r=0;
	LCT(ll S, ll E):s(S),e(E){}
    inline static thread_local deque<LCT> alloc;
    static LCT* make(ll S, ll E){
        alloc.emplace_back(S, E);
        return &alloc.back();
    }
	void insert(Line f);
	ll get(ll x);
};
```

*   **Description:** A struct for implementing a Li Chao Tree.
*   **Usage:** Use `LCT::make(min_x, max_x)` to create a Li Chao Tree, then call the member functions.

*   **Functions:**
    *   `LCT(ll S, ll E)`: Constructor with range `[S, E]`.
    *   `static LCT* make(ll S, ll E)`: Creates a new `LCT` node with range `[S, E]`.
    *   `void insert(Line f)`: Inserts a line `f` into the Li Chao Tree.
        ```cpp
        void insert(Line f);
        ```
        *   **Parameters:**
            *   `f`: The line to insert, represented as a `Line` struct (a*x + b).
    *   `ll get(ll x)`: Queries the maximum value at point `x`.
        ```cpp
        ll get(ll x);
        ```
        *   **Parameters:**
            *   `x`: The x-coordinate to query.
        *   **Returns:** The maximum value among all lines at point `x`.