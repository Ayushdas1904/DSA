/***************2D ARRAY BINARY SEARCH************/

#include <iostream>
using namespace std;

bool binarySearch(int arr[][3], int target, int row, int col){
    int s=0, e= row*col -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        int element = arr[mid/col][mid%col];
        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }

}

int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    
    return 0;
}