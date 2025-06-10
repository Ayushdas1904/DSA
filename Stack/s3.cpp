/*********MINIMUM COST TO MAKE STRING VALID********* */


#include<iostream>
#include<stack>
#include<string>
using namespace std;

int minCount(string s, stack<char> &st){
    if(s.size()%2 == 1) return -1; // if odd brackets then invalid

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }

    int a = 0, b = 0;
    while(!st.empty()){
        if(st.top() == '{') b++;
        else a++;
        st.pop();
    }


    return (a+1)/2 + (b+1)/2;

}

int main(){
    string s = "{}{}}{";
    stack<char> st;

    cout << "Min Count : " <<  minCount(s, st);
    
    return 0;
}