#include<bits/stdc++.h>
using namespace std;

//Solution 1
bool isPerfect(int n) {
    int count=1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            count+=i;
        }
    }
    return n==count;
}

//Solution 2
bool isPerfect(int n) {
    int count=1;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            count+=i;
            count+=(n/i);
        }
    }
    return n==count;
}

int main()
{
    int n;
    cin >> n;

    bool res = isPerfect(n);
    cout << res; 
}
