#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int findKthPositive(vector<int>& arr, int k) {
    vector<int> miss(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++) {
        miss[i] = arr[i] - i - 1;
    }

    int ans = lowerBound(miss, k);

    if (ans == miss.size()) {
        return arr.back() + (k - miss.back());
    }

    return arr[ans] - (miss[ans] - k + 1);
}

int main() {
    vector<int> nums = {3, 5, 7, 10};
    int k = 6;

    cout << findKthPositive(nums, k);
    return 0;
}
