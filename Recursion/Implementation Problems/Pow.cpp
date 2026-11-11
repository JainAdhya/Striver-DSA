#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
        if(n==0){
            return 1;
          }
          if(n<0){
            return (1/x)*myPow(x,n+1);
          }
          else{
            return (x)*myPow(x,n-1);
          }
}

int main(){
    int ans=myPow(2.0000,10);
    cout << ans;
    return 0;
}