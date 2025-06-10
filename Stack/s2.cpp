
#include<iostream>
#include<stack>
using namespace std;

// *************REMOVE MIDDLE ELEMENT OF STACK *************
void removeMid(stack<int> &st, int count, int size){
    if(count == size/2){
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();

    removeMid(st, count+1, size);
    st.push(top);

}

/******ADDING AN ELEMENT AT BOTTO OF THE STACK *********** */
void addBottom(stack<int> &st, int d){
    if(st.empty()){
        st.push(d);
        return;
    }
    int top = st.top();
    st.pop();

    addBottom(st, d);
    st.push(top);
}

/*******REVERSE A STACK ********** */
void revStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();

    revStack(st);
    addBottom(st, top);
}

/*SORTED INSERT IN A STACK*/
void sortedInsert(stack<int>& st, int num){
    if(st.empty() || num > st.top()){
        st.push(num);
        return;
    }

    int top = st.top();
    st.pop();

    sortedInsert(st, num);
    st.push(top);
}

void sortedStack(stack<int> st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();

    sortedStack(st);
    sortedInsert(st, top);
}

//number of changes to make the parenthesis valid
int makeValidParenthesis(string s){
    stack<char> st;
    //removing valid part
    for(int i = 0; i < s.length(); i++){
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

    //number of changes required
    int a = 0, b =0;
    for(int i =0; i<st.size() ; i++){
        if(st.top() == '{'){
            a++;
            st.pop();
        }
        else{
            b++;
            st.pop();
        }

    }
    return (a+1)/2 + (b+1)/2;
}


int main(){
    // stack<int> st;
    // st.push(30);
    // st.push(20);
    // st.push(10);
    // int size = 6, count = 0, d = 90;

    // // removeMid(st, count, size);
    // // addBottom(st, d);
    // revStack(st);

    // cout << "The top of the stack : " << st.top() << endl;
    // while (!st.empty()) {
    //     cout << st.top() <<" ";
    //     st.pop();
    // }

    cout << makeValidParenthesis("}}}}{{{{") << endl;
    return 0;
}