# Data Structure/persistent_lefitist_heap.cpp

This file defines a `PersistentLeftistHeap` struct for implementing a persistent leftist heap.

## PersistentLeftistHeap Struct

*   **Description:** This file defines a `PersistentLeftistHeap` struct that implements a persistent leftist heap, which is a heap-based data structure that supports efficient merging and allows you to maintain previous versions of the heap.

*   **Template:**
    *   `PersistentLeftistHeap<Key, Value>`: A template for creating a persistent leftist heap with keys of type `Key` and values of type `Value`.
        ```cpp
        template <typename Key, typename Value>
        struct PersistentLeftistHeap {
            // ...
        };
        ```
        *   **Parameters:**
            *   `Key`: The type of the keys in the heap.
            *   `Value`: The type of the values associated with the keys.

*   **Struct Members:**
    *   `node_rank`: The rank of the node.
    *   `key`: The key of the node.
    *   `value`: The value of the node.
    *   `left`: A pointer to the left child.
    *   `right`: A pointer to the right child.

*   **Functions:**
    *   `PersistentLeftistHeap(int rank_, Key key_, Value value_, self_t* left_, self_t* right_)`: Constructor that initializes the node.
    *   `friend self_t* heap_insert(self_t* a, const Key &k, const Value &v, std::deque<self_t> &alloc)`: Inserts a new node with key `k` and value `v` into the heap.
