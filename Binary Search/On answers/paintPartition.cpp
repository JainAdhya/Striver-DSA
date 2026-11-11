#include <bits/stdc++.h>
using namespace std;

int paint(int A, int B, vector<int>& nums) {
    const long long MOD = 10000003;
    int n = nums.size();

    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long res = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        int painter = 1;
        long long board = 0;

        for (int i = 0; i < n; i++) {
            if (board + nums[i] > mid) {
                painter++;
                board = nums[i];

                // Early termination
                if (painter > A) {
                    break;
                }
            } else {
                board += nums[i];
            }
        }

        if (painter <= A) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (res * B) % MOD;
}

int main() {
    vector<int> nums = {25, 12, 8, 14, 19};

    cout << paint(2, 5, nums);
    return 0;
}