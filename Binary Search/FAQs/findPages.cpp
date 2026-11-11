#include <bits/stdc++.h>
using namespace std;

int findPages(vector<int> &nums, int m)  {
    int n = nums.size();

    if (m > n) {
        return -1;
    }
 
    int low = *max_element(nums.begin(), nums.end());
    int high = 0;
    for(int i=0;i<nums.size();i++){
        high+=nums[i];
    }

    int res = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long student = 1;
        int pages=0;
        for (int i = 0; i < nums.size(); i++) {
            if(pages+nums[i]>mid){
                student++;
                pages=nums[i];
            }else{
                pages+=nums[i];
            }
        }

        if (student <= m) {
            res=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }

    return res;
}

int main() {
vector<int> nums={25, 46, 28, 49, 24};
int limit=4;

    int ans = findPages(nums,limit);
    cout << ans;

    return 0;
}
