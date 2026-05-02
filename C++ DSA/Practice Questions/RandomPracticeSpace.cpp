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

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* removeDuplicatesSorted(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* unique = head;
    Node* temp = head->next;
    while(temp != NULL) {
        if(unique->data != temp->data) {
            unique->next = temp;
            unique = temp;
        }
        temp = temp->next;
    }
    unique->next = NULL;
    return head;
}


Node* removeDuplicatesUnsorted(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    
}