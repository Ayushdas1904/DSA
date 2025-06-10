/**************POINTERS************/

#include<iostream>
using namespace std;

int main(){
    // //null pointers is created contains garbage value
    // int *p;  //we write int* to know the datatype of the variable and a;so how many bytes to consider
    
    // //creating a pointer differently
    // int i =5;
    // int *q = 0;
    // q = &i;

    // cout<< q << endl;
    // cout<< *q << endl;

    // //adding values using pointer
    // (*q)++;
    // cout << *q << endl;

    // //copying a pointer ( q stores same address and values as p)
    // int *s = q;
    // cout << s << endl;
    // cout<< *s << endl;

    // //
    // int a = 5; 
    // int *t = &a;

    // // t += 1; //increment the address by 4 bytes for integer   
    // cout<< t << endl; 
    // cout<< *t << endl;

    /**************INTEGER ARRAYS******************/

    // int arr[10]  = {1,2,3}; //arr = arr+1 is not possible once you assign the sixe of array

    // int *p = &arr[0]; 
    // cout<< p << endl;
    // p += 1;           //this changes the value of p by 4 bytes and displays the value stored at that memery address
    // cout<< p << endl;
    // cout<< *p << endl;
    
    /*************CHARACTER ARRAYS*****************/

    // char a[10] = {'a', 'b', 'c'};

    // char *ptr = &a[0];
    // cout<< ptr << endl;
    // cout<< *ptr << endl;

    /********DOUBLE POINTERS***********/
    int i =7;
    int *p = &i;
    int **p2 = &p;

    //address of i OR value of p
    cout<< p << endl;
    cout<< &i << endl;
    cout<< *p2 <<endl;

    //value of i
    cout<< *p << endl;
    cout<< i << endl;  
    cout<< **p2 << endl;

    //address of p
    cout<< &p << endl;
    cout<< p2 << endl;

    //adress of p2
    cout<< &p2 << endl;

    return 0;
}