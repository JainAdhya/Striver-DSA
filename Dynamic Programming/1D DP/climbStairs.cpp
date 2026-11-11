#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Recusrion
    int helper(int n) {
        if (n == 0) {
            return 1;
        } 
        else if (n < 0) {
            return 0;
        }

        return helper(n - 1) + helper(n - 2);
    }

    int climbStairs(int n) {
        return helper(n);
    }


    // DP
    int helper(int n, vector<int>& steps) {
        if (n == 0) {
            return 1;
        } 
        else if (n < 0) {
            return 0;
        }

        if (steps[n] != -1) {
            return steps[n];
        }

        steps[n] = helper(n - 1, steps) + helper(n - 2, steps);
        return steps[n];
    }

    int climbStairs(int n) {
        vector<int> steps(n + 1, -1);
        return helper(n, steps);
    }
};

int main() {
    Solution sol;
    int n = 2;

    cout << sol.climbStairs(n) << endl;

    return 0;
}
