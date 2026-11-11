#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION
    int helper(vector<vector<int>>& matrix, int n, int taken) {
        if (n == 0) {
            return 0;
        }

        int one = INT_MIN;
        int two = INT_MIN;
        int three = INT_MIN;

        if (taken != 1) {
            one = matrix[n - 1][0] + helper(matrix, n - 1, 1);
        }

        if (taken != 2) {
            two = matrix[n - 1][1] + helper(matrix, n - 1, 2);
        }

        if (taken != 3) {
            three = matrix[n - 1][2] + helper(matrix, n - 1, 3);
        }

       return max(one, max(two, three));
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> points(n + 1, vector<int>(4, -1));

        return helper(matrix, n, -1, points);
    }



    // DP
    int helper(vector<vector<int>>& matrix, int n, int taken,
               vector<vector<int>>& points) {
        if (n == 0) {
            return 0;
        }

        if (points[n][taken + 1] != -1) {
            return points[n][taken + 1];
        }

        int one = INT_MIN;
        int two = INT_MIN;
        int three = INT_MIN;

        if (taken != 1) {
            one = matrix[n - 1][0] + helper(matrix, n - 1, 1, points);
        }

        if (taken != 2) {
            two = matrix[n - 1][1] + helper(matrix, n - 1, 2, points);
        }

        if (taken != 3) {
            three = matrix[n - 1][2] + helper(matrix, n - 1, 3, points);
        }

        points[n][taken + 1] = max(one, max(two, three));
        return points[n][taken + 1];
    }

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> points(n + 1, vector<int>(4, -1));

        return helper(matrix, n, -1, points);
    }

    // OPTIMAZTION

    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> points(n + 1, vector<int>(3, -1));
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0) {
                    points[i + 1][j] = matrix[0][j];
                    ans = max(ans, points[i + 1][j]);
                } else {
                    int maxi = INT_MIN;

                    for (int k = 0; k < 3; k++) {
                        if (k != j) {
                            maxi = max(maxi, points[i][k]);
                        }
                    }

                    points[i + 1][j] = maxi + matrix[i][j];
                    ans = max(ans, points[i + 1][j]);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << sol.ninjaTraining(matrix) << endl;

    return 0;
}
