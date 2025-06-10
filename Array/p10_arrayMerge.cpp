/************************Merging two sorted arrays in sorted form *****************/

#include <iostream>
using namespace std;

int main()
{
    int arr1[100] = {1, 2, 3, 7, 10};
    int arr2[100] = {4, 6, 8, 9};
    int m = 5, n = 4;
    int arr3[m + n];
    int a=0;

    int i = 0,j = 0;
    while (i<m && j<n)
    {
        if(arr1[i]<arr2[j]){
            arr3[a++] = arr1[i++];
        }
        else{
            arr3[a++] = arr2[j++];
        }
    }

    while (i<m)
    {
        arr3[a++] = arr1[i++];
    }
    while (j<n)
    {
        arr3[a++] = arr2[j++];
    }
    
    

    for (int i = 0; i < m + n; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}