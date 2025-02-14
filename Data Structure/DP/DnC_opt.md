# Data Structure/DP/DnC_opt.cpp

This file provides a template for Divide and Conquer Optimization.

## Divide and Conquer Optimization Template

*   **Description:** This file provides a template for applying Divide and Conquer Optimization to dynamic programming problems where the optimal substructure exhibits monotonicity.

*   **Usage:**
    *   The code assumes a DP recurrence of the form `cur[i] = min(pre[j] + C(j,i))`, where `Opt(i)` is monotone.
    *   `C(j, i)` is the cost function, which is typically a Monge array.
    *   The `dnc` lambda function performs the divide and conquer optimization.

*   **Lambda Functions:**
    *   `C(int j, int i)`: The cost function that calculates the cost of transitioning from state `j` to state `i`.
        *   **Important:** You should carefully handle the case where `j > i`.
    *   `dnc(auto& self, int l, int r, int optl, int optr)`: A recursive lambda function that performs the divide and conquer optimization.
        *   `l`: The left boundary of the current range.
        *   `r`: The right boundary of the current range.
        *   `optl`: The left boundary of the optimal range.
        *   `optr`: The right boundary of the optimal range.
