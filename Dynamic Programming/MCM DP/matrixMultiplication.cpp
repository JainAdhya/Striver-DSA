#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums,int i,int j){
    if(i == j) {
            return 0;
        }

        int mini = INT_MAX;

        for(int k = i; k < j; k++) {

            int steps = nums[i-1] * nums[k] * nums[j]
                      + helper(nums, i, k)
                      + helper(nums, k+1, j);

            mini = min(mini, steps);
        }

        return mini;
}

int matrixMultiplication(vector<int>& nums){
            //your code goes here
    return helper(nums,1,nums.size()-1);
    	
}

int helper(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
    if(i == j) {
        return 0;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k = i; k < j; k++) {

        int steps = nums[i-1] * nums[k] * nums[j]
                  + helper(nums, i, k, dp)
                  + helper(nums, k+1, j, dp);

        mini = min(mini, steps);
    }

    dp[i][j] = mini;

    return mini;
}

int matrixMultiplication(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

    return helper(nums, 1, nums.size()-1, dp);
}

int matrixMultiplication(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n-1, vector<int>(n-1, -1));
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }

    for(int i=1;i<n-1;i++){
        for(int j=0;j+i<n-1;j++){
            int k=j+i;
            int dp[i][j]=nums[i-1] * nums[k] * nums[j]+min(dp[i+1][k],dp[i][k-1]);
        }
    }


    return dp[0][n-1];
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