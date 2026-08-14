#include <bits/stdc++.h>
using namespace std;

int secondMostFrequentElement(vector<int>& nums) {
     map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        } 

        int maxFreq=0;
        int secMaxFreq=0;
        int secEle=0;
        int maxEle=0;

        for(auto it : hash) {
            int ele = it.first; 
            int freq = it.second; 
            
            if(freq > maxFreq) {
                secMaxFreq = maxFreq;
                maxFreq = freq;
                secEle = maxEle;
                maxEle = ele;
            } 
            else if(freq == maxFreq) {
                maxEle = min(maxEle, ele);
            }
            else if(freq > secMaxFreq) {
                secMaxFreq = freq;
                secEle = ele;
            }
            else if(freq == secMaxFreq) {
                secEle = min(secEle, ele);
            }
        }
        return secEle;
}

int main() {
    vector<int> arr={1, 2, 2, 3, 3, 3};
    int ans= secondMostFrequentElement(arr);
    cout << ans;
}