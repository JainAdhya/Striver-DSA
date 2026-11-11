#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;
    helper(nums, left + 1, right - 1);
}

vector<int> reverseArray(vector<int>& nums) {
    helper(nums, 0, nums.size() - 1);
    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = reverseArray(nums);
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}