#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,5,63,3,0,67};
    int k=6;
    for (int i = 0; i < k-1; i++)
    { // SORTING ARRAY
        for (int j = i+1; j < k; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout<< arr[i]<<"    ";
    }
    
    return 0;
}