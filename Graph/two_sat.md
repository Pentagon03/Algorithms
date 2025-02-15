# two_sat.cpp

This file implements an algorithm for solving the 2-Satisfiability (2-SAT) problem using strongly connected components (SCCs).

## Usage

*   **Description:** This file implements an algorithm for solving the 2-Satisfiability (2-SAT) problem using strongly connected components (SCCs).
*   **Structs:**
    *   `two_sat`
        *   **Description:** A struct that implements the 2-SAT algorithm.
        *   **Members:**
            *   `n`: The number of variables in the 2-SAT problem.
            *   `ans`: A vector storing the solution to the 2-SAT problem.
            *   `scc`: An instance of the `scc_graph` struct, used to find strongly connected components.
        *   **Functions:**
            *   `add_clause(int x, int y)`: Adds a clause (x OR y) to the 2-SAT formula.
            *   `add_clause(int i, bool a, int j, bool b)`: Adds a clause (i == a OR j == b) to the 2-SAT formula.
            *   `is_equal(int i, bool a, int j, bool b)`: Adds constraints to ensure that (i == a) is equivalent to (j == b).
            *   `atMostOneNaive(const vector<pair<int,bool>>& v)`: Adds constraints to ensure that at most one of the variables in v is true (naive implementation).
            *   `addVar()`: Adds a new variable to the 2-SAT problem.
            *   `atMostOne(const vector<pair<int,bool>>& v)`: Adds constraints to ensure that at most one of the variables in v is true (efficient implementation).
            *   `satisfiable()`: Checks if the 2-SAT formula is satisfiable.
            *   `answer()`: Returns the solution to the 2-SAT problem.