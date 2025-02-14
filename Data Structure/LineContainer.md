# Data Structure/LineContainer.cpp

This file defines a `LC` struct that implements a dynamic Line Container for Convex Hull Trick.

## LC Struct

*   **Description:** This file defines a `LC` struct that implements a dynamic Line Container for Convex Hull Trick, allowing you to add lines and query the minimum value for a given x.

*   **Struct Members:**
    *   Inherits from `multiset<Line, less<>>`, storing lines sorted by slope.

*   **Structs:**
    *   `Line`: Represents a line with the equation y = kx + m.
        *   `k`: The slope of the line.
        *   `m`: The y-intercept of the line.
        *   `p`: The x-coordinate where this line intersects with the previous line in the container.

*   **Functions:**
    *   `bool add(const Line &t)`: Adds a line to the container, maintaining the convex hull property.
    *   `Line qry(ll x)`: Queries the container for the line that minimizes the value at the given x-coordinate.
    *   `static const ll inf = numeric_limits<ll>::max()`: Defines infinity for long long integers.
