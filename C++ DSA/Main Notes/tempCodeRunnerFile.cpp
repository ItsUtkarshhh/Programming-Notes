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
        Node* start = head;
        Node* temp = head;
        do {
            if(temp->next->data == val) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
                if(newNode->next == head) head = newNode;
                temp = newNode->next;
            }
            else {
                temp = temp->next;
            }

        }while(temp != start);
    }
    else if(pos == AFTER && occ == EVERY) {
        // Node* start = head;
        Node* temp = head;
        do {
            if(temp->data == val) {
                Node* newNode = new Node(data);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == tail) tail = newNode;
                temp = newNode->next;
            }
            else {
                temp = temp->next;
            }
        }while(temp != head);
    }
    else if(pos == BEFORE && occ == LAST) {
        Node* curr = head;
        Node* prevLast = NULL;
        do {
            if(curr->next->data == val) prevLast = curr;
            curr = curr->next;
        }while(curr != head);

        if(prevLast == NULL) {
            cout<<"No Occurence!";
        }
        else {
            Node* newNode = new Node(data);
            newNode->next = prevLast->next;
            prevLast->next = newNode;
            if(newNode->next == head) head = newNode;
            return;
        }
    }
    else if(pos == AFTER && occ == LAST) {
        Node* curr = head;
        Node* nextLast = NULL;
        do {
            if(curr->data == val) nextLast = curr;
            curr = curr->next;
        }while(curr != head);

        if(nextLast == NULL) {
            cout<<"No Occurence!";
        }
        else {
            Node* newNode = new Node(data);
            newNode->next = nextLast->next;
            nextLast->next = newNode;
            if(nextLast == tail) tail = newNode;
            return;
        }
    }
}

void insertNodeByValNth(Node* &head, Node* &tail, int val, int data, Occurence occ, int nth, Position pos) {
    if (head == NULL) return;

    if(occ == Nth && pos == BEFORE) {
        Node* curr = head;
        int totalOcc = occurenceOfVal(head, val);
        if(nth > totalOcc) {
            cout<<"Invalid Position!"<<endl;
            return;
        }
        int count = 0;
        do {
            if(curr->next->data == val) {
                count++;
                if(count == nth) break;
            }
            curr = curr->next;
        }while(curr != head);
        if(count < nth) {
            cout<<"No Occurence"<<endl;
        }
        else {
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;
            if(newNode->next == head) head = newNode;
        }
    }
    else if(occ == Nth && pos == AFTER) {
        Node* curr = head;
        int totalOcc = occurenceOfVal(head, val);
        if(nth > totalOcc) {
            cout<<"Invalid Position!"<<endl;
            return;
        }
        int count = 0;
        do {
            if(curr->data == val) {
                count++;
            }
            if(count == nth) {
                break;
            }
            curr = curr->next;
        }while(curr != head);
        if(count < nth) {
            cout<<"No Occurence"<<endl;
        }
        else {
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;
            if(curr == tail) tail = newNode;
        }
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

    cout<<endl;

    // Testing Insert by Val variations!
    Node* n10 = new Node(2);
    Node* head2 = n10;
    Node* tail2 = n10;
    n10->next = n10;
    insertAtHead(head2, 2);
    insertAtHead(head2, 2);
    insertAtHead(head2, 2);
    insertAtHead(head2, 2);
    insertAtHead(head2, 2);
    cout<<"Current Head : "<<head2->data<<endl;
    cout<<"Current Tail : "<<tail2->data<<endl;
    cout<<getLen(head2)<<endl;
    printLL(head2);
    insertNodeByVal(head2, tail2, 2, 99, EVERY, BEFORE);
    cout<<"Current Head : "<<head2->data<<endl;
    cout<<"Current Tail : "<<tail2->data<<endl;
    cout<<getLen(head2)<<endl;
    printLL(head2);

    cout<<endl;

    // Testing Insert by Val variations!
    Node* n11 = new Node(2);
    Node* head3 = n11;
    Node* tail3 = n11;
    n11->next = n11;
    insertAtHead(head3, 2);
    insertAtHead(head3, 2);
    insertAtHead(head3, 2);
    insertAtHead(head3, 2);
    insertAtHead(head3, 2);
    cout<<"Current Head : "<<head3->data<<endl;
    cout<<"Current Tail : "<<tail3->data<<endl;
    cout<<getLen(head3)<<endl;
    printLL(head3);
    insertNodeByVal(head3, tail3, 2, 99, EVERY, AFTER);
    cout<<"Current Head : "<<head3->data<<endl;
    cout<<"Current Tail : "<<tail3->data<<endl;
    cout<<getLen(head3)<<endl;
    printLL(head3);

    cout<<endl;

    // Testing Insert by Val variations!
    Node* n12 = new Node(2);
    Node* head4 = n12;
    Node* tail4 = n12;
    n12->next = n12;
    insertAtHead(head4, 2);
    insertAtHead(head4, 2);
    insertAtHead(head4, 2);
    insertAtHead(head4, 2);
    insertAtHead(head4, 2);
    cout<<"Current Head : "<<head4->data<<endl;
    cout<<"Current Tail : "<<tail4->data<<endl;
    cout<<getLen(head4)<<endl;
    printLL(head4);
    insertNodeByValNth(head4, tail4, 2, 99, Nth, 3, BEFORE);
    cout<<"Current Head : "<<head4->data<<endl;
    cout<<"Current Tail : "<<tail4->data<<endl;
    cout<<getLen(head4)<<endl;
    printLL(head4);
}