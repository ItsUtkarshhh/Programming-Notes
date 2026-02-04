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

void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

Node* reverseList(Node* &head, Node* &tail) {
    if(head == NULL) {
        cout<<"Empty List!";
        return NULL;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* fwd = curr->next;
    while(curr != NULL) {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    tail = head;
    head = prev;
    return head;
}

void revLL_helper(Node* &head, Node* &tail, Node* curr, Node* prev) {
    if(curr == NULL) {
        tail = head;
        head = prev;
        return;
    }

    Node* fwd = curr->next;
    revLL_helper(head, tail, fwd, curr);
    curr->next = prev;
}

Node* revLL(Node* &head, Node* &tail) {
    if(head == NULL || tail == NULL) {
        cout<<"Empty List!";
        return NULL;
    }
    Node* curr = head;
    Node* prev = NULL;
    revLL_helper(head, tail, curr, prev);
    return head;
}

void printLL(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    Node* temp = head;
    do {
        cout<<temp->data<<" > ";
        temp = temp->next;
    }while(temp != NULL);
    cout<<"NULL\n";
}

int main() {
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 0);

    cout<<"Current LL : ";
    printLL(head);

    // Node* newHead = reverseList(head, tail);
    Node* newHead = revLL(head, tail);

    cout<<"New LL : ";
    printLL(newHead);

}