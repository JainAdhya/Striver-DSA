#include <bits/stdc++.h>
using namespace std;

int helper(string str, string pat, int n, int m, int i, int j) {

    if(i == n && j == m) {
        return true;
    }

    if(j == m) {
        return false;
    }

    if(i == n) {
        for(int k = j; k < m; k++) {
            if(pat[k] != '*') {
                return false;
            }
        }
        return true;
    }

    if(str[i] == pat[j] || pat[j] == '?') {
        return helper(str, pat, n, m, i+1, j+1);
    }

    if(pat[j] == '*') {
        return helper(str, pat, n, m, i, j+1) ||
               helper(str, pat, n, m, i+1, j);
    }

    return false;
}

bool wildCard(string str, string pat) {
    int n = str.length();
    int m = pat.length();

    return helper(str, pat, n, m, 0, 0);
}

int helper(string str, string pat, int n, int m, int i, int j,
               vector<vector<int>>& dp) {

        if(i == n && j == m) {
            return true;
        }

        if(j == m) {
            return false;
        }

        if(i == n) {
            for(int k = j; k < m; k++) {
                if(pat[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(str[i] == pat[j] || pat[j] == '?') {
            return dp[i][j] = helper(str, pat, n, m, i+1, j+1, dp);
        }

        if(pat[j] == '*') {
            return dp[i][j] =
                helper(str, pat, n, m, i, j+1, dp) ||
                helper(str, pat, n, m, i+1, j, dp);
        }

        return dp[i][j] = false;
    }

    bool wildCard(string str, string pat) {
        int n = str.length();
        int m = pat.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return helper(str, pat, n, m, 0, 0, dp);
    }

    bool wildCard(string str, string pat) {
        int n = str.length();
        int m = pat.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = 1;

        for(int j = 1; j <= m; j++) {
            if(pat[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str[i-1] == pat[j-1] || pat[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pat[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else {
                dp[i][j] = 0;
            }
            }
        }

        return dp[n][m]==n;
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