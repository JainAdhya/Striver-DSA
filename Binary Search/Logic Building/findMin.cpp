#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)  {
      int n = nums.size();
    int low = 0;
    int high = n - 1;
        int ans=INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] >= nums[low]) {
            ans=min(ans,nums[low]);
            low = mid + 1;
        } else {
            ans=min(ans,nums[mid]);
            high = mid-1;
        }
    }

    return ans;
}

int main(){
    vector<int> nums={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    // int ans=search(nums,9);
    int ans=search2(nums,3);
    cout << ans;
    return 0;
}