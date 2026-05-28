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

    while(prevGroupEnd != NULL && prevGroupEnd->next != NULL) {
        // We can also use while(true) here because the actual stopping condition is whether a complete group of k nodes exists,and that logic is determined inside the loop itself.
        // So the choice mainly depends on coding style and readability. Using while(true) often makes the algorithm cleaner and more, natural to express, but using an explicit loop condition is also completely fine if written correctly.
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

Node* reverseInSizeK(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    
    int count = 1;
    Node* kth = head;
    while(count < k && kth != NULL) {
        kth = kth->next;
        count++;
    }

    if(kth == NULL) return head;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    count = 1;

    while(count <= k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if(curr != NULL) {
        head->next = reverseInSizeK(curr, k);
    }
    return prev;
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
    // insertNode(head, tail, 7);

    int k;
    cout<<"Enter K : ";
    cin>>k;

    Node* ansHead = reverseInSizeK(head, k);
    printLL(ansHead);
}