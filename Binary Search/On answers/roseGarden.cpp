#include <bits/stdc++.h>
using namespace std;

int roseGarden(int n,vector<int> nums, int k, int m) {
    if (1LL * k * m > n) {
        return -1;
    }

    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int res = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int roses = 0;
        int bouquet = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                roses++;

                if (roses == k) {
                    bouquet++;
                    roses = 0;
                }
            } else {
                roses = 0;
            }
        }

        if (bouquet >= m) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
vector<int> nums={7, 7, 7, 7, 13, 11, 12, 7};
int limit=5;

    int ans = roseGarden(8,nums,2,3);
    cout << ans;

    return 0;
}
