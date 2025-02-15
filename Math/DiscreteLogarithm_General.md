# DiscreteLogarithm_General.cpp

This file implements an algorithm for solving the discrete logarithm problem in a general group.

## Usage

*   **Description:** This file implements an algorithm for solving the discrete logarithm problem in a general group.
*   **Functions:**
    *   `extendedGcd(ll a, ll b)`: Calculates the extended GCD of a and b.
    *   `power(ll a, ll b)`: Calculates a raised to the power of b.
    *   `powerMod(ll a, ll b, ll mod)`: Calculates a raised to the power of b modulo mod.
    *   `fact(ll n)`: Returns the prime factorization of n.
    *   `phi(ll n)`: Calculates Euler's totient function for n.
    *   `multiplicativeOrder(ll a, ll m)`: Calculates the multiplicative order of a modulo m.
    *   `discreteLogarithm(ll a, ll b, ll m)`: Calculates the discrete logarithm of b with base a modulo m.