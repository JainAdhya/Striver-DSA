#include <bits/stdc++.h>
using namespace std;

    
string longestCommonPrefix(vector<string>& str){
 int minSize = 100000;
        int index = 0;
        for (int i = 0; i < str.size(); i++) {
            if (minSize > str[i].length()) {
                minSize = str[i].length();
                index = i;
            }
        }
        string rev = "";
        for (int i = 0; i < str[index].length(); i++) {

            for (int j = 0; j < str.size(); j++) {

                if (str[index][i] != str[j][i]) {
                    return rev;
                }
            }
            rev += str[index][i];
        }

        return rev;
    }

int main() {
    vector<string> str ={"flowers" , "flow" , "fly", "flight" };
    cout << longestCommonPrefix(str);
}