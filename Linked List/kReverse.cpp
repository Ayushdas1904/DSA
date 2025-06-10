#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//INSERTING ELEMENT AT HEAD
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}


//INSERTING ELEMENT AT TAIL
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}


// INSERTING ELEMENT AT A CERTAIN POSITION
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    Node *temp = head;

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// REVERSING USING RECURSION in K GROUPS
Node* kRev(Node* &head, int k){
    //base case
    if(head == NULL ){
        return NULL;
    }

    Node* next = NULL;
    Node* prev =NULL;
    Node* curr = head;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //recrsion laga do
    if(next != NULL){
        head -> next = kRev(next , k);
    }
    return prev;
}


//TRAVERSING LIST
void print(Node* &head, Node* &tail){
    Node* temp = head;

    cout << "The Linked List: ";
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    } cout << endl;

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << endl;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 9);
    insertAtTail(tail, 11);
    insertAtPosition(head,tail, 2, 22);
    print(head, tail);

    //Reversing linked list using recursion 
    
    kRev(head, 2);
    return 0;
}