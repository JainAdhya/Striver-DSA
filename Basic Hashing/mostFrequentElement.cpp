#include <bits/stdc++.h>
using namespace std;

int mostFrequentElement1(vector<int>& nums) {
    map<int,int> hash;
    for(int i=0;i<nums.size();i++){
        auto it=hash.find(nums[i]);
        if(it!=hash.end()){
            it->second++;
        }else{
            hash.insert({nums[i],1});
        }
    }
    int max = 0;
    int ans = 0;
    for(auto it : hash) {
        if(it.second > max) {
            max = it.second;
            ans = it.first;
        }
    }
    return ans;
}

int main() {
    vector<int> arr={1, 2, 2, 3, 3, 3};
    int ans= mostFrequentElement2(arr);
    cout << ans;
}