#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<2*n-1;i++){
        for(int k=0;k<2*n-1;k++){
            int top=i;
            int left=k;
            int bottom= 2*n-2-i;
            int right = 2*n-2-k;
            int value=n-min(min(left, right), min(top, bottom));


            cout << value;
    }
     cout << "\n";
}
} 
