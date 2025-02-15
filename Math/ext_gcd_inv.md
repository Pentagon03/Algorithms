# ext_gcd_inv.cpp

This file implements the extended Euclidean algorithm for finding the greatest common divisor (GCD) and modular inverse.

## Usage

*   **Description:** This file implements the extended Euclidean algorithm for finding the greatest common divisor (GCD) and modular inverse.
*   **Functions:**
    *   `ext_gcd(ll a, ll b)`: Calculates the extended GCD of a and b, returning a tuple (g, x, y) such that ax + by = g = gcd(a, b).
    *   `inv(ll a, ll m)`: Calculates the modular inverse of a modulo m.
    *   `do_smth(ll a, ll b, ll s)`: Finds non-negative integer solutions x and y to the equation ax + by = s.