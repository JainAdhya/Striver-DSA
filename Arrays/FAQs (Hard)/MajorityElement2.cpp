#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int k = 3;
    vector<int> bucket(k - 1, -1);
    vector<int> count(k - 1, 0);
    vector<int> ans;

    int threshold = nums.size() / k;

    for (int i = 0; i < nums.size(); i++) {
        int j = 0;

        // 1. Check existing candidates first
        while (j < k - 1 &&
               (count[j] == 0 || bucket[j] != nums[i])) {
            j++;
        }

        if (j < k - 1) {
            count[j]++;
            continue;
        }

        // 2. Find an empty slot
        j = 0;
        while (j < k - 1 && count[j] != 0) {
            j++;
        }

        if (j < k - 1) {
            bucket[j] = nums[i];
            count[j] = 1;
        } else {
            // 3. Decrement all counts
            for (int p = 0; p < k - 1; p++) {
                count[p]--;
            }
        }
    }

    // 4. Verify actual frequencies
    for (int p = 0; p < k - 1; p++) {
        if (count[p] == 0) continue;

        int freq = 0;
        for (int x : nums) {
            if (x == bucket[p]) {
                freq++;
            }
        }

        if (freq > threshold) {
            ans.push_back(bucket[p]);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {7, 8, 8, 9, 8};

    vector<int> ans = majorityElement(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
