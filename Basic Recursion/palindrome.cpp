#include <bits/stdc++.h>
using namespace std;

bool helper(string s,int left,int right) {
    if (left>=right) {
        return true;
    }
    if(s[left]!=s[right]){
        return false;
    }
    return helper(s,left+1,right-1);
}

bool palindrome(string s) {
    return helper(s, 0,s.size()-1);
}

int main() {
    string n = "hanyah";
    cout << palindrome(n);
    return 0;
}