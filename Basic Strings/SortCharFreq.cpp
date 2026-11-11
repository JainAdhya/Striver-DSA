#include <bits/stdc++.h>
using namespace std;

vector<char> frequencySort(string& s){
	unordered_map<char, int> mp;
            for (char c : s) {
                mp[c]++;
            }
            vector<pair<char, int>> v;
            for (auto x : mp) {
                v.push_back({x.first, x.second});
            }
            sort(v.begin(), v.end(), [](auto& a, auto& b) {
                if (a.second != b.second)
                    return a.second > b.second;  
                return a.first < b.first;      
            });
            vector<char> ans;
            for (auto x : v) {
                ans.push_back(x.first);
            }
            return ans;
}

int main() {
    string s = "anagram";
    vector<char> ans=frequencySort(s);
    for(int i=0;i<ans.size();i++){
        cout << ans[i];
    }
}