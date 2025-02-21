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
#include<map>
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

Node* uniqueSortedList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {  // Ensure curr->next is not NULL before accessing its data
        if (curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            nodeToDelete->next = NULL;  // Good practice before deleting
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }
    return head;
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
    insertAnywhere(head, tail, 1, -5);
    cout<<"Current Linked List : ";
    printList(head);
    cout<<"Current head : "<<head->data<<" Current tail : "<<tail->data<<endl;

    cout<<endl<<endl;
    
    insertAnywhere(head, tail, getLen(head) + 1, 15);
    insertAnywhere(head, tail, getLen(head) + 1, 20);
    insertAnywhere(head, tail, getLen(head) + 1, 20);
    insertAnywhere(head, tail, getLen(head) + 1, 20);
    insertAnywhere(head, tail, getLen(head) + 1, 25);
    insertAnywhere(head, tail, getLen(head) + 1, 30);
    insertAnywhere(head, tail, getLen(head) + 1, 30);
    insertAnywhere(head, tail, getLen(head) + 1, 35);
    cout<<"Current Linked List : ";
    printList(head);
    cout<<"Current head : "<<head->data<<" Current tail : "<<tail->data<<endl;
    
    cout<<endl<<endl;
    
    // Removing Duplicates!
    Node* Head = uniqueSortedList(head);
    cout<<"Final Linked List : ";
    printList(head);
    cout<<"Current head : "<<head->data<<" Current tail : "<<tail->data<<endl;
}