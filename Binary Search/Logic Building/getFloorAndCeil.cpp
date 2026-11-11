#include<bits/stdc++.h>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x) {
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
    if(nums[ans]==target){
        return {nums[ans],nums[ans]};
    }else if(ans==0){
        return {-1,nums[ans]};
    }else if(ans==n){
        return {nums[ans-1],-1};
    }
    return {nums[ans-1],nums[ans]};
}

int main(){
    vector<int> nums={3,5,8,15,19};
    int ans=lowerBound(nums,9);
    cout << ans;
    return 0;
}