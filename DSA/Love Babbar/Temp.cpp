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
    Node* random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* leftHead, Node* rightHead) {
    if(leftHead == NULL) return rightHead;
    if(rightHead == NULL) return leftHead;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(leftHead != NULL && rightHead != NULL) {
        if(leftHead->data < rightHead->data) {
            temp->next = leftHead;
            temp = leftHead;
            leftHead = leftHead->next;
        }
        else {
            temp->next = rightHead;
            temp = rightHead;
            rightHead = rightHead->next;
        }
    }

    while(leftHead) {
        temp->next = leftHead;
        temp = leftHead;
        leftHead = leftHead->next;
    }

    while(rightHead) {
        temp->next = rightHead;
        temp = rightHead;
        rightHead = rightHead->next;
    }
    return ans->next;
}

Node* mergeSort(Node* &head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* mid = findMid(head);
    Node* leftHead = head;
    Node* rightHead = mid->next;
    mid->next = NULL;

    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);
    return merge(leftHead, rightHead);    
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
    Node* n1 = new Node(30);
    Node* head = n1;
    Node* tail = n1;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 40);
    cout<<"Current Linked List : ";
    printList(head);

    Node* sortedList = mergeSort(head);
    cout<<"Sorted Linked List : ";
    printList(sortedList);
}