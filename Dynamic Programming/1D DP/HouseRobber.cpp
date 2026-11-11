#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION

     int helper(vector<int>& nums, int start,int index) {
        if (index < start) {
            return 0;
        }

        int pick = nums[index] + helper(nums, start,index - 2);
        int notpick = helper(nums, start, index - 1);

        return max(pick, notpick);
    }

     int houseRobber(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int first=helper(nums, 0,nums.size() - 2);
        int last=helper(nums, 1,nums.size() - 1);
        return max(first,last);
    } 
    
     // DP

    int helper(vector<int>& nums, int start, int index, vector<int>& dp) {
        if (index < start) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int pick = nums[index] + helper(nums, start, index - 2, dp);
        int notpick = helper(nums, start, index - 1, dp);

        dp[index] = max(pick, notpick);

        return dp[index];
    }

    int houseRobber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, -1);
        int first = helper(nums, 0, n - 2, dp);
        fill(dp.begin(), dp.end(), -1);
        int last = helper(nums, 1, n - 1, dp);

        return max(first, last);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
