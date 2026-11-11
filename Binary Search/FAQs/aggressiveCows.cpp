#include <bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int>& nums, int k) {
    int n = nums.size();

    if (k > n) {
        return -1;
    }

    sort(nums.begin(), nums.end());

    int low = 1;
    int high = nums[n - 1] - nums[0];
    int res = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        int cows = 1;
        int last = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] - last >= mid) {
                cows++;
                last = nums[i];
            }
        }

        if (cows >= k) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return res;
}

int main() {
vector<int> nums={4, 2, 1, 3, 6};
int limit=5;

    int ans = aggressiveCows(nums,limit);
    cout << ans;

    return 0;
}
