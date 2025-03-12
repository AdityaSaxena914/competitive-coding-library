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
vector<pair<long long, int>> prime_factors(long long n) {
    vector<pair<long long, int>> factors;
    int count = 0;
    while (n % 2 == 0) {  // Factor out all 2s
        n /= 2;
        count++;
    }
    if (count > 0) factors.push_back({2, count});
    for (long long i = 3; i * i <= n; i += 2) {  // Factor out odd numbers
        count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) factors.push_back({i, count});
    }
    if (n > 1) factors.push_back({n,1});  // If n is still > 1, it's a prime
    return factors;
}


// Macros
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

// Include all searching algorithms
#include "searching/linear_search.h"
#include "searching/binary_search.h"
#include "searching/lower_bound.h"
#include "searching/upper_bound.h"
#include "searching/first_occurrence.h"
#include "searching/last_occurrence.h"
#include "searching/count_occurrences.h"
#include "searching/exponential_search.h"
#include "searching/jump_search.h"
#include "searching/ternary_search.h"
#include "searching/two_pointer_search.h"
#endif // COMPETITIVE_H
