#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// INSERTING ELEMENT AT HEAD
void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// INSERTING ELEMENT AT TAIL
void insertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        tail->prev = NULL;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// INSERTING ELEMENT AT A CERTAIN POSITION
void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}

// DELETING AN ELEMENT
void deleteNode(Node*& head, Node*& tail, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        int cnt = 1;

        while (cnt < position && curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL) {
            return;
        }

        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
        }

        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }

        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

// CONCATENATING TWO LINKED LISTS
Node* concatenate(Node*& head1, Node*& head2, Node*& tail1, Node*& tail2) {
    if (head1 == NULL) {
        head1 = head2;
        tail1 = tail2;
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    tail1->next = head2;
    head2->prev = tail1;
    tail1 = tail2;

    return head1;
}

// TRAVERSING LIST
void print(Node*& head, Node*& tail) {
    Node* temp = head;

    cout << "The Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    if (head) cout << "head : " << head->data << endl;
    if (tail) cout << "tail : " << tail->data << endl;
    cout << endl;
}

int main() {
    // CREATING A DOUBLY LINKED LIST
    Node* node1 = new Node(10);
    Node* node2 = new Node(50);

    // Head pointed to node
    Node* head = node1;
    Node* head2 = node2;

    // Tail pointed to node
    Node* tail = node1;
    Node* tail2 = node2;
    print(head, tail);

    cout << "After inserting at head -" << endl;
    insertAtHead(head, tail, 9);
    print(head, tail);

    cout << "After inserting at tail -" << endl;
    insertAtTail(tail, 11);
    print(head, tail);

    cout << "After inserting at a position -" << endl;
    insertAtPosition(head, tail, 2, 22);
    print(head, tail);

    cout << "After deleting an element -" << endl;
    deleteNode(head, tail, 4);
    print(head, tail);

    // Appending elements to node2
    insertAtTail(tail2, 60);
    insertAtTail(tail2, 70);
    insertAtTail(tail2, 80);

    cout << "After concatenating two lists -" << endl;
    concatenate(head, head2, tail, tail2);
    print(head, tail);

    return 0;
}