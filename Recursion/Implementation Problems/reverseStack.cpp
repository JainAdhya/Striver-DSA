#include<bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &st,int temp) {
        if(st.empty()){
            st.push(temp);
            return;
        }
        int ele=st.top();
        st.pop();
        insertBottom(st,temp);
        st.push(ele);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int temp=st.top();
        st.pop();
        reverseStack(st);
        insertBottom(st,temp);
        
    }

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}