#include <bits/stdc++.h>
using namespace std;

int sumOfFirstN(int n) {
    if(n==1){
        return 1;
    }
    return n+sumOfFirstN(n-1);
}

int main() {
    int n=4;
    cout << sumOfFirstN(n);
    return 0;
}