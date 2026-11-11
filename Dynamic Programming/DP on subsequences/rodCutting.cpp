#include <bits/stdc++.h>
using namespace std;

// RECURSION
int helper(vector<int> price, int n,int index,int sum) {
    if(sum == n) return 0;

    if(index == price.size()) return INT_MIN;

    int notTaken = helper(price, n, index+1, sum);

    int taken = INT_MIN;

    if(sum + index + 1 <= n) {
        int temp = helper(price, n, index, sum + index + 1);

        if(temp != INT_MIN)
            taken = price[index] + temp;
    }

    return max(taken, notTaken);
}

int rodCutting(vector<int> price, int n) {
    return helper(price, n, 0, 0);
}


// DP
int helper(vector<int> price, int n,int index,int sum,vector<vector<int>>& dp) {

    if(sum == n) return 0;

    if(index == price.size()) return INT_MIN;

    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }

    int notTaken = helper(price, n, index+1, sum,dp);

    int taken = INT_MIN;

    if(sum + index + 1 <= n) {
        int temp = helper(price, n, index, sum + index + 1,dp);

        if(temp != INT_MIN)
            taken = price[index] + temp;
    }
    dp[index][sum]=max(taken, notTaken);

    return max(taken, notTaken);
}
    
    int rodCutting(vector<int> price, int n) {
     vector<vector<int>> dp(price.size(), vector<int>(n+1, -1));

    return helper(price,n,0,0,dp);
    }

// 

int rodCutting(vector<int> price, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i]);
            }
        }
    }
    return dp[n][n];
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