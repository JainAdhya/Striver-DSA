#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int i=0;
    int j=0;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]<nums2[j]){
            res.push_back(nums1[i]);
            i++;
        }else if(nums1[i]==nums2[j]){
        res.push_back(nums1[i]);
        i++;
        j++;
        }else{
            res.push_back(nums2[j]);
            j++;
        }
    }
    while(i<nums1.size()){
        res.push_back(nums1[i]);
        i++;
    }
    while(j<nums2.size()){
        res.push_back(nums2[j]);
        j++;
    }
    return res;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 7};
    vector<int> ans=unionArray(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}