#include<iostream>
using namespace std;

class Heap{
    private:
    int arr[100];
    int size = 0;
    public:

    Heap(){
        arr[0] = -1;
    }

    void insert(int val){
        size++;
        arr[size] = val;
        int index = size;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(51);
    h.print();
    return 0;
}