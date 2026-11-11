#include<bits/stdc++.h>
using namespace std;

//Solution 1
int countDigit1(int n) {
    if(n==0){
        return 1;
    }
    int count=0;
    while(n>0){
        count++;
        n=n/10;
    }
    return count;
}

//Solution 2
int countDigit2(int n) {
    if(n==0){
        return 1;
    }
    return (int)log10(n)+1;
}

int main()
{
    int n;
    cin >> n;

    int res = countDigit2(n);
    cout << res; 
}
