#include <bits/stdc++.h>
using namespace std;
  
int numberOfLIS(vector<int> nums) {
    int n = nums.size();
    if(n == 0) return 0;

    vector<int> dp(n, 1);
    vector<int> count(n,1);

    int maxLen = 1;
    int LastIndex = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                if(dp[i]==dp[j]+1){
                    count[i] += count[j];
                }else if(dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
            }
        }
    maxLen = max(maxLen, dp[i]);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(dp[i] == maxLen) {
            ans += count[i];
        }
    }

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