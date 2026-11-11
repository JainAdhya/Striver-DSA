#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& n, int index) {
    if (index == n.size()) {
        return 0;
    }
    return n[index] + helper(n, index + 1);
}

int sumOfArray(vector<int>& n) {
    return helper(n, 0);
}

int main() {
    vector<int> n = {1, 2, 3, 4};
    cout << sumOfArray(n);
    return 0;
}