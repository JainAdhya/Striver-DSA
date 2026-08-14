#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n) {
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;	  
}

int main() {
    int arr[]={1,2,3,4,5};
    int res=sum(arr,5);
    cout << res;
}