#include <bits/stdc++.h>
using namespace std;

    
string largeOddNum(string& s){
    int start=0;
        int last=s.length()-1;
        while(start <= last && s.at(start) == '0') 
        {
            start++;
        }
        while(start <= last && (s.at(last)-'0')%2== 0) 
        {
            last--;
        }
        return s.substr(start,last-start+1);
}

int main() {
    string str = "0214638";
    cout << largeOddNum(str);
}