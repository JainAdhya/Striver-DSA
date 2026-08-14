#include <bits/stdc++.h>
using namespace std;

    
void reverseString(vector<char>& s) {
    int start = 0, end = s.size()-1;
    while(start < end) {
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            start++, end--;
        }
        
        return;
}

int main() {
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    reverseString(str);
    for (char c : str) {
        cout << c;
    }
    return 0;
}