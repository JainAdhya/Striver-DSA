#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return first;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return last;
    }

    int countOccurrences(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);

        if (first == -1) return 0;

        int last = lastOccurrence(nums, target);

        return last - first + 1;
    }

int main(){
    vector<int> nums={1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans=singleNonDuplicate(nums);
    cout << ans;
    return 0;
}