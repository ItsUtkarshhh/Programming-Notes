#include<iostream>
#include<unordered_map>
using namespace std;

class NodeSLL3 {
    public:
    int data;
    NodeSLL3* next;
    
    NodeSLL3(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int getLenSLL3(NodeSLL3* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return 0;
    }
    int len = 0;
    NodeSLL3* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL3(NodeSLL3* &head, NodeSLL3* &tail, int pos, int data) {
    NodeSLL3* newNode = new NodeSLL3(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    
    int len = getLenSLL3(head);
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
    
    NodeSLL3* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

// Approach 1: Brute Force - O(n^2)
NodeSLL3* removeDuplicatesSLL3A(NodeSLL3* head) {
    if(head == NULL) return NULL;

    NodeSLL3* curr = head;
    while(curr != NULL) {
        NodeSLL3* temp = curr;
        while(temp->next != NULL) {
            if(temp->next->data == curr->data) {
                NodeSLL3* duplicate = temp->next;
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
NodeSLL3* removeDuplicatesSLL3B(NodeSLL3* head) {
    if (!head) return nullptr;

    unordered_map<int, bool> visited;
    NodeSLL3* curr = head;
    NodeSLL3* prev = nullptr;

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

void printListSLL3(NodeSLL3* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    NodeSLL3* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeSLL3* n1 = new NodeSLL3(10);
    NodeSLL3* head = n1;
    NodeSLL3* tail = n1;

    insertAnywhereSLL3(head, tail, 1, -5);
    insertAnywhereSLL3(head, tail, 1, 5);
    insertAnywhereSLL3(head, tail, 1, 0);
    insertAnywhereSLL3(head, tail, 1, -5);
    cout<<"Current Linked List: ";
    printListSLL3(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 15);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 20);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 30);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 25);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 20);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 20);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 35);
    insertAnywhereSLL3(head, tail, getLenSLL3(head) + 1, 30);
    cout<<"Current Linked List: ";
    printListSLL3(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    cout<<endl;

    // Removing Duplicates - Approach 1
    head = removeDuplicatesSLL3A(head);
    cout<<"Final Linked List after Approach 1: ";
    printListSLL3(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    cout<<endl;

    // Removing Duplicates - Approach 3
    head = removeDuplicatesSLL3B(head);
    cout<<"Final Linked List after Approach 3: ";
    printListSLL3(head);
    cout<<"Current head: "<<head->data<<" Current tail: "<<tail->data<<endl;

    return 0;
}