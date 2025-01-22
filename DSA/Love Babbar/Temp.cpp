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
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
    temp->next = NULL;
}

void insertAtAnyPosition(Node* &head, int data, int pos) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* tail = head;
    Node* temp = tail;
    int count = 1;

    while(count < pos && temp->next != NULL) {
        temp = temp->next;
        count++
    }

    if(temp != NULL) {

    }
}

int main() {
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
}