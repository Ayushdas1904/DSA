#include<iostream>
using namespace std;

class Node{
    public: 
    
    int data; 
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;

    }
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &head,Node* &tail, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
        return;

    }
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    Node* temp = head;

    if(position == 1){
        insertAtHead(head, tail, d);
        return;
    }

    int cnt = 1;
    while(cnt < position -1){
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL){
        insertAtTail(head, tail, d);
        return ;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    nodeToInsert -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    else{
        Node* temp = head;

        int cnt = 1;
        while(cnt < position){
            temp = temp -> next;    
            cnt++;
        }

        // deleting tail
        if(temp -> next == NULL){
            temp -> prev -> next = NULL;
            tail = temp -> prev;
            temp -> prev = NULL;
            delete temp;
            return;
        }
        
        temp -> prev -> next = temp -> next;
        temp -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    }
}

void print(Node*&head, Node* &tail){
    Node* temp = head;
    while(temp !=  NULL){
        cout << temp ->data << " ";
        temp = temp -> next;

    } cout << endl;
    cout << "Head : " << head -> data << endl;

    cout << "Tail : " << tail -> data << endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    // print(head, tail);

    insertAtHead(head, tail, 12);
    print(head, tail);

    insertAtTail(head, tail, 15);
    print(head, tail);

    insertAtPosition(head, tail, 2, 25);
    print(head, tail);

    deleteNode(head, tail, 2);
    print(head, tail);

    return 0;
}