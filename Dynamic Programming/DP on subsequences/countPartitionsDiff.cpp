#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Tabluation

    int mod = 1e9 + 7;

int helper(vector<int>& arr, int n, int diff, int i, int sum1, int total,
            vector<vector<int>>& ans) {

     int sum2 = total - sum1;

        if (i == n) {
            if (sum1 >= sum2 && sum1 - sum2 == diff) {
                return 1;
            }
            return 0;
        }

        if (ans[i][sum1] != -1) {
            return ans[i][sum1];
        }

        int include = helper(arr, n, diff, i + 1, sum1 + arr[i], total, ans);
        int exclude = helper(arr, n, diff, i + 1, sum1, total, ans);

        ans[i][sum1] = (include + exclude) % mod;

        return ans[i][sum1];
}

int countPartitions(int n, int diff, vector<int>& arr) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    if (diff > total || (total + diff) % 2 != 0) {
        return 0;
    }

    vector<vector<int>> ans(n, vector<int>(total + 1, -1));

    return helper(arr, n, diff, 0, 0, total, ans);
}

};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};

    cout << sol.houseRobber(nums) << endl;

    return 0;
}
