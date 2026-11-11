#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEle(vector<vector<int>>& mat, int col, int rows) {
        int maxi = INT_MIN;
        int index = -1;

        for (int i = 0; i < rows; i++) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = maxEle(mat, mid, mat.size());

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < mat[0].size()) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            }
            else if (mat[row][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    Solution sol;
    vector<int> ans = sol.findPeakGrid(mat);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}