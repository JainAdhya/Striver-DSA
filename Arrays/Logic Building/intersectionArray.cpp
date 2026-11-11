#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                i++;
            }
        }

        return ans;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 4, 6, 7};

    vector<int> ans = intersectionArray(nums1, nums2);

    cout << "Intersection: ";
    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}