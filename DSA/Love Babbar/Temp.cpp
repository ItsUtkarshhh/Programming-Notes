// Single Linked List Implementation! - Creation, Insertion (Head Tail and Anywhere), Deletion, Length, Print! [DONE]
// Doubly Linked List Implementation! - Creation, Insertion (Head Tail and Anywhere), Deletion, Length, Print! [DONE]
// Circular Singly Linked List Implementation! - Creation, Insertion (Tail and Anywhere), Deletion, Length, Print! [DONE]
// Circular Doubly Linked List Implementation! - Creation, Insertion (Tail and Anywhere), Deletion, Length, Print! [DONE]
// Reverse a Linked List! - Recursive and Non-Recursive Method! [DONE]
// Middle Node! - Brute force and Optimized approach! [DONE]
// Reverse the Linkedlist in the groups of K!
// Check whether a LinkedList is Circular or Not! - Circular, Detect-Loop using Maps and Detect-Loop using Floyd's Algo methods!
// Detect, Get Starting Node of Loop and Remove the Loop!

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int getLen(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return 0;
    }
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhere(Node* &head, Node* &tail, int pos, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }

    int len = getLen(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid Length!";
        delete newNode;
        return;
    }

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    if(pos == len + 1) {
        tail->next = newNode;
        tail = newNode;
        return;
    }

    Node* temp = head;
    int count = 0;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

Node* reverseK(Node* &head, int k) {
    if(head == NULL) {
        return NULL;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;
    while(curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if(forward != NULL) {
        head->next = reverseK(forward, k);
    }
    return prev;
}

void printList(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    insertAnywhere(head, tail, 1, 5);
    insertAnywhere(head, tail, 1, 0);
    insertAnywhere(head, tail, 1, -5);
    cout<<"Current Linked List : ";
    printList(head);
    cout<<"Current head : "<<head->data<<" Current tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhere(head, tail, getLen(head) + 1, 15);
    insertAnywhere(head, tail, getLen(head) + 1, 20);
    insertAnywhere(head, tail, getLen(head) + 1, 25);
    cout<<"Current Linked List : ";
    printList(head);
    cout<<"Current head : "<<head->data<<" Current tail : "<<tail->data<<endl;

    cout<<endl<<endl;

    int k;
    cout<<"Enter K : ";
    cin>>k;
    head = reverseK(head, k);
    cout<<"Current Linked List : ";
    printList(head);
    cout<<"Current head : "<<head->data<<" Current tail : "<<tail->data<<endl;
}