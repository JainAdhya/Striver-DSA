#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& arr,int left,int end){
    while(left<end){
        int temp=arr[left];
        arr[left]=arr[end];
        arr[end]=temp;
        left++;
        end--;
    }
}

void leftRotateByK(vector<int>& arr,int k) {
    reverse(arr,0,arr.size()-1);
    reverse(arr,0,arr.size()-1-k);
    reverse(arr,arr.size()-k,arr.size()-1);

}

int main() {
    vector<int> arr={1, 2, 3, 4, 5, 6};
    leftRotateByK(arr,2);
     for(int i=0;i<arr.size();i++){
       cout<<arr[i];
    }
}