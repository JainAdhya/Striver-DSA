#include<bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &nums, int x)  {
      int n = nums.size();

    if (n == 0) return -1;

    int low = 0;
    int high = n - 1;

    // Find the pivot (smallest element's index)
    while (low <= high) {
        int mid = (low +high) / 2;
        if (nums[mid] == x) {
            return true;
        }else if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
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
    return false;
    }

int main(){
    vector<int> nums={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    // int ans=search(nums,9);
    int ans=search2(nums,3);
    cout << ans;
    return 0;
}