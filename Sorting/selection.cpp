#include <bits/stdc++.h>
using namespace std;

vector<int> selection(vector<int>& a) {
    for(int i = 0; i < a.size(); i++) {
        int min = i;
        for(int j = i + 1; j < a.size(); j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return a;
}

int main() {
    vector<int> nums = {7, 4, 1, 5, 3};
    vector<int> ans = selection(nums);
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}