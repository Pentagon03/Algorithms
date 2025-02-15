# Geometry_All.cpp

This file implements a comprehensive collection of geometric algorithms and data structures within the `Geometry` namespace.

## Usage

*   **Description:** This file provides a comprehensive set of geometric algorithms and data structures, including points, lines, circles, polygons, and related operations, all within the `Geometry` namespace.
*   **Namespaces:**
    *   `Geometry`
        *   **Description:** A namespace that encapsulates all geometric algorithms and data structures.
        *   **Structs:**
            *   `Point`: Represents a point in 2D space.
                *   **Members:**
                    *   `x`: The x-coordinate of the point.
                    *   `y`: The y-coordinate of the point.
                *   **Functions:**
                    *   Various operators for point arithmetic (addition, subtraction, multiplication, division).
                    *   `norm()`: Returns the Euclidean norm (distance from the origin) of the point.
                    *   `norm2()`: Returns the squared Euclidean norm of the point.
                    *   `arg()`: Returns the angle of the point with respect to the x-axis.
                    *   `perpendicular()`: Returns a vector perpendicular to the point.
                    *   `unit()`: Returns a unit vector with the same direction as the point.
            *   `Line`: Represents a line in 2D space.
                *   **Members:**
                    *   `s`: A point on the line.
                    *   `e`: Another point on the line.
                *   **Functions:**
                    *   `length()`: Returns the length of the line segment.
                    *   `length2()`: Returns the squared length of the line segment.
                    *   `is_on_line(Point x)`: Checks if a point x is on the line.
                    *   `chk_inter(Line p, Line q)`: Checks if two lines intersect.
                    *   `parrallel_inter(Line a, Line b)`: Returns the intersection point of two parallel lines.
                    *   `inter(Line p, Line q)`: Returns the intersection point of two lines.
                    *   `dist_signed(Line a, Point x)`: Returns the signed distance from a point x to the line a.
                    *   `dist(Line a, Point x)`: Returns the distance from a point x to the line a.
        *   **Functions:**
            *   `dot(Point a, Point b)`: Returns the dot product of two points.
            *   `dist(Point a, Point b)`: Returns the distance between two points.
            *   `dist2(Point a, Point b)`: Returns the squared distance between two points.
            *   `cross(Point a, Point b)`: Returns the cross product of two points.
            *   `cross(Point a, Point b, Point c)`: Returns the cross product of vectors b-a and c-a.
            *   `ccw(Point a, Point b, Point c)`: Returns the orientation of point c with respect to the line formed by points a and b.
            *   `cmp_angle(Point a, Point b)`: Compares two points by their angle with respect to the origin.
            *   `area_signed(Point a, Point b, Point c)`: Returns the signed area of the triangle formed by points a, b, and c.
            *   `area(Point a, Point b, Point c)`: Returns the area of the triangle formed by points a, b, and c.
            *   `getCH(Polygon pg)`: Returns the convex hull of a polygon.
            *   `find_farthest(const Polygon&v)`: Finds the farthest pair of points in a polygon.
            *   `point_in_polygon_naive(const Polygon& h,const Point& p)`: Checks if a point is inside a polygon (naive method).
            *   `is_point_in_convex(Polygon &p, const Point &x)`: Checks if a point is inside a convex polygon.
            *   `is_point_on_polygon(const Polygon& p, const Point &z)`: Checks if a point is on a polygon.
            *   `winding_number(Polygon &p, const Point &z)`: Returns the winding number of a point with respect to a polygon.
            *   `is_point_in_polygon(Polygon &p, const Point &z)`: Checks if a point is inside a polygon.