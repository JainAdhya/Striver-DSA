#include<bits/stdc++.h>
using namespace std;

void nextPermutation1(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
}
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] <= nums[i +1]) {
        i--;
    }
    if (i == -1) {
        reverse(nums.begin(), nums.end());
    } else {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i+1, nums.end());
    }
}
int main(){
    vector<int> nums={2,1,3};
    nextPermutation1(nums);
    for(int i=0;i<nums.size();i++){
        cout << nums[i];
    }
    return 0;
}