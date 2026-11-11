
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // BRUTE FORCE
    long long fact(int m) {
        if (m == 0) {
            return 1;
        }

        long long ans = 1;

        for (int i = 2; i <= m; i++) {
            ans *= i;
        }

        return ans;
    }

    int uniquePaths(int m, int n) {
        long long ans = fact(m + n - 2) /
                        (fact(m - 1) * fact(n - 1));

        return (int)ans;
    }

    // OPTIMIZATION
    int uniquePaths(int m, int n) {
        int total = m + n - 2;
        int r = min(m - 1, n - 1);
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (total - r + i) / i;
        }

        return (int)ans;
    }


    // RECUSRION
    int helper(int m,int n, int i,int j) {
        if(i==m-1 && j==n-1){
            return 1;
        }
        int count=0;

        if(i<m-1){
            count=helper(i+1,j);
        }
        if(j<n-1){
            count+=helper(i,j+1);
        }

        return count;
    }

    int uniquePaths(int m, int n) {
        return helper(0,0);
    }

    // RECUSRION
    int helper(int m,int n, int i,int j) {
        if(i==m-1 && j==n-1){
            return 1;
        }
        int count=0;

        if(i<m-1){
            count=helper(m,n,i+1,j);
        }
        if(j<n-1){
            count+=helper(m,n,i,j+1);
        }

        return count;
    }

    int uniquePaths(int m, int n) {
        return helper(m,n,0,0);
    }

    // DP - Memorization
    int helper(int m,int n, int i,int j,vector<vector<int>> ans) {
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(ans[i][j]!=-1){
            return ans[i][j];
        }
        int count=0;

        if(i<m-1){
            count=helper(m,n,i+1,j);
        }
        if(j<n-1){
            count+=helper(m,n,i,j+1);
        }
        ans[i][j]=count;

        return count;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int> (n,-1));
        return helper(m,n,0,0,ans);
    }

    // DP - Tabulation
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            ans[0][i]=1;
        }
        for(int j=0;j<m;j++){
            ans[j][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ans[i][j]=ans[i][j-1]+ans[i-1][j];
            }
        }
        return ans[m-1][n-1];
    }


    // DP - Space Optimaztion
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(2,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            ans[0][i]=1;
        }
        ans[1][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(i%2==1){
                    ans[i%2][j]=ans[i%2][j-1]+ans[(i-1)%2][j];
                }else{
                    ans[i%2][j]=ans[i%2][j-1]+ans[(i+1)%2][j];
                }
            }
        }
        return ans[(m-1)%2][(n-1)];
    }






};

int main() {
    Solution sol;

    int m = 3, n = 7;

    cout << sol.uniquePaths(m, n) << endl;

    return 0;
}
