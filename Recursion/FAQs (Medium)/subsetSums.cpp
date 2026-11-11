#include <bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int>& nums,vector<int>& final, int ans, int j) {
    if (j == nums.size()) {
        final.push_back(ans);
        return final;
    }
    helper(nums, final, ans+nums[j], j + 1);
    helper(nums, final, ans, j + 1);

    return final;
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> final;

    helper(nums, final, 0, 0);

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