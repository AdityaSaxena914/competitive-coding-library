#include "templates/competitive.h"

int32_t main() {
    fast_io();  // Enable fast I/O

    cout << "Testing Competitive Coding Library 🚀\n\n";

    // Testing GCD & LCM
    int a = 24, b = 36;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << '\n';
    cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << '\n';

    // Testing Modular Exponentiation
    int base = 2, exp = 10;
    cout << base << "^" << exp << " % " << MOD << " = " << mod_exp(base, exp) << '\n';

    // Testing Modular Inverse
    int num = 3;
    cout << "Modular Inverse of " << num << " under mod " << MOD << " = " << mod_inverse(num) << '\n';

    // Testing Prime Check
    int prime_candidate = 29;
    cout << prime_candidate << " is " << (is_prime(prime_candidate) ? "Prime" : "Not Prime") << '\n';

    // Testing Sieve of Eratosthenes
    int limit = 50;
    vector<bool> primes = sieve(limit);
    cout << "Primes up to " << limit << ": ";
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) cout << i << " ";
    }
    cout << '\n';

    // Testing Prime Factorization
    int number = 84;
    vector<int> factors = prime_factors(number);
    cout << "Prime Factors of " << number << ": ";
    for (int f : factors) cout << f << " ";
    cout << '\n';

    return 0;
}
