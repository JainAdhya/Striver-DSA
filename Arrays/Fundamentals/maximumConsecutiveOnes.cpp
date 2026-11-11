#include <bits/stdc++.h>
using namespace std;

int maximumConsecutiveOnes(vector<int>& a) {
    int ones=0;
    int maxi=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==1){
            ones++;
        }else if(a[i]==0){
            maxi=max(maxi,ones);
            ones=0;
        }
    }
    return maxi;
}

int main() {
    vector<int> arr={1, 1, 0, 0, 1, 1, 1, 0};
    int res=maximumConsecutiveOnes(arr);
    cout << res;
}