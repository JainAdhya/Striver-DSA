#include <bits/stdc++.h>
using namespace std;
    
bool rotate(string s, string goal) {
    if(s == goal) {
        return true;
    }
    for(int i = 0; i < s.length(); i++) {
        string res = "";
        res = s.substr(i) + s.substr(0, i);
        if(goal == res) {
            return true;
        }
    }
    return false;
}

int main() {
    string s="abcde";
    string goal = "cdbab";
    cout << rotate(s,goal);
    return 0;
}