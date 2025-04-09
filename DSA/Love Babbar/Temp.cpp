// Implementation of Stack (Using Arrays)! [DONE]
// Implementation of Stack (Using Linked Lists)! [DONE]
// Implementation of 2 Stacks in an array! [DONE]
// Reverse a string using a Stack! [DONE]
// Delete middle element of the Stack! [DONE]
// Check whether a valid parenthesis or not! [DONE]
// Add an element at the bottom of the Stack! [DONE]
// Reverse a Stack! [DONE]
// Sort a Stack! [DONE]
// Remove redundant brackets! [DONE]
// Minimum Cost to Make a String Valid (Bracket Reversal Problem)!
// Find next smaller element!

// Minimum Cost to Make a String Valid (Bracket Reversal Problem)!
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextSmallerElement(vector<int> v1) {
    int size = v1.size();
    vector<int> ans(size, -1);
    stack<int> stk;
    stk.push(-1);
    for(int i = size-1; i>=0; i--) {
        int curr = v1[i];
        while(stk.top() >= curr) {
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(curr);
    }

    for(int i = 0; i < size; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int size;
    cout<<"Enter size of array : ";
    cin>>size;
    vector<int> v1(size);
    cout<<"Enter elements of the array : ";
    for(int i = 0; i<size; i++) {
        cin>>v1[i];
    }
    cout<<"Final answer : ";
    nextSmallerElement(v1);
}























#include<iostream>
using namespace std;

class NodeSLL {
    public :
    int data;
    NodeSLL* next;

    NodeSLL(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~NodeSLL() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

int getLenSLL(NodeSLL* head) {
    if(head == NULL) {
        return 0;
    }
    int len = 0;
    NodeSLL* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAnywhereSLL(NodeSLL* &head, NodeSLL* &tail, int pos, int data) {
    NodeSLL* newNode = new NodeSLL(data);
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

    int len = getLenSLL(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        return;
    }

    NodeSLL* temp = head;
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

NodeSLL* reverseSLL(NodeSLL* head) {
    NodeSLL* curr = head;
    NodeSLL* prev = NULL;
    NodeSLL* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// This func is created to insert the digit in the answer linkedlist!
void insertAtTailSLL(NodeSLL* &head, NodeSLL* &tail, int data) {
    NodeSLL* temp = new NodeSLL(data);
    if(head == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

NodeSLL* addingSLLs1(NodeSLL* LL1, NodeSLL* LL2) {
    int carry = 0;
    NodeSLL* ansHead = NULL;
    NodeSLL* ansTail = NULL;
    while(LL1 != NULL && LL2 != NULL) {
        int sum = carry + LL1->data + LL2->data;
        int digit = sum%10;
        insertAtTailSLL(ansHead, ansTail, digit); // Create node and add it in answer Likedlist!

        // Calculating carry...
        carry = sum/10;
        LL1 = LL1->next;
        LL2 = LL2->next;
    }

    // When first List is short...
    while(LL1 != NULL) {
        int sum = carry + LL1->data;
        int digit = sum%10;
        insertAtTailSLL(ansHead, ansTail, digit); // Create node and add it in answer Likedlist!

        // Calculating carry...
        carry = sum/10;
        LL1 = LL1->next;
    }

    // When second List is short...
    while(LL2 != NULL) {
        int sum = carry + LL2->data;
        int digit = sum%10;
        insertAtTailSLL(ansHead, ansTail, digit); // Create node and add it in answer Likedlist!

        // Calculating carry...
        int carry = sum/10;
        LL2 = LL2->next;
    }

    // When carry is still remaining after adding all the nodes...
    while(carry != 0) {
        int sum = carry;
        int digit = sum%10;
        insertAtTailSLL(ansHead, ansTail, digit); // Create node and add it in answer Likedlist!

        carry = sum/10;
    }

    return ansHead;
} // But this function have became too lengthy! so we will write another function addingLLs2. where we will combine all these while loops together!

// Optimized function to add two linked lists representing numbers
NodeSLL* addingSLLs2(NodeSLL* LL1, NodeSLL* LL2) {
    int carry = 0;
    NodeSLL* ansHead = NULL;
    NodeSLL* ansTail = NULL;

    // Loop runs while there are nodes in either list or there is a carry left
    while(LL1 != NULL || LL2 != NULL || carry != 0) {
        int val1 = 0;
        if(LL1 != NULL) {
            val1 = LL1->data;
        }

        int val2 = 0;
        if(LL2 != NULL) {
            val2 = LL2->data;
        }
        
        // Sum the values from both lists and carry
        int sum = carry + val1 + val2;
        int digit = sum % 10;  // Extract last digit to store in node
        insertAtTailSLL(ansHead, ansTail, digit); // Add node to result linked list

        // Calculate carry for the next position
        carry = sum / 10;

        // Move to next nodes if available
        if(LL1 != NULL) {
            LL1 = LL1->next;
        }
        if(LL2 != NULL) {
            LL2 = LL2->next;
        }
    }
    return ansHead;  // Return head of the sum linked list
}

// Function to add two linked lists representing numbers
NodeSLL* addTwoLLs(NodeSLL* LL1, NodeSLL* LL2) {
    // Step 1: Reverse both input linked lists
    LL1 = reverseSLL(LL1);
    LL2 = reverseSLL(LL2);

    // Step 2: Add the two reversed linked lists
    NodeSLL* ans = addingSLLs2(LL1, LL2); 

    // Step 3: Reverse the resultant linked list to get the final sum
    ans = reverseSLL(ans);
    return ans;
}

void printListSLL(NodeSLL* &head) {
    NodeSLL* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist LL1...
    NodeSLL* nodeLL1 = new NodeSLL(1);
    NodeSLL* headLL1 = nodeLL1;
    NodeSLL* tailLL1 = headLL1;
    
}