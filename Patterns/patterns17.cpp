#include<bits/stdc++.h>
using namespace std;

//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char p='A';
        for(int j=0;j<n-i;j++){
            cout << (" ");
        }
        for(int k=0;k<=i;k++){
            cout << p;
            p++;
        }
        p='A'+(i-1);
        for(int k=0;k<i;k++){
            cout << p;
            p--;
        }
        cout << "\n";
    }
} 
