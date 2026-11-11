#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return dp;
}

vector<int> LDS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return dp;
}

int LongestBitonicSequence(vector<int> arr) {
    vector<int> increasing=LIS(arr);
   vector<int> decreasing=LDS(arr);
    int maxi=0;
   for(int i=0;i<arr.size();i++){
        if(increasing[i]+decreasing[i]-1>max){
            maxi=max(increasing[i]+decreasing[i]-1,maxi);
        }
   }
   return maxi;
}


int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = powerSet(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}