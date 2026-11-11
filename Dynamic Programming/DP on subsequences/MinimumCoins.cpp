#include <bits/stdc++.h>
using namespace std;


int helper(vector<int>& coins, int amount){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }

    int mini=INT_MAX;
    int ans=0;

    for(int i=0;i<coins.size();i++){
        ans=helper(coins,amount-coins[i]);

        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }

    return mini;

}
int MinimumCoins(vector<int>& coins, int amount) {
  return helper(coins,amount);
}

// DP

int helper(vector<int>& coins, int amount, vector<int>& dp){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }

    int mini=INT_MAX;
    int ans=0;

    for(int i=0;i<coins.size();i++){
        ans=helper(coins,amount-coins[i],dp);

        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }

    dp[amount]=mini;

    return mini;
}

int MinimumCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,-1);
    int mini=helper(coins,amount,dp);
    return mini!=INT_MAX?mini:-1;
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