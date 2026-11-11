#include <bits/stdc++.h>
using namespace std;

vector<int> bubble(vector<int>& a) {
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    return a;
}

int main() {
    vector<int> nums = {7, 4, 1, 5, 3};
    vector<int> ans = bubble(nums);
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}