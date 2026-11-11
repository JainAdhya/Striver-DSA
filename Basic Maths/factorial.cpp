#include<bits/stdc++.h>
using namespace std;

//Solution 1
int factorial1(int n) {
    if(n==0 || n==1){
        return 1;
    }
    return n*factorial1(n-1);
    
}

//Solution 2
int factorial2(int n) {
    if(n==0 || n==1){
        return 1;
    }
    int prod=1;
    for(int i=2;i<=n;i++){
        prod*=i;
    }
    return prod;
}

int main()
{
    int n;
    cin >> n;

    int res = factorial2(n);
    cout << res; 
}
