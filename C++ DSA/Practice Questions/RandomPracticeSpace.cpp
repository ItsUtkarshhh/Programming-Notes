#include<iostream>
using namespace std;

class Node {
    
}


// Flattening a Linked List!
// Idea : What is the problem right now?
//      : There is list which has a down pointer attached with every node of it. and that is a sorted list
//      : Idea is to merge all these downward sorted lists into one single downward sorted list
// Step 1 : I think we can use three pointers, prev, curr & forward... where prev will point at first node, curr at the second and forward at the node next to curr (which will keep the track of remaining list while we do operations with the current two)
// Step 2 : You will start a sorting of prev and curr lists
// Step 3 : Create a dummyNode as a temp head & use two temp pointers which will sort the list and keep attaching it with the dummyNode and make sure you make every next pointer of these nodes = NULL
// Step 4 : Once it happens and the lists are merged in sorted order, you will simply attached the head of this sorted list's next to the forward.
// Step 5 : Then, simply point the prev at the new merged head & curr at the forward and forward at the curr's next.
// Step 6 : Repeat the same pattern until curr goes NULL.

Node* flattenList(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* prev = head;
    Node* curr = head->next;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        Node* tempPrev = prev;
        Node* tempCurr = curr;

        Node* dummyNode = new Node(-1);
        Node* dummyTail = dummyNode;

        while(tempPrev != NULL && tempCurr != NULL) {
            if(tempPrev->data <= tempCurr->data) {
                dummyTail->down = tempPrev;
                dummyTail = tempPrev;
                tempPrev = tempPrev->down;
            }
            else {
                dummyTail->down = tempCurr;
                dummyTail = tempCurr;
                tempCurr = tempCurr->down;
            }
            dummyTail->next = NULL;
        }

        if(tempPrev == NULL) {
            while(tempCurr != NULL) {
                dummyTail->down = tempCurr;
                dummyTail = dummyTail->down;                
                dummyTail->next = NULL;
                tempCurr = tempCurr->down;
            }
        }
        if(tempCurr == NULL) {
            while(tempPrev != NULL) {
                dummyTail->down = tempPrev;
                dummyTail = dummyTail->down;
                dummyTail->next = NULL;
                tempPrev = tempPrev->down;
            }
        }

        prev = dummyNode->down;
        curr = forward;
        delete dummyNode;
    }
    return prev;
}