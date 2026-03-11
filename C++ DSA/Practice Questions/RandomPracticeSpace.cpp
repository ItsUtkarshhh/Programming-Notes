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
    dummy->next = head;

    Node* previous = dummy;
    Node* current = head;
    Node* forward = current->next;

    while(current != NULL) {
        
    }
}

int main() {

}