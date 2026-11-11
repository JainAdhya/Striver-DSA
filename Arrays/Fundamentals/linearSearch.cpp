#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
        //your code goes here
        for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr={1,2,3,4,5};
    int res=linearSearch(arr,5);
    cout << res;
}