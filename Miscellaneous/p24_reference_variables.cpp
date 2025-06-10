#include<iostream>
using namespace std;

void hello(int& a){  // int& here makes a new variable which also refers to the orginal variable
    a++;
}

int main(){
    int i = 5;
    cout<< "Before: " << i << endl;
    hello(i);
    cout<< "After : " << i << endl;
    return 0;
}