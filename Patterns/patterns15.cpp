#include<bits/stdc++.h>
using namespace std;

// ABCDE
// ABCD
// ABC
// AB
// A

int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        char p='A';
        for(int j=0;j<n-i;j++){
                cout << p;
                p++;
        }
        cout << "\n";
    }
} 
