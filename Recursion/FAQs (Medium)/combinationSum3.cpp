#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& cs, vector<int>& arr,
                vector<int>& nums, int k, int sum,
                int ans, int j, int count) {

        if (count == k) {
            if (ans == sum) {
                cs.push_back(arr);
            }
            return;
        }

        if (ans > sum || j == nums.size()) {
            return;
        }

        for (int i = j; i < nums.size(); i++) {
            if (ans + nums[i] > sum) {
                break;
            }

            arr.push_back(nums[i]);

            helper(cs, arr, nums, k, sum,
                   ans + nums[i], i + 1, count + 1);

            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> cs;
        vector<int> arr;

        helper(cs, arr, nums, k, n, 0, 0, 0);

        return cs;
    }
};

int main() {
    Solution s;

    int k = 3;
    int n = 7;

    vector<vector<int>> ans = s.combinationSum3(k, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}