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
    return;
}

Node* reverseInSizeK(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* dummyNode = new Node(-1);
    Node* prevGroupEnd = dummyNode;
    prevGroupEnd->next = head;

    while(true) {
        Node* currGroupStart = prevGroupEnd->next;
        Node* kth = currGroupStart;

        int count = 1;
        while(count < k && kth != NULL) {
            kth = kth->next;
            count++;
        }

        if(kth == NULL) break;
        
        Node* nextGroupStart = kth->next;
        kth->next = NULL;

        Node* prev = NULL;
        Node* curr = currGroupStart;
        Node* forward = NULL;

        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        currGroupStart->next = nextGroupStart;
        prevGroupEnd->next = prev;
        prevGroupEnd = currGroupStart;
    }

    return dummyNode->next;
}

void printLL(Node* head) {
    if(head == NULL) return;

    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" > ";
        temp = temp->next;
    }
    cout<<"NULL";
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
    insertNode(head, tail, 7);

    int k;
    cout<<"Enter K : ";
    cin>>k;

    Node* ansHead = reverseInSizeK(head, k);
    printLL(ansHead);
}