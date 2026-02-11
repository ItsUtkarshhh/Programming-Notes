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

    ~Node() {
        cout<<"Node with data "<<this->data<<" is deleted!";
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

int getLen(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

Node* revLL(Node* head) {
    if(head == NULL) return head;

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

Node* getMid(Node* head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
    }
    return slow;
}

bool isPalindrome(Node* head) {
    if(head == NULL) return false;
    if(head->next == NULL) return true;

    int len = getLen(head);

    Node* mid = getMid(head);
    Node* temp3 = head;
    while(temp3->next = mid) {
        temp3 = temp3->next;
    }

    Node* midHead = revLL(mid);

    Node* temp1 = head;
    Node* temp2 = midHead;
    temp3->next = 
    while(temp1 != midHead && temp2 != NULL) {
        if(temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    Node* originalMid = revLL(midHead);

    return true;
}

void printLL(Node* head) {
    Node* temp = head;
    do {
        cout<<temp->data<<" > ";
        temp = temp->next;
    }while(temp != NULL);
    cout<<"NULL"<<endl;
}

int main() {
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    
    printLL(head);
    isPalindrome(head) ? cout<<"Yes its a palidrome!" : cout<<"No, its not!";
    printLL(head);
}