#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& arr) {
    int max=arr[0];
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return (max*(max+1)/2-sum)==0? (max+1): (max*(max+1)/2-sum);
}

int main() {
    vector<int> arr={0, 0, 3, 3, 5, 6};
    int ans=missingNumber(arr);
    cout<<ans;
}