# Data Structure/IntervalContainer.cpp

This file defines an `IntervalSet` class for managing a set of disjoint intervals.

## IntervalSet Class

*   **Description:** This file defines an `IntervalSet` class that allows you to manage a set of disjoint intervals, supporting adding and removing intervals.

*   **Class:**
    *   `IntervalSet`: A class for managing a set of disjoint intervals, represented as pairs of integers `(L, R)` where the interval is `[L, R)`.
        ```cpp
        class IntervalSet : public set<pii> {
            // ...
        };
        ```

*   **Functions:**
    *   `set<pii>::iterator add(int L, int R)`: Adds the interval `[L, R)` to the set.
        *   If the interval is empty (`L == R`), it returns `end()`.
        *   It merges overlapping intervals and returns an iterator to the newly added or merged interval.
    *   `void remove(int L, int R)`: Removes the interval `[L, R)` from the set.
        *   It splits the existing intervals as necessary to remove the specified range.
