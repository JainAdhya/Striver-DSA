#include <bits/stdc++.h>
using namespace std;

vector<int> divisors1(int n) {
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> divisors2(int n) {
    vector<int> ans;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i!=i){
                ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> res = divisors2(n);
    for(int i=0;i<res.size();i++){
        cout << res[i];
    }
}