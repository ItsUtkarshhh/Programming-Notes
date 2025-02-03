#include <iostream>
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
        cout << "Memory freed for node with value: " << data << endl;
    }
};

// Insert a node after the given element
void insertNode(Node*& tail, int element, int data) {
    Node* newNode = new Node(data);

    // Case 1: Empty List
    if (tail == NULL) {
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    // Case 2: Insert after a specific element
    Node* current = tail;
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail) {
                tail = newNode; // Update tail if inserting after the last node
            }
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode; // Prevent memory leak
}

// Print the list
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
    Node* tail = NULL;

    insertNode(tail, -1, 3);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;
    
    cout<<endl;

    insertNode(tail, 3, 5);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNode(tail, 5, 7);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNode(tail, 7, 9);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNode(tail, 3, 4);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNode(tail, 9, 10);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNode(tail, 7, 8);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertNode(tail, 10, 2);
    cout<<"Current Linked List : ";
    printList(tail);
    cout<<"Current Tail : "<<tail->data<<endl;

    return 0;
}