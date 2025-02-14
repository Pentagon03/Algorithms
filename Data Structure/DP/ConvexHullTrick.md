# Data Structure/DP/ConvexHullTrick.cpp

This file defines a `CHT` struct that implements a Convex Hull Trick container.

## CHT Struct

*   **Description:** This file defines a `CHT` struct that implements a Convex Hull Trick container, allowing you to add lines and query the minimum value for a given x.

*   **Structs:**
    *   `Line`: Represents a line with the equation y = kx + m.
        *   `k`: The slope of the line.
        *   `m`: The y-intercept of the line.
        *   `p`: The x-coordinate where this line intersects with the previous line in the container.

*   **Struct Members:**
    *   `stk`: A vector storing the lines in the convex hull.
    *   `n`: The number of lines in the convex hull.
    *   `p`: The index of the last queried line.

*   **Functions:**
    *   `bool add(const L& t)`: Adds a line to the container, maintaining the convex hull property.
    *   `L qry(P x)`: Queries the container for the line that minimizes the value at the given x-coordinate, assuming x is increasing.
    *   `L qry_bs(P x)`: Queries the container for the line that minimizes the value at the given x-coordinate, using binary search (for unsorted x).
