#include<iostream>
using namespace std;

class Node{
    public: 
    
    int data; 
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


void insertNode(Node* &tail, int element, int d){
    
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;

    }

    //non -empty list
    else{
        Node* curr = tail;

        while(curr -> data != element){
            curr = curr -> next;
        }

        //now curr represents element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }

}

void deleteNode(Node* &tail, int d){
    // empty list
    if(tail == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    // non empty list
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != d){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 node list
        if(prev == curr){
            tail = NULL;
        }

        //node>=2
        else if(tail == curr){
            tail = prev;
        }


        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &tail){
    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = tail;
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;

    // cout << "Head : " << head -> data << endl;

    cout << "Tail : " << tail -> data << endl;
}

int main(){

    Node* tail = NULL;
    // print(tail); 

    insertNode(tail, 1,  3);
    print(tail);

    // insertNode(tail, 3,  1);
    // print(tail);

    // insertNode(tail, 3,  5);
    // print(tail);

    // insertNode(tail, 5,  7);
    // print(tail);

    deleteNode(tail, 3);
    print(tail);

}