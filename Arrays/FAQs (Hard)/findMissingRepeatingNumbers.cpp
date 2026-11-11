#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers1(vector<int>& nums) {
    long long n = nums.size();

    long long s = n * (n + 1) / 2;
    long long s2 = n * (n + 1) * (2 * n + 1) / 6;

    long long sn = 0;
    for (int x : nums) {
        sn += x;
    }

    long long s2n = 0;
    for (int x : nums) {
        s2n += 1LL * x * x;
    }

    long long val1 = s - sn;
    long long val2 = s2 - s2n;

    long long sum = val2 / val1;

    long long missing = (sum + val1) / 2;
    long long repeating = (sum - val1) / 2;

    return {(int)repeating, (int)missing};
}

vector<int> findMissingRepeatingNumbers2(vector<int>& nums) {
    long long n = nums.size();

}

int main() {
    vector<int> nums = {6, 5, 7, 1, 8, 6, 4, 3, 2};

    vector<int> ans = findMissingRepeatingNumbers(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
