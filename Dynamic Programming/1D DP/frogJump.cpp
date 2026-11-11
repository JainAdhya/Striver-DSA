#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Recusrion
    int helper(vector<int>& heights, int index) {
        if (index == 0) {
            return 0;
        }


        int left = helper(heights, index - 1, jumps)
                   + abs(heights[index] - heights[index - 1]);

        int right = INT_MAX;

        if (index > 1) {
            right = helper(heights, index - 2)
                    + abs(heights[index] - heights[index - 2]);
        }

        return min(left, right);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
    
        return helper(heights, n - 1);
    }

    // DP
    int helper(vector<int>& heights, int index, vector<int>& jumps) {
        if (index == 0) {
            return 0;
        }

        if (jumps[index] != -1) {
            return jumps[index];
        }

        int left = helper(heights, index - 1, jumps)
                   + abs(heights[index] - heights[index - 1]);

        int right = INT_MAX;

        if (index > 1) {
            right = helper(heights, index - 2, jumps)
                    + abs(heights[index] - heights[index - 2]);
        }

        jumps[index] = min(left, right);

        return jumps[index];
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> jumps(n, -1);

        return helper(heights, n - 1, jumps);
    }
};

int main() {
    Solution sol;

    vector<int> heights = {10, 20, 30, 10};

    cout << sol.frogJump(heights) << endl;

    return 0;
}
