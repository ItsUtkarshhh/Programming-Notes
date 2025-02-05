// Implementation! (Position based insertion!)
#include<iostream>
using namespace std;

class Node { // General Node Creation!
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int getLen(Node* tail) { // Calculating Length!
    if(tail == NULL) {
        cout<<"Empty List!";
        return 0;
    }
    Node* curr = tail->next;
    int len = 0;
    do {
        len++;
        curr = curr->next;
    } while (curr != tail->next);
    return len;
}

void insertNode(Node* &tail, int pos, int data) {
    Node* newNode = new Node(data);

    if(tail == NULL) { // Empty List Condition!
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    int len = getLen(tail);
    if(pos < 1 || pos > len + 1) { // Validating Position!
        cout<<"Invalid Position!";
        delete newNode;
        return;
    }

    if (pos == 1) { // Insertion at Head!
        newNode->next = tail->next;
        tail->next = newNode;
        if (tail == tail->next) {
            tail = newNode;
        }
        return;
    }

    if(pos == len + 1) { // Insertion at Tail!
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Insert at some position in between!
    Node* temp = tail->next;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void printList(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

int main() {
    Node* n1 = new Node(10);
    Node* tail = n1;
    tail->next = tail; // Making it a circular LL!
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNode(tail, getLen(tail) + 1, 20);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNode(tail, getLen(tail) + 1, 30);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;
    
    insertNode(tail, getLen(tail) + 1, 40);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNode(tail, getLen(tail) + 1, 50);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data;

    cout<<endl;

    insertNode(tail, getLen(tail) + 1, 60);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data;
}