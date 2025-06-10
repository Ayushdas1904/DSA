#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permut(vector<string>& res, string str, int index){
    if(index >= str.size()){
        res.push_back(str);
        return ;
    }
    for (int i = index; i < str.size(); i++)
    {
        swap(str[index], str[i]);
        permut(res, str, index+1);
        swap(str[index], str[i]);
    }
    
}

int main(){
    string str = "123";
    vector<string> res;
    string output;
    int index = 0;
    permut(res, str, index);
    for(int i = 0; i< res.size(); i++){
        cout<< res[i] << " ";
    }
    return 0;
}