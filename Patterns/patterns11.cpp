#include<bits/stdc++.h>
using namespace std;

// 1 
// 0 1 
// 1 0 1 
// 0 1 0 1 
// 1 0 1 0 1

int main()
{
    int n;
    cin >> n;
    int p;

    for(int i=0;i<n;i++){
        if(i%2){
            p=1;
        }else{
            p=0;
        }
        for(int k=0;k<=i;k++){
            cout << !p;
            p=!p;
            
        }
        cout << "\n";
    }
} 
