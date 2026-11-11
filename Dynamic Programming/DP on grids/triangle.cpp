#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION
     int helper(vector<vector<int>>& matrix, int i,int j) {
        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }

        int mini = INT_MAX;

        int bottom = helper(matrix, i + 1, j);
        int bottomr = helper(matrix, i + 1, j + 1);

        mini = min({bottom, bottomr});

        return matrix[i][j] + mini;
    }

     int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        mini = min(mini, helper(matrix, 0, k));
        return mini;
    }
    
    // DP
    int helper(vector<vector<int>>& matrix, int i,int j,vector<vector<int>>& ans) {
        if (i == matrix.size() - 1) {
            ans[i][j]=matrix[i][j];
            return matrix[i][j];
        }

        if(ans[i][j]!=-1){
            return ans[i][j];
        }

        int mini = INT_MAX;

        int bottom = helper(matrix, i + 1, j,ans);
        int bottomr = helper(matrix, i + 1, j + 1,ans);

        mini = min({bottom, bottomr});
        ans[i][j]=matrix[i][j] + mini;
        return ans[i][j];
    }

     int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),-1));

        for (int k = 0; k < matrix[0].size(); k++) {
            mini = min(mini, helper(matrix, 0, k,ans));
        }

        return mini;
    }

    // Tabluation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(vector<int>(matrix[i].size(), -1));
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i==0){
                    ans[0][0]=matrix[i][j];
                }else{
                    if(j==0){
                        ans[i][j]=ans[i-1][j];
                    }else if(j==matrix[i].size()-1){
                        ans[i][j]=ans[i-1][j-1];
                    }else{
                        ans[i][j]=min({ans[i-1][j-1],ans[i-1][j]});
                    }
                    ans[i][j]+=matrix[i][j];
                }
            }
        }
         for (int j = 0; j < matrix[n-1].size(); j++) {
            mini = min(mini, ans[n-1][j]);
        }

        return mini;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
