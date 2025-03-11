#include "templates/competitive.h"

int32_t main() {
    fast_io();  // Testing Fast I/O

    cout << "GCD of 36 and 60: " << gcd(36, 60) << endl;
    cout << "LCM of 36 and 60: " << lcm(36, 60) << endl;

    int base = 2, exp = 10;
    cout << "2^10 mod 1e9+7: " << mod_exp(base, exp) << endl;

    int num = 29;
    cout << num << (is_prime(num) ? " is prime" : " is not prime") << endl;

    vector<int> factors = prime_factors(60);
    cout << "Prime factors of 60: ";
    for (int f : factors) cout << f << " ";
    cout << endl;

    return 0;
}
