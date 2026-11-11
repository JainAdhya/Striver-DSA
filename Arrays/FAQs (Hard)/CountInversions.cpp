#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int>& nums,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    long long count=0;
    while(i<=mid && j<=high){
if(nums[i]>nums[j]){
    count+=(mid-i+1);
    j++;
}else{
    i++;
}
    }
    i=low;
    j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(nums[j]);
        j++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
    return count;
}



long long mergeSort(vector<int>& nums,int low,int high){
    if(low>=high) return 0;
    int mid=low+(high-low)/2;
    long long count=0;
    count+=mergeSort(nums,low,mid);
    count+=mergeSort(nums,mid+1,high);
    count+=merge(nums,low,mid,high);
    return count;
}



long long int numberOfInversions(vector<int> nums) {
return mergeSort(nums,0,nums.size()-1);
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};

    cout << numberOfInversions(nums);

    return 0;
}
