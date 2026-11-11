#include <bits/stdc++.h>
using namespace std;

// Tabulation
int longestStringChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](string& a, string& b) {
    return a.size() < b.size();
});
        int n = words.size();
        if(n == 0) return 0;

        vector<int> dp(n, 1);
        vector<int> parent(n);

        int maxLen = 1;
        int LastIndex = 0;

        for(int i = 0; i < n; i++) {
            parent[i] = i;

            for(int j = 0; j < i; j++) {

                if(words[i].size() == words[j].size() + 1 &&
                   isPredecessor(words[j], words[i]) &&
                   dp[i] < dp[j] + 1) {

                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if(dp[i] > maxLen) {
                maxLen = dp[i];
                LastIndex = i;
            }
        }

        return maxLen;
    }

    bool isPredecessor(string& shorter, string& longer) {
        int i = 0, j = 0;

        while(i < shorter.size() && j < longer.size()) {
            if(shorter[i] == longer[j]) {
                i++;
            }
            j++;
        }

        return i == shorter.size();
    }



int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = powerSet(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}