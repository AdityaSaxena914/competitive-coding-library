#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace NumberTheory
{

    // ======================= CONSTANTS =======================
    const long long MOD = 1e9 + 7; // Common modulus

    // =================== 1. Binary Exponentiation ===================
    long long binary_exponentiation(long long base, long long exp)
    {
        long long res = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // =================== 2. Extended GCD ===================
    long long extended_gcd(long long a, long long b, long long &x, long long &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1;
        long long gcd = extended_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }

    // =================== 3. Modular Inverse ===================
    long long mod_inverse(long long a, long long mod = MOD)
    {
        long long x, y;
        long long g = extended_gcd(a, mod, x, y);
        if (g != 1)
            return -1; // Inverse doesn't exist
        return (x % mod + mod) % mod;
    }

    // =================== 4. LCM ===================
    long long lcm(long long a, long long b)
    {
        return (a / __gcd(a, b)) * b;
    }

    // =================== 5. Modular Exponentiation ===================
    long long mod_exp(long long base, long long exp, long long mod = MOD)
    {
        long long res = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // =================== 6. Prime Check ===================
    bool is_prime(long long n)
    {
        if (n <= 1)
            return false;
        for (long long i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    // =================== 7. Sieve of Eratosthenes ===================
    vector<bool> sieve(int n)
    {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }

    // =================== 8. Prime Factors ===================
    vector<pair<long long, int>> prime_factors(long long n)
    {
        vector<pair<long long, int>> factors;
        for (long long i = 2; i * i <= n; i++)
        {
            int count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            if (count > 0)
                factors.emplace_back(i, count);
        }
        if (n > 1)
            factors.emplace_back(n, 1);
        return factors;
    }

    // =================== 9. Fibonacci (Logarithmic) ===================
    long long fibonacci_nth(long long n)
    {
        if (n <= 1)
            return n;
        long long a = 0, b = 1;
        for (int i = 2; i <= n; i++)
        {
            long long temp = (a + b) % MOD;
            a = b;
            b = temp;
        }
        return b;
    }

    // =================== 10. Divisor Count and Sum ===================
    pair<int, long long> divisor_count_sum(long long n)
    {
        int count = 0;
        long long sum = 0;
        for (long long i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                count++;
                sum += i;
                if (i != n / i)
                {
                    count++;
                    sum += n / i;
                }
            }
        }
        return {count, sum};
    }

    // =================== 11. Euler's Totient Function ===================
    long long eulers_totient(long long n)
    {
        long long result = n;
        for (long long i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    }

    // =================== 12. Lucas Theorem ===================
    long long lucas_theorem(long long n, long long k, long long mod)
    {
        if (k == 0)
            return 1;
        long long ni = n % mod, ki = k % mod;
        if (ki > ni)
            return 0;
        return (lucas_theorem(n / mod, k / mod, mod) * mod_exp(ni, ki, mod)) % mod;
    }

    // =================== 13. Miller-Rabin Primality Test ===================
    bool miller_rabin(long long n, int iter = 5)
    {
        if (n < 2)
            return false;
        if (n != 2 && n % 2 == 0)
            return false;
        long long d = n - 1;
        while (d % 2 == 0)
            d /= 2;

        auto check = [](long long n, long long d, long long a)
        {
            long long x = mod_exp(a, d, n);
            if (x == 1 || x == n - 1)
                return true;
            while (d != n - 1)
            {
                x = (x * x) % n;
                d *= 2;
                if (x == 1)
                    return false;
                if (x == n - 1)
                    return true;
            }
            return false;
        };

        vector<long long> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
        for (auto a : bases)
        {
            if (a >= n)
                break;
            if (!check(n, d, a))
                return false;
        }
        return true;
    }

    // =================== 14. Modular Arithmetic ===================
    long long mod_add(long long a, long long b, long long mod = MOD)
    {
        return (a + b) % mod;
    }

    long long mod_sub(long long a, long long b, long long mod = MOD)
    {
        return (a - b + mod) % mod;
    }

    long long mod_mul(long long a, long long b, long long mod = MOD)
    {
        return (a * b) % mod;
    }

    long long mod_div(long long a, long long b, long long mod = MOD)
    {
        long long inv = mod_inverse(b, mod);
        if (inv == -1)
            throw runtime_error("Division not defined");
        return (a * inv) % mod;
    }

    // =================== 15. Chinese remainder theorem ===================
    long long chinese_remainder_theorem(const vector<long long> &num, const vector<long long> &rem)
    {
        long long prod = 1;
        for (long long n : num)
            prod *= n;
        long long result = 0;
        for (int i = 0; i < num.size(); i++)
        {
            long long pp = prod / num[i];
            result += rem[i] * mod_inverse(pp, num[i]) * pp;
        }
        return result % prod;
    }

} // namespace NumberTheory
