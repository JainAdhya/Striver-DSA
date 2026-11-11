#include<bits/stdc++.h>
using namespace std;

// E 
// D E 
// C D E 
// B C D E 
// A B C D E

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        char p='A'+n-i-1;
        for(int k=0;k<=i;k++){
            cout << p;
            p++;
        }
        
        cout << "\n";
    }
} 
