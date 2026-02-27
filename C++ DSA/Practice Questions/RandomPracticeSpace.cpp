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

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* revK(Node* head, Node* tail, int k) {
    if(head == NULL) return NULL;

    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* prevGroupEnd = dummy;

    while(true) {
        Node* kth = prevGroupEnd; // groupEnd
        int i = 0;
        while(i < k && kth != NULL) {
            kth = kth->next;
            i++;
        }
        
        if(kth == NULL) break;

        Node* groupStart = prevGroupEnd->next;
        Node* nextGroupStart = kth->next;

        kth->next = NULL;

        Node* prev = NULL;
        Node* curr = groupStart;

        while(curr != NULL) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        prevGroupEnd->next = prev;
        groupStart->next = nextGroupStart;
        prevGroupEnd = groupStart;
    }
    return dummy->next;
}

Node* revK(Node* head, Node* tail, int k) {
    if(head == NULL) return NULL;

    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* prevGroupEnd = dummy;

    while(true) {
        Node* kth = prevGroupEnd; // groupEnd
        int i = 0;
        while(i < k && kth != NULL) {
            kth = kth->next;
            i++;
        }
        
        if(kth == NULL) break;

        Node* groupStart = prevGroupEnd->next;
        Node* prev = kth->next;
        Node* curr = groupStart;

        while(i = 0; i < k; i++) {
            Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        prevGroupEnd->next = prev;
        prevGroupEnd = groupStart;
    }
    return dummy->next;
}

int main() {

}