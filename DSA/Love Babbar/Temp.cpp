#include<iostream>
using namespace std;

// Node creation!
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout<<"Node deleted with value : "<<this->data<<endl;
    }
};

void insertAtHead(Node* &head, int data) {
    // Empty List!
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    // Empty List!
    if(tail == NULL) {
        head = tail = newNode;
        tail->next = NULL;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int getLen(Node* &head) {
    int len = 0;
    Node* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhere(Node* &head, Node* &tail, int pos, int data) {
    // Empty List!
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Insertion at Head!
    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    int len = getLen(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traversing between nodes where excluding first node and last node!
    while(count < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Insertion at Tail Node!
    Node* newNode = new Node(data);

    if(temp->next == NULL) {
        temp->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    // Empty List!
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }

    // Validating Position!
    int len = getLen(head);
    if(pos < 1 || pos > len) {
        cout<<"Invalid Position!";
        return;
    }

    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    int count = 1;

    while(count < pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;
    if(curr->next == NULL) {
        tail = prev;
        delete curr;
        return; 
    }
    curr->next = NULL;
    delete curr;
}

void printNode(Node* &head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    insertAtHead(head, 5);
    insertAtHead(head, 0);
    cout<<"Current Linked List : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;
    
    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 20);
    cout<<"Current Linked List : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhere(head, tail, 1, -5);
    insertAnywhere(head, tail, getLen(head)+1, 25);
    insertAnywhere(head, tail, 3, 1000);
    insertAnywhere(head, tail, getLen(head)+1, 40);
    cout<<"Current Linked List : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNode(head, tail, 1);
    cout<<"Current Linked List : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
    
    cout<<endl;

    deleteNode(head, tail, 3);
    cout<<"Current Linked List : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNode(head, tail, getLen(head));
    cout<<"Current Linked List : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
}