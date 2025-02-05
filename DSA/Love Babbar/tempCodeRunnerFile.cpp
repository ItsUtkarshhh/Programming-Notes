// Implementing!
#include <iostream>
using namespace std;

class NodeCSLL3 {
public:
    int data;
    NodeCSLL3* next;

    NodeCSLL3(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~NodeCSLL3() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertNodeCSLL3(NodeCSLL3*& tail, int element, int data) {
    NodeCSLL3* newNode = new NodeCSLL3(data);

    // Case 1: Empty List (tail == NULL)
    if (tail == nullptr) {
        tail = newNode;
        newNode->next = newNode; // Points to itself (circular)
        return;
    }

    NodeCSLL3* current = tail->next; // Start from the head (tail's next)
    do {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            
            // If inserted after tail, update the tail pointer
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != tail->next); // Loop until you complete the circle

    cout << "Element " << element << " not found in the list!" << endl;
    delete newNode; // Prevent memory leak
}

// Delete a node with a given element
void deleteNodeCSLL3(NodeCSLL3*& tail, int element) {
    if (tail == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCSLL3* prev = tail;
    NodeCSLL3* curr = tail->next;

    // Case 1: Single node in the list
    if (curr == tail && curr->data == element) {
        delete tail;
        tail = nullptr;
        return;
    }

    // Case 2: Multiple nodes
    do {
        if (curr->data == element) {
            prev->next = curr->next;
            if (curr == tail) {
                tail = prev; // Update tail if the last node is deleted
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);
    cout << "Element " << element << " not found in the list!" << endl;
}

// Print the list
void printListCSLL3(NodeCSLL3* tail) {
    if (tail == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    NodeCSLL3* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

int main() {
    NodeCSLL3* tail = nullptr;

    // Test case: Insert into empty list
    insertNodeCSLL3(tail, -1, 3);  // Insert after -1, which is not in the list
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << tail->data << endl;
    cout << endl;

    // Test case: Delete the only node
    deleteNodeCSLL3(tail, 3);
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl; // Just to print NULL, if the list is empty!
    cout << endl;

    // Test case: Insert multiple nodes
    insertNodeCSLL3(tail, -1, 5);  // Insert into empty list (tail is null)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " <<(tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    insertNodeCSLL3(tail, 5, 7);  // Insert after 5
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    insertNodeCSLL3(tail, 7, 9);  // Insert after 7
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    insertNodeCSLL3(tail, 9, 3);  // Insert after 9 (tail)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    // Test case: Delete from the list
    deleteNodeCSLL3(tail, 7);  // Delete node with data 7
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    deleteNodeCSLL3(tail, 9);  // Delete node with data 9 (tail)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    deleteNodeCSLL3(tail, 3);  // Delete node with data 3 (only element)
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout << endl;

    deleteNodeCSLL3(tail, 5);
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;
    cout<<endl;

    // Edge case: Try to delete from an empty list
    deleteNodeCSLL3(tail, 5);  // List is empty
    cout << "Current Linked List: ";
    printListCSLL3(tail);
    cout << "Current Tail: " << (tail ? to_string(tail->data) : "null") << endl;

    return 0;
}