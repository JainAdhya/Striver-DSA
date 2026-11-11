#include <bits/stdc++.h>
using namespace std;

int helper(const vector<int>& arr, int n, int index, bool buy) {
        if(index >= n) {
            return 0;
        }

        int buying = 0;
        int notbuying = 0;
        int selling = 0;
        int notselling = 0;

        if(buy) {
            buying = -arr[index] + helper(arr, n, index+1, false);
            notbuying = helper(arr, n, index+1, true);
        }
        else {
            selling = arr[index] + helper(arr, n, index+2, true);
            notselling = helper(arr, n, index+1, false);
        }

        return max({buying, notbuying, selling, notselling});
    }

    int maxProfit(const vector<int>& arr) {
        int n = arr.size();
        return helper(arr, n, 0, true);
    }


int helper(const vector<int>& arr, int n, int index, bool buy,
               vector<vector<int>>& dp) {

        if(index >= n) {
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
            buying = -arr[index] + helper(arr, n, index+1, false, dp);
            notbuying = helper(arr, n, index+1, true, dp);

            dp[1][index] = max(buying, notbuying);
            return dp[1][index];
        }
        else {
            selling = arr[index] + helper(arr, n, index+2, true, dp);
            notselling = helper(arr, n, index+1, false, dp);

            dp[0][index] = max(selling, notselling);
            return dp[0][index];
        }
    }

    int maxProfit(const vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(2, vector<int>(n, -1));

        return helper(arr, n, 0, true, dp);
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