#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    int maxLength=INT_MIN;
    
    for(auto it : st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            maxLength=max(maxLength,cnt);
        }
    }
    return maxLength;     
}

int main(){
    vector<int> nums={100, 4, 200, 1, 3, 2};
    int ans=longestConsecutive(nums);
    cout << ans;
    return 0;
}