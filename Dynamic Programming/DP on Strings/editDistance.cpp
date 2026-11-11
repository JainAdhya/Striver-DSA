#include <bits/stdc++.h>
using namespace std;

// DP
int helper(string start, string target, int n, int m, int i, int j) {

    if(i == n) {
        return m - j;  // Insert remaining characters
    }

    if(j == m) {
        return n - i;  // Delete remaining characters
    }

    if(start[i] == target[j]) {
        return helper(start, target, n, m, i+1, j+1);
    }

    int insert = 1 + helper(start, target, n, m, i, j+1);

    int del = 1 + helper(start, target, n, m, i+1, j);

    int replace = 1 + helper(start, target, n, m, i+1, j+1);

    return min({insert, del, replace});
}

int editDistance(string start, string target) {
    int n = start.length();
    int m = target.length();

    return helper(start, target, n, m, 0, 0);
}


// DP
int helper(string start, string target, int n, int m, int i, int j,vector<vector<int>>& dp) {

    if(i == n) {
        return m - j;  // Insert remaining characters
    }

    if(j == m) {
        return n - i;  // Delete remaining characters
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(start[i] == target[j]) {
        return helper(start, target, n, m, i+1, j+1,dp);
    }

    int insert = 1 + helper(start, target, n, m, i, j+1,dp);

    int del = 1 + helper(start, target, n, m, i+1, j, dp);

    int replace = 1 + helper(start, target, n, m, i+1, j+1,dp);

    dp[i][j]=min({insert, del, replace});
    return dp[i][j];
}

 int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }

        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min({
                        dp[i-1][j-1] + 1,
                        dp[i-1][j] + 1,
                        dp[i][j-1] + 1
                    });
                }
            }
        }

        return dp[n][m];
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