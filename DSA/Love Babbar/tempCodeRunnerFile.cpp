#include<iostream>
using namespace std;

class NodeSLL9 {
    public:
    int data;
    NodeSLL9* next;

    NodeSLL9(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL9() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertAtTailSLL9(NodeSLL9* &head, NodeSLL9* &tail, int data) {
    NodeSLL9* newNode = new NodeSLL9(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

NodeSLL9* ReverseK(NodeSLL9* head, int K) {
    if(head == NULL) {
        return NULL;
    }
    NodeSLL9* prev = NULL;
    NodeSLL9* curr = head;
    NodeSLL9* next = NULL;
    int count = 0;
    while(curr != NULL && count < K) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next != NULL) {
        head->next = ReverseK(next, K);
    }
    return prev;
}

void printListSLL9(NodeSLL9* head) { 
    if(head == NULL) {
        cout << "Empty List!";
        return;
    }
    NodeSLL9* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    NodeSLL9* n1 = new NodeSLL9(10);
    NodeSLL9* head = n1;
    NodeSLL9* tail = n1;

    insertAtTailSLL9(head, tail, 20);
    insertAtTailSLL9(head, tail, 30);
    insertAtTailSLL9(head, tail, 40);
    insertAtTailSLL9(head, tail, 50);
    insertAtTailSLL9(head, tail, 60);
    
    cout << "Current Linked List: ";
    printListSLL9(head);

    cout<<"Enter you value of K : ";
    int k;
    cin>>k;
    NodeSLL9* reversedK = ReverseK(head, k);
    cout << "Current Linked List: ";
    printListSLL9(reversedK);

    return 0;
}