#include <bits/stdc++.h>
using namespace std;

// RECURSION
int helper(int index, vector<int>& wt, vector<int>& val, int n, int W) {
    if(index == 0) {
        return (W / wt[0]) * val[0];
    }

    int notTaken = helper(index-1, wt, val, n, W);

    int taken = 0;
    if(wt[index] <= W) {
        taken = val[index] + helper(index, wt, val, n, W-wt[index]);
    }

    return max(taken, notTaken);
}

int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    return helper(n-1, wt, val, n, W);
}


// DP

int helper(int index, vector<int>& wt, vector<int>& val, int n, int W,
           vector<vector<int>>& dp) {

    if(index == 0) {
        return (W / wt[0]) * val[0];
    }

    if(dp[index][W] != -1) {
        return dp[index][W];
    }

    int notTaken = helper(index-1, wt, val, n, W, dp);

    int taken = 0;
    if(wt[index] <= W) {
        taken = val[index] + helper(index, wt, val, n, W-wt[index], dp);
    }

    return dp[index][W] = max(taken, notTaken);
}

int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return helper(n-1, wt, val, n, W, dp);
}

// 

int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    for(int i=0;i<=W;i++){
        dp[0][i]=(i/wt[0])*val[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=W;j++){
            int notTaken = dp[i-1][j];

                int taken = 0;
                if(j >= wt[i]) {
                    taken = val[i] + dp[i][j-wt[i]];
                }

                dp[i][j] = max(taken, notTaken);
        }
    }
    return dp[n-1][W];
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