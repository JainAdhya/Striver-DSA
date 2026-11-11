 #include <bits/stdc++.h>
using namespace std;

int median(vector<int> &a, vector<int>& b) {
    int n=a.size();
    int m=a.size();
   if(n>m){
    return median(b,a);
   }
   int low=0;
   int high=n;
   while(low<=high){
    int mid1=(low+high)/2;
    int mid2=(n+m+1)/2-mid1;

    int l1=(mid1>0)? a[mid1-1] : INT_MIN;
    int l2=(mid2>0)? b[mid2-1] : INT_MIN;
    int r1=(mid1<n)? a[mid1] : INT_MAX;
    int r2=(mid2<m)? b[mid2] : INT_MAX;

    if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 != 0) {
                    return max(l1, l2);
                } else {
                    return ((double)max(l1, l2) +
                            min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
   }
   return 0;
}

int main() {
vector<int> a={2, 3, 6, 7, 9};
vector<int> b={1, 4, 8, 10};

    int ans = kthElement(a,b,5);
    cout << ans;

    return 0;
}
