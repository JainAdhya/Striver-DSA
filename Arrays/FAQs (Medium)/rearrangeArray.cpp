#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    int even=0;
    int odd=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            ans[even]=nums[i];
            even+=2;
        }else{
            ans[odd]=nums[i];
            odd+=2;
        }
    }
        return ans;
}

int main(){
    vector<int> nums={2, 4, 5, -1, -3, -4};
    vector<int> ans=rearrangeArray(nums);
    for(int j=0;j<ans.size();j++){
        cout << ans[j];
    }
    return 0;
}