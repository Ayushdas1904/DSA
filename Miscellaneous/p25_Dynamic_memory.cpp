/**************************DYNAMIC MEMORY ALLOCATION ************************/

#include<iostream>
using namespace std;

//STACK - this type of memory stores memmory required to code during compile time and contains little memory
//HEAP - contains large chunk of memory and we can allocate and deallocate the memory in this memory

int main(){
    int* a = new int; //integer allocation where pointers is of 8 bytes and integer is of 4 bytes
    delete a; // deleting memory in heap

    //1D ARRAY
    int n;
    cin>> n;
    int* arr = new int[n]; //array allocation

    //2D ARRAY
    int row, col;
    cin >> row;
    cin >> col;
    cout<< endl;
    int** arr2 = new int*[row]; //all 1st memory of rows are allocated as int*

    for (int i = 0; i < row; i++)
    {
        arr2[i] = new int[row]; //all the corresponding memory are allocated
    }

//INPUT
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr2[i][j]; 
        }
    }

//OUTPUT
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<< arr2[i][j] << " ";
        }
        cout<< endl;
    }

//deleting memory allocated

    for (int i = 0; i < row; i++)
    {
        delete []arr2[i]; //all memory except base memory of all rows are deleted
    }
    delete []arr2; //base row memory is also deleted
    
    
    
    
    return 0;
}