#include <bits/stdc++.h>
using namespace std;

 int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
             //your code goes here
             vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                if(j < wt[i-1]){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = max(dp[i-1][j],
                                   dp[i-1][j-wt[i-1]] + val[i-1]);
                }
            }
        }

        return dp[n][W];
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