#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    int i=1;
    int ele=0;
    int j=1;
    int c=1;
    while(i!=arr.size()){
        if(arr[i]==arr[ele]){
            i++;
        }else if(arr[i]!=arr[ele]){
            ele=i;
            arr[j]=arr[ele];
            j++;
            i++;
            c++;
        }
    }
    return c;
}

int main() {
    vector<int> arr={0, 0, 3, 3, 5, 6};
    removeDuplicates(arr);
     for(int i=0;i<arr.size();i++){
       cout<<arr[i];
    }
}