#include<bits/stdc++.h>
using namespace std;

//Solution 1
int largestDigit(int n) {
    int max=-1;
    while(n>0){
        int digit=n%10;
        if(digit>max){
            max=digit;
        }
        n=n/10;
    }
    return max;
}

int main()
{
    int n;
    cin >> n;

    int res = largestDigit(n);
    cout << res; 
}
