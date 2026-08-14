#include<bits/stdc++.h>
using namespace std;

int countDigit(int n) {
    if(n==0){
        return 1;
    }
    return (int)log10(n)+1;
}

bool isArmstrong(int n) {
    int original = n;
    int digit = countDigit(n);
    int sum = 0;

    while (n > 0) {
        sum += (int)round(pow(n % 10, digit));
        n /= 10;
    }

    return sum == original;
}

int main()
{
    int n;
    cin >> n;

    int res = isArmstrong(n);
    cout << res; 
}
