#include<bits/stdc++.h>
using namespace std;

// Positive + Negative
int longestSubarray(vector<int> &nums){
    int k=0;
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
    vector<int> nums={15, -2, 2, -8, 1, 7, 10, 23};
    int ans=longestSubarray(nums);
    cout << ans;
    return 0;
}