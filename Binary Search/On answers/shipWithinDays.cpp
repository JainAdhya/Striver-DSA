#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& nums, int days) {
        // Your code goes here
    int low = *max_element(nums.begin(), nums.end());
    int high = 0;
    for(int i=0;i<nums.size();i++){
        high+=nums[i];
    }
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;

        int day=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if((sum+nums[i])>mid){
                day++;
                sum=0;
            }
            sum+=nums[i];
        }

        if(day<=days){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main() {
vector<int> nums={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int limit=5;

    int ans = shipWithinDays(nums,5);
    cout << ans;

    return 0;
}
