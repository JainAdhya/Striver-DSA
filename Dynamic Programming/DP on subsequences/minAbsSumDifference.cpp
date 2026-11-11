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
    
    int minDifference(int n, vector<int> arr) {
        int total = 0;
        for(int x : arr) total += x;
        int target=total/2;
        while(!(helper(arr,target,0))){
            target--;
        }
        return total-(2*target);
    }
    
    // DP
    bool helper(vector<int> arr, int target, int i, vector<vector<int>>& ans) {
        if(target < 0) return 0;

        if(i == arr.size()) {
            return target == 0;
        }

        if(ans[i][target] != -1) {
            return ans[i][target];
        }

        int include = helper(arr, target-arr[i], i+1, ans);
        int exclude = helper(arr, target, i+1, ans);

        ans[i][target] = include || exclude;
        return ans[i][target];
    }

    int minDifference(vector<int>& arr, int n) {
        int total = 0;
        for(int x : arr) total += x;

        int target = total/2;

        vector<vector<int>> ans(arr.size()+1, vector<int>(target+1, -1));

        while(target >= 0) {
            if(helper(arr, target, 0, ans)) {
                return total - 2*target;
            }
            target--;
        }

        return total;
    }

    // Tabluation
    int minDifference(vector<int>& arr, int n) {
        int total = 0;
        for(int x : arr) total += x;

        int target = total/2;

        vector<vector<bool>> ans(n+1, vector<bool>(target+1, false));

        for(int i=0; i<=n; i++){
            ans[i][0] = true;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){

                if(j < arr[i-1]){
                    ans[i][j] = ans[i-1][j];
                }
                else if(j == arr[i-1]){
                    ans[i][j] = true;
                }
                else{
                    ans[i][j] = ans[i-1][j] || ans[i-1][j-arr[i-1]];
                }
            }
        }

        while(target >= 0 && !ans[n][target]){
            target--;
        }

        return total - 2*target;
    }

};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
