#include <bits/stdc++.h>
using namespace std;


int helper(int n, int target, vector<int>& nums) {
    if(n==nums.size()){
        if(target==0){
            return 1;
        }else{
            return 0
        }
    }

    int plus=helper(n+1,target-nums[n],nums);
    int neg=helper(n+1,target+nums[n],nums);

    return plus+neg;
}
int targetSum(int n, int target, vector<int>& nums) {
  return helper(coins,amount);
}

// DP
int mod = 1e9+7;

    int helper(int n, int target, vector<int>& nums,
               vector<vector<int>>& dp, int total) {

        if(target+total < 0 || target+total > 2*total){
            return 0;
        }

        if(n==nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }

        if(dp[n][target+total]!=-1){
            return dp[n][target+total];
        }

        int plus=helper(n+1,target-nums[n],nums,dp,total);
        int neg=helper(n+1,target+nums[n],nums,dp,total);

        dp[n][target+total]=(plus+neg)%mod;

        return dp[n][target+total];
    }

    int targetSum(int n, int target, vector<int>& nums) {

        int total=0;

        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }

        if(abs(target)>total){
            return 0;
        }

        vector<vector<int>> dp(n,vector<int>(2*total+1,-1));

        return helper(0,target,nums,dp,total);
    }


// TABULATION
int MinimumCoins(vector<int>& coins, int amount) {
       vector<int> dp(amount+1,INT_MAX);

        dp[0]=0;

        for(int i=1;i<=amount;i++){

            int mini=INT_MAX;

            for(int j=0;j<coins.size();j++){

                if(i-coins[j]>=0){

                    int ans=dp[i-coins[j]];

                    if(ans!=INT_MAX){
                        mini=min(mini,1+ans);
                    }
                }
            }

            dp[i]=mini;
        }

        return dp[amount]!=INT_MAX?dp[amount]:-1;
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