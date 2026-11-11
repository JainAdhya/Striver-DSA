#include<bits/stdc++.h>
using namespace std;

// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int k=0;k<n-i;k++){
            cout << "*";
        }
        for(int k=0;k<2*i;k++){
            cout << "&";
        }
        for(int k=0;k<n-i;k++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<=i;k++){
            cout << "*";
        }
        for(int k=0;k<2*(n-1)-2*i;k++){
            cout << "&";
        }
        for(int k=0;k<=i;k++){
            cout << "*";
        }
        cout << "\n";
    }
} 
