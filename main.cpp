#include "templates/competitive.h"
using namespace NumberTheory;

int32_t main() {
    fast_io();
    cout << "Testing Number Theory Algorithms:\n\n";

    // 1. Binary Exponentiation
    cout << "1. Binary Exponentiation (2^10): " << binary_exponentiation(2, 10) << "\n";

    // 2. Extended GCD
    int x, y;
    int gcd = extended_gcd(56, 98, x, y);
    cout << "2. Extended GCD (56, 98): GCD = " << gcd << ", x = " << x << ", y = " << y << "\n";

    // 3. Chinese Remainder Theorem
    vector<long long> num = {3, 5, 7};
    vector<long long> rem = {2, 3, 2};
    cout << "3. Chinese Remainder Theorem: " << chinese_remainder_theorem(num, rem) << "\n";

    // 4. LCM
    cout << "4. LCM (15, 20): " << lcm(15, 20) << "\n";

    // 5. Modular Exponentiation
    cout << "5. Modular Exponentiation (2^10 % 1000): " << mod_exp(2, 10, 1000) << "\n";

    // 6. Modular Inverse
    cout << "6. Modular Inverse (3 mod 11): " << mod_inverse(3, 11) << "\n";

    // 7. Prime Check
    cout << "7. Prime Check (31): " << (is_prime(31) ? "Yes" : "No") << "\n";

    // 8. Sieve of Eratosthenes
    vector<bool> primes = sieve(50);
    cout << "8. Sieve up to 50: ";
    for (int i = 0; i <= 50; i++) {
        if (primes[i]) cout << i << " ";
    }
    cout << "\n";

    // 9. Prime Factors
    cout << "9. Prime Factors of 84: ";
    vector<pair<long long, int>> factors = prime_factors(84);
    for (auto [prime, count] : factors) cout << prime << "^" << count << " ";
    cout << "\n";

    // 10. Fibonacci (Logarithmic)
    cout << "10. Fibonacci (10): " << fibonacci_nth(10) << "\n";

    // 11. Divisor Count and Sum
    auto [count, sum] = divisor_count_sum(28);
    cout << "11. Divisor Count of 28: " << count << "\n";
    cout << "11. Divisor Sum of 28: " << sum << "\n";

    // 12. Euler's Totient Function
    cout << "12. Euler's Totient (36): " << eulers_totient(36) << "\n";

    // 13. Lucas Theorem
    cout << "13. Lucas Theorem C(10, 2) % 13: " << lucas_theorem(10, 2, 13) << "\n";

    // 14. Miller-Rabin Primality Test
    cout << "14. Miller-Rabin Primality Test (101): " << (miller_rabin(101, 5) ? "Prime" : "Not Prime") << "\n";

    // 15. Modular Arithmetic
    cout << "15. Modular Arithmetic:\n";
    cout << "Modular Addition (7 + 5 % 3): " << mod_add(7, 5, 3) << "\n";
    cout << "Modular Subtraction (7 - 5 % 3): " << mod_sub(7, 5, 3) << "\n";
    cout << "Modular Multiplication (7 * 5 % 3): " << mod_mul(7, 5, 3) << "\n";
    cout << "Modular Division (7 / 5 % 3): " << mod_div(7, 5, 3) << "\n";

    cout << "\nAll tests completed!\n";

    return 0;
}
