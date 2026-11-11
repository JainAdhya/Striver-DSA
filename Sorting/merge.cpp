#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>& a, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int index = 0;
    vector<int> b(high - low + 1);
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[index] = a[i];
            i++;
        }
        else {
            b[index] = a[j];
            j++;
        }
        index++;
    }
    while (i <= mid) {
        b[index] = a[i];
        i++;
        index++;
    }
    while (j <= high) {
        b[index] = a[j];
        j++;
        index++;
    }
    for (int i = 0; i < index; i++) {
        a[low + i] = b[i];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeArray(arr, low, mid, high);
}

vector<int> merge(vector<int>& a) {
    mergeSort(a, 0, a.size() - 1);
    return a;
}

int main() {
    vector<int> nums = {7, 4, 1, 5, 3};
    vector<int> ans = merge(nums);
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}