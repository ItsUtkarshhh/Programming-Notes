#include<iostream>
using namespace std;

// Node Creation!
class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout<<"Node deleted : "<<this->data<<endl;
    }
};

void printLL(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    Node* temp = head;
    cout<<"Current LL : X";
    while(temp != head->next) {
        cout<<" < "<<temp->data<<" > ";
        temp = temp->next;
    }
    cout<<"X"<<endl;
}

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
    return;
}

int getLen(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != head->next) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereByPos(Node* &head, int pos, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        head->next = NULL;
        return;
    }

    int len = getLen(head);
    if(pos <= 0 || pos > len + 1) {
        cout<<"Invalid Positions!";
        return;
    }

    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    if(pos == len + 1) {
        insertAtTail(head, tail, data);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return;
}

bool findVal(Node* head, int val) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertAnywhereByVal(Node* &head, Node* &tail, int val, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }

    if(!findVal(head, val)) {
        cout<<"Value does not exists!";
        return;
    }

    Node* temp = head;
    if(temp->data == val) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    while(temp->data != val) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        tail->next = newNode;
        newNode->prev = temp;
        tail = newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    return;
}

void deletingNodeByPos(Node* &head, Node* &tail, int pos) {
    if(head == NULL || tail == NULL) {
        cout<<"Empty list!";
        return;
    }

    int len = getLen(head);
    if(pos <= 0 || pos > len) {
        cout<<"Invalid position!";
        return;
    }

    if(pos == 1) {
        Node* temp = head;
        if(head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }

        temp->next = NULL;
        delete temp;
        return;
    }

    if (pos == len) {
        Node* temp = tail;

        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < pos) {
        temp = temp->next;
        count++;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
    return;
}

int main() {
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;
    
    Node* n2 = new Node(2);
    n1->next = n2;
    n2->prev = n1;
    tail = n2;

    Node* n0 = new Node(0);
    n0->next = n1;
    n1->prev = n0;
    head = n0;

    printLL(head);

    insertAtHead(head, -1);
    insertAtTail(head, tail, 3);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);
    
    cout<<endl;
    
    insertAnywhereByPos(head, tail, 3, 100);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);
    
    cout<<endl;
    
    insertAnywhereByVal(head, tail, 3, 10000);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);
    
    cout<<endl;
    
    insertAnywhereByVal(head, tail, 1, 10000);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);

    cout<<"----------------------Deleting a node---------------------------->>"<<endl;
    
    deletingNodeByPos(head, tail, 1);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);

    cout<<endl;
    
    deletingNodeByPos(head, tail, getLen(head));
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);

    cout<<endl;
    
    deletingNodeByPos(head, tail, 2);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    printLL(head);
    cout<<getLen(head);
}