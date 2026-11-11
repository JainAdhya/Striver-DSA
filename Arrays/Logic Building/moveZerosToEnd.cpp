#include <bits/stdc++.h>
using namespace std;

void moveZerosToEnd(vector<int>& arr) {
    int j=0;
    int i=0;
    while(i!=arr.size()){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j++;
        }
        i++;
    }
    while(j!=arr.size()){
        arr[j]=0;
        j++;
    }
}

int main() {
    vector<int> arr={0, 1, 4, 0, 5, 2};
    moveZerosToEnd(arr);
     for(int i=0;i<arr.size();i++){
       cout<<arr[i];
    }
}