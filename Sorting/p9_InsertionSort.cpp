/************INSERTION SORT**********/

#include<iostream>
using namespace std;

int main(){
    int arr[]=  {3,7,12,8,1,44};
    int size = 6;

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j>=0)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }

            j--;
            
        }
        arr[j+1] = temp;
        
    }

    for (int k = 0; k < size; k++)
    {
        cout<< arr[k] << " ";
    }
    
    
    return 0;
}