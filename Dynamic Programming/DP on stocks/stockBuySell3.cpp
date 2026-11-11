#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& arr, int n, int index, bool buy,int count) {
    if(index == n) {
        if(count==2){
            return 0;
        }else {
            return INT_MIN;
        }
    }

    int buying = 0;
    int notbuying = 0;
    int selling = 0;
    int notselling = 0;

    if(buy) {
        buying = -arr[index] + helper(arr, n, index+1, false, count);
        notbuying = helper(arr, n, index+1, true, count);
    }
    else {
        selling = arr[index] + helper(arr, n, index+1, true, count+1);
        notselling = helper(arr, n, index+1, false, count);
    }

    return max({buying, notbuying, selling, notselling});
}

int stockBuySell(vector<int> arr, int n) {
    return helper(arr, n, 0, true,0);
}



int helper(vector<int>& arr, int n, int index, bool buy,
           vector<vector<vector<int>>>& dp, int count) {

    if(index == n || count == 2) {
        return 0;
    }

    if(dp[buy][index][count] != -1) {
        return dp[buy][index][count];
    }

    int buying = 0;
    int notbuying = 0;
    int selling = 0;
    int notselling = 0;

    if(buy) {
        buying = -arr[index] + helper(arr, n, index+1, false, dp, count);
        notbuying = helper(arr, n, index+1, true, dp, count);

        dp[1][index][count] = max(buying, notbuying);
        return dp[1][index][count];
    }
    else {
        selling = arr[index] + helper(arr, n, index+1, true, dp, count+1);
        notselling = helper(arr, n, index+1, false, dp, count);

        dp[0][index][count] = max(selling, notselling);
        return dp[0][index][count];
    }
}

int stockBuySell(vector<int> arr, int n) {
    vector<vector<vector<int>>> dp(
        2, vector<vector<int>>(n, vector<int>(3, -1))
    );

    return helper(arr, n, 0, true, dp, 0);
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