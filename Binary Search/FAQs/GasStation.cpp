#include<bits/stdc++.h>
using namespace std;

//VERSION 1
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> par(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 1; i < n; i++) {
        pq.push({(long double)(arr[i] - arr[i - 1]), i - 1});
    }


    for(int i=0;i<k;i++){
        auto it=pq.top();
        pq.pop();
        int index = it.second;
        par[index]++;

        long double originalGap = arr[index + 1] - arr[index];
        long double newDistance =
            originalGap / (par[index] + 1);

        pq.push({newDistance, index});
    }
    return pq.top().first;
}

//VERSION 2
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> par(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 1; i < n; i++) {
        pq.push({(long double)(arr[i] - arr[i - 1]), i - 1});
    }


    for(int i=0;i<k;i++){
        auto it=pq.top();
        pq.pop();
        int index = it.second;
        par[index]++;

        long double originalGap = arr[index + 1] - arr[index];
        long double newDistance =
            originalGap / (par[index] + 1);

        pq.push({newDistance, index});
    }
    return pq.top().first;
}



int main(){
    vector<int> nums={1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
    // int ans=search(nums,9);
    int ans=search2(nums,10);
    cout << ans;
    return 0;
}