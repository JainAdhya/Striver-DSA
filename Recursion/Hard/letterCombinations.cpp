#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // your code goes here
        if (digits.empty()) {
            return {};
        }

        unordered_map<int, vector<string>> mapping = {
            {2, {"a", "b", "c"}},
            {3, {"d", "e", "f"}},
            {4, {"g", "h", "i"}},
            {5, {"j", "k", "l"}},
            {6, {"m", "n", "o"}},
            {7, {"p", "q", "r", "s"}},
            {8, {"t", "u", "v"}},
            {9, {"w", "x", "y", "z"}}
        };

        vector<string> ans;

        for (int i = 0; i < mapping[digits[0] - '0'].size(); i++) {
            ans.push_back(mapping[digits[0] - '0'][i]);
        }

        for (int i = 1; i < digits.size(); i++) {
            vector<string> curr = mapping[digits[i] - '0'];
            vector<string> temp;

            for (int j = 0; j < ans.size(); j++) {
                string p = ans[j];

                for (int k = 0; k < curr.size(); k++) {
                    temp.push_back(p + curr[k]);
                }
            }

            ans = temp;
        }

        return ans;
    }
};

int main() {
    Solution s;

    string digits = "23";

    vector<string> ans = s.letterCombinations(digits);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}