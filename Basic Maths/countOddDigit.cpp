#include<bits/stdc++.h>
using namespace std;

//Solution 1
int countOddDigit(int n) {
    if(n==0){
        return 0;
    }
    int count=0;
    while(n>0){
        int digit=n%10;
        if(digit%2){
            count++;
        }
        n=n/10;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int res = countOddDigit(n);
    cout << res; 
}
