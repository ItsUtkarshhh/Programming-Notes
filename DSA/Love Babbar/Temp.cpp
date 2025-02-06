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

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

int getLen(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return -1;
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
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLen(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        delete newNode;
        return;
    }

    if(pos == 1) {
        insertAtHead(head, data);
        delete newNode;
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(pos == len + 1) {
        insertAtTail(head, tail, data);
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

Node* reverseLL(Node* &head, Node* &tail) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    tail = head;
    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
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

    insertAnywhere(head, tail, getLen(head) + 1, 20);
    insertAnywhere(head, tail, getLen(head) + 1, 30);
    insertAnywhere(head, tail, getLen(head) + 1, 40);
    insertAnywhere(head, tail, getLen(head) + 1, 50);
    insertAnywhere(head, tail, getLen(head) + 1, 60);

    printList(head);

    reverseLL(head, tail);

    printList(head);
}