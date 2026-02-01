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
    Node* temp = head;
    cout<<"Current LL : ";
    do {
        cout<<temp->data<<" > ";
        temp = temp->next;
    }while(temp != head);
    cout<<"Repeat"<<endl;
}

int getLen(Node* head) {
    Node* temp = head;
    int len = 0;
    do {
        len++;
        temp = temp->next;
    }while(temp != head);
    return len;
}

void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    tail = newNode;
}

void insertNodeAtPos(Node* &head, Node* &tail, int pos, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        newNode->next = newNode;
        return;
    }

    int len = getLen(head);
    if(pos <= 0 || pos > len + 1) {
        cout<<"Invalid Position Value!";
        return;
    }

    if(pos == 1) {
        insertAtHead(head, data);
    }

    if(pos == len + 1) {
        insertAtTail(head, tail, data);
    }

    Node* temp = head;
    int count = 1;
    while(count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

// All values unique!
void insertNodeByVal_Before(Node* &head, Node* &tail, int val, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        newNode->next = newNode;
        return;
    }

    if(head->data == val) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    while(temp->next->data != val) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void insertNodeByVal_After(Node* &head, Node* &tail, int val, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        newNode->next = newNode;
        return;
    }

    if(tail->data == val) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* temp = head;
    while(temp->data != val) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

// If Duplicates Exists!
enum Occurence { FIRST, LAST, Nth, EVERY };
enum Position { BEFORE, AFTER };

int occurenceOfVal(Node* head, int val) {
    int count = 0;
    Node* temp = head;
    do {
        if(temp->data == val) count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

bool findVal(Node* head, int val) {
    Node* temp = head;
    do {
        if(temp->data == val) {
            return true;
        }
        temp = temp->next;
    }while(temp != head);
    return false;
}

void insertNodeByVal(Node* &head, Node* &tail, int val, int data, Occurence occ, Position pos) {
    if(head == NULL || tail == NULL) {
        Node* newNode = new Node(data);
        head = tail = newNode;
        newNode->next = newNode;
        return;
    }

    if(!findVal(head, val)) {
        cout<<"Value does not exist!";
        return;
    }

    if(pos == BEFORE && occ == FIRST) {
        Node* newNode = new Node(data);
        Node* curr = head;
        if(curr->data == val) {
            newNode->next = tail->next;
            tail->next = newNode;
            head = newNode;
            return;
        }
        while(curr->next != head && curr->next->data != val) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return;
    }
    else if(pos == AFTER && occ == FIRST) {
        Node* newNode = new Node(data);
        Node* curr = head;
        if(tail->data == val) {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
            return;
        }
        while(curr->next != head && curr->data != val) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return;
    }
    else if(pos == BEFORE && occ == EVERY) {
        
    }
    else if(pos == AFTER && occ == EVERY) {
        
    }
    else if(pos == BEFORE && occ == LAST) {
        int count = occurenceOfVal(val);
    }
    else if(pos == AFTER && occ == LAST) {
        int count = occurenceOfVal(val);
    }
    else if(pos == BEFORE && occ == Nth) {
        int count = occurenceOfVal(val);
    }
    else if(pos == AFTER && occ == Nth) {
        int count = occurenceOfVal(val);
    }
}

int main() {
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;
    n1->next = n1;
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);
    
    cout<<endl;
    
    // Manual Insertion into the List! - At "Tail"
    Node* n2 = new Node(2);
    n2->next = head;
    tail->next = n2;
    tail = n2;
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);
    
    cout<<endl;
    
    // Manual Insertion into the List! - At "Head"
    Node* n0 = new Node(0);
    n0->next = head;
    tail->next = n0;
    head = n0;
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);
    
    cout<<endl;
    
    // Manual Insertion into the List! - At "Between";
    Node* nRandom = new Node(100);
    Node* temp = head;
    while(temp->data != 1) {
        temp = temp->next;
    }
    nRandom->next = temp->next;
    temp->next = nRandom;
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    // Function based insertion at Head!
    insertAtHead(head, -1);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    // Function based insertion at Tail!
    insertAtTail(head, tail, 3);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    // Function based insertion at a Position!
    insertNodeAtPos(head, tail, 3, 200);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    // Function based insertion before a value!
    insertNodeByVal_Before(head, tail, -1, 1000);
    insertNodeByVal_Before(head, tail, 200, 2000);
    insertNodeByVal_Before(head, tail, 3, 3000);
    insertNodeByVal_Before(head, tail, 1000, 999);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);

    cout<<endl;

    // Function based insertion after a value!
    insertNodeByVal_After(head, tail, 999, 400);
    insertNodeByVal_After(head, tail, 200, 401);
    insertNodeByVal_After(head, tail, 3, 402);
    insertNodeByVal_After(head, tail, 1000, 403);
    cout<<"Current Head : "<<head->data<<endl;
    cout<<"Current Tail : "<<tail->data<<endl;
    cout<<getLen(head)<<endl;
    printLL(head);
}



#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printCLL(Node* head) {
    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }

    Node* temp = head;
    cout << "CLL: ";
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

// 🔥 Insert BEFORE EVERY occurrence of val
void insertBeforeEvery(Node* &head, int val, int data) {
    if (head == NULL) return;

    // 🔹 Find last node
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    // 🔹 Phase 1: Handle consecutive head matches
    while (head->data == val) {
        Node* newNode = new Node(data);
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }

    // 🔹 Phase 2: Handle remaining nodes
    Node* prev = head;
    Node* curr = head->next;

    while (curr != head) {
        if (curr->data == val) {
            Node* newNode = new Node(data);
            prev->next = newNode;
            newNode->next = curr;

            prev = newNode;
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {
    // Create circular list: 2 → 2 → 3 → 2 → 5 → back
    Node* head = new Node(2);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(5);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head;

    printCLL(head);

    insertBeforeEvery(head, 2, 99);

    printCLL(head);

    return 0;
}
