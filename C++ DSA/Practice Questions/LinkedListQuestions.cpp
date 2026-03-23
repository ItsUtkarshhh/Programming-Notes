// ------------------------------------------------------- Linked List Questions ------------------------------------------------------------------------>
// Problem 1 : Reverse a Linkedlist!
// Approach 1 (Array + Two Pointers) : Convert the linked list into an array. Use two pointers (left and right) and swap elements while moving them toward the center.
// Approach 2 (Iterative Pointer Reversal) : Use three pointers: prev, curr, and forward. curr points to the current node. forward stores curr->next so we don’t lose the rest of the list. Reverse the link by pointing curr->next to prev. Move all pointers forward until curr == NULL.
// Approach 3 (Recursive Reversal) : In this approach too, we follow a similar strategy as of previous iterative one.
//                                 : We know that will need a prev, curr always so that we can always point our curr to prev in order to reverse the links of linked list.
//                                 : But that's not it, we also need to keep the track of remaining linked list, that's the job of forward. So as now we know the roles of each pointer, we will simple initiate with the prev & curr first, initially prev will be NULL & curr will be at head.
//                                 : And now, we will create a separate recursive rev function, because the current main function, is to handle the edge cases related to the linked list, like empty list or single node cases, also as the parameter only has a head, why we will ask the user to input the curr and prev pointers as an argument, that is why we need separated functions so that we can use it for better abstraction of functionality and design.
//                                 : Now after this, in order to move forward in the list, we will create a forward pointer which will be curr->next and will pass it into the recursive helper function for easy traversal (why need to traverse?) Because in recursion we first reduce the problem at every step until it gets so small and reaches the base case and then the based case returns and while returning down in the call stack, we actually start solving the problem.
//                                 : That's why we solve it change the curr->next pointing to prev once recursive method returns and executes the later line of code.
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    vector<int> v;
    Node* temp = head;
    while(temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0; int j = v.size() - 1;
    while(i < j) {
        swap(v[i], v[j]);
        i++; j--;
    }

    temp = head;
    i = 0;
    while(temp != NULL) {
        temp->data = v[i];
        temp = temp->next;
        i++;
    }
    return head;
}

Node* reverseLL2(Node* head) {
    if(head == NULL || head->next == NULL) return head;

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

void revRecursive(Node* &head, Node* &tail, Node* prev, Node* curr) {
    if(curr == NULL) {
        tail = head;
        head = prev;
        return;
    }

    Node* forward = curr->next;
    revRecursive(head, tail, curr, forward);
    curr->next = prev;
}

Node* reverseLL3(Node* &head, Node* &tail) {
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;

    revRecursive(head, tail, prev, curr);
    return head;
}

void printNode(Node* head) {
    if(head == NULL) {
        cout<<"Empty List!";
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" > ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertNode(head, tail, 1);
    insertNode(head, tail, 2);
    insertNode(head, tail, 3);
    insertNode(head, tail, 4);
    insertNode(head, tail, 5);

    reverseLL3(head, tail);
    printNode(head);
}

// Problem 2 : Find Middle of the Linked List!
// Approach 1 : Compute the length of the list and identify the middle index (len / 2). Traverse the list up to the node just before the middle,
//            : then adjust pointers to remove the middle node. This can be done using either two pointers (prev & curr) or a single temp pointer.
// Approach 2 (Optimized) : Use the fast and slow pointer technique. Move fast by 2 steps and slow by 1 step. When fast reaches the end, slow will be at the middle.
//                        : Maintain a previous pointer to remove the middle node efficiently.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int findLen(Node* head) {
    if(head == NULL) return 0;
    if(head->next == NULL) return 1;

    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* findMid(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    int mid = findLen(head) / 2;
    int count = 1;

    Node* temp = head;
    while(count <= mid) {
        temp = temp->next;
        count++;
    }

    return temp;
}

Node* findMid2(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertNode(head, tail, 1);
    insertNode(head, tail, 2);
    insertNode(head, tail, 3);
    insertNode(head, tail, 4);
    insertNode(head, tail, 5);
    insertNode(head, tail, 6);

    cout<<findMid(head)->data<<endl;
    cout<<findMid2(head)->data<<endl;
}

// Problem 3 : Reverse the Linked List in a group of size K.
// Approach 1 (Iterative Approach) : Approach is simple, you want to traverse the full list in K groups, and you are going to reverse every group, you can see its demanding two nested loops!
//                                 : We use while(true) because the stopping condition depends on checking whether k nodes exist ahead, which can only be determined inside the loop after traversal. So instead of pre-checking, we use an internal break for cleaner and efficient logic.
//                                 : And then we create a dummyNode, because we are not sure about the new head! then few important pointers like prevGroupEnd to track the end of previus group which will be helpful while linking previous group to the new group.
//                                 : Now another is, groupStart which determines the current group start and kth pointer which is technically curr groupEnd, but will become prevGroupEnd when we move forward.
//                                 : Now in a similar manner, we simply keep traversing the list one by one! until we do find K nodes!
// Approach 2 (Recursive Approach) : 
Node* reverseLL(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        Node* kth = prevGroupEnd;
        int i = 0;
        while(i < k && kth != NULL) {
            kth = kth->next;
            i++;
        }

        if(kth == NULL) break;

        Node* groupStart = prevGroupEnd->next;
        Node* newGroupStart = kth->next;
        kth->next = NULL;

        Node* prev = NULL;
        Node* curr = groupStart;
        Node* forward = NULL;

        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        prevGroupEnd->next = prev;
        groupStart->next = newGroupStart;
        prevGroupEnd = groupStart;
    }
    return dummyNode->next;
}

Node* reverseLL2(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        Node* kth = prevGroupEnd;
        int i = 0;
        while(i < k && kth != NULL) {
            kth = kth->next;
            i++;
        }

        if(kth == NULL) break;

        Node* groupStart = prevGroupEnd->next;
        Node* newGroupStart = kth->next;

        Node* prev = newGroupStart;
        Node* curr = groupStart;
        Node* forward = NULL;

        while(curr != newGroupStart) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        prevGroupEnd->next = prev;
        groupStart->next = newGroupStart;
        prevGroupEnd = groupStart;
    }
    return dummyNode->next;
}

Node* reverseRecursion(Node* head, int k) {
    if(head == NULL) return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int count = 0;

    while(count < k && curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(curr != NULL) {
        head->next = reverseRecursion(curr, k);
    }
    return prev;
}