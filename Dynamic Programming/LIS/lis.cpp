#include <bits/stdc++.h>
using namespace std;
  
// DP Tabulation
int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    int m = sorted.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(nums[i-1] == sorted[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

// MEMORIZATION

int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    int m = sorted.size();

    vector<vector<int>> dp(2, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(nums[i-1] == sorted[j-1]) {
                dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
            }
            else {
                dp[i%2][j] = max(
                    dp[(i-1)%2][j],
                    dp[i%2][j-1]
                );
            }
        }
    }

    return dp[n%2][m];
}


int LIS(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;

    vector<int> dp(n, 1);
    vector<int> parent(n);

    int maxLen = 1;
    int LastIndex = 0;

    for(int i = 0; i < n; i++) {
        parent[i] = i;

        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if(dp[i] > maxLen) {
            maxLen = dp[i];
            LastIndex = i;
        }
    }

    return maxLen;
}

// Binary Search

int upperBound(vector<int> arr, int num){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=num){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

int LIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp;

    for(int i = 0; i < n; i++) {

        if(dp.empty()) {
            dp.push_back(nums[i]);
        }
        else if(dp.back() < nums[i]) {
            dp.push_back(nums[i]);
        }
        else {
            int pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[pos] = nums[i];
        }
    }

    return dp.size();
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