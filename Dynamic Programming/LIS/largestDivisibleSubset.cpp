#include <bits/stdc++.h>
using namespace std;
  
// DP 
vector<int> helper(vector<int>& nums, int prev, int index, vector<int> ans) {

    if(index == nums.size()) {
        return ans;
    }

    vector<int> include, exclude;

    // Exclude
    exclude = helper(nums, prev, index+1, ans);

    // Include
    if(prev == -1 || nums[index] % nums[prev] == 0) {
        ans.push_back(nums[index]);
        include = helper(nums, index, index+1, ans);
    }

    if(include.size() > exclude.size()) {
        return include;
    }

    return exclude;
}

vector<int> largestDivisibleSubset(vector<int> nums) {

    sort(nums.begin(), nums.end());

    vector<int> ans;

    return helper(nums, -1, 0, ans);
}

// Tabulation
vector<int> largestDivisibleSubset(vector<int> nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    if(n == 0) return {};

    vector<int> dp(n, 1);
    vector<int> parent(n);

    int maxLen = 1;
    int LastIndex = 0;

    for(int i = 0; i < n; i++) {
        parent[i] = i;

        for(int j = 0; j < i; j++) {
            if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if(dp[i] > maxLen) {
            maxLen = dp[i];
            LastIndex = i;
        }
    }

    vector<int> ans;

    while(parent[LastIndex] != LastIndex) {
        ans.push_back(nums[LastIndex]);
        LastIndex = parent[LastIndex];
    }

    ans.push_back(nums[LastIndex]);

    reverse(ans.begin(), ans.end());

    return ans;
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