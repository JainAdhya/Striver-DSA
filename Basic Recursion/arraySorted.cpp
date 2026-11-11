#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int>& nums, int i) {
    if (i==nums.size()-1) {
        return true;
    }
    if(nums[i]>nums[i+1]){
        return false;
    }
    return helper(nums, i+1);
}

bool arraySorted(vector<int>& nums) {
    return helper(nums, 0);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << arraySorted(nums);
    return 0;
}