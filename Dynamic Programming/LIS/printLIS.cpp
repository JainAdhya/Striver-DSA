#include <bits/stdc++.h>
using namespace std;
  
// DP Tabulation

vector<int> LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    int m = sorted.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(nums[i-1] == sorted[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<int> ans;

    int i = n;
    int j = m;

    while(i > 0 && j > 0) {

        if(nums[i-1] == sorted[j-1] &&
           dp[i][j] == dp[i-1][j-1] + 1) {

            ans.push_back(nums[i-1]);
            i--;
            j--;

        }
        else if(dp[i][j] == dp[i-1][j]) {
            i--;
        }
        else {
            j--;
        }
    }

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