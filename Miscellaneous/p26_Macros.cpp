/***************************MACROS****************************/
//Its a piece ofcode in program tht is replaced by the value of macro

#define PI 3.14 //no semicolon and it does not take storage in memory just puts the value of PI wherever mentioned

#include<iostream>
using namespace std;

int main(){
    int r = 5;
    double pi = 3.14;
    pi+=1;  // variable is  modifiable 
    cout<< pi * r * r << endl;

    cout << PI * r * r << endl;  // not modifiable like PI+=1
    return 0;
}