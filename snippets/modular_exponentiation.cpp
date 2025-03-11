#include <bits/stdc++.h>
using namespace std;

// Function to compute (base^exp) % mod in O(log exp) time
long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod; // If exp is odd
        base = (base * base) % mod; // Square the base
        exp /= 2; // Reduce exponent
    }
    return result;
}

int main() {
    long long base, exp, mod;
    cin >> base >> exp >> mod;
    cout << modExpo(base, exp, mod) << endl;
    return 0;
}
