#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Tabluation
    int perfectSum(vector<int>&arr, int K) {
        vector<vector<int>> ans(arr.size()+1, vector<int>(target+1,0));

        for(int i=0; i<=arr.size(); i++){
            ans[i][0] = 1;
        }

        for(int i=1; i<=arr.size(); i++){
            for(int j=1; j<=target; j++){

                ans[i][j] = ans[i-1][j];

                if(j >= arr[i-1]){
                    ans[i][j] += ans[i-1][j-arr[i-1]];
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
