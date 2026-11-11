#include <bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    if(n < m) {
        return lcs(str2, str1);
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(str1[i-1] != str2[j-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else {
                dp[i][j] = 1 + dp[i-1][j-1];
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