#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxsum){
                maxsum=sum;
            }
            if(sum<0){
                sum=0;
            }
    
        }
        return maxsum;
}

int main(){
    vector<int> nums={7, 0, 0, 1, 7, 7, 2, 7, 7};
    int ans=maxSubArray(nums);
    cout << ans;
    return 0;
}