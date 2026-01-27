#include<iostream>
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
        cout<<"This node is deleted!"<<endl;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTail(Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(tail == NULL) {
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

void insertAtTail2(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    tail = newNode;
    return;
}

int getLen(Node* head) {
    Node* temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void printLL(Node* head) {
    Node* temp = head;
    cout<<"Current LL : ";
    while(temp != NULL) {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL "<<endl;
    return;
}

void insertAnywhereByPos(Node* &head, Node* &tail, int pos, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }

    int len = getLen(head);
    if(pos <= 0 || pos > len + 1) {
        cout<<"Enter valid position!";
        return;
    }

    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    if(pos == len + 1) {
        insertAtTail(tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos - 1) {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

bool findVal(Node* head, int value) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void insertAnywhereByVal(Node* &head, Node* &tail, int val, int data) {
    if(!findVal(head, val)) {
        cout<<"Value does not exist!";
        return;
    }

    Node* newNode = new Node(data);
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        if(curr->data == val) {
            newNode->next = curr;
            prev->next = newNode;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    return;
}

void deletingNodeByPos(Node* &head, Node* &tail, int pos) {
    if(head == NULL || tail == NULL) {
        cout<<"No Deletion Possible!";
        return;
    }

    int len = getLen(head);
    if(pos <= 0 || pos > len) {
        cout<<"Invalid Position!";
    }

    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    int count = 1;
    while(count < pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr->next == NULL) {
        tail = prev;
        prev->next = NULL;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
}

void deletingNodeByVal(Node* &head, Node* &tail, int val) {
    if(!findVal(head, val)) {
        cout<<"Value does not exist!";
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        if(curr->data == val) {
            prev->next = curr->next;
            curr->next = NULL;
        }
        prev = curr;
        curr = curr->next;
    }
    
}

int main() {
    Node* n1 = new Node(1); // Node Creation!
    Node* head = n1; // Head creation!
    Node* tail = n1; // Tail creation!

    Node* n2 = new Node(2);
    n1->next = n2;

    Node* n3 = new Node(3);
    n2->next = n3;
    tail = n3;

    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);
    
    cout<<endl;
    
    insertAtHead(head, 0);
    insertAtHead(head, -1);
    insertAtHead(head, -2);
    
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);
    
    cout<<endl;
    
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);
    
    cout<<endl;
    
    insertAtTail2(head, tail, 7);
    insertAtTail2(head, tail, 8);
    insertAtTail2(head, tail, 9);
    
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    cout<<"Inserting at position 3 : "<<endl;
    insertAnywhereByPos(head, tail, getLen(head) + 1, 100);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    cout<<"Inserting where value is 5 : "<<endl;
    insertAnywhereByVal(head, tail, 5, 100);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    cout<<"Deleting value 100 : "<<endl;
    deletingNodeByPos(head, tail, 8);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    cout<<"Deleting value 100 : "<<endl;
    deletingNodeByVal(head, tail, 100);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<"Length of LL : "<<getLen(head)<<endl;
    printLL(head);
}