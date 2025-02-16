# modint_combination.cpp

This file implements a modular arithmetic class and a combination calculator.

## Usage

*   **Description:** This file implements a modular arithmetic class and a combination calculator, which are useful for solving problems involving large numbers modulo a prime.
*   **Template Parameters:**
    *   `P`: The prime modulus.
*   **Structs:**
    *   `modint<P>`
        *   **Description:** A struct that implements modular arithmetic.
        *   **Members:**
            *   `x`: The integer value of the modular integer.
        *   **Functions:**
            *   `norm(int x) const`: Normalizes the integer x to be within the range [0, P).
            *   `val() const`: Returns the integer value of the modular integer.
            *   `pow(ll b)`: Returns the modular integer raised to the power of b.
            *   `inv() const`: Returns the modular inverse of the modular integer.
            *   Various operator overloads for arithmetic operations (+, -, *, /).
    *   `comb<P, UP>`
        *   **Description:** A struct that calculates combinations modulo a prime number.
        *   **Members:**
            *   `n`: The maximum value for which factorials have been precomputed.
            *   `_fac`: A vector storing factorials modulo P.
            *   `_invfac`: A vector storing inverse factorials modulo P.
            *   `_inv`: A vector storing modular inverses.
            *   `bm`: A 2D vector storing binomial coefficients (unsigned long long version).
        *   **Functions:**
            *   `init(int m)`: Initializes the factorial, inverse factorial, and inverse arrays up to m.
            *   `fac(int m)`: Returns the factorial of m modulo P.
            *   `invfac(int m)`: Returns the inverse factorial of m modulo P.
            *   `inv(int m)`: Returns the modular inverse of m modulo P.
            *   `binom(int m, int k)`: Returns the binomial coefficient (m choose k) modulo P.
            *   `init_ull(int m)`: Initializes the binomial coefficient table (unsigned long long version) up to m.
            *   `binom_ull(int m, int k)`: Returns the binomial coefficient (m choose k) as an unsigned long long.