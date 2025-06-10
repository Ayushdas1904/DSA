#include<iostream>
using namespace std;

int modularExpo(int x, int n, int m ) /**Finding (x^n)%m **/ /**ITS HAS COMPLEXICITY OF O(LOGN)***/
{
    int res =1;

    while(n>0){
        if (n&1)
        {
            res = (1LL * res%m * x%m)%m;
        }
        x = (1LL * x%m *x%m)%m;
        n = n>>1;
    }
    return res;
}

int main(){
    
    cout<< modularExpo(2, 4, 5);
    return 0;
}