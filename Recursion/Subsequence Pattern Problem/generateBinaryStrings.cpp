#include <bits/stdc++.h>
using namespace std;

vector<string> helper(vector<string>& nums,string& ans, int n, int j) {
        if (j == n) {
            nums.push_back(ans);
            return nums;
        }

        // Include 0
        helper(nums, ans + "0", n, j + 1);

        // Include 1 only if the previous character is not 1
        if (ans.empty() || ans.back() == '0') {
            helper(nums, ans + "1", n, j + 1);
        }

        return nums;
    }

    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
         vector<string> nums;
        helper(nums,"",n,0);
    }

int main() {
    vector<int> nums = {1, 2, 3};

    cout << boolalpha << checkSubsequenceSum(nums, 5);

    return 0;
}