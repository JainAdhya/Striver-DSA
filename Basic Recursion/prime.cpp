#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int i) {

    if (i == n) {
        return true;
    }
    if(n%i==0){
        return false;
    }
    return helper(n,i+1);
}

bool prime(int n) {
    return helper(n, 2);
}

int main() {
    int n = 15;
    cout << prime(n);
    return 0;
}