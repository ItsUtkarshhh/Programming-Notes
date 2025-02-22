#include<iostream>
#include<vector>
using namespace std;

class NodeSLL7 {
    public :
    int data;
    NodeSLL7* next;

    NodeSLL7(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL7() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

// Function to calculate the length of the linked list
int getLenSLL7(NodeSLL7* head) {
    int len = 0;
    NodeSLL7* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to insert a node at any given position in a linked list
void insertAnywhereSLL7(NodeSLL7* &head, NodeSLL7* &tail, int pos, int data) {
    NodeSLL7* newNode = new NodeSLL7(data);

    // If the list is empty, make the new node the head and tail
    if (head == NULL) {
        head = tail = newNode;
        return;
    }

    // Check for valid position
    int len = getLenSLL7(head);
    if (pos < 1 || pos > len + 1) {
        cout << "Invalid Position!" << endl;
        delete newNode;
        return;
    }

    // Insert at the head position
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Insert at the tail position
    if (pos == len + 1) {
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Insert at the middle position
    NodeSLL7* temp = head;
    int count = 1;
    while (count < pos - 1) {
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

NodeSLL7* getMidSLL7(NodeSLL7* head) {
    NodeSLL7* slow = head;
    NodeSLL7* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

NodeSLL7* reverseSLL7(NodeSLL7* head) {
    NodeSLL7* curr = head;
    NodeSLL7* prev = NULL;
    NodeSLL7* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindromeSLL7(NodeSLL7* head) {
    // If the list is empty...
    if(head == NULL || head->next == NULL) {
        return 1;
    }

    // Finding the middle node...
    NodeSLL7* mid = getMidSLL7(head);

    // Reverse the list after the middle node...
    NodeSLL7* temp = mid->next;
    mid->next = reverseSLL7(temp);

    // Now lets compare the two halves! for that we will create two pointers! head1 and head2! where head1 will be pointing at the first half of the LL and head2 will pointing at the other half of the LL!
    NodeSLL7* head1 = head;
    NodeSLL7* head2 = mid->next;
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    // Now bss ab vapis LL ko reverse krdo! taki we get our original LL back! hum chaahe toh bina iske bhi humara answer sahi ayega! we just have used this piece of code with a wider perspective! that ki kabhi agar hume future me LL original vaali chahiye! toh thats why we did this! taaki original LL intact rahe!
    temp = temp->next;
    reverseSLL7(temp);

    // Now return true agar ye sab hoke uss loop se successfully bahar aa chuke hai toh...
    return true;
}

// Function to print the linked list
void printListSLL7(NodeSLL7* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    NodeSLL7* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a Linkedlist...
    NodeSLL7* node = new NodeSLL7(1);
    NodeSLL7* head = node;
    NodeSLL7* tail = head;
    cout<<"First node of LL : ";
    printListSLL7(head);
    
    cout<<"Singly Linkedlist : ";
    insertAnywhereSLL7(head, tail, 2, 2);
    insertAnywhereSLL7(head, tail, 3, 3);
    insertAnywhereSLL7(head, tail, 4, 2);
    insertAnywhereSLL7(head, tail, 5, 1);
    printListSLL7(head);

    if(isPalindromeSLL7(head)) {
        cout<<"This Linked List is a Palindrome!";
    }
    else {
        cout<<"Its not a Palindrome!";
    }
}