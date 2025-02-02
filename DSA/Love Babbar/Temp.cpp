// Doubly Linked List!
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node() {
        next = NULL;
        prev = NULL;
        cout << "Value of deleted node: " << data << endl;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head ,Node* &tail, int data) {
    Node* temp = new Node(data);
    if(tail == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
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

void insertAnywhere(Node* &head, Node* &tail, int data, int pos) {
    if(head == NULL) {
        Node* temp = new Node(data);
        head = tail = temp;
        return;
    }

    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    int len = getLen(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid Length!";
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(temp->next == NULL) {
        Node* newNode = new Node(data);
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }

    int len = getLen(head);
    if(pos < 1 || pos > len) {
        cout<<"Invalid Position!";
        return;
    }

    // Deleting from Head!
    if(pos == 1) {
        Node* temp = head;
        head = temp->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos) { // Traversing to a particular node!
        count++;
        temp = temp->next;
    }

    // Delete from tail!
    if(temp->next == NULL) {
        tail = temp->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void printNode(Node* &head) {
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

    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAtHead(head, 5);
    insertAtHead(head, 0);
    insertAtHead(head, -5);
    insertAtHead(head, -10);
    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 25);
    insertAtTail(head, tail, 30);
    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhere(head, tail, -15,1);
    insertAnywhere(head, tail, -20,1);
    insertAnywhere(head, tail, 101,5);
    insertAnywhere(head, tail, 35, getLen(head) + 1);
    insertAnywhere(head, tail, 40, getLen(head) + 1);
    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNode(head, tail, 5);
    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNode(head, tail, 1);
    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNode(head, tail, getLen(head));
    cout<<"Current LinkedList : ";
    printNode(head);
    cout<<"Current Head : "<<head->data<<" Current Tail : "<<tail->data<<endl;
}