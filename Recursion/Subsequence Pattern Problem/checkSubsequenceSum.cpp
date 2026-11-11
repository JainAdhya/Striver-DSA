#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int>& nums, int j, int sum, int ans) {
    if (j == nums.size()) {
        if (ans == sum) {
            return true;
        }
        return false;
    }

    // Include nums[j]
    ans += nums[j];
    if (helper(nums, j + 1, sum, ans)) {
        return true;
    }

    // Exclude nums[j]
    ans -= nums[j];
    if (helper(nums, j + 1, sum, ans)) {
        return true;
    }

    return false;
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    return helper(nums, 0, k, 0);
}

int main() {
    vector<int> nums = {1, 2, 3};

    cout << boolalpha << checkSubsequenceSum(nums, 5);

    return 0;
}