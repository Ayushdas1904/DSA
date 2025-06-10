/*****************replaacing " " with "@40" in a string ***************/

#include<iostream>
#include<String>
using namespace std;

int main(){
    string s;
    cout<< "Enter a string: ";
    getline(cin, s);
    string temp = "";

    int st = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' '){
            temp.append(s.begin()+st, s.begin()+i);
            temp.append("@40");
            st = i+1;
        }
    }
    temp.append(s.begin()+st, s.end());
    s = temp;
    cout<<endl<<s<<endl;
    
    return 0;
}