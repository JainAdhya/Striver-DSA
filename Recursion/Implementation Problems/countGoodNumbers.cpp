#include <bits/stdc++.h>
using namespace std;

// VERSION1 
int countGoodNumbers(long long n) {
        const long long mod = 1000000007;

        if (n == 0) {
            return 1;
        }

        if (n % 2 == 1) {
            return (5LL * countGoodNumbers(n - 1)) % mod;
        }

        return (4LL * countGoodNumbers(n - 1)) % mod;
}

// VERSION2

long long power(long long x, long long n) {
        const long long mod = 1000000007;
        long long y = 1;
        x %= mod;

        while (n > 0) {
            if (n % 2 == 1) {
                y = (y * x) % mod;
            }

            x = (x * x) % mod;
            n = n / 2;
        }

        return y;
}

int countGoodNumbers(long long n) {
        const long long mod = 1000000007;

        return (power(5, (n + 1) / 2) *
                power(4, n / 2)) % mod;
}

int main() {

    int ans=countGoodNumbers(2);
    cout << ans;
    return 0;
}