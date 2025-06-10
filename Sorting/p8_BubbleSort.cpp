/*********BUBBLE SORT**************/

#include<iostream>
using namespace std;

int main(){
    int arr[] = {0,6,1,9,34,7};
    int size = 6;

    int swapped = false;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false){ //Already Sorted (optimising the code)
            break;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout<< arr[i]<< " ";
    }
    
    
    return 0;
}