#include <bits/stdc++.h>
using namespace std;

int sumHighestAndLowestFrequency(vector<int>& nums) {
     map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        } 

    int max = 0;
    int maxAns = 0;
    int min=1000000;
    int minAns=0;

    for(auto it : hash) {
        if(it.second > max) {
            max = it.second;
            maxAns = it.first;
        }
        if(it.second <min){
            min = it.second;
            minAns = it.first;
        }
    }
    return max+min;
}

int main() {
    vector<int> arr={1, 2, 2, 3, 3, 3};
    int ans= sumHighestAndLowestFrequency(arr);
    cout << ans;
}