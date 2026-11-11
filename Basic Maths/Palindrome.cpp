#include<bits/stdc++.h>
using namespace std;

//Solution 1
bool Palindrome(int n) {
    int num=n;
    int reverse=0;
    while(n>0){
        int digit=n%10;
        reverse=reverse*10+digit;
        n=n/10;
    }
    return reverse==num;
}

int main()
{
    int n;
    cin >> n;

    bool res = Palindrome(n);
    cout << res; 
}
