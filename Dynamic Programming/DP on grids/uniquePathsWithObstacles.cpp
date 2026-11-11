#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION
     int helper(vector<vector<int>>& matrix, int i,int j) {
        if(matrix[i][j]==1){
            return 0;
        }
        if(i==matrix.size()-1 && j==matrix[0].size()-1){
            return 1;
        }
        int count=0;

        if(i<matrix.size()-1){
            count=helper(nums, i+1,j);
        }
        if(j<matrix[0].size()-1){
            count+=helper(nums, i,j+1);
        }
        return count;
    }

     int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        return helper(matrix,0,0);
    }
    
    // DP
    int helper(vector<int>& nums, int start, int index, vector<vector<int>>& dp) {
        if(matrix[i][j]==1){
            ans[i][j]=0;
            return 0;
        }
        if(i==matrix.size()-1 && j==matrix[0].size()-1){
            return 1;
        }
        if(ans[i][j]!=-1){
            return ans[i][j];
        }
        int count=0;

        if(i<matrix.size()-1){
            count=helper(nums, i+1,j,ans);
        }
        if(j<matrix[0].size()-1){
            count+=helper(nums, i,j+1,ans);
        }
        return ans[i][j]=count;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),-1));
         return helper(matrix,0,0,ans);
    }

    // Tabluation
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        if (matrix[0][0] == 1) {
            return 0;
        }

        ans[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                ans[i][0] = ans[i - 1][0];
            }
        }

        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                ans[0][j] = ans[0][j - 1];
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    ans[i][j] = 0;
                } else {
                    ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                }
            }
        }

        return ans[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
