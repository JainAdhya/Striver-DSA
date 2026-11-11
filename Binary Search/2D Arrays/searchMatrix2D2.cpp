#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target){
    int rows = mat.size();
    int col = mat[0].size();

    int i = 0;
    int j = col - 1;

    while (i < rows && j >= 0) {
        if (mat[i][j] == target) {
            return true;
        } 
        else if (mat[i][j] > target) {
            j--;
        } 
        else {
            i++;
        }
    }

    return false;

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
