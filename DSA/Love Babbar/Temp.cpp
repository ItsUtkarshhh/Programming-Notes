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
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node* &head, int pos, int data) {
    if(head == NULL) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    if(pos == 1) {
        insertAtHead(head,data);
        return;
    }

    Node* tail = head;
    Node* temp = head;

    int count = 1;
    while(count < pos && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    if(newNode->next == NULL) {
        tail = newNode;
    }
}

int getLength(Node* &head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void deletNode(Node* &head, int pos) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }

    int len = getLength(head);
    if(pos < 1 || pos > len) {
        cout<<"Invalid Position!";
    }

    Node* tail = head;
    int count = 1;

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

        while(count < pos && curr->next != NULL) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        if(curr->next == NULL) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void printLL(Node* &head) {
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

    insertAtAnyPosition(head,1,10);
    insertAtAnyPosition(head,2,10);
    insertAtAnyPosition(head,3,10);
    insertAtAnyPosition(head,4,10);
    insertAtAnyPosition(head,5,10);
    insertAtAnyPosition(head,6,10);
    insertAtAnyPosition(head,7,10);
    insertAtAnyPosition(head,8,10);
    insertAtAnyPosition(head,9,10);
    insertAtAnyPosition(head,10,10);
    printLL(head);
}