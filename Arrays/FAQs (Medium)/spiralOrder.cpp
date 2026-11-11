
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int count = 0;
    vector<int> ans;

    int left = 0 + count;
    int right = matrix[0].size() - count - 1;
    int top = 0 + count;
    int bottom = matrix.size() - 1 - count;

    while (left <= right && top <= bottom) {

        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }

        top++;

        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }

        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }

        count++;
    }

    return ans;
}

int main() {
    vector<vector<int>> nums = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans = spiralOrder(nums);

    for (int j = 0; j < ans.size(); j++) {
        cout << ans[j] << " ";
    }

    return 0;
}
