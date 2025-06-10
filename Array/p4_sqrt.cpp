/*************Square Root using binary search ************/

#include<iostream>
using namespace std;

int sqroot(int n){
    int s = 0, e = n;
    int mid = s + (e-s)/2;
    int ans = -1;

    while (s<e)
    {
        int square = mid*mid;
        if (square == n)
        {
            return mid;
        }
        else if(square < n){
            ans = mid;
            s = mid+1;
        }
        else if(square > n){
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
    
}

double more(int n, int tempsol){
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < 2; i++)
    {
        factor = factor/10;
        for (double j = ans; j*j < n; j = j + factor)
        {
            ans = j;
        }
        
    }
    return ans;
    
}

int main(){
    int n;
    cout<< "Enter a number: ";
    cin >> n;
    int tempsol = sqroot(n);
    cout<<more(n, tempsol);

    return 0;
}