#include <iostream>
using namespace std;

class GeneralNodeLL5 {
public:
    int data;
    GeneralNodeLL5* next;

    GeneralNodeLL5(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at Tail for Singly Linked List
void insertSinglyLL5(GeneralNodeLL5*& head, GeneralNodeLL5*& tail, int data) {
    GeneralNodeLL5* newNode = new GeneralNodeLL5(data);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Detect Loop using Floyd’s Algorithm
GeneralNodeLL5* floydLoopDetectionAlgo3(GeneralNodeLL5* head) {
    if (head == NULL) return NULL;

    GeneralNodeLL5* slow = head;
    GeneralNodeLL5* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return slow;
    }
    return NULL;
}

// Find the Starting Node of the Loop
GeneralNodeLL5* getStartingNode2(GeneralNodeLL5* head) {
    if (head == NULL) return NULL;

    GeneralNodeLL5* intersection = floydLoopDetectionAlgo3(head);
    if (intersection == NULL) return NULL;

    GeneralNodeLL5* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove Loop from the Linked List
void removeLoop(GeneralNodeLL5* head) {
    if (head == NULL) return;

    GeneralNodeLL5* loopStart = getStartingNode2(head);
    if (loopStart == NULL) return;

    GeneralNodeLL5* temp = loopStart;

    while (temp->next != loopStart) {
        temp = temp->next;
    }

    temp->next = NULL;
}

// Print the Linked List
void printLinkedList5(GeneralNodeLL5* head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    GeneralNodeLL5* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main Function
int main() {
    GeneralNodeLL5* headS = NULL;
    GeneralNodeLL5* tailS = NULL;

    insertSinglyLL5(headS, tailS, 10);
    insertSinglyLL5(headS, tailS, 20);
    insertSinglyLL5(headS, tailS, 30);
    insertSinglyLL5(headS, tailS, 40);
    insertSinglyLL5(headS, tailS, 50);

    tailS->next = headS->next->next; // Creating a loop at node 30
    cout<<"Tail next (Before Removal) : "<<tailS->next->data<<endl;

    // Detect Loop
    GeneralNodeLL5* loopNode = floydLoopDetectionAlgo3(headS);
    if (loopNode) {
        cout << "Loop detected at node with value : " << loopNode->data << endl;
        GeneralNodeLL5* loopStart = getStartingNode2(headS);
        cout << "The loop starts at node with value : " << loopStart->data << endl;

        // Remove the loop
        removeLoop(headS);
        cout << "Loop removed. Linked List after loop removal : ";
        printLinkedList5(headS);
        cout << "Tail next (After Removal) : " << (tailS->next == NULL ? "null" : to_string(tailS->next->data)) << endl;
    }
    else {
        cout << "No loop detected!" << endl;
    }
    return 0;
}