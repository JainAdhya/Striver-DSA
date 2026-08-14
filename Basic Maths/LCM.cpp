#include <bits/stdc++.h>
using namespace std;

int LCM(int n1,int n2) {
    int lcm;
    int n = max(n1, n2);
    int i = 1;
    while(1) {
        int mul = n * i;
        if(mul % n1 == 0 && mul % n2 == 0) {
            lcm = mul;
            break;
        }
        i++;
    }
    return lcm;
}

int GCD(int n1, int n2) {
    while(n1!=0 && n2!=0){
        if(n1>n2){
            n1=n1%n2;
        }else{
            n2=n2%n1;
        }
    }
    if(n1==0){
        return n2;
    }
    return n1;
}

int LCM(int n1,int n2) {
        int gcd=GCD(n1,n2);
        return n1*n2/gcd;
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    int res = LCM(n1, n2);
    cout << res;
}