#include<bits/stdc++.h>
using namespace std;

vector<string> helper(vector<string>& ans,string s,int n,int close,int open){
        if (open==close && (open+close)==2*n) {
                ans.push_back(s);
            return ans;
        }

            if(open<n){
                helper(ans,s+'(',n,close,open+1);
            }
            if(close<open){
            helper(ans,s+')',n,close+1,open); 
            }
        return ans;
    }
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helper(ans, "", n, 0, 0);
    return ans;
 }
int main(){
    vector<string> ans=generateParenthesis(3);
    for(int i=0;i<ans.size();i++){
         cout << ans[i];
    }
    return 0;
}