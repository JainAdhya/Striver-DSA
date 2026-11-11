#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>>&matrix) {
    int mid=(matrix[0].size()-1)/2;
    int j=0;
    for(int i=0;i<matrix.size();i++){
        matrix[0][j]=matrix[i][mid];
        j++;
    }
    sort(matrix[0].begin(),matrix[0].end());
    return matrix[0][mid];
      
}

int main() {
    vector<vector<int>> nums = {
        {1, 4, 9}, {2, 5, 6}, {3, 7, 8}
    };

    int ans = rowWithMax1s(nums);
    cout << ans;

    return 0;
}
