#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& cs, vector<int>& arr,
                vector<int>& nums, int sum, int ans, int j) {

        if (ans > sum) {
            return;
        }

        if (ans == sum) {
            cs.push_back(arr);
            return;
        }

        for (int i = j; i < nums.size(); i++) {
            arr.push_back(nums[i]);

            helper(cs, arr, nums, sum, ans + nums[i], i);

            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> cs;
        vector<int> arr;

        helper(cs, arr, candidates, target, 0, 0);

        return cs;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 3, 5, 4};
    int target = 7;

    vector<vector<int>> ans = s.combinationSum(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}