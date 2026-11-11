#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& nums) {
      stack<int> st;
        int count=0;
        for(int j=nums.size()-1;j>=0;j--){
            if(st.empty()){
                st.push(nums[j]);
                count++;
            }else if(st.top()<nums[j]){
                st.push(nums[j]);
                count++;
            }
        }
        vector<int> ans;
        for(int j=0;j<count;j++){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
}

int main(){
    vector<int> nums={1, 2, 5, 3, 1, 2};
    vector<int> ans=leaders(nums);
    for(int j=0;j<ans.size();j++){
        cout << ans[j];
    }
    return 0;
}