#include <bits/stdc++.h>
using namespace std;
// Arrays/FAQs (Hard)/MergeTwoSortedNoExtra.cpp
vector<int> unionArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-n-1;
    int j=n-1;
    int res=m-1;
    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[res]=nums1[i];
            res--;
            i--;
        }else{
            nums1[res]=nums2[j];
            res--;
            j--;
        }
    }
    while(i>=0){
        nums1[res]=nums1[i];
            res--;
            i--;
    }
    while(j<nums2.size()){
        nums1[res]=nums2[j];
            res--;
            j--;
    }
    return nums1;
}

int main() {
    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
    vector<int> nums2 = {-3, 1, 8};
    vector<int> ans=unionArray(nums1,7,nums2,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}