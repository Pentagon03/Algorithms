# [WIP] Sieve.cpp

This file implements a sieve algorithm for finding prime numbers and related functions.

## Usage

*   **Description:** This file implements a sieve algorithm for finding prime numbers and related functions, such as Euler's totient function, Möbius function, divisor count, and divisor sum.
*   **Namespaces:**
    *   `Sieve`
        *   **Description:** A namespace that encapsulates the sieve algorithm and related functions.
        *   **Structs:**
            *   `Sieve`
                *   **Description:** A struct that implements the sieve algorithm.
                *   **Members:**
                    *   `SZ`: The size of the sieve.
                    *   `p`: A vector storing the prime numbers.
                    *   `spf`: A vector storing the smallest prime factor of each number.
                    *   `e`: A vector storing the exponent of the smallest prime factor in the prime factorization of each number.
                    *   `phi`: A vector storing the Euler's totient function for each number.
                    *   `mu`: A vector storing the Möbius function for each number.
                    *   `tau`: A vector storing the number of divisors for each number.
                    *   `sigma`: A vector storing the sum of divisors for each number.
                    *   `isp`: A vector storing whether a number is prime.
                *   **Functions:**
                    *   `Sieve(int n=1e6)`: Constructor that initializes the sieve.
                    *   `isprime(int n)`: Checks if a number is prime.
                    *   `factor(int n)`: Returns the prime factorization of a number.
                    *   `primelist(T A,T B)`: Returns a list of prime numbers in the range [A, B).