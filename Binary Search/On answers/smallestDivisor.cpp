#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int> &nums, int limit) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int res = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans += ceil((double)nums[i] / mid);
            if (ans > limit) {
                break;
            }
        }

        if (ans <= limit) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
vector<int> nums={25, 12, 8, 14, 19};
int limit=5;

    int ans = smallestDivisor(nums,limit);
    cout << ans;

    return 0;
}
