#include<bits/stdc++.h>
using namespace std;

// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321

int main()
{
    int n;
    cin >> n;
    int p;

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
                cout << (j+1);
            }
            for (int j = 0; j < 2*(n-1)-2*i; j++) {
                cout << (" ");
            }
            for(int j=i+1;j>0;j--){
                cout << (j);
            }
           cout << "\n";
    }
} 
