#include <bits/stdc++.h>
using namespace std;

    
string reverseString(string& s) {
    int end = s.size()-1;
    string rev="";
    while(end>=0) {
            rev+=s.at(end);
            end--;
    }
        
    return rev;
}
bool palindromeCheck(string& s){
    if(s==reverseString(s)){
        return true;
    }
    return false;
}

int main() {
    string str = "abba";
    cout << palindromeCheck(str);
}