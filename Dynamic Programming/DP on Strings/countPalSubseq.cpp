#include <bits/stdc++.h>
using namespace std;


int helper(const string& s,String ans,int index) {
    if(index==s.length()){
        string rev=reverse(ans.begin(),ans.end());
        if(ans==rev){
            return 1;
        }
        return 0;
    }

    int include=helper(s,ans+s[index],index+1);
    int exclude=helper(s,ans,index+1);
    return include+exclude;
}
int countPalSubseq(const string& s) {
    return helper(s,"",0);
}

int countPalSubseq(string s) {
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            if(s[i]==s[j]){
                dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
            }else{
                dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            }
        }
    }
    return dp[0][n-1];
        
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = powerSet(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}