#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION
     int helper(vector<vector<int>>& matrix, int i,int j) {
        if (j < 0 || j >= matrix[0].size()) {
            return INT_MAX;
        }

        if (i == matrix.size() - 1) {
            return matrix[i][j];
        }

        int mini = INT_MAX;

        int bottom = helper(matrix, i + 1, j);
        int bottoml = helper(matrix, i + 1, j - 1);
        int bottomr = helper(matrix, i + 1, j + 1);

        mini = min({bottom, bottoml, bottomr});

        return matrix[i][j] + mini;
    }

     int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;

        for (int k = 0; k < matrix[0].size(); k++) {
            mini = min(mini, helper(matrix, 0, k));
        }

        return mini;
    }
    
    // DP
    int helper(vector<vector<int>>& matrix, int i,int j,vector<vector<int>>& ans) {
        if (j < 0 || j >= matrix[0].size()) {
            return INT_MAX;
        }

        if (i == matrix.size() - 1) {
            ans[i][j]=matrix[i][j];
            return matrix[i][j];
        }

        if(ans[i][j]!=-1){
            return ans[i][j];
        }

        int mini = INT_MAX;

        int bottom = helper(matrix, i + 1, j,ans);
        int bottoml = helper(matrix, i + 1, j - 1,ans);
        int bottomr = helper(matrix, i + 1, j + 1,ans);

        mini = min({bottom, bottoml, bottomr});
            if (mini == INT_MAX) {
        return INT_MAX;
    }

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
        if (matrix.size() == 1) {
        return *min_element(matrix[0].begin(), matrix[0].end());
    }

    if (matrix[0].size() == 1) {
        int sum = 0;
        for (int i = 0; i < matrix.size(); i++) {
            sum += matrix[i][0];
        }
        return sum;
    }

        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0){
                    ans[i][j]=matrix[i][j];
                }else{
                    if(j==0){
                        ans[i][j]=min(ans[i-1][j],ans[i-1][j+1]);
                    }else if(j==matrix[0].size()-1){
                        ans[i][j]=min(ans[i-1][j-1],ans[i-1][j]);
                    }else{
                        ans[i][j]=min({ans[i-1][j-1],ans[i-1][j],ans[i-1][j+1]});
                    }
                    ans[i][j]+=matrix[i][j];
                }
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            mini=min(mini,ans[matrix.size()-1][j]);
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
