#include<iostream>
#include<vector>
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

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

Node* deleteAllOcc(Node* head, int data) {
    if(head == NULL) return head;

    Node* dummy = new Node(data);
    Node* previous = dummy;
    Node* current = head;

    while(current != NULL) {
        if(current->data == data) {
            Node* ntd = current;
            previous->next = current->next;
            current->next->prev = previous;
            ntd->next = ntd->prev = NULL;
            delete ntd;
        }
        else {
            previous = current;
        }
        current = current->next;
    }
    return dummy->next;
}

int main() {
    Node* n1
}