#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& arr, int n, int fee, int index, bool buy) {
    if(index == n) {
        return 0;
    }

    int buying = 0;
    int notbuying = 0;
    int selling = 0;
    int notselling = 0;

    if(buy) {
        buying = -arr[index] + helper(arr, n,fee, index+1, false);
        notbuying = helper(arr, n, fee,index+1, true);
    }
    else {
        selling = arr[index] + helper(arr, n,fee, index+1, true)-fee;
        notselling = helper(arr, n,fee, index+1, false);
    }

    return max({buying, notbuying, selling, notselling});
}

int stockBuySell(vector<int> arr, int n, int fee){
    return helper(arr, n,fee, 0, true,0);
}



int helper(vector<int>& arr, int n, int k, int index, bool buy,
           vector<vector<int>>& dp ) {

    if(index == n) {
        return 0;
    }

    if(dp[buy][index] != -1) {
        return dp[buy][index];
    }

    int buying = 0;
    int notbuying = 0;
    int selling = 0;
    int notselling = 0;

    if(buy) {
        buying = -arr[index] + helper(arr, n, k, index+1, false, dp);
        notbuying = helper(arr, n,k, index+1, true, dp);

        dp[1][index] = max(buying, notbuying);
        return dp[1][index];
    }
    else {
        selling = arr[index] + helper(arr, n,k, index+1, true, dp)-k;
        notselling = helper(arr, n,k, index+1, false, dp);

        dp[0][index] = max(selling, notselling);
        return dp[0][index];
    }
}

int stockBuySell(vector<int> arr, int n, int fee) {
    vector<vector<int>> dp(2, vector<int>(n, -1));
    return helper(arr, n,k, 0, true, dp);
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