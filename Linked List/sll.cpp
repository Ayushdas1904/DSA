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

// INSERTING ELEMENT AT HEAD
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// INSERTING ELEMENT AT TAIL
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
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

// DELETING AN ELEMENT
void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if (curr->next == NULL)
        {
            tail = prev;
        }
        else
        {
            curr->next = NULL;
        }
        delete curr;
    }
}

// CONCATENATING TWO LINKED LIST
Node *concatenate(Node *&head1, Node *&head2, Node *&tail1, Node *&tail2)
{
    if (head1 == NULL)
    {
        head1 = head2;
        tail1 = tail2;
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;

    tail1 = tail2;

    return head1;
}

// TRAVERSING LIST
void print(Node *&head, Node *&tail)
{
    Node *temp = head;

    cout << "The Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << endl;
}

// Reversing LL
void reverseLL(Node *&head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next; // Save the next node
        curr->next = prev;    // Reverse the link
        prev = curr;          // Move prev to current
        curr = forward;       // Move to next node
    }

    // Swap the head and tail
    tail = head;
    head = prev;
}

// MIDDLE NODE = mid of the node , for even number of nodes the node further from head is middle node
Node *midNode(Node *&head, Node *&tail)
{
    int len = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    int halfLen = len / 2;

    Node *mid = head;
    while (halfLen)
    {
        mid = mid->next;
        halfLen--;
    }
    return mid;
}

int main()
{

    // CREATING A LINKED LIST
    Node *node1 = new Node(10);
    Node *node2 = new Node(50);

    // head pointed to node
    Node *head = node1;
    Node *head2 = node2;

    // tail pointed to node1
    Node *tail = node1;
    Node *tail2 = node2;
    print(head, tail);

    cout << "After inserting at head -" << endl;
    insertAtHead(head, 9);
    print(head, tail);

    cout << "After inserting at tail -" << endl;
    insertAtTail(tail, 11);
    print(head, tail);

    cout << "After inserting at a position -" << endl;
    insertAtPosition(head, tail, 2, 22);
    print(head, tail);

    cout << "After inserting at a position -" << endl;
    insertAtPosition(head, tail, 4, 69);
    print(head, tail);

    cout << "After deleting an element -" << endl;
    deleteNode(head, tail, 4);
    print(head, tail);

    // appending element to node1;
    insertAtTail(tail2, 60);
    insertAtTail(tail2, 70);
    insertAtTail(tail2, 80);

    cout << "After concatenating two lists -" << endl;
    concatenate(head, head2, tail, tail2);
    print(head, tail);

    // REVERSING LL
    //  cout <<  "Reversed LInked List : " << endl;
    //  reverseLL(head, tail);
    //  print(head, tail);

    // MIDDEL OF THE LINKED LIST
    cout << "The mid node of LL is: ";
    cout << midNode(head, tail)->data;

    return 0;
}