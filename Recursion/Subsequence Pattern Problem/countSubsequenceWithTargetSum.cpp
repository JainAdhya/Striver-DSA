#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int j, int sum, int ans) {
        if (j == nums.size()) {
            if (ans == sum) {
                return 1;
            }
            return 0;
        }

        // Include nums[j]
        ans += nums[j];
        int count = helper(nums, j + 1, sum, ans);

        // Exclude nums[j]
        ans -= nums[j];
        count += helper(nums, j + 1, sum, ans);

        return count;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        // your code goes here
        return helper(nums, 0, k, 0);
    }

int main() {
    vector<int> nums = {1, 2, 3};

    cout << boolalpha << checkSubsequenceSum(nums, 5);

    return 0;
}