/************Book allocation (allocating maximum no pages which is minimum of all possibility) ***************/

#include <iostream>
using namespace std;

bool isPossible(int arr[], int size, int student, int mid)
{
    int StuCount = 1;
    int pageSum = 0;

    for (int i = 0; i < size; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            StuCount++;
            if (StuCount > student || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int bookAlloc(int arr[], int size, int student)
{

    int s = 0;
    int e = 0;
    int ans = -1;
    for (int i = 0; i < size; i++)
    {
        e += arr[i];
    }
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (isPossible(arr, size, student, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    cout << bookAlloc(arr, 4, 3);
    return 0;
}