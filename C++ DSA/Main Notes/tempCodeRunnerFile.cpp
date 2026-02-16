#include<iostream>
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
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* cloneRandomLL(Node* head) {
    if(head == NULL) return NULL;

    Node* original = head;
    Node* clonedHead = new Node(originalHead->data);
    Node* clonedTail = clonedHead;

    while(original != NULL) {
        Node* newNode = new Node(original->data);
        clonedTail->next = newNode;
        clonedTail = newNode;
        original = original->next;
    }

    original = head;
    Node* cloned = clonedHead;

    while(original != NULL) {
        if(original->random) {
            Node* temp = original;
            Node* tempClone = cloned;
            while(temp != NULL) {
                if(temp == original->random) {
                    cloned->random = tempClone;
                    break;
                }
                temp = temp->next;
                tempClone = tempClone->next;
            }
        }
        original = original->next;
        cloned = cloned->next;
    }
}