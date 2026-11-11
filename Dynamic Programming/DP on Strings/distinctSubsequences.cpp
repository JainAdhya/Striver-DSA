#include <bits/stdc++.h>
using namespace std;

int helper(string str1, string str2, int n,int m,int i,int j){
    if(j == m) {
        return 1;
    }

    if(i == n) {
        return 0;
    }

    if(str1[i] == str2[j]) {
        return helper(str1, str2, n, m, i+1, j+1)
             + helper(str1, str2, n, m, i+1, j);
    }

    return helper(str1, str2, n, m, i+1, j);

}
int distinctSubsequences(string s, string t) {
    return helper(s, t, s.length(), t.length(), 0, 0);
}

int helper(string str1, string str2, int n, int m,
           int i, int j, vector<vector<int>>& dp) {

    if(j == m) return 1;

    if(i == n) return 0;

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(str1[i] == str2[j]) {
        dp[i][j] = (helper(str1, str2, n, m, i+1, j+1, dp)
                  + (long long)helper(str1, str2, n, m, i+1, j, dp))
                  % 1000000007;
    }
    else {
        dp[i][j] = helper(str1, str2, n, m, i+1, j, dp);
    }

    return dp[i][j];
}

int distinctSubsequences(string s, string t) {
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));

    return helper(s, t, s.length(), t.length(), 0, 0, dp);
}

int distinctSubsequences(string s, string t) {

    int n = s.length();
    int m = t.length();
    int mod = 1e9 + 7;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(s[i-1] == t[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + (long long)dp[i-1][j]) % mod;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int distinctSubsequences(string s, string t) {

    int n = s.length();
        int m = t.length();
        int mod = 1e9 + 7;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int x = 0; x <= m; x++) {
            dp[x][0] = 0;
        }

        for(int y = 0; y <= n; y++) {
            dp[0][y] = 1;
        }

        for(int x = 1; x <= m; x++) {
            for(int y = 1; y <= n; y++) {
                if(t[x-1] == s[y-1]) {
                    dp[x][y] = (dp[x-1][y-1] + (long long)dp[x][y-1]) % mod;
                }
                else {
                    dp[x][y] = dp[x][y-1];
                }
            }
        }

        return dp[m][n];
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