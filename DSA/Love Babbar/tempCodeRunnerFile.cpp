#include <iostream>
#include <unordered_map>
using namespace std;

class NodeSLL2 {
public:
    int data;
    NodeSLL2* next;
    NodeSLL2* random;

    NodeSLL2(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~NodeSLL2() {
        cout << "Node deleted with value : " << data << endl;
    }
};

int getLenSLL2(NodeSLL2* head) {
    if(head == NULL) {
        return 0;
    }
    int len = 0;
    NodeSLL2* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtTailSLL2(NodeSLL2* &head, NodeSLL2* &tail, int data) {
    NodeSLL2* temp = new NodeSLL2(data);
    if(head == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAnywhereSLL2(NodeSLL2* &head, NodeSLL2* &tail, int pos, int data) {
    NodeSLL2* newNode = new NodeSLL2(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Insertion at Head!
    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    int len = getLenSLL2(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        return;
    }

    NodeSLL2* temp = head;
    int count = 1;

    // Traversing between nodes where excluding first node and last node!
    while(count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        temp->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

NodeSLL2* cloneList(NodeSLL2* head) {
    if (!head) return NULL;

    NodeSLL2* cloneHead = NULL;
    NodeSLL2* cloneTail = NULL;
    NodeSLL2* temp = head;

    unordered_map<NodeSLL2*, NodeSLL2*> oldToNewNode;
    while (temp != NULL) {
        insertAtTailSLL2(cloneHead, cloneTail, temp->data);
        oldToNewNode[temp] = cloneTail;
        temp = temp->next;
    }

    NodeSLL2* originalNode = head;
    NodeSLL2* cloneNode = cloneHead;
    while (originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

void printListSLL2(const NodeSLL2* head) {
    const NodeSLL2* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->random) {
            cout << " [Random points to " << temp->random->data << "]";
        }
        cout << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    NodeSLL2* headO = new NodeSLL2(1);
    NodeSLL2* tailO = headO;

    // Construct the linked list
    insertAnywhereSLL2(headO, tailO, 2, 2);
    insertAnywhereSLL2(headO, tailO, 3, 3);
    insertAnywhereSLL2(headO, tailO, 4, 4);
    insertAnywhereSLL2(headO, tailO, 5, 5);

    // Set up random pointers
    headO->random = headO->next->next; // Head's random points to third node
    headO->next->random = headO->next->next->next; // Second node's random points to fourth node
    headO->next->next->random = headO; // Third node's random points back to head

    // Print the original list
    cout << "Original list:" << endl;
    printListSLL2(headO);

    NodeSLL2* clonedList = cloneList(headO); // Clone the list

    cout << "Cloned list:" << endl; // Print the cloned list
    printListSLL2(clonedList);

    return 0;
}