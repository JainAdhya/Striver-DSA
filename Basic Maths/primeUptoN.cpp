#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int primeUptoN(int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    int res = primeUptoN(n);
    cout << res;
}