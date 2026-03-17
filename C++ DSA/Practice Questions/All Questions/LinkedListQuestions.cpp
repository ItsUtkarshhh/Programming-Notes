// ------------------------------------------------------- Linked List Questions ------------------------------------------------------------------------>
// Problem 1 : Reverse a Linkedlist!
// Approach 1 (Array + Two Pointers) : Convert the linked list into an array. Use two pointers (left and right) and swap elements while moving them toward the center.
// Approach 2 (Iterative Pointer Reversal) : Use three pointers: prev, curr, and forward. curr points to the current node. forward stores curr->next so we don’t lose the rest of the list. Reverse the link by pointing curr->next to prev. Move all pointers forward until curr == NULL.
// Approach 3 (Recursive Reversal) : Recursive version of the pointer-reversal approach. Call recursion with prev and curr, and generate forward using curr->next. Traverse until curr == NULL, then while returning, reverse the links by pointing curr->next to prev.
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    vector<int> v;
    Node* temp = head;
    while(temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0; int j = v.size() - 1;
    while(i < j) {
        swap(v[i], v[j]);
        i++; j--;
    }

    temp = head;
    i = 0;
    while(temp != NULL) {
        temp->data = v[i];
        temp = temp->next;
        i++;
    }
    return head;
}

Node* reverseLL2(Node* head) {
    if(head == NULL || head->next == NULL) return head;

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

Node* revRecursive(Node* head, Node* prev, Node* curr) {
    if(curr == NULL) return ;

    Node* forward = curr->next;
    
}

Node* reverseLL3(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;

    Node* revHead = revRecursive(head, prev, curr);
    return revHead;
}

int main() {}