#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // RECUSRION
    bool helper(vector<int>arr, int target, int i) {
        if (i == matrix.size()) {
            if(target==0){
                return true;
            }else{
                return false;
            }
        }

        bool include = helper(arr, target-arr[i], j+1);
        bool exclude = helper(arr, target, j+1);

        return include || exclude;
    }

    bool isSubsetSum(vector<int>arr, int target){
        return helper(arr,target,0);
    }
    
    // DP
     int helper(vector<int>&arr, int target, int i, vector<vector<int>>& ans) {

        if(target < 0) return 0;

        if (i == arr.size()) {
            if(target==0){
                ans[i][target]=1;
                return 1;
            }else{
                ans[i][target]=0;
                return 0;
            }
        }

        if(ans[i][target]!=-1){
            return ans[i][target];
        }

        int include = helper(arr, target-arr[i], i+1,ans);
        int exclude = helper(arr, target, i+1,ans);

        ans[i][target]=include || exclude;
        return ans[i][target];
    }

    bool isSubsetSum(vector<int>arr, int target){

        vector<vector<int>> ans(arr.size()+1,vector<int>(target+1,-1));

        int result=helper(arr,target,0,ans);

        if(result==1){
            return true;
        }
        return false;
    }

    // Tabluation
    bool isSubsetSum(vector<int>arr, int target){
         vector<vector<bool>> ans(arr.size()+1,vector<bool>(target+1,0));

        for(int i=0;i<target+1;i++){
            ans[0][i]=false;
        }

        for(int i=0;i<arr.size()+1;i++){
            ans[i][0]=true;
        }
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=target;j++){
                if(j<arr[i-1]){
                    ans[i][j]=a[i-1][j];
                }else if(j==arr[i-1]){
                    ans[i][j]=true;
                }else{
                    ans[i][j]=ans[i-1][j] || ans[i-1][j-arr[i-1]];
                }
            }
        }
        return ans[arr.size()][target];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
