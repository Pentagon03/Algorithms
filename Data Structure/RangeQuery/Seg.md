# Data Structure/RangeQuery/Seg.cpp

This file contains a struct. You need to create an object of the struct to use it.

## Seg (Segment Tree)

```cpp
template<class S, S (*e)(), S (*op)(S, S)>
struct Seg{
    public:
    Seg(int n = 0);
    Seg(const vector<S>&v);
    const S& get(int i) const;
    void upd(int i, S val);
    S qry_all();
    S qry(int l,int r) const;
    private:
    int n;
    vector<S> tree;
    void pull(int i);
};
```

*   **Description:** A struct for implementing a Segment Tree with point updates.
*   **Template Parameters:**
    *   `S`: The type of the monoid for the tree.
    *   `e`: A function that returns the identity element of the monoid.
    *   `op`: A function that performs the monoid action.
*   **Usage:** Create an object of the `Seg` struct and then call the member functions.

*   **Functions:**
    *   `Seg(int n = 0)`: Constructor that initializes the tree with `n` elements, all set to the identity element.
        ```cpp
        Seg(int n = 0);
        ```
        *   **Parameters:**
            *   `n`: The number of elements in the tree.
    *   `Seg(const vector<S>&v)`: Constructor that initializes the tree with the elements from the given vector.
        ```cpp
        Seg(const vector<S>&v);
        ```
        *   **Parameters:**
            *   `v`: The input vector.
    *   `const S& get(int i) const`: Returns the value of the i-th element.
        ```cpp
        const S& get(int i) const;
        ```
        *   **Parameters:**
            *   `i`: The index of the element to retrieve.
        *   **Returns:** The value of the i-th element.
    *   `void upd(int i, S val)`: Updates the value of the i-th element to `val`.
        ```cpp
        void upd(int i, S val);
        ```
        *   **Parameters:**
            *   `i`: The index of the element to update.
            *   `val`: The new value for the element.
    *   `S qry_all()`: Queries the entire range and returns the result of the monoid action.
        ```cpp
        S qry_all();
        ```
        *   **Returns:** The result of the monoid action over the entire range.
    *   `S qry(int l,int r) const`: Queries the range `[l, r]` and returns the result of the monoid action.
        ```cpp
        S qry(int l,int r) const;
        ```
        *   **Parameters:**
            *   `l`: The left boundary of the range.
            *   `r`: The right boundary of the range.
        *   **Returns:** The result of the monoid action over the range `[l, r]`.