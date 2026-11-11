#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Tabluation
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            ans[i][0]=matrix[i][0];
        }
        for(int j=0;j<m;j++){
            ans[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;i<m;j++){
                ans[i][j]=min(ans[i-1][j],ans[i][j-1])+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;i<m;j++){
                sum+=ans[i][j];
            }
        }
        return sum;
        
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
