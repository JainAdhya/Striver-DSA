#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size() - 1;
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid - 1 >= 0 && mid + 1 <= n &&
            arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) {
            return mid;
        }
        else if (mid + 1 <= n && arr[mid + 1] > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
vector<int> nums={1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

    int ans = findPeakElement(nums);
    cout << ans;

    return 0;
}
