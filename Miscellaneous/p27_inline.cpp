#include <iostream>
using namespace std;

/*******************INLINE FUNCTION***********************/
inline int Sum(int &a, int &b)
{ // if function code is one line then it replaces the functino call to the line of code to boost performance and extra storage is not used for the function
    return a + b;
}

/******************DEFAULT ARGUMENTS************************/
int hello(int arr[], int n, int start = 0) // here start is a default argument with default value 0 and default arguments starts from rightmost of function arguments
{
    for (int i = start; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
    
}

int main()
{
    int a = 1, b = 2;
    cout << Sum(a, b) <<endl;

    int arr[] = {1,2,3,4,5,6};
    hello(arr, 6); // start default value of start

    return 0;
}