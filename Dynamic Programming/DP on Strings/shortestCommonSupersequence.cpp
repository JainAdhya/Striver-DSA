#include <bits/stdc++.h>
using namespace std;

// DP
string shortestCommonSupersequence(string str1, string str2){
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(str1[i-1] != str2[j-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }

    vector<vector<int>> ranges;

    int i = n, j = m;
    int end1 = n-1, end2 = m-1;
    int count = 0;

    while(i > 0 && j > 0) {

        if(str1[i-1] == str2[j-1]) {
            count++;
            i--;
            j--;
        }
        else {
            if(count > 0) {
                ranges.push_back({
                    end1-count+1, end1,
                    end2-count+1, end2
                });
            }

            if(dp[i-1][j] >= dp[i][j-1]) {
                i--;
            }
            else {
                j--;
            }

            end1 = i-1;
            end2 = j-1;
            count = 0;
        }
    }

    if(count > 0) {
        ranges.push_back({
            end1-count+1, end1,
            end2-count+1, end2
        });
    }

    reverse(ranges.begin(), ranges.end());

    string result = "";
    int start1 = 0, start2 = 0;

    for(int k = 0; k < ranges.size(); k++) {

        int s1 = ranges[k][0];
        int e1 = ranges[k][1];
        int s2 = ranges[k][2];
        int e2 = ranges[k][3];

        result += str1.substr(start1, s1-start1);
        result += str2.substr(start2, s2-start2);

        result += str1.substr(s1, e1-s1+1);

        start1 = e1+1;
        start2 = e2+1;
    }

    result += str1.substr(start1);
    result += str2.substr(start2);

    return result;
}


string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            if(str1[i-1] != str2[j-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            else {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
        }
    }

    string result = "";

    int i = n, j = m;

    while(i > 0 && j > 0) {

        if(str1[i-1] == str2[j-1]) {
            result += str1[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                result += str1[i-1];
                i--;
            }
            else {
                result += str2[j-1];
                j--;
            }
        }
    }

    while(i > 0) {
        result += str1[i-1];
        i--;
    }

    while(j > 0) {
        result += str2[j-1];
        j--;
    }

    reverse(result.begin(), result.end());

    return result;
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