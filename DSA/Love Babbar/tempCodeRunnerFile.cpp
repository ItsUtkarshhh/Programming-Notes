#include<iostream>
using namespace std;

// Node creation!
class NodeSLL5 {
    public:
    int data;
    NodeSLL5* next;

    NodeSLL5(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL5() {
        cout<<"Node deleted with value : "<<this->data<<endl;
    }
};

void insertAtHeadSLL4(NodeSLL5* &head, int data) {
    // Empty List!
    NodeSLL5* newNode = new NodeSLL5(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtTailSLL3(NodeSLL5* &head, NodeSLL5* &tail, int data) {
    NodeSLL5* newNode = new NodeSLL5(data);
    // Empty List!
    if(tail == NULL) {
        head = tail = newNode;
        tail->next = NULL;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int getLenSLL2(NodeSLL5* &head) {
    int len = 0;
    NodeSLL5* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL2(NodeSLL5* &head, NodeSLL5* &tail, int pos, int data) {
    // Empty List!
    if(head == NULL) {
        NodeSLL5* newNode = new NodeSLL5(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Insertion at Head!
    if(pos == 1) {
        insertAtHeadSLL4(head, data);
        return;
    }

    int len = getLenSLL2(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        return;
    }

    NodeSLL5* temp = head;
    int count = 1;

    // Traversing between nodes where excluding first node and last node!
    while(count < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    // Insertion at Tail Node!
    NodeSLL5* newNode = new NodeSLL5(data);

    if(temp->next == NULL) {
        temp->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeSLL2(NodeSLL5* &head, NodeSLL5* &tail, int pos) {
    // Empty List!
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }

    // Validating Position!
    int len = getLenSLL2(head);
    if(pos < 1 || pos > len) {
        cout<<"Invalid Position!";
        return;
    }

    if(pos == 1) {
        NodeSLL5* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    NodeSLL5* prev = NULL;
    NodeSLL5* curr = head;
    int count = 1;

    while(count < pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;
    if(curr->next == NULL) {
        tail = prev;
        delete curr;
        return; 
    }
    curr->next = NULL;
    delete curr;
}

void printNodeSLL4(NodeSLL5* &head) {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    NodeSLL5* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    NodeSLL5* n1 = new NodeSLL5(10);
    NodeSLL5* head = n1;
    NodeSLL5* tail = n1;

    insertAtHeadSLL4(head, 5);
    insertAtHeadSLL4(head, 0);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;
    
    insertAtTailSLL3(head, tail, 15);
    insertAtTailSLL3(head, tail, 20);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    insertAnywhereSLL2(head, tail, 1, -5);
    insertAnywhereSLL2(head, tail, getLenSLL2(head)+1, 25);
    insertAnywhereSLL2(head, tail, 3, 1000);
    insertAnywhereSLL2(head, tail, getLenSLL2(head)+1, 40);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeSLL2(head, tail, 1);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
    
    cout<<endl;

    deleteNodeSLL2(head, tail, 3);
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;

    cout<<endl;

    deleteNodeSLL2(head, tail, getLenSLL2(head));
    cout<<"Current Linked List : ";
    printNodeSLL4(head);
    cout<<"Current Head : "<<head->data<<" "<<"Current Tail : "<<tail->data<<endl;
}