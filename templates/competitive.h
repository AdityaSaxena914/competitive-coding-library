#ifndef COMPETITIVE_H
#define COMPETITIVE_H
#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // To avoid overflow
}

const int MOD = 1e9 + 7;  // Common large prime modulus

// Modular Exponentiation: Computes (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod = MOD) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exponent is odd, multiply result by base
            result = (result * base) % mod;
        base = (base * base) % mod;  // Square the base
        exp /= 2;  // Reduce exponent by half
    }
    return result;
}

// Modular Inverse using Fermat’s Theorem: Computes (a^-1) % mod
long long mod_inverse(long long a, long long mod = MOD) {
    return mod_exp(a, mod - 2, mod);  // Uses mod_exp function
}

// Check if a number is prime (O(√n))
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {  // Checking divisibility by 6k ± 1
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Sieve of Eratosthenes to generate primes up to MAX_N (O(n log log n))
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

// Prime Factorization (O(√n))
vector<int> prime_factors(int n) {
    vector<int> factors;
    while (n % 2 == 0) {  // Factor out all 2s
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {  // Factor out odd numbers
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);  // If n is still > 1, it's a prime
    return factors;
}

#endif // COMPETITIVE_H
