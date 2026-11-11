#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // RECUSRION 
    
    int helper(vector<int>& nums, int index) {
        if (index < 0) {
            return 0;
        }

        int pick = nums[index] + helper(nums, index - 2);
        int notpick = helper(nums, index - 1);

        return max(pick, notpick);
    }

    int nonAdjacent(vector<int>& nums) {
        return helper(nums, nums.size()-1);
    }

    //DP

    int helper(vector<int>& nums, int index, vector<int>& dp) {
        if (index < 0) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int pick = nums[index] + helper(nums, index - 2, dp);
        int notpick = helper(nums, index - 1, dp);

        dp[index] = max(pick, notpick);

        return dp[index];
    }

    int nonAdjacent(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, nums.size() - 1, dp);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 1, 4, 9};

    cout << sol.nonAdjacent(nums) << endl;

    return 0;
}
