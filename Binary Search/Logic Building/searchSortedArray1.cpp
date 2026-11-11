#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target){
    int n = nums.size();

    if (n == 0) return -1;

    int low = 0;
    int high = n - 1;
  
    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= nums[0]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    int start = low;

    if (start == 0) {
        low = 0;
        high = n - 1;
    } else if (target >= nums[0] && target <= nums[start - 1]) {
        low = 0;
        high = start - 1;
    } else {
        low = start;
        high = n - 1;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

// Version 2
int search2(vector<int> &nums, int x) {
    int n = nums.size();

    if (n == 0) return -1;

    int low = 0;
    int high = n - 1;

    // Find the pivot (smallest element's index)
    while (low <= high) {
        int mid = (low +high) / 2;
        if (nums[mid] == x) {
            return mid;
        } else if(nums[low]<=nums[mid]){
            if(nums[low]<=x && x<nums[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(nums[mid]<=x && x<=nums[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;

}

int main(){
    vector<int> nums={7, 8, 9, 1, 2, 3, 4, 5, 6};
    // int ans=search(nums,9);
    int ans=search2(nums,9);
    cout << ans;
    return 0;
}