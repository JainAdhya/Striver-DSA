#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= high && a[i] < pivot) {
            i++;
        }
        while (j >= low && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}

void quick(vector<int>& a, int low, int high) {
    if (low >= high) {
        return;
    }
    int p = partition(a, low, high);
    quick(a, low, p - 1);
    quick(a, p + 1, high);
}

int main() {
    vector<int> nums = {7, 4, 1, 5, 3};
    quick(nums, 0, nums.size() - 1);
    for (int x : nums) {
        cout << x << " ";
    }
    return 0;
}