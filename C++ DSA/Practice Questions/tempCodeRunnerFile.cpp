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

// Reverse Nodes in group of K!
Node* reverseKNodes(Node* head, int k) {
    if(head == NULL) {
        return NULL;
    }

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        Node* kth = prevGroupEnd;
        int count = 0;
        while(count < k && kth != NULL) {
            kth = kth->next;
            count++;
        }

        if(kth == NULL) break;

        Node* groupStart = prevGroupEnd->next;
        Node* nextGroupStart = kth->next;
        kth->next = NULL;

        Node* prev = NULL;
        Node* curr = groupStart;
        Node* forward = NULL;

        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        prevGroupEnd->next = prev;
        groupStart->next = nextGroupStart;
        prevGroupEnd = groupStart;
    }
    return dummyNode->next;
}

Node* reverseKNodes(Node* head, int k) {
    if(head == NULL) {
        return NULL;
    }

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        Node* kth = prevGroupEnd;
        int count = 0;
        while(count < k && kth != NULL) {
            kth = kth->next;
            count++;
        }

        if(kth == NULL) break;

        Node* groupStart = prevGroupEnd->next;
        Node* nextGroupStart = kth->next;
        // kth->next = NULL;

        Node* prev = nextGroupStart;
        Node* curr = groupStart;
        Node* forward = NULL;

        while(curr != nextGroupStart) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        prevGroupEnd->next = prev;
        // groupStart->next = nextGroupStart;
        prevGroupEnd = groupStart;
    }
    return dummyNode->next;
}

Node* reverseKNodes2(Node* head, int k) {
    if(head == NULL) return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    if(curr != NULL) {
        head->next = reverseKNodes2(curr, k);
    }
    return prev;
}

void printLL(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }

    Node* curr = head;
    while(curr != NULL) {
        cout<<curr->data<<" > ";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
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

    // printLL(head);
    // Node* newHead = reverseLL(head);
    // printLL(newHead);

    // reverseLL2(newHead);
    // printLL(head);

    printLL(head);
    Node* newHead = reverseKNodes2(head, 2);
    printLL(newHead);
}