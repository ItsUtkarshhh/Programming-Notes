#include<iostream>
#include<map>
#include<climits>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printLL(Node* &head) {
    if(head == NULL) return;

    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->next<<" > ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// Delete all occurences of a key from the in DLL!
Node* deleteAllOcc(Node* head, int data) {
    if(head == NULL) return NULL;

    Node* dummyNode = new Node(INT_MIN);
    Node* prev = dummyNode;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        if(curr->data == data) {
            Node* ntd = curr;
            prev->next = forward;
            forward->prev = prev;
            ntd->next = NULL;
            ntd->prev = NULL;
            delete ntd;
        }
        prev = curr;
        curr = forward;
    }
    return dummyNode->next;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertNode(head, tail, 1);
    insertNode(head, tail, 2);
    insertNode(head, tail, 3);
    insertNode(head, tail, 4);
    insertNode(head, tail, 5);
    insertNode(head, tail, 6);
}