#include<iostream>
#include<map>
#include<climits>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* revLL(Node* head) {
    if(head == NULL) return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* cloneRandom(Node* head) {
    if(head == NULL) return NULL;

    Node* originalHead = head;
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    while(originalHead != NULL) {
        Node* newNode = new Node(originalHead->data);
        if(cloneHead == NULL || cloneTail == NULL) cloneHead = cloneTail = newNode;
        else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        originalHead = originalHead->next;
    }
    originalHead = head;

    Node* original = head;
    Node* clone = cloneHead;

    while(original != NULL) {
        if(original->random != NULL) {
            Node* tempOrg = head;
            Node* tempClone = cloneHead;
            while(tempOrg != NULL) {
                if(original->random == tempOrg) {
                    clone->random = tempClone;
                    break;
                }
                tempOrg = tempOrg->next;
                tempClone = tempClone->next;
            }
        }
        original = original->next;
        clone = clone->next;
    }
    return cloneHead;
}

Node* cloneRandom(Node* head) {
    if(head == NULL) return NULL;

    Node* tempOrg = head;
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    unordered_map<Node*, Node*> oldToNew;

    while(tempOrg != NULL) {
        Node* newNode = new Node(tempOrg->data);
        if(cloneHead == NULL || cloneTail == NULL) {
            cloneHead = cloneTail = newNode;
        }
        else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        oldToNew[tempOrg] = cloneTail;
        tempOrg = tempOrg->next;
    }

    tempOrg = head;
    Node* tempClone = cloneHead;
    while(tempOrg != NULL) {
        tempClone->random = oldToNew[tempOrg->random]
        tempOrg = tempOrg->next;
        tempClone = tempClone->next;
    }

    return cloneHead;
}

Node* cloneRandom3(Node* head) {
    if(head == NULL) return NULL;

    Node* tempOrg = head;
    while(tempOrg != NULL) {
        Node* newNode = new Node(tempOrg->data);
        newNode->next = tempOrg->next;
        tempOrg->next = newNode;
        tempOrg = newNode->next;
    }

    tempOrg = head;
    while(tempOrg != NULL) {
        if(tempOrg->random != NULL) {
            tempOrg->next->random = tempOrg->random->next;
        }
        tempOrg = tempOrg->next->next;
    }

    tempOrg = head;
    Node* cloneHead = head->next;
    Node* tempClone = cloneHead;
    while(tempClone != NULL) {
        tempOrg->next = tempOrg->next->next;
        if(tempClone->next != NULL) tempClone->next = tempClone->next->next;
        tempOrg = tempOrg->next;
        tempClone = tempClone->next;
    }
    return cloneHead;
}

void printList(Node* head) {
    if(head == NULL) return;
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;
    insertNode(head, tail, 5);
    insertNode(head, tail, 8);
    insertNode(head, tail, 9);
    insertNode(head, tail, 10);

    Node* n2 = new Node(2);
    Node* head2 = n2;
    Node* tail2 = n2;

    insertNode(head2, tail2, 5);
    insertNode(head2, tail2, 6);

    Node* ans = addingLLs(head, head2);
    printList(ans);
}