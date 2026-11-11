#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //RECUSRION
    int helper(vector<int>& heights, int index, int k) {
        if (index == 0) {
            return 0;
        }

        int minEnergy = INT_MAX;

        for (int i = 1; i <= k; i++) {
            if (index - i < 0) {
                break;
            }

            int jump = helper(heights, index - i, k)
                       + abs(heights[index] - heights[index - i]);

            minEnergy = min(minEnergy, jump);
        }

        return minEnergy;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();

        return helper(heights, n - 1, k);
    }

    //DP

    int helper(vector<int>& heights, int index,
               vector<int>& jumps, int k) {
        if (index == 0) {
            return 0;
        }

        if (jumps[index] != -1) {
            return jumps[index];
        }

        int minEnergy = INT_MAX;

        for (int i = 1; i <= k; i++) {
            if (index - i < 0) {
                break;
            }

            int jump = helper(heights, index - i, jumps, k)
                       + abs(heights[index] - heights[index - i]);

            minEnergy = min(minEnergy, jump);
        }

        jumps[index] = minEnergy;
        return jumps[index];
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> jumps(n, -1);

        return helper(heights, n - 1, jumps, k);
    }
};

int main() {
    Solution sol;

    vector<int> heights = {10, 30, 40, 50, 20};
    int k = 3;

    cout << sol.frogJump(heights, k) << endl;

    return 0;
}
