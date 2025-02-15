# DiscreteLogarithm_Prime.cpp

This file implements an algorithm for solving the discrete logarithm problem modulo a prime number using the Pohlig-Hellman algorithm.

## Usage

*   **Description:** This file implements an algorithm for solving the discrete logarithm problem modulo a prime number using the Pohlig-Hellman algorithm.
*   **Namespaces:**
    *   `DiscreteLog`
        *   **Description:** A namespace that encapsulates the discrete logarithm algorithm.
        *   **Functions:**
            *   `get_random_int(int l,int r)`: Generates a random integer between l and r.
            *   `powmod(int x,int n,int mod=inf)`: Calculates x raised to the power of n modulo mod.
            *   `get_divisor(int n)`: Returns a vector of prime factors of n.
            *   `get_order_prime(int g,int p)`: Calculates the multiplicative order of g modulo p.
            *   `is_primitive(int g, int p)`: Checks if g is a primitive root modulo p.
            *   `get_primitive(int p)`: Finds a primitive root modulo p.
            *   `dlog(int base, int val, int p,int ord = -1)`: Calculates the discrete logarithm of val with base base modulo p.
            *   `ext_gcd(ll a, ll b, ll& x, ll& y)`: Calculates the extended GCD of a and b.
            *   `inv(ll a, ll m)`: Calculates the modular inverse of a modulo m.
            *   `pohlig_hellman(int base,int val,int p)`: Solves the discrete logarithm problem using the Pohlig-Hellman algorithm.