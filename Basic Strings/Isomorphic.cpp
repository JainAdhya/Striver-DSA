#include <bits/stdc++.h>
using namespace std;

    
bool Isomorphic(string& s,string& t){
    int map1[26] = {0};
    int map2[26] = {0};
    for(int i = 0; i < s.size(); i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if(map1[a] != map2[b])
            return false;
            map1[a] = i + 1;
            map2[b] = i + 1;
        }
        return true;
}

int main() {
    string s="apple",t="bbnbm";
    cout << Isomorphic(s,t);
}