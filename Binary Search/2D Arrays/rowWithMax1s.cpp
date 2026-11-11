#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &mat) {
    int maxOnes = 0;
    int index = -1;

    for (int i = 0; i < mat.size(); i++) {
        int low = 0;
        int high = mat[0].size() - 1;
        int res = mat[0].size();

        while (low <= high) {
            int mid = (low + high) / 2;

            if (mat[i][mid] == 1) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (maxOnes < (mat[0].size() - res)) {
            maxOnes = mat[0].size() - res;
            index = i;
        }
    }

    return index;
}

int main() {
    vector<vector<int>> nums = {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    int ans = rowWithMax1s(nums);
    cout << ans;

    return 0;
}
