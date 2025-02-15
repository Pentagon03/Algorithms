# cp-geo.cpp

This file implements various geometric algorithms and data structures.

## Usage

*   **Description:** This file implements a comprehensive set of geometric algorithms and data structures, including points, lines, circles, polygons, and related operations.
*   **Namespaces:**
    *   `geo`
        *   **Description:** A namespace that encapsulates all geometric algorithms and data structures.
        *   **Structs:**
            *   `PT`: Represents a point in 2D space.
                *   **Members:**
                    *   `x`: The x-coordinate of the point.
                    *   `y`: The y-coordinate of the point.
                *   **Functions:**
                    *   Various operators for point arithmetic (addition, subtraction, multiplication, division).
                    *   `norm()`: Returns the Euclidean norm (distance from the origin) of the point.
                    *   `norm2()`: Returns the squared Euclidean norm of the point.
                    *   `perp()`: Returns a vector perpendicular to the point.
                    *   `arg()`: Returns the angle of the point with respect to the x-axis.
                    *   `truncate(ld r)`: Returns a vector with norm r and having the same direction.
            *   `line`: Represents a line in 2D space.
                *   **Members:**
                    *   `a`: A point on the line.
                    *   `b`: Another point on the line.
                    *   `v`: The direction vector of the line.
                    *   `c`: The offset of the line.
                *   **Functions:**
                    *   Various constructors for defining a line.
                    *   `side(PT p)`: Returns the side of the line on which the point p lies.
                    *   `perpendicular_through(PT p)`: Returns a line perpendicular to this line and passing through point p.
                    *   `translate(PT t)`: Translates the line by vector t.
                    *   `cmp_by_projection(PT p, PT q)`: Compares two points by their orthogonal projection on this line.
                    *   `shift_left(ld d)`: Shifts the line to the left by a distance d.
            *   `circle`: Represents a circle in 2D space.
                *   **Members:**
                    *   `p`: The center of the circle.
                    *   `r`: The radius of the circle.
                *   **Functions:**
                    *   Various constructors for defining a circle.
                    *   `area()`: Returns the area of the circle.
                    *   `circumference()`: Returns the circumference of the circle.
        *   **Functions:**
            *   `dot(PT a, PT b)`: Returns the dot product of two points.
            *   `dist2(PT a, PT b)`: Returns the squared distance between two points.
            *   `dist(PT a, PT b)`: Returns the distance between two points.
            *   `cross(PT a, PT b)`: Returns the cross product of two points.
            *   `cross2(PT a, PT b, PT c)`: Returns the cross product of vectors b-a and c-a.
            *   `orientation(PT a, PT b, PT c)`: Returns the orientation of point c with respect to the line formed by points a and b.
            *   `project_from_point_to_line(PT a, PT b, PT c)`: Projects point c onto the line formed by points a and b.
            *   `reflection_from_point_to_line(PT a, PT b, PT c)`: Reflects point c across the line formed by points a and b.
            *   `dist_from_point_to_line(PT a, PT b, PT c)`: Returns the distance from point c to the line formed by points a and b.
            *   `is_point_on_seg(PT a, PT b, PT p)`: Checks if point p lies on the line segment formed by points a and b.
            *   `project_from_point_to_seg(PT a, PT b, PT c)`: Projects point c onto the line segment formed by points a and b.
            *   `dist_from_point_to_seg(PT a, PT b, PT c)`: Returns the distance from point c to the line segment formed by points a and b.
            *   `is_parallel(PT a, PT b, PT c, PT d)`: Checks if the line formed by points a and b is parallel to the line formed by points c and d.
            *   `are_lines_same(PT a, PT b, PT c, PT d)`: Checks if the line formed by points a and b is the same as the line formed by points c and d.
            *   `angle_bisector(PT &a, PT &b, PT &c)`: Returns the angle bisector of angle <abc.
            *   `point_line_relation(PT a, PT b, PT p)`: Returns the relation of point p to the line formed by points a and b.
            *   `point_seg_relation(PT a, PT b, PT p)`: Returns the relation of point p to the line segment formed by points a and b.
            *   `line_line_intersection(PT a, PT b, PT c, PT d, PT &ans)`: Finds the intersection point between the line formed by points a and b and the line formed by points c and d.
            *   `seg_seg_intersection(PT a, PT b, PT c, PT d, PT &ans)`: Finds the intersection point between the line segment formed by points a and b and the line segment formed by points c and d.
            *   `seg_seg_intersection_inside(PT a, PT b, PT c, PT d)`: Finds the intersection points between the line segment formed by points a and b and the line segment formed by points c and d, including overlapping segments.
            *   `seg_line_relation(PT a, PT b, PT c, PT d)`: Returns the relation between the line segment formed by points a and b and the line formed by points c and d.
            *   `seg_line_intersection(PT a, PT b, PT c, PT d, PT &ans)`: Finds the intersection point between the line segment formed by points a and b and the line formed by points c and d.
            *   `dist_from_seg_to_seg(PT a, PT b, PT c, PT d)`: Returns the distance between the line segment formed by points a and b and the line segment formed by points c and d.
            *   `dist_from_point_to_ray(PT a, PT b, PT c)`: Returns the distance from point c to the ray starting at point a with direction vector b.
            *   `ray_ray_intersection(PT as, PT ad, PT bs, PT bd)`: Checks if the ray starting at point as with direction vector ad intersects the ray starting at point bs with direction vector bd.
            *   `ray_ray_distance(PT as, PT ad, PT bs, PT bd)`: Returns the distance between the ray starting at point as with direction vector ad and the ray starting at point bs with direction vector bd.
            *   `circle_point_relation(PT p, ld r, PT b)`: Returns the relation between point b and the circle with center p and radius r.
            *   `circle_line_relation(PT p, ld r, PT a, PT b)`: Returns the relation between the line formed by points a and b and the circle with center p and radius r.
            *   `circle_line_intersection(PT c, ld r, PT a, PT b)`: Finds the intersection points between the line formed by points a and b and the circle with center c and radius r.
            *   `circle_circle_relation(PT a, ld r, PT b, ld R)`: Returns the relation between the circle with center a and radius r and the circle with center b and radius R.
            *   `circle_circle_intersection(PT a, ld r, PT b, ld R)`: Finds the intersection points between the circle with center a and radius r and the circle with center b and radius R.
            *   `get_circle(PT a, PT b, ld r, circle &c1, circle &c2)`: Finds the circles passing through points a and b with radius r.
            *   `get_circle(line u, PT q, ld r1, circle &c1, circle &c2)`: Finds the circles tangent to line u, passing through point q, and with radius r1.
            *   `get_apollonius_circle(PT p, PT q, ld rp, ld rq)`: Finds the Apollonius circle for points p and q with distance ratios rp and rq.
            *   `circle_circle_area(PT a, ld r1, PT b, ld r2)`: Returns the area of the intersection between two circles.
            *   `tangent_lines_from_point(PT p, ld r, PT q, line &u, line &v)`: Finds the tangent lines from point q to the circle with center p and radius r.
            *   `tangents_lines_from_circle(PT c1, ld r1, PT c2, ld r2, bool inner, line &u, line &v)`: Finds the tangent lines from the circle with center c1 and radius r1 to the circle with center c2 and radius r2.
            *   `area_of_triangle(PT a, PT b, PT c)`: Returns the area of the triangle formed by points a, b, and c.
            *   `is_point_in_triangle(PT a, PT b, PT c, PT p)`: Checks if point p lies inside the triangle formed by points a, b, and c.
            *   `perimeter(vector<PT> &p)`: Returns the perimeter of the polygon formed by the points in vector p.
            *   `area(vector<PT> &p)`: Returns the area of the polygon formed by the points in vector p.
            *   `centroid(vector<PT> &p)`: Returns the centroid of the polygon formed by the points in vector p.
            *   `get_direction(vector<PT> &p)`: Returns the direction of the polygon formed by the points in vector p (0 for clockwise, 1 for counterclockwise).
            *   `geometric_median(vector<PT> p)`: Returns the geometric median of the points in vector p.
            *   `convex_hull(vector<PT> &p)`: Returns the convex hull of the points in vector p.
            *   `is_convex(vector<PT> &p)`: Checks if the polygon formed by the points in vector p is convex.
            *   `is_point_in_convex(vector<PT> &p, const PT &x)`: Checks if point x lies inside the convex polygon formed by the points in vector p.
            *   `is_point_on_polygon(vector<PT> &p, const PT &z)`: Checks if point z lies on the boundary of the polygon formed by the points in vector p.
            *   `winding_number(vector<PT> &p, const PT &z)`: Returns the winding number of point z with respect to the polygon formed by the points in vector p.
            *   `is_point_in_polygon(vector<PT> &p, const PT &z)`: Checks if point z lies inside the polygon formed by the points in vector p.
            *   `extreme_vertex(vector<PT> &p, const PT &z, const int top)`: Returns the index of the vertex in the convex polygon p that has the maximum dot product with vector z.
            *   `diameter(vector<PT> &p)`: Returns the diameter of the convex polygon formed by the points in vector p.
            *   `width(vector<PT> &p)`: Returns the width of the convex polygon formed by the points in vector p.
            *   `minimum_enclosing_rectangle(vector<PT> &p)`: Returns the minimum perimeter of a rectangle enclosing the convex polygon formed by the points in vector p.
            *   `minimum_enclosing_circle(vector<PT> &p)`: Returns the minimum enclosing circle of the points in vector p.
            *   `cut(vector<PT> &p, PT a, PT b)`: Cuts the polygon formed by the points in vector p with the line formed by points a and b.
            *   `polygon_line_intersection(vector<PT> p, PT a, PT b)`: Returns the total intersected length of the line formed by points a and b with the polygon formed by the points in vector p.
            *   `convex_line_intersection(vector<PT> &p, PT a, PT b, int top)`: Finds the intersection of the line formed by points a and b with the convex polygon formed by the points in vector p.
            *   `point_poly_tangent(vector<PT> &p, PT Q, int dir, int l, int r)`: Finds a tangent from point Q to the convex polygon formed by the points in vector p.
            *   `tangents_from_point_to_polygon(vector<PT> &p, PT Q)`: Finds the tangents from point Q to the convex polygon formed by the points in vector p.
            *   `dist_from_point_to_polygon(vector<PT> &p, PT z)`: Returns the distance from point z to the convex polygon formed by the points in vector p.
            *   `dist_from_polygon_to_line(vector<PT> &p, PT a, PT b, int top)`: Returns the distance from the convex polygon formed by the points in vector p to the line formed by points a and b.
            *   `dist_from_polygon_to_polygon(vector<PT> &p1, vector<PT> &p2)`: Returns the distance between the convex polygon formed by the points in vector p1 and the convex polygon formed by the points in vector p2.
            *   `maximum_dist_from_polygon_to_polygon(vector<PT> &u, vector<PT> &v)`: Returns the maximum distance between the convex polygon formed by the points in vector u and the convex polygon formed by the points in vector v.
            *   `polygon_union(vector<vector<PT>> &p)`: Calculates the area of the union of n polygons.
            *   `half_plane_intersection(vector<HP> h)`: Finds the intersection of half-planes.
            *   `reorder_polygon(vector<PT> &p)`: Reorders the vertices of a polygon such that the (bottom, left)-most point is at the first position.
            *   `minkowski_sum(vector<PT> a, vector<PT> b)`: Returns the convex hull of the Minkowski sum of two polygons.
            *   `_triangle_circle_intersection(PT c, ld r, PT a, PT b)`: Returns the area of the intersection between a circle and a triangle.
            *   `polygon_circle_intersection(vector<PT> &v, PT p, ld r)`: Returns the area of the intersection between a polygon and a circle.
            *   `maximum_circle_cover(vector<PT> p, ld r, circle &c)`: Finds a circle of radius r that contains as many points as possible.
            *   `maximum_inscribed_circle(vector<PT> p)`: Returns the radius of the maximum inscribed circle in a convex polygon.
            *   `triangulate(vector<PT> p)`: Performs ear decomposition to triangulate a polygon.
            *   `get_maximum_polygon_area_for_given_lengths(vector<ld> v)`: Given a list of side lengths, returns the maximum area of a non-degenerate polygon that can be formed.