#include<bits/stdc++.h>
using namespace std;

// A
// BB
// CCC
// DDDD
// EEEEE

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char p='A'+i;
        for(int j=0;j<=i;j++){
                cout << p;
        }
        cout << "\n";
    }
} 
