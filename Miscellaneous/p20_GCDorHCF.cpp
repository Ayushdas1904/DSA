#include<iostream>
using namespace std;

int gcd(int a, int b){

    while(a!=0 && b!=0){
        if (a<b)
        {
            b = b%a;
        }
        else if (a>b)
        {
            a = a%b;
        }
        
    }
    
    if(a==0){
        return b;
    }
    return a;
}

int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;

    cout<< "The GCD is: "<< gcd(a,b);

    return 0;
}