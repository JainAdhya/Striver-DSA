#include<bits/stdc++.h>
using namespace std;

// A
// AB
// ABC
// ABCD
// ABCDE

int main()
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        char p='A';
        for(int j=0;j<i+1;j++){
                cout << p;
                p++;
        }
        cout << "\n";
    }
} 
