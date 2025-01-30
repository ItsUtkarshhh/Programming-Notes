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
    ~Node() {
        cout<<"Node Deleted!";
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
    tail = temp;
}

void insertAtAnyPosition(Node* &head, int data, int pos) {
    // Empty list!
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }

    // If pos == 1 then insert at Head!
    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertAtTail(head, data);
        return;
    }

    Node* newNode = new Node(data);
    temp->next = newNode;
    newNode->next = temp->next;
}

int getLength(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void deleteNode(Node* head, int pos) {
    // Empty List!
    if(head == NULL) {
        cout<<"List is Empty!";
        return;
    }

    int len = getLength(head);
    if(pos < 1 || pos > len) {
        cout<<"Invalid position!";
        return;
    }

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else {
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;
        while(count < pos) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL) {
            prev->next = NULL;
            tail = prev;
            delete curr;
            return;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
}