#include <bits/stdc++.h>
using namespace std;

int stockBuySell(vector<int> arr, int n){
        int mini=arr[0];
        int maxProfit=0;
        for(int i=1;i<n;i++){
            maxProfit=max(maxProfit,arr[i]-mini);
            mini=min(mini,arr[i]);
        }
        return maxProfit;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = powerSet(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}