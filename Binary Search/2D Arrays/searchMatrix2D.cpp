#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target){
    int rows=mat.size();
    int col=mat[0].size();
    int total=rows*col;
low=0;
high=total-1;
    while(low<=high){
        int mid=(low+high)/2;
        int i=mid/col;
        int j=mid%col;
        if(mat[i][j]==target){
            return true;
        }else if(mat[i][j]>target){
            high=mid-1;
        }else{
            low=mid+1;
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
