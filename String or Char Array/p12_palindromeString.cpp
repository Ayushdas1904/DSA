/*************Check for palindrome string being non case sensitive*************/

#include<iostream>
#include<cmath>
using namespace std;

char toLower(char ch){
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
    
}

bool checkPalindrome(char arr[], int size){
    int s = 0, e = size-1;
    while (s<=e)
    {
        if(int(arr[s]) >= 32 && int(arr[s]) <= 47 && int(arr[s]) >= 58 && int(arr[s]) <= 64){
                s++;
                e--;
        }
        
        else if (toLower(arr[s]) != toLower(arr[e]))
        {
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

int main(){
    
    int size;
    char ch[size];
    cout<<"Enter size and string : ";
    cin>>size>>ch[size];
    
    if(checkPalindrome(ch,size)==1){
        cout<<"Number is a palindrome";
    }

    else if(checkPalindrome(ch,size)==0){
        cout<<"Number is NOT a palindrome";
    }

    return 0;
}