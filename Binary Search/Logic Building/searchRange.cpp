#include<bits/stdc++.h>
using namespace std;

// VERSION 1
vector<int> getFloorAndCeil(vector<int> nums, int x) {
   int n = nums.size(); 
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid=(low+high)/2;
        if(nums[mid]==target){
            int i=mid-1;
            int j=mid+1;
            while(i>=0 && nums[i]==target){
                i--;
            }
            while(j<=n-1 && nums[j]==target){
                j++;
            }
            return {i+1,j-1};
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return {-1,-1};
}

//VERSION 2
int lowerBound(vector<int> &nums, int target){
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> &nums, int target){
        int low=0;
    int high=nums.size()-1;
    int ans=nums.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int firstOcc = lowerBound(nums, target);  
    if(firstOcc == nums.size() || nums[firstOcc] != target) return {-1, -1}; 
    int lastOcc = upperBound(nums, target) - 1;  
    return {firstOcc, lastOcc};  
}

//VERSION 3
int firstOccurrence(vector<int> &nums, int target){
    int low=0;
    int high=nums.size()-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            first=mid;
            high=mid-1;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return first;
}

int lastOccurrence(vector<int> &nums, int target){
    int low=0;
    int high=nums.size()-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            first=mid;
            low=mid+1;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return first;
}

vector<int> searchRange(vector<int> &nums, int target) {
        int first = firstOccurrence(nums, target); 
        if(first == -1) return {-1, -1};  
        int last = lastOccurrence(nums, target);  
        return {first, last};  
}

int main(){
    vector<int> nums={3,5,8,15,19};
    int ans=lowerBound(nums,9);
    cout << ans;
    return 0;
}