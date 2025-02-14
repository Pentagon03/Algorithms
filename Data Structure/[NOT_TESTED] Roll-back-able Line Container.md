# Data Structure/[NOT_TESTED] Roll-back-able Line Container.cpp

This file defines a `LineContainer` struct that implements a dynamic Convex Hull Trick with rollback capability.

## LineContainer Struct

*   **Description:** This file defines a `LineContainer` struct that implements a dynamic Convex Hull Trick, allowing you to add lines, query the minimum value for a given x, and rollback the operations.

*   **Structs:**
    *   `Line`: Represents a line with the equation y = kx + m.
        *   `k`: The slope of the line.
        *   `m`: The y-intercept of the line.
        *   `p`: The x-coordinate where this line intersects with the previous line in the container.

*   **Struct Members:**
    *   Inherits from `multiset<Line, less<>>`, storing lines sorted by slope.
    *   `info`: A vector storing the sizes of the added lines for rollback.
    *   `S`: A vector storing the lines for rollback.

*   **Functions:**
    *   `bool add(ll k, ll m)`: Adds a line with slope `k` and y-intercept `m` to the container, maintaining the convex hull property.
    *   `void rollback()`: Rolls back the last add operation.
    *   `ll qry(ll x)`: Queries the container for the minimum value at the given x-coordinate.
