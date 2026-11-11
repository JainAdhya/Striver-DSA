#include<bits/stdc++.h>
using namespace std;

//Solution 1
bool isPrime1(int n) {
    for(int i=2;i<n;i++){
        if(n%i==0){
            return true;
        }
    }
    return false;
}

//Solution 2
bool isPrime2(int n) {
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    bool res = isPrime2(n);
    cout << res; 
}
