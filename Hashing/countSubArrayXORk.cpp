#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k){
    unordered_map<int, int> count;
    int prefix = 0;
    int ans = 0;

    count[0] = 1;

    for(int i = 0; i < nums.size(); i++) {
        prefix ^= nums[i];

        int rem = prefix ^ k;

        if(count.find(rem) != count.end()) {
            ans += count[rem];
        }

        count[prefix]++;
    }

    return ans;
}

int main(){
    vector<int> nums={4, 2, 2, 6, 4};
    int ans=subarraySum(nums,6);
    cout << ans;
    return 0;
}