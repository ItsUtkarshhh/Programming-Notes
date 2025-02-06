#include<iostream>
using namespace std;

class NodeSLL8 {
    public:
    int data;
    NodeSLL8* next;

    NodeSLL8(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL8() {
        cout << "Value of deleted element: " << data << endl;
    }
};

void insertAtHeadSLL8(NodeSLL8* &head, int data) {
    NodeSLL8* newNode = new NodeSLL8(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTailSLL8(NodeSLL8* &head, NodeSLL8* &tail, int data) {
    NodeSLL8* newNode = new NodeSLL8(data);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

int getLenSLL8(NodeSLL8* head) {
    if(head == NULL) {
        cout << "Empty List!";
        return -1;
    }
    int len = 0;
    NodeSLL8* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL8(NodeSLL8* &head, NodeSLL8* &tail, int pos, int data) {
    NodeSLL8* newNode = new NodeSLL8(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    int len = getLenSLL8(head);
    if(pos < 1 || pos > len + 1) {
        cout << "Invalid position!";
        delete newNode;
        return;
    }

    if(pos == 1) {
        insertAtHeadSLL8(head, data);
        delete newNode;
        return;
    }

    NodeSLL8* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if(pos == len + 1) {
        insertAtTailSLL8(head, tail, data);
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

NodeSLL8* findMiddleNodeSLL8(NodeSLL8* head) {
    int len = getLenSLL8(head);
    int mid = len / 2;
    NodeSLL8* temp = head;
    int cnt = 0;
    while(cnt < mid) {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

void printListSLL8(NodeSLL8* head) { 
    if(head == NULL) {
        cout << "Empty List!";
        return;
    }
    NodeSLL8* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    NodeSLL8* n1 = new NodeSLL8(10);
    NodeSLL8* head = n1;
    NodeSLL8* tail = n1;

    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 20);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 30);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 40);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 50);
    insertAnywhereSLL8(head, tail, getLenSLL8(head) + 1, 60);
    
    cout << "Current Linked List : ";
    printListSLL8(head);
    
    NodeSLL8* middleNode = findMiddleNodeSLL8(head);
    cout << "Middle Node: " << middleNode->data << endl;

    cout<<endl;

    NodeSLL8* n2 = new NodeSLL8(10);
    NodeSLL8* head2 = n2;
    NodeSLL8* tail2 = n2;

    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 20);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 30);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 40);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 50);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 60);
    insertAnywhereSLL8(head2, tail2, getLenSLL8(head2) + 1, 70);
    
    cout << "Current Linked List : ";
    printListSLL8(head2);
    
    NodeSLL8* middleNode2 = findMiddleNodeSLL8(head2);
    cout << "Middle Node: " << middleNode2->data << endl;
    
    return 0;
}