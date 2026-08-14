#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n){
    int p1=0;
    int p2=n-1;
    while(p1<p2){
        int temp=arr[p1];
        arr[p1]=arr[p2];
        arr[p2]=temp;
        p1++;
        p2--;
    }  
}

int main() {
    int arr[]={1,2,3,4,5};
    reverse(arr,5);
    for(int i=0;i<5;i++){
        cout << arr[i];
    }
}