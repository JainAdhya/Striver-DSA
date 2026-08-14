#include <bits/stdc++.h>
using namespace std;

int countOdd(int arr[], int n) {
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2){
            count++;
        }
    }
    return count;	  
}

int main() {
    int arr[]={1,2,3,4,5};
    int res=countOdd(arr,5);
    cout << res;
}