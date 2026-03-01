#include<iostream>
#include<map>
#include<climits>
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
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* getMid(Node* head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if(fast != NULL) fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node* revLL(Node* head) {
    if(head == NULL) return NULL;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool checkPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) return true;

    Node* mid = getMid(head);
    Node* midHead = mid->next;
    mid->next = revLL(midHead);

    Node* temp1 = head;
    Node* temp2 = mid->next;

    while(temp2 != NULL) {
        if(temp1->data != temp2->data) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    mid->next = revLL(mid->next);
    return true;
}

void printList(Node* head) {
    if(head == NULL) return;
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;
    insertNode(head, tail, 5);
    insertNode(head, tail, 8);
    insertNode(head, tail, 9);
    insertNode(head, tail, 10);

    Node* n2 = new Node(2);
    Node* head2 = n2;
    Node* tail2 = n2;

    insertNode(head2, tail2, 5);
    insertNode(head2, tail2, 6);

    Node* ans = mergeTwoLists(head, head2);
    printList(ans);
}