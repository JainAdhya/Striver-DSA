#include <bits/stdc++.h>
using namespace std;

int largestSubarraySumMinimized(vector<int> &a, int k) {
    long long low = *max_element(a.begin(), a.end());
    long long high = accumulate(a.begin(), a.end(), 0LL);
    long long res = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long sum = 0;
        int count = 1;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] + sum > mid) {
                count++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }

        if (count <= k) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)res;
}

int main() {
vector<int> nums={4, 2, 1, 3, 6};
int limit=5;

    int ans = aggressiveCows(nums,limit);
    cout << ans;

    return 0;
}
