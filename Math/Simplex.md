# Simplex.cpp

This file implements the two-phase simplex algorithm for solving linear programming problems.

## Usage

*   **Description:** This file implements the two-phase simplex algorithm for solving linear programming problems of the form:
    *   maximize c^T x
    *   subject to Ax <= b
    *   x >= 0
*   **Structs:**
    *   `LPSolver`
        *   **Description:** A struct that implements the two-phase simplex algorithm.
        *   **Members:**
            *   `m`: The number of constraints.
            *   `n`: The number of variables.
            *   `B`: A vector storing the indices of the basic variables.
            *   `N`: A vector storing the indices of the non-basic variables.
            *   `D`: A 2D vector representing the simplex tableau.
        *   **Functions:**
            *   `LPSolver(const VVD& A, const VD& b, const VD& c)`: Constructor that initializes the simplex tableau with the given constraint matrix A, constraint vector b, and objective function vector c.
            *   `pivot(int r, int s)`: Performs a pivot operation on the simplex tableau.
            *   `simplex(int phase)`: Performs the simplex algorithm for a given phase.
            *   `solve(VD& x)`: Solves the linear programming problem and stores the optimal solution in x.