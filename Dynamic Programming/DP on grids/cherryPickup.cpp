#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION
     int helper(vector<vector<int>>& matrix, int i1,int j1,int i2,int j2) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
            return INT_MIN;
        }
        if (i1 == n - 1 && i2 == n - 1) {
            if (j1 == j2) {
                return matrix[i1][j1];
            }
            return matrix[i1][j1] + matrix[i2][j2];
        }

        int maxi = INT_MIN;
        int one=helper(matrix, i1 + 1, j1-1,i2+1,j2-1);
        int two=helper(matrix, i1 + 1, j1-1,i2+1,j2);
        int three=helper(matrix, i1 + 1, j1-1,i2+1,j2+1);
        int four=helper(matrix, i1 + 1, j1,i2+1,j2-1);
        int five=helper(matrix, i1 + 1, j1,i2+1,j2);
        int six=helper(matrix, i1 + 1, j1,i2+1,j2+1);
        int seven=helper(matrix, i1 + 1, j1+1,i2+1,j2-1);
        int eight=helper(matrix, i1 + 1, j1+1,i2+1,j2);
        int nine=helper(matrix, i1 + 1, j1+1,i2+1,j2+1);
        mini = max({one,two,three,four,five,six,seven,eight,nine});
        if (maxi == INT_MIN) {
            return INT_MIN;
        }

        int current;
        if (j1 == j2) {
            current = matrix[i1][j1];
        } else {
            current = matrix[i1][j1] + matrix[i2][j2];
        }

        return current + maxi;
    }

    int cherryPickup(vector<vector<int>>& matrix, int i1,int j1,int i2,int j2) {
        return helper(matrix, 0, 0, 0, matrix[0].size() - 1);
    }
    
    // DP
    int helper(vector<vector<int>>& matrix, int i1,int j1,int i2,int j2,vector<vector<int>>& ans) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
            return INT_MIN;
        }

        if (i1 == n - 1) {
            if (j1 == j2) {
                return matrix[i1][j1];
            }
            return matrix[i1][j1] + matrix[i2][j2];
        }

        if (ans[i1][j1][j2] != -1) {
            return ans[i1][j1][j2];
        }

        int one = helper(matrix, i1 + 1, j1 - 1, i2 + 1, j2 - 1, ans);
        int two = helper(matrix, i1 + 1, j1 - 1, i2 + 1, j2, ans);
        int three = helper(matrix, i1 + 1, j1 - 1, i2 + 1, j2 + 1, ans);
        int four = helper(matrix, i1 + 1, j1, i2 + 1, j2 - 1, ans);
        int five = helper(matrix, i1 + 1, j1, i2 + 1, j2, ans);
        int six = helper(matrix, i1 + 1, j1, i2 + 1, j2 + 1, ans);
        int seven = helper(matrix, i1 + 1, j1 + 1, i2 + 1, j2 - 1, ans);
        int eight = helper(matrix, i1 + 1, j1 + 1, i2 + 1, j2, ans);
        int nine = helper(matrix, i1 + 1, j1 + 1, i2 + 1, j2 + 1, ans);

        int maxi = max({one, two, three, four, five, six, seven, eight, nine});

        if (maxi == INT_MIN) {
            return ans[i1][j1][j2] = INT_MIN;
        }

        int current;
        if (j1 == j2) {
            current = matrix[i1][j1];
        } else {
            current = matrix[i1][j1] + matrix[i2][j2];
        }

        return ans[i1][j1][j2] = current + maxi;
    }

    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<int>>> ans(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        return helper(matrix, 0, 0, 0, m - 1, ans);
    }

    // Tabluation
    int cherryPickup(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(m, -1))
    );

    dp[0][0][m - 1] = matrix[0][0];

    if (m > 1) {
        dp[0][0][m - 1] += matrix[0][m - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int one = (j1-1 >= 0 && j2-1 >= 0 &&
                           dp[i-1][j1-1][j2-1] != -1)
                           ? dp[i-1][j1-1][j2-1] : INT_MIN;

                int two = (j1-1 >= 0 &&
                           dp[i-1][j1-1][j2] != -1)
                           ? dp[i-1][j1-1][j2] : INT_MIN;

                int three = (j1-1 >= 0 && j2+1 < m &&
                             dp[i-1][j1-1][j2+1] != -1)
                             ? dp[i-1][j1-1][j2+1] : INT_MIN;

                int four = (j2-1 >= 0 &&
                            dp[i-1][j1][j2-1] != -1)
                            ? dp[i-1][j1][j2-1] : INT_MIN;

                int five = (dp[i-1][j1][j2] != -1)
                           ? dp[i-1][j1][j2] : INT_MIN;

                int six = (j2+1 < m &&
                           dp[i-1][j1][j2+1] != -1)
                           ? dp[i-1][j1][j2+1] : INT_MIN;

                int seven = (j1+1 < m && j2-1 >= 0 &&
                             dp[i-1][j1+1][j2-1] != -1)
                             ? dp[i-1][j1+1][j2-1] : INT_MIN;

                int eight = (j1+1 < m &&
                             dp[i-1][j1+1][j2] != -1)
                             ? dp[i-1][j1+1][j2] : INT_MIN;

                int nine = (j1+1 < m && j2+1 < m &&
                            dp[i-1][j1+1][j2+1] != -1)
                            ? dp[i-1][j1+1][j2+1] : INT_MIN;

                int maxi = max({one, two, three, four, five,
                                six, seven, eight, nine});

                if (maxi == INT_MIN) {
                    continue;
                }

                int current;

                if (j1 == j2) {
                    current = matrix[i][j1];
                } else {
                    current = matrix[i][j1] + matrix[i][j2];
                }

                dp[i][j1][j2] = current + maxi;
            }
        }
    }

    int ans = 0;

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            ans = max(ans, dp[n-1][j1][j2]);
        }
    }

    return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
