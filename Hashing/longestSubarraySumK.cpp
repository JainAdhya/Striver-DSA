#include<bits/stdc++.h>
using namespace std;

// Positive + Negative
int longestSubarray(vector<int> &nums, int k){
    int n=nums.size();
    map<int, int> preSumMap;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        int rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len=i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> nums={10, 5, 2, 7, 1, 9};
    int ans=longestSubarray(nums,15);
    cout << ans;
    return 0;
}