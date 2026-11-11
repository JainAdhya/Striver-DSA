#include <bits/stdc++.h>
using namespace std;

int largestEle(vector<int>& arr, int target) {
        //your code goes here
        int max=arr[0];
        for(int i=1;i<arr.size();i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main() {
    vector<int> arr={3, 3, 6, 1};
    int res=largestEle(arr,5);
    cout << res;
}