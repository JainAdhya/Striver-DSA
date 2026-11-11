#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> helper(vector<int>& nums, vector<vector<int>>& final,
                           vector<int>& ans, int j) {
    if (j == nums.size()) {
    if (find(final.begin(), final.end(), sort(ans.begin(),ans.end())) == final.end()) {
        final.push_back(ans);
    }
    return final;
}

    // Include nums[j]
    ans.push_back(nums[j]);
    helper(nums, final, ans, j + 1);

    // Backtrack
    ans.pop_back();

    // Exclude nums[j]
    helper(nums, final, ans, j + 1);

    return final;
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> final;
    vector<int> ans;

    helper(nums, final, ans, 0);

    return final;
    }

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = powerSet(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}