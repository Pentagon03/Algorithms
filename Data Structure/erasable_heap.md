# Data Structure/erasable_heap.cpp

This file defines a `heap` struct that implements an erasable heap.

## Erasable Heap Struct

*   **Description:** This file defines a `heap` struct that implements an erasable heap, which allows you to push elements and delete specific elements.

*   **Template:**
    *   `heap<T, cmp>`: A template for creating an erasable heap with elements of type `T` and a comparison function `cmp`.
        ```cpp
        template<class T, class cmp = less<T>>
        struct heap{
            // ...
        };
        ```
        *   **Parameters:**
            *   `T`: The type of the elements in the heap.
            *   `cmp`: The comparison function (default: `less<T>`).

*   **Struct Members:**
    *   `iq`: A priority queue for storing inserted elements.
    *   `dq`: A priority queue for storing deleted elements.
    *   `f`: The comparison function.

*   **Functions:**
    *   `void push(T x)`: Pushes an element `x` into the heap.
    *   `void del(T x)`: Marks an element `x` as deleted.
    *   `void upd()`: Updates the heap by removing deleted elements from the top.
    *   `bool empty()`: Checks if the heap is empty.
    *   `T pop()`: Removes and returns the top element of the heap.
    *   `T top()`: Returns the top element of the heap.
