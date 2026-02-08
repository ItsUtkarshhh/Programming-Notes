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
        cout<<"This node is deleted "<<this->data<<endl;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

void printLL(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!"<<endl;
        return;
    }
    Node* temp = head;
    do {
        cout<<temp->data<<" > ";
        temp = temp->next;
    }while(temp != head);
    cout<<"NULL"<<endl;
}

// Sort 0 1 2
Node* sort012(Node* head, Node* tail) {
    if(head == NULL || tail == NULL) {
        return NULL;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* curr = head;

    while(curr != NULL) {
        if(curr->data == 0) zeroCount++;
        if(curr->data == 1) oneCount++;
        if(curr->data == 2) twoCount++;
        curr = curr->next;
    }

    curr = head;
    while(curr != NULL) {
        if(zeroCount > 0) {
            curr->data = 0;
            zeroCount--;
        }
        else if(oneCount > 1) {
            curr->data = 1;
            oneCount--;
        }
        else if(twoCount > 2) {
            curr->data = 2;
            twoCount--;
        }
        curr = curr->next;
    }

    return head;
}

int main() {
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 0);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);

    printLL(head);

    cout<<endl;

    Node* newHead = sort012(head, tail);
    printLL(newHead);

}