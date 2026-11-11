#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>& arr, int target) {
        //your code goes here
        int max=arr[0];
        int sec=-1;
        for(int i=1;i<arr.size();i++){
        if(arr[i]>max){
            sec=max;
            max=arr[i];
        }else if(arr[i]>sec && arr[i]<max){
            sec=arr[i];
        }
    }
    return sec;
}

int main() {
    vector<int> arr={8, 8, 7, 6, 5};
    int res=secondLargest(arr,5);
    cout << res;
}