#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)  {
    int n = nums.size(); 
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={3,5,8,15,19};
    int ans=lowerBound(nums,9);
    cout << ans;
    return 0;
}