/***************ROTATING AN ARRAY OR FORWARDING AN ARRAY BY K FACTOR (imp) **************/ 

#include<iostream>
using namespace std;

int main(){
    int nums[5] = {0,1,0,3,12};
    int size = 5;
    int k;
    cout<< "Enter the value of k : ";
    cin>>k;

    int temp[size];

    for (int i = 0; i < size; i++)
    {
        temp[(i+k)%size] = nums[i]; //Rotating an element in array by a factor k and storing it in new array
    }
    
    for (int i = 0; i < size; i++)
    {
        nums[i] = temp[i];
        cout<< nums[i]<< " ";
    }
    
    
    return 0;
}