#include <bits/stdc++.h>
using namespace std;

void leftRotateByOne(vector<int>& arr) {
    int first=arr[0];
    for(int i=0;i<arr.size()-1;i++){
        arr[i]=arr[i+1];
    }
    arr[arr.size()-1]=first;
}

int main() {
    vector<int> arr={3, 3, 6, 1};
    leftRotateByOne(arr);
     for(int i=0;i<arr.size();i++){
       cout<<arr[i];
    }
}