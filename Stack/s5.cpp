#include <bits/stdc++.h>
using namespace std;


int longestValidParentheses(string s) {
        stack<char> st;
        int cnt = 0, k =0;
        for(int i=0; i < s.length(); i++){
            if(s[i] == '(') 
            {
                if(!st.empty() && st.top() != '('){
                    st.push(s[i]);
                }
                else{
                    st.push(s[i]);
                    cnt = max(cnt, k);
                    k=0;
                }
            }
            else{
                if(!st.empty()){
                    k+=2;
                    st.pop();
                }
                else{
                    cnt = max(cnt, k);
                    k=0;
                }
            }
        }
        cnt = max(cnt, k);
        return cnt;
}
int main(){
    cout<< longestValidParentheses(")()())");
    return 0;
}