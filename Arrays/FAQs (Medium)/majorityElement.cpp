#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int bucket=nums[0];
        int count=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]==bucket){
                count++;
            }else if(count==0){
                bucket=nums[j];
                count=1;
            }else if(nums[j]!=bucket && count>0){
                count--;
            }
        }
        return bucket;
}

int main(){
    vector<int> nums={7, 0, 0, 1, 7, 7, 2, 7, 7};
    int ans=majorityElement(nums);
    cout << ans;
    return 0;
}