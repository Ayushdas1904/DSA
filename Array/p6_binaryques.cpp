/****************AGGRESSIVE COWS (binary search)**********0*/

#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int arr[], int k, int mid)
{ // k = no of aggressive cows and no of elements in the array
    int cowcount = 1;
    int lastPos = arr[0];

    for (int i = 0; i < k; i++)
    {
        if (arr[i] - lastPos >= mid)
        {
            cowcount++;
            if (cowcount == k)
            {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}

int search(int arr[], int k)
{

    for (int i = 0; i < k - 1; i++)
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

    int s = 0;
    int maxi = -1;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(arr, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {6, 4, 7, 1, 8};
    cout << search(arr, 5);
    return 0;
}