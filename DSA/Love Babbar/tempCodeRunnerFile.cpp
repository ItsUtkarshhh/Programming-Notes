#include<iostream>
#include<unordered_map>
using namespace std;

class NodeSLL7 {
    public:
    int data;
    NodeSLL7* next;
    
    NodeSLL7(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int getLenN2(NodeSLL7* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return 0;
    }
    int len = 0;
    NodeSLL7* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereN2(NodeSLL7* &head, NodeSLL7* &tail, int pos, int data) {
    NodeSLL7* newNode = new NodeSLL7(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    
    int len = getLenN2(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid Length!";
        delete newNode;
        return;
    }
    
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    if(pos == len + 1) {
        tail->next = newNode;
        tail = newNode;
        return;
    }
    
    NodeSLL7* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Approach 1: Brute Force - O(n^2)
NodeSLL7* removeDuplicatesN2(NodeSLL7* head) {
    if(head == NULL) return NULL;

    NodeSLL7* curr = head;
    while(curr != NULL) {
        NodeSLL7* temp = curr;
        while(temp->next != NULL) {
            if(temp->next->data == curr->data) {
                NodeSLL7* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            }
            else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

// Approach 3: Hashing - O(n)
NodeSLL7* removeDuplicatesN3(NodeSLL7* head) {
    if (!head) return nullptr;

    unordered_map<int, bool> visited;
    NodeSLL7* curr = head;
    NodeSLL7* prev = nullptr;

    while (curr != nullptr) {
        if (visited[curr->data]) { // If duplicate is found
            prev->next = curr->next; 
            delete curr;
            curr = prev->next; // Move to the next node
        } else {
            visited[curr->data] = true; // Mark node as visited
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

void printListN2(NodeSLL7* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    NodeSLL7* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeSLL7* n1 = new NodeSLL7(10);
    NodeSLL7* head = n1;
    NodeSLL7* tail = n1;

    insertAnywhereN2(head, tail, 1, 5);
    insertAnywhereN2(head, tail, 1, 0);
    insertAnywhereN2(head, tail, 1, -5);
    insertAnywhereN2(head, tail, 1, -5);
    cout<<"Current Linked List: ";
    printListN2(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereN2(head, tail, getLenN2(head) + 1, 15);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 20);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 20);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 20);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 25);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 30);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 30);
    insertAnywhereN2(head, tail, getLenN2(head) + 1, 35);
    cout<<"Current Linked List: ";
    printListN2(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    cout<<endl;

    // Removing Duplicates - Approach 1
    head = removeDuplicatesN2(head);
    cout<<"Final Linked List after Approach 1: ";
    printListN2(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    cout<<endl;

    // Removing Duplicates - Approach 3
    head = removeDuplicatesN3(head);
    cout<<"Final Linked List after Approach 3: ";
    printListN2(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    return 0;
}