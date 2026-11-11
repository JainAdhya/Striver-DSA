#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
    int low = 1;
    int high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long val = 1;

        for (int i = 0; i < n; i++) {
            val *= mid;

            if (val > m) {
                break;
            }
        }

        if (val == m) {
            return mid;
        } 
        else if (val < m) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n = 3;
    int m = 27;

    int ans = floorSqrt(n, m);
    cout << ans;

    return 0;
}
