// ---------------------------------------------------------- LECTURE 51 - Add two numbers represented by a LinkedList! --------------------------------------------------------------------------------------------------------->
// Question 1 : We are given two numbers represented as linked lists, where each node contains a single digit. The digits are stored in forward order, meaning the most significant digit appears first. Our task is to add these two numbers and return the sum as a linked list in the same format.
//            : Example : Input : LL1 = 4 -> 5 -> NULL (represents 45), LL2 = 3 -> 4 -> 5 -> NULL (represents 345)
//                      : Output : Result = 3 -> 9 -> 0 -> NULL (represents 390)
// Approach : Problem with Direct Addition : Normally, we add numbers from the rightmost digit (least significant) first. But in linked lists, numbers are given from the leftmost digit (most significant) first. To correctly align corresponding digits for addition, we need to reverse both linked lists first.
//          : Reverse the Input Lists : LL1 = 4 -> 5 -> NULL → After reversing: 5 -> 4 -> NULL
//                                    : LL2 = 3 -> 4 -> 5 -> NULL → After reversing: 5 -> 4 -> 3 -> NULL
//          : Perform Addition Digit by Digit : Add corresponding nodes, keeping track of the carry. If the sum of two digits is >= 10, store the last digit and carry forward the remaining value.
// Implementation!
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
    
    insertAnywhereSLL(headLL1, tailLL1, 2, 3);
    insertAnywhereSLL(headLL1, tailLL1, 3, 4);
    insertAnywhereSLL(headLL1, tailLL1, 4, 1);
    cout<<"Linkedlist 1 : ";
    printListSLL(headLL1);

    // Creating another Linkedlist LL2...
    NodeSLL* nodeLL2 = new NodeSLL(1);
    NodeSLL* headLL2 = nodeLL2;
    NodeSLL* tailLL2 = headLL2;
    
    insertAnywhereSLL(headLL2, tailLL2, 2, 2);
    insertAnywhereSLL(headLL2, tailLL2, 3, 3);
    insertAnywhereSLL(headLL2, tailLL2, 4, 2);
    insertAnywhereSLL(headLL2, tailLL2, 5, 1);
    cout<<"Linkedlist 2 : ";
    printListSLL(headLL2);

    cout<<"Sum of LL1 & LL2 : ";
    NodeSLL* ans = addTwoLLs(headLL1, headLL2);
    printListSLL(ans);
} // Time Complexity (TC) : Since we process both linked lists completely, the time complexity depends on the longer list. Operations include reversing, traversing, and adding nodes, all taking O(MAX(M,N)) time.
// Space Complexity (SC) : The new linked list (sum of two lists) requires space proportional to the larger list. Extra space is used only for storing the result, making it O(MAX(M,N)) space.

// ---------------------------------------------------------- LECTURE 52 - Clone a Linkedlist with Random pointers! --------------------------------------------------------------------------------------------------------->
// Question : We have a special type of linked list, where each node contains : Data (value of the node), Next pointer (points to the next node in the list) and Random pointer (can point to any random node in the list, or it can be NULL).
//          : Our task is to create a clone (copy) of this linked list, meaning we need to make an exact duplicate of the given list, including both the next and random pointers.
// Approach 1 : Naive (Brute Force) - O(n^2) Time Complexity
//            : Step 1 : First, copy the linked list without random pointers.
//            : Step 3 : Then, for each node in the original list, find the corresponding random pointer in the copied list.
//            : Step 3 : Set the random pointer in the cloned list accordingly.
//            : Problem : Since finding the correct random pointer for each node requires another traversal, this results in O(n²) time complexity, which is slow for large lists.
// Implementation!
#include <iostream>
using namespace std;

// Definition for a Node.
class NodeSLL2A {
public:
    int data;
    NodeSLL2A* next;
    NodeSLL2A* random;
    
    NodeSLL2A(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

// Function to clone the linked list using brute force approach
NodeSLL2A* cloneLinkedListSLL2A(NodeSLL2A* head) {
    if (!head) return NULL;  // If the list is empty, return NULL.

    // Step 1: Copy the linked list without random pointers
    Node* originalHead = head;
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    while(originalHead) {
        NodeSLL2A* newNode = new NodeSLL2A(originalHead->data);
        if(cloneHead == NULL || cloneTail == NULL) {
            cloneHead = cloneTail = newNode;
        }
        else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        originalHead = originalHead->next;
    }
    originalHead = head; // Restoring originalHead pointer back to head

    // Step 2: Assign random pointers
    NodeSLL2A* original = head;
    NodeSLL2A* clone = cloneHead;

    while (original) {
        if (original->random) {
            // Step 3: Find the corresponding node in the cloned list
            NodeSLL2A* tempOrg = head;
            NodeSLL2A* tempClone = cloneHead;
            while (tempOrg) {
                if (tempOrg == original->random) {
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

// Function to print the linked list (for testing)
void printListSLL2A(NodeSLL2A* head) {
    NodeSLL2A* temp = head;
    while (temp) {
        cout << "Node: " << temp->data;
        if (temp->random) {
            cout << ", Random: " << temp->random->data;
        } else {
            cout << ", Random: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

// Driver code to test the function
int main() {
    NodeSLL2A* head = new NodeSLL2A(1);
    head->next = new NodeSLL2A(2);
    head->next->next = new NodeSLL2A(3);
    head->next->next->next = new NodeSLL2A(4);

    // Assign random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head; // 2 -> 1
    head->next->next->random = head->next->next->next; // 3 -> 4

    cout << "Original Linked List:\n";
    printListSLL2A(head);

    NodeSLL2A* clonedList = cloneLinkedListSLL2A(head);

    cout << "\nCloned Linked List:\n";
    printListSLL2A(clonedList);

    return 0;
}
// Time Complexity O(n^2) : We traverse the list twice.
// Space Complexity O(n) : For the hash map storing the cloned nodes.

// Approach 2 : Using a Hash Map - O(n) Time Complexity (Optimized Approach)
//            : Create a copy of the linked list, storing the mapping of original nodes to cloned nodes in a hash map. Key: Original Node, Value: Corresponding Cloned Node
//            : Assign next and random pointers using the map : cloneNode->next = map[originalNode->next], cloneNode->random = map[originalNode->random]
//            : Why is this better? We traverse the list only twice, making it O(n) time complexity. We use a hash map for storing references, leading to O(n) space complexity.
// Implementation!
#include <iostream>
#include <unordered_map>
using namespace std;

class NodeSLL2B {
public:
    int data;
    NodeSLL2B* next;
    NodeSLL2B* random;

    NodeSLL2B(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    ~NodeSLL2B() {
        cout << "Node deleted with value : " << data << endl;
    }
};

int getLenSLL2B(NodeSLL2B* head) {
    if(head == NULL) {
        return 0;
    }
    int len = 0;
    NodeSLL2B* temp = head;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtTailSLL2B(NodeSLL2B* &head, NodeSLL2B* &tail, int data) {
    NodeSLL2B* temp = new NodeSLL2B(data);
    if(head == NULL) {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAnywhereSLL2B(NodeSLL2B* &head, NodeSLL2B* &tail, int pos, int data) {
    NodeSLL2B* newNode = new NodeSLL2(data);
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

    int len = getLenSLL2B(head);
    if(pos < 1 || pos > len + 1) {
        cout<<"Invalid position!";
        return;
    }

    NodeSLL2B* temp = head;
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

NodeSLL2B* cloneLinkedListSLL2B(NodeSLL2B* head) {
    if (!head) return NULL;

    NodeSLL2B* cloneHead = NULL;
    NodeSLL2B* cloneTail = NULL;
    NodeSLL2B* temp = head;

    unordered_map<NodeSLL2B*, NodeSLL2B*> oldToNewNode;
    while (temp != NULL) {
        insertAtTailSLL2B(cloneHead, cloneTail, temp->data);
        oldToNewNode[temp] = cloneTail;
        temp = temp->next;
    }

    NodeSLL2B* originalNode = head;
    NodeSLL2B* cloneNode = cloneHead;
    while (originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

void printListSLL2B(const NodeSLL2* head) {
    const NodeSLL2B* temp = head;
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
    NodeSLL2B* headO = new NodeSLL2B(1);
    NodeSLL2B* tailO = headO;

    // Construct the linked list
    insertAnywhereSLL2B(headO, tailO, 2, 2);
    insertAnywhereSLL2B(headO, tailO, 3, 3);
    insertAnywhereSLL2B(headO, tailO, 4, 4);
    insertAnywhereSLL2B(headO, tailO, 5, 5);

    // Set up random pointers
    headO->random = headO->next->next; // Head's random points to third node
    headO->next->random = headO->next->next->next; // Second node's random points to fourth node
    headO->next->next->random = headO; // Third node's random points back to head

    // Print the original list
    cout << "Original list:" << endl;
    printListSLL2B(headO);

    NodeSLL2B* clonedList = cloneLinkedListSLL2B(headO); // Clone the list

    cout << "Cloned list:" << endl; // Print the cloned list
    printListSLL2B(clonedList);

    return 0;
}
// Time Complexity O(n) : Copy nodes and store in HashMap → O(n), Assign next and random pointers using HashMap → O(n) and Return the cloned list → O(1)
// Space Complexity O(n) : We store n nodes in the hashmap, which takes O(n) space and We don’t modify the original list structure 

// Approach 3 : Optimized Approach (O(n) Time & O(1) Space)
// In this approach, we don’t use extra space like a hashmap. Instead, we modify the linked list structure temporarily to efficiently copy it.
// Steps to Solve the Problem : Step 1 : Insert Cloned Nodes in Between
//                                     : For each original node, create a cloned node and insert it right next to the original node. This will interleave the original and cloned nodes.
//                                     : Original List : 1 → 2 → 3 → 4 → NULL, After inserting cloned nodes : 1 → 1' → 2 → 2' → 3 → 3' → 4 → 4' → NULL, (where ' represents cloned nodes).
//                            : Step 2 : Copy Random Pointers
//                                     : For each original node, update the random pointer of its cloned node.
//                                     : Since cloned nodes are placed right after their originals, we can copy the random pointers easily : clonedNode->random = originalNode->random->next;
//                                     : This works because originalNode->random already points to the correct node, and the cloned version of that node is right after it.
//                                     : Example Random Pointer Copying : Original Node 1 → Random → 3, Cloned Node  1' → Random → 3' and Similarly, we copy random pointers for all nodes.
//                            : Step 3 : Separate the Cloned List
//                                     : Now, we need to separate the cloned nodes from the original list. We restore the original list while extracting the cloned list.
//                                     : Example After Separation : Original List:  1 → 2 → 3 → 4 → NULL, Cloned List:   1' → 2' → 3' → 4' → NULL
//                                     : Now, the cloned list is independent and identical to the original.
// Implementation!
#include <iostream>
using namespace std;

class NodeSLL2C {
public:
    int data;
    NodeSLL2C* next;
    NodeSLL2C* random;

    NodeSLL2C(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

// Function to clone a linked list with random pointers
NodeSLL2C* cloneLinkedListSLL2C(NodeSLL2C* head) {
    if (!head) return NULL;

    // Step 1: Insert cloned nodes in between original nodes
    NodeSLL2C* temp = head;
    while (temp) {
        NodeSLL2C* cloneNode = new NodeSLL2C(temp->data);
        cloneNode->next = temp->next;
        temp->next = cloneNode;
        temp = cloneNode->next;
    }

    // Step 2: Copy random pointers
    temp = head;
    while (temp) {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    // Step 3: Separate the cloned list from the original
    NodeSLL2C* cloneHead = head->next;
    NodeSLL2C* original = head;
    NodeSLL2C* clone = cloneHead;
    
    while (original) {
        original->next = original->next->next;
        if (clone->next) clone->next = clone->next->next;
        original = original->next;
        clone = clone->next;
    }

    return cloneHead;
}

// Utility function to print the linked list
void printListSLL2C(NodeSLL2C* head) {
    NodeSLL2C* temp = head;
    while (temp) {
        cout << "Data: " << temp->data << ", Random: ";
        if (temp->random) 
            cout << temp->random->data;
        else 
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating a test case
    NodeSLL2C* head = new NodeSLL2C(1);
    head->next = new NodeSLL2C(2);
    head->next->next = new NodeSLL2C(3);
    head->next->next->next = new NodeSLL2C(4);

    // Setting up random pointers
    head->random = head->next->next;  // 1 → 3
    head->next->random = head;        // 2 → 1
    head->next->next->random = head->next->next->next; // 3 → 4
    head->next->next->next->random = NULL; // 4 → NULL

    cout << "Original List:\n";
    printListSLL2C(head);

    NodeSLL2C* clonedHead = cloneLinkedListSLL2C(head);

    cout << "\nCloned List:\n";
    printListSLL2C(clonedHead);

    return 0;
}
// Time Complexity O(n) : O(n) (Insert cloned nodes), O(n) (Copy random pointers) and O(n) (Separate lists)
// Space Complexity O(1) : We don’t use extra memory, only modify pointers.

// ---------------------------------------------------------- LECTURE 53 - Merge Sort in LinkedList --------------------------------------------------------------------------------------------------------->
// Question 1 : You are given a singly linked list, and you need to sort it using Merge Sort. You cannot change the data inside nodes; instead, you should only rearrange the links to achieve the sorted order.
// Approach (Merge Sort on Linked List) : Merge Sort follows Divide and Conquer, so we will break the list into smaller parts, sort them, and merge them back.
//                                      : Step 1 : Find the Middle of the Linked List, Using the slow and fast pointer technique to find the middle node. Slow pointer moves one step, and fast pointer moves two steps at a time.
//                                               : When the fast pointer reaches the end, the slow pointer will be at the middle. Why? This helps us split the linked list into two halves.
//                                      : Step 2: Recursively Sort Both Halves, Call mergeSort() recursively on both halves until we reach a single-node list.
//                                      : Step 3: Merge Two Sorted Lists, Use the Merge Two Sorted Lists technique to combine the two sorted halves. Compare the values and adjust the next pointers accordingly.
// Implementation!
#include <iostream>
using namespace std;

// Node class for Singly Linked List (SLL3)
class NodeSLL3A {
public:
    int data;
    NodeSLL3A* next;

    // Constructor to initialize the node
    NodeSLL3A(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor to free memory
    ~NodeSLL3A() {
        cout << "Memory is free for the node with data " << this->data << endl;
    }
};

// Function to get the length of the linked list
int getLenSLL3A(NodeSLL3A* head) {
    int len = 0;
    NodeSLL3A* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to insert a node at any position in the linked list
void insertAnywhereSLL3A(NodeSLL3A* &head, NodeSLL3A* &tail, int pos, int data) {
    NodeSLL3A* newNode = new NodeSLL3A(data);
    
    // If the list is empty
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Insert at the head position
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    int len = getLenSLL3A(head);
    
    // If position is invalid
    if (pos < 1 || pos > len + 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    NodeSLL3A* temp = head;
    int count = 1;
    
    // Traverse to the position before insertion point
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // If inserting at the last position, update tail
    if (temp->next == NULL) {
        temp->next = newNode;
        tail = newNode;
        return;
    }
    
    // Insert in the middle
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to find the middle node of the linked list
NodeSLL3A* findMidSLL3A(NodeSLL3A* head) {
    NodeSLL3A* slow = head;
    NodeSLL3A* fast = head->next;
    
    // Fast moves twice as slow, so when fast reaches the end, slow is at the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
NodeSLL3A* mergeSLL3A(NodeSLL3A* left, NodeSLL3A* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    // Dummy node to simplify merging
    NodeSLL3A* ans = new NodeSLL3A(-1);
    NodeSLL3A* temp = ans;

    // Merge both lists in sorted order
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next  = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // Attach the remaining elements
    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    // Return merged list, skipping dummy node
    return ans->next;
}

// Merge Sort function for linked list
NodeSLL3A* mergeSortSLL3A(NodeSLL3A* head) {
    // Base case: if list is empty or has only one node, it's already sorted
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the middle node
    NodeSLL3A* mid = findMidSLL3A(head);

    // Split the list into two halves
    NodeSLL3A* leftHalf = head;
    NodeSLL3A* rightHalf = mid->next;
    mid->next = NULL; // Break the link to split the list

    // Recursively sort both halves 
    leftHalf = mergeSortSLL3A(leftHalf);
    rightHalf = mergeSortSLL3A(rightHalf);

    // Merge the sorted halves
    return mergeSLL3A(leftHalf, rightHalf);
}

// Function to print the linked list
void printListSLL3A(NodeSLL3A* head) {
    NodeSLL3A* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list
    NodeSLL3A* node = new NodeSLL3A(1);
    NodeSLL3A* head = node;
    NodeSLL3A* tail = node;

    cout << "First node of SLL3: ";
    printListSLL3A(head);

    // Insert elements at various positions
    insertAnywhereSLL3A(head, tail, 2, 3);
    insertAnywhereSLL3A(head, tail, 3, 4);
    insertAnywhereSLL3A(head, tail, 4, 1);
    insertAnywhereSLL3A(head, tail, 5, 0);

    cout << "Original Linked List: ";
    printListSLL3A(head);

    // Apply Merge Sort
    head = mergeSortSLL3A(head);

    cout << "Sorted Linked List: ";
    printListSLL3A(head);

    return 0;
}
// Time Complexity O(nlogn) : Since we divide the list into halves → O(log n) and merge each node once → O(n).
// Space Complexity O(log n) : Due to recursive stack space.

// Question 2 : Flatten a Linked List!
//            : We are given a 2D linked list, where each node has two pointers : next (pointing to the right node in the same row) and down (pointing to a node in the downward direction, creating a vertical linked list).
//            : Our task is to flatten this 2D linked list into a single sorted linked list by merging the downward nodes into the right nodes.
// Approach : Merge-Based Recursion
//          : Understanding the Structure : Each node has a next → Points to the next linked list horizontally. and down → Points to the next node in a vertically sorted list.
//                                        : You are given multiple vertically sorted linked lists connected horizontally via next, and the goal is to merge them into a single sorted linked list.
//          : Merging Two Sorted Lists : This function merges two sorted lists in a manner similar to the merge step of Merge Sort : Uses a dummy node (dummyNode) for easy list construction. Iterates through both lists, attaching the smaller node to down and updating the pointer.
//                                     : Ensures next is always NULL for the merged result. Handles remaining elements from either list. Time Complexity is O(N) (where N is the total number of nodes in the two lists).
//          : Recursively Flattening the Linked List : Base Case: If the list is empty or only has one column, return head. Recursively flattens the rest of the list (head->next). Merges the current vertical list (head) with the flattened remaining list (mergeHead) using mergeSLL3B.
//                                                   : Time Complexity : Merging each pair takes O(N) Recursive calls reduce horizontal size by half.
// Implementation!
#include<iostream>
using namespace std;

class NodeSLL3B {
public:
    int data;
    NodeSLL3B* next;
    NodeSLL3B* down;

    NodeSLL3B(int data) {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

// Merging two sorted linked lists (like in Merge Sort)
NodeSLL3B* mergeSLL3B(NodeSLL3B* LL1, NodeSLL3B* LL2) {
    if (LL1 == NULL) return LL2;
    if (LL2 == NULL) return LL1;

    NodeSLL3B* dummyNode = new NodeSLL3B(-1);
    NodeSLL3B* result = dummyNode;
    while(LL1 != NULL && LL2 != NULL) {
        if(LL1->data < LL2->data) {
            result->down = LL1;
            result = LL1;
            LL1 = LL1->down;
        }
        else {
            result->down = LL2;
            result = LL2;
            LL2 = LL2->down;
        }
        result->next = NULL;
    }
    if(LL1 != NULL) result->down = LL1;
    else result->down = LL2;

    return dummyNode->down;
}

// Recursively flatten the linked list
NodeSLL3B* flattenSLL3B(NodeSLL3B* head) {
    if (head == NULL || head->next == NULL)
        return head;

    NodeSLL3B* mergeHead = flattenSLL3B(head->next);
    return mergeSLL3B(head, mergeHead);
}

// Utility function to print the flattened linked list
void printListSLL3B(NodeSLL3B* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->down;
    }
    cout << endl;
}

int main() {
    NodeSLL3B* head = new NodeSLL3B(1);
    head->down = new NodeSLL3B(5);
    head->down->down = new NodeSLL3B(9);

    head->next = new NodeSLL3B(2);
    head->next->down = new NodeSLL3B(6);
    head->next->down->down = new NodeSLL3B(10);

    head->next->next = new NodeSLL3B(3);
    head->next->next->down = new NodeSLL3B(7);
    head->next->next->down->down = new NodeSLL3B(11);

    head->next->next->next = new NodeSLL3B(4);
    head->next->next->next->down = new NodeSLL3B(8);
    head->next->next->next->down->down = new NodeSLL3B(12);

    cout << "Flattened Linked List: ";
    NodeSLL3B* result = flattenSLL3B(head);
    printListSLL3B(result);

    return 0;
}
// Time Complexity : O(N*logk) (where N is the total number of nodes and  k is the number of initial linked lists).
// Space Complexity : Recursive stack space: O(logk) No extra data structures used, Overall Complexity: O(logk) (Auxiliary).

// ---------------------------------------------------------- LECTURE 54 - Introduction to Stacks --------------------------------------------------------------------------------------------------------->
// Understanding Stack with a Simple Analogy
// Imagine a stack of plates in your kitchen. You always add a new plate on top, and when you need a plate, you remove the top one first. This follows the LIFO (Last In, First Out) principle, meaning the last item added is the first one to be removed.

// Stack Operations and Their Meaning!
// Push (Insertion) : Just like placing a new plate on top of the stack, when we add an element to the stack, it goes on top. Example : If we push 1, 2, 3, 4 into the stack, the order will be : Top → [4, 3, 2, 1] (4 is at the top).
// Pop (Removal) : Just like removing the topmost plate, when we remove an element from the stack, the top element is removed first. If we pop(), the stack changes like this, Before Pop : [4, 3, 2, 1] (Top is 4) -> After Pop : [3, 2, 1] (Now, 3 is on top).
// Peek (Top Element) : Suppose you just want to see the top plate without removing it. Similarly, peek() returns the top element of the stack without removing it. Example : Stack [4, 3, 2, 1] -> Peek() returns 4 (but does not remove it).
// Empty (Check if Stack is Empty) : This function checks if there are any plates left in the stack. If the stack is empty, it returns true; otherwise, it returns false.
// Implementation using STL!
#include<iostream>
#include<stack> // Include stack library
using namespace std;

int main() {
    stack<int> s1;

    // Pushing elements onto the stack (LIFO Order)
    s1.push(1);    
    s1.push(2);    
    s1.push(3);    
    s1.push(4);
    s1.push(5);
    // At this point, the stack looks like: Top -> 5  4  3  2  1 <- Bottom

    s1.pop(); // Removing the topmost element (5)
    cout << "Topmost element: " << s1.top() << endl; // Display the current top element (which is now 4)

    // Checking if the stack is empty
    if(s1.empty()) cout << "Stack is empty!" << endl;
    else cout << "Stack is not empty!" << endl;

    // Display the current size of the stack
    cout << "Size of stack: " << s1.size() << endl; // Expected output: 4
    return 0;
}

// Implementation of Stack!
// Understanding the Approach : A stack follows the LIFO (Last In, First Out) principle, which means the last element inserted will be the first one to be removed.
// There are two common ways to implement a stack : Using Arrays and Using Linked Lists.

// Implementation of Stack (Using Arrays)!
// Essentials : An Array (arr) (This will store the stack elements), A top variable (This will track the index of the topmost element) and A size variable (This will define the capacity of the stack)
// Functionalities of the Stack : Push Operation (Insert an element) : Before inserting, check if the stack is full (top >= size - 1). If it's not full, insert the element at arr[top] and then increment top. If it's full, print "Stack Overflow" (No more insertions possible).
//                              : Pop Operation (Remove an element) : Before removing, check if the stack is empty (top == -1). If it's not empty, decrease top to remove the element. If it's empty, print "Stack Underflow" (Nothing to remove).
//                              : Top Function (Get the Topmost Element) : If the stack is empty, return "Stack is empty". Otherwise, return arr[top], which is the topmost element.
//                              : Empty Function (Check if Stack is Empty) : If top == -1, it means there are no elements in the stack. Otherwise, the stack is not empty.
// Note : Stack Overflow occurs when we try to push elements beyond the fixed size of the array.
//      : Stack Underflow occurs when we try to pop elements from an empty stack.
//      : The time complexity of push(), pop(), top(), and empty() operations is O(1) because they require only constant time.
//      : Stacks are widely used in Recursion, Expression Evaluation (Postfix/Infix), Function Calls (Call Stack), and Undo/Redo operations in applications.
#include<iostream>
using namespace std;

class Stack1 {
    // Stack properties (data members)
    private:
    int top; // To keep track of the topmost index
    int* arr; // Dynamic array to store stack elements
    int size; // Maximum size of the stack
    
    public:
    // Constructor to initialize stack with given size
    Stack1(int size) {
        this->size = size;
        arr = new int[size];
        top = -1; // Stack is initially empty
    }

    // Push Function - Inserts an element into the stack
    void push(int element) {
        if(top < size - 1) { // Check if space is available
            top++; // Move top pointer
            arr[top] = element; // Insert element at top
        }
        else {
            cout<<"Stack Overflow"<<endl; // Stack is full
        }
    }
    
    // Pop Function - Removes the topmost element from the stack
    void pop() {
        if(top >= 0) { // Check if stack is not empty
            top--; // Remove top element by moving pointer
        }
        else {
            cout<<"Stack Underflow"<<endl; // Stack is already empty
        }
    }

    // Peek Function - Returns the topmost element without removing it
    int peek() {
        if(top >= 0) { // Check if stack is not empty
            return arr[top];
        }
        else {
            cout<<"Stack is empty!"<<endl;
            return -1; // Indicating stack is empty
        }
    }

    // Empty Function - Checks if the stack is empty
    bool empty() {
        return (top == -1); // Returns true if stack is empty
    }

    int size() {
        return top + 1;
    }

    bool isFull() {
        return top == size - 1;
    }

    ~Stack1() {
        delete [] arr;
    }
};

int main() {
    Stack1 s1(5); // Creating a stack with a maximum size of 5

    // Pushing elements into the stack
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    cout<<"The topmost element is: "<<s1.peek()<<endl; // Printing the topmost element
    
    // Checking if the stack is empty
    if(s1.empty()) cout<<"The stack is empty!"<<endl;
    else cout<<"Stack is not empty"<<endl;
    
    s1.pop(); // Popping an element
    cout<<"The topmost element is: "<<s1.peek()<<endl; // Now the top should be 4

    // Trying to push beyond the stack's limit
    s1.push(5);
    s1.push(6); // This will trigger "Stack Overflow" because max size is 5
    
    return 0;
}
// In C++, we need to free the memory to get the memory free from the object that we created, now here is two things : Object created in stack & Objects created in heap memory.
// Now, the thing is, if an object is being created in a stack, then in that case once the scope ends, C++ will automatically frees the memory by itself calling the destructor.
// But, if the object is being created using the new keyword, we need to manually free the memory! using the "delete" keyword. And then C++ will call the destructor to free the memory from that dynamically allocated object.

// Now, if there is no destructor to clean the memory during program getting executed, in case of stack based object, C++ will free all the memory which are created for the program inside the stack, but if during program execution, if there's any memory head based object creation or allocation, those will not be cleaned by C++ itself, we need to clean it, otherwise it will be memory leak.
// And these memory will not be cleaned until the program does not terminate.
// Example 1 : LinkedList list1; Stack based allocation of list, but the internal operation may include allocation like Node* newNode = new Node(data); here using the new keyword, the newNode memory gets allocated in the heap, so after program execution, C++ will clean the memory allocated to "list1" in the stack, but will not cleaned for memories like "newNode" in the heap.
// Example 2 : LinkedList* list2 = new LinkedList(); Now in this case the whole linked list is inside the heap memory, only the pointer is in the stack, so the same things applies here as well.
// In the example 1, the list1 object will be stored in the stack memory, but list2 object will be stored in the heap memory.

// Implementation of Stack (Using LinkedList)!
// A stack follows the LIFO (Last In, First Out) principle, where the last inserted element is the first one to be removed. We can implement this behavior efficiently using a singly linked list.
// Why Use a Linked List Instead of an Array : Dynamic Size – Unlike an array, we don't need to define a fixed size.
//                                           : Efficient Insertions & Deletions – No need to shift elements; operations occur in constant time O(1).
//                                           : Memory Efficient – Uses memory only when needed, unlike arrays that allocate fixed memory.
// How Does It Work : We define a Node structure containing : data (Stores the element) and next (Pointer to the next node).
//                  : The Stack class will have: top (Points to the top node of the stack like the head of a linked list).
// Operations : Push (Insert at the top) : Create a new node -> Point its next to the current top -> Update top to this new node.
//            : Pop (Remove from the top) : Check if the stack is empty -> Update top to top->next and delete the removed node.
//            : Peek (Get top element without removing) : Return top->data.
//            : Empty (Check if stack is empty) : Return true if top == NULL.
#include<iostream>
using namespace std;

// Node structure for Stack
class NodeforStack2 {
    public:
    int data;
    NodeforStack2* next;

    // Constructor
    NodeforStack2(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Stack class
class Stack2 {
    private:
    NodeforStack2* top; // Top pointer
    // int size; // If you do not maintain this instance variable for this implementation, then while finding out the size, it will take O(n) time complexity, whereas for arrays based implementation its already O(1) as it just need to return top + 1.
    // But due to the structural difference between arrays and LLs, we need to maintain this instance variable to achieve constant time complexity while finding size of the stack (implemented via LL). Simple size++ while push operations & size-- while pop operations.

    public:
    // Constructor - Initialize top to NULL
    Stack2() {
        top = NULL;
    }

    // Push Operation - Insert at the top
    void push(int element) {
        NodeforStack2* newNode = new NodeforStack2(element); // Create a new node
        newNode->next = top; // Link new node with the previous top
        top = newNode; // Update top to the new node
    }

    // Pop Operation - Remove the topmost element
    void pop() {
        if(top == NULL) { // Check for underflow
            cout<<"Stack Underflow"<<endl;
            return;
        }
        NodeforStack2* temp = top; // Store current top
        top = top->next; // Move top to next node
        temp->next = NULL;
        delete temp; // Delete the old top node
    }

    // Peek Operation - Get the top element
    int peek() {
        if(top == NULL) { // Check if stack is empty
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return top->data; // Return the top element
    }

    // Empty Function - Check if stack is empty
    bool empty() {
        return (top == NULL); // Returns true if top is NULL
    }
};

int main() {
    Stack2 s1; // Creating a stack

    // Pushing elements into stack
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    // Printing the topmost element
    cout<<"The topmost element is: "<<s1.peek()<<endl;

    // Checking if the stack is empty
    if(s1.empty()) {
        cout<<"The stack is empty!"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }

    // Popping an element
    s1.pop();
    cout<<"The topmost element after pop is: "<<s1.peek()<<endl; // Now top should be 4

    return 0;
}
// Note : In LinkedList Implementation of Stack, stack overflow condition does not occur in the same way as in an array-based implementation. However, it can still run out of memory in extreme cases.
// Why Stack Overflow Does Not Occur in a Linked List Implementation!
// Dynamic Memory Allocation : In a linked list, new nodes are allocated dynamically using new in C++ (or malloc() in C).
//                           : This means there is no fixed size limit as in an array-based stack.
// No Fixed Capacity : Unlike an array-based stack, which has a pre-defined size (int arr[100]), a linked list-based stack can keep growing as long as memory is available.
// Efficient Push Operation : Each new element is added as a new node, and there's no need to shift elements as in an array.

// When Can It Still Run Out of Memory!
// Even though a stack overflow (like in an array) does not happen, the system can still run out of heap memory in these cases.
// Too many push operations : If you keep pushing elements indefinitely, the system will run out of available heap memory.
// Memory fragmentation : If heap memory is fragmented due to inefficient allocations, a new operation might fail.
// Recursive stack overflow : If recursion is involved, the system might hit a stack segment overflow in deep recursive calls.

// Practice Question : Implement two stacks in an array!
// This problem requires us to implement two stacks using a single array, ensuring that both stacks follow the LIFO (Last In, First Out) principle while efficiently utilizing the available memory.
// Approach : Understanding the Challenge : Normally, a stack is implemented using an array, where: Push operation adds elements to the top. Pop operation removes elements from the top. Peek operation returns the top element. Empty check determines if the stack is empty.
//                                        : Here, we have two stacks but only one array to store their elements efficiently.
//          : How to Store Two Stacks in One Array : Instead of dividing the array into two fixed parts (which may waste space), we dynamically use the array from both ends.
//                                                 : Stack1 starts from index 0 (left to right) : Its top pointer, top1, starts at -1 (meaning stack1 is empty). Elements are inserted from the left side (top1++).
//                                                 : Stack2 starts from index size-1 (right to left) : Its top pointer, top2, starts at size (meaning stack2 is empty). Elements are inserted from the right side (top2--).
//                                                 : Stopping Condition : When top1 + 1 == top2, it means no space is left in the array, and we can’t insert further.
// Implementation!
#include<iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    // Constructor to initialize stack
    TwoStack(int s) {
        this->size = s;
        top1 = -1;  // Stack1 starts from left
        top2 = s;   // Stack2 starts from right
        arr = new int[s];
    }

    // Push element into Stack1
    void Push1(int element) {
        if (top2 - top1 > 1) { // Ensure there is space
            top1++;
            arr[top1] = element;
            cout << "Pushed " << element << " into Stack1 at index " << top1 << endl;
        } else {
            cout << "Stack1 Overflow!" << endl;
        }
    }

    // Push element into Stack2
    void Push2(int element) {
        if (top2 - top1 > 1) { // Ensure there is space
            top2--;
            arr[top2] = element;
            cout << "Pushed " << element << " into Stack2 at index " << top2 << endl;
        } else {
            cout << "Stack2 Overflow!" << endl;
        }
    }

    // Pop element from Stack1
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            cout << "Popped " << ans << " from Stack1 at index " << top1 << endl;
            top1--;
            return ans;
        } else {
            cout << "Stack1 Underflow!" << endl;
            return -1;
        }
    }

    // Pop element from Stack2
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            cout << "Popped " << ans << " from Stack2 at index " << top2 << endl;
            top2++;
            return ans;
        } else {
            cout << "Stack2 Underflow!" << endl;
            return -1;
        }
    }

    // Display the current state of the array
    void printArray() {
        cout << "Current Stack Representation: [";
        for (int i = 0; i < size; i++) {
            if (i == top1) cout << "(T1)";
            if (i == top2) cout << "(T2)";
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }
};
// Note : You could choose to divide the array into two halves and allocate each stack a fixed half.
//      : However, this is not an efficient approach because if one stack fills up while the other has unused space, that memory goes to waste. Instead, a dynamic approach that allows both stacks to grow towards each other optimally utilizes available space.

int main() {
    TwoStack s1(10); // Creating a common array of size 10 for both stacks

    s1.Push1(1);
    s1.Push1(2);
    s1.Push1(3);
    s1.Push1(4);
    s1.Push1(5);
    s1.Push1(6); // Stack1 filled up to index 5
    s1.printArray();

    s1.Push2(10);
    s1.Push2(20);
    s1.Push2(30);
    s1.Push2(40); // Stack2 filled up to index 6
    s1.printArray();

    s1.Push1(10); // Overflow condition
    s1.printArray();

    s1.pop1(); // Remove top of Stack1
    s1.pop2(); // Remove top of Stack2
    s1.printArray();

    return 0;
}

// ---------------------------------------------------------- LECTURE 55 - Questions on Stack! --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse a string using stack!
// Approach : A stack follows the LIFO (Last In, First Out) principle, which means the last element inserted into the stack is the first to be removed. This property makes a stack perfectly suited for reversing a string.
//          : Push all characters into the stack : Since a stack stores elements in the order they are inserted, we push each character of the string into the stack one by one.
//          : Pop characters from the stack : As we pop elements from the stack, they will come out in reverse order because the last inserted character is removed first.
//          : Reconstruct the reversed string : We store the popped characters in a new string and return it as the reversed version of the original string.
//          : This method ensures that the string is reversed efficiently using the fundamental properties of a stack.
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    string str1 = "Utkarsh";
    stack<char> st1;
    // Pushing into stack!
    for(int i = 0; i<str1.length(); i++) {
        char ch = str1[i];
        st1.push(ch);
    }
    
    string ans = "";
    // Popping from stack and storing into a string!
    while(!st1.empty()) {
        char ch = st1.top();
        ans.push_back(ch);
        st1.pop();
    }
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}
// Time Complexity O(N) : Where N is the length of the string (each character is pushed and popped once).
// Note : Previously, we reversed the string using the swap function, where the time complexity was O(n) and space complexity was O(1) because we didn't use any extra space just swapped characters in place.
//      : However, in the stack-based approach, we require an additional variable (reversed) to store the reversed string, leading to O(n) space complexity since we are using extra memory for the stack.
//      : Thus, the swap method is more efficient in terms of space, making it the preferred approach. However, using a stack provides an alternative way to solve the problem, leveraging the Last In, First Out (LIFO) property.

// Question 2 : Delete middle element of the stack!
// Approach : To delete the middle element from a stack, we follow a method similar to how we handle deletion in an array or linked list first identifying the middle element and then removing it.
//          : However, since a stack follows the LIFO (Last In, First Out) principle, we can't directly access the middle element. Instead, we need to remove elements from the top until we reach the middle element.
//          : Find the middle index : The middle position can be determined using mid = stack.size() / 2. If the stack has odd elements, the exact middle is removed. If the stack has even elements, we remove the lower middle element (0-based index).
//          : Recursively remove elements until we reach the middle : We pop elements from the stack one by one and store them temporarily (either in a separate variable or by using recursion).
//          : Remove the middle element : Once the middle index is reached, we pop it from the stack.
//          : Push back the stored elements in the same order : After deleting the middle element, we push the previously popped elements back into the stack, ensuring the order remains unchanged.
#include <iostream>
using namespace std;

// Custom Stack Implementation (Array-based)
class Stack3 {
    private:
    int top;   // Tracks the topmost index
    int* arr;  // Dynamic array for stack storage
    int size;  // Maximum size of the stack

    public:
    Stack3(int size) {  // Constructor to initialize stack
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push an element onto the stack
    void push(int element) {
        if (top < size - 1) {
            arr[++top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    // Get the top element of the stack
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    // Check if the stack is empty
    bool empty() {
        return top == -1;
    }

    // Returns the size of stack
    int stackSize() {
        return top + 1;
    }
};

// Recursive function to delete the middle element
void solve(Stack3& inputStack, int count, int size) {
    // Base case: If count reaches mid position, remove element
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    // Store the top element and remove it temporarily
    int num = inputStack.peek();
    inputStack.pop();

    // Recursive call to move deeper in the stack
    solve(inputStack, count + 1, size);

    // Push the element back after removing the middle one
    inputStack.push(num);
}

// Function to delete the middle element of the stack
void deleteMiddle(Stack3& inputStack, int n) {
    int count = 0;
    // int size = inputStack.stackSize(); // You can also use this stackSize() function instead of passing it as parameter
    solve(inputStack, count, n);
}

int main() {
    Stack3 st1(5); // Create a stack of size 5

    // Pushing elements into the stack
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    // Delete middle element
    deleteMiddle(st1, 5);

    // Printing remaining elements after deletion
    while (!st1.empty()) {
        cout << st1.peek() << " "; // Stack prints in reverse order (LIFO)
        st1.pop();
    }

    return 0;
}
// Time Complexity : O(N), since we remove and push back elements once.
// Space Complexity : O(N), due to recursive calls storing temporary elements.

// Question 3 : Valid Parentheses!
// Problem Statament : We are given a string containing only opening and closing brackets : () (Round Brackets), {} (Curly Braces) and [] (Square Brackets).
//                   : Our task is to check whether the given string has valid parentheses or not. A set of parentheses is considered valid if : Every opening bracket has a corresponding closing bracket and the brackets are closed in the correct order.
//                   : Examples of Valid Parentheses : "()" → Valid, as opening ( is closed by ). "{}[]" → Valid, as {} and [] are correctly closed. "{[()]}" → Valid, as {} contains [], which contains (), and all are closed in the correct order.
//                   : Examples of Invalid Parentheses : "({)" → Invalid, because { is not closed before ). "{[}" → Invalid, because { is opened but not properly closed. "(" → Invalid, because an opening bracket is not closed.
// Approach : Why Use a Stack : A stack is a perfect data structure for this problem because it follows LIFO (Last In, First Out), which helps track the most recent opening brackets that need closing.
//          : Explaination : Read the string character by character.
//                         : If an opening bracket ((, {, [), push it into the stack.
//                         : If a closing bracket (), }, ]), check the stack : If the stack is empty → Invalid (no matching opening bracket). If the top of the stack has the correct matching opening bracket → Pop it. If the top doesn’t match → Invalid.
//                         : After scanning the string, if the stack is empty, the parentheses are valid. Otherwise, invalid.
// Example : For input: "{[()]}"
//         : Push { → Stack: {
//         : Push [ → Stack: { [
//         : Push ( → Stack: { [ (
//         : Encounter ) → Matches with (, so pop → Stack: { [
//         : Encounter ] → Matches with [, so pop → Stack: {
//         : Encounter } → Matches with {, so pop → Stack: [] (empty)
//         : Stack is empty at the end, so the string is valid.
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValidParantheses(string exp) {
    stack<char> st1;
    for(int i = 0; i<exp.length(); i++) {
        char ch = exp[i];
        if(ch == '{' || ch == '(' || ch == '[') {
            st1.push(ch);
        }
        else {
            if(st1.empty()) {
                return false;
            }
            else {
                char top = st1.top();
                if( (ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                    st1.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    if(st1.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string s1 = "{([{}])}";
    if(isValidParantheses(s1)) {
        cout<<"It is a valid parantheses set!";
    }
    else {
        cout<<"Not a valid parantheses";
    }
}
// Time Complexity : O(N) (We traverse the string once)
// Space Complexity : O(N) (In worst case, all brackets go into the stack)

// Question 4 : Add an element at the bottom of the stack!
// Approach : We will follow a similar approach to deleting the middle node of a stack.
//          : The idea is to temporarily remove elements from the stack until it becomes empty, then push the new element at the bottom, and finally restore the removed elements back in order.
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &inputStack, int value) {
    // Base case
    if(inputStack.empty()) {
        inputStack.push(x);
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    // recurive call
    solve(inputStack, x);
    inputStack.push(num);
}

stack<int> pushAtBottom(stack<int> &inputStack, int value) {
    solve(inputStack, value);
    return inputStack;
}

void printStack(stack<int> st) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st1;
    // Printing remaining nodes...
    st1.push(5);
    st1.push(4);
    st1.push(3);
    st1.push(2);
    st1.push(1);
    cout << "Original stack: ";
    printStack(st1);

    pushAtBottom(st1, 6);

    cout << "After pushing 6 to bottom: ";
    printStack(st1);
}

// Question 5 : Reverse a stack!
// Approach : We will use recursion to reverse the stack step by step. The idea is to remove elements from the top one by one, reverse the remaining stack, and then insert the removed elements at the bottom.
//          : Remove the Top Element : Take out the top element of the stack and store it in a variable. This reduces the problem size, as we now have a smaller stack to work with.
//          : Recursively Reverse the Remaining Stack : Call the function recursively to reverse the rest of the stack. This continues until the stack becomes empty.
//          : Insert the Removed Element at the Bottom : Once the stack is completely reversed, insert the stored top element at the bottom of the stack. This is done using another helper function that pushes the element at the bottom instead of the top.
//          : Stack is Now Reversed! By following this process, we effectively reverse the order of elements in the stack.
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottomHelper(stack<int> &inputStack, int value) {
    // Base case
    if (inputStack.empty()) {
        inputStack.push(value);
        return;
    }
    int topElement = inputStack.top();
    inputStack.pop();

    // Recursive call
    insertAtBottomHelper(inputStack, value);
    inputStack.push(topElement);
}

stack<int> insertAtBottom(stack<int> &inputStack, int value) {
    insertAtBottomHelper(inputStack, value);
    return inputStack;
}

void printStack(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

void reverseStack(stack<int> &inputStack) {
    // Base case
    if (inputStack.empty()) {
        return;
    }
    int topElement = inputStack.top();
    inputStack.pop();

    // Recursive call
    reverseStack(inputStack);
    insertAtBottom(inputStack, topElement);
}

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    cout << "Original stack: ";
    printStack(stk);

    reverseStack(stk);

    cout << "Reversed stack: ";
    printStack(stk);
}

// Question 6 : Sort a stack! Constraint is not to use loop!
// Approach : We will use recursion to sort the stack. The idea is to remove elements one by one, sort the remaining stack recursively, and then insert each removed element back in the correct position.
//          : Remove and Sort the Stack Recursively : Take the top element from the stack and store it. Recursively sort the remaining stack until the stack becomes empty. This ensures that the smaller elements reach the bottom and larger elements stay at the top.
//          : Insert Each Element Back in Sorted Order : After sorting the remaining stack, insert the stored element back in its correct position. Use a helper function to insert an element into the correct place in the sorted stack.
//          : Base Condition : If the stack is empty, return (this is our base case for recursion).
#include<iostream>
#include<stack> // You can use Stack Implementation rather than using STL! Its your choice!
using namespace std;

void sortedInsert(stack<int> &inputStack, int num) {
    // Base case
    if(inputStack.empty() || (!inputStack.empty() && inputStack.top() < num)) {
        inputStack.push(num);
        return;
    }
    int n = inputStack.top();
    inputStack.pop();

    // recursive call
    sortedInsert(inputStack, num);
    inputStack.push(n);
}

void sortStack(stack<int> &inputStack) {
    // Base case
    if(inputStack.empty()) {
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    sortStack(inputStack);
    sortedInsert(inputStack, num);
}

void printStack3(stack<int> stk) {
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(5);
    stk.push(3);
    stk.push(2);
    stk.push(4);

    cout << "Original stack st1 : ";
    printStack3(stk);

    sortStack(stk);

    cout << "After sorting the stack st1 : ";
    printStack3(stk);
}

// Question 7 : Remove redudant brackets!
//            : A bracket is redundant if there is no useful operation inside it. Example of Redundant Brackets : ((a+b)) → The outer brackets are redundant because a+b is already grouped. and (a) → The brackets are redundant as they don’t serve any purpose.
//            : Example of Non-Redundant Brackets : (a+b*c) → The brackets are useful because they maintain the correct precedence. (a+(b/c)) → The inner brackets are necessary for division to happen first.
// Approach : Use a Stack to Process the String : Push each character of the expression onto the stack.
//  	    : Check for Redundant Brackets : When encountering a closing bracket ), check if there’s at least one operator (+, -, *, /) between this and its matching opening bracket (.
//                                         : If no operator is found, the brackets are redundant.
//          : How to Detect Redundant Brackets : If between an opening ( and closing ), there is no operator, the brackets are redundant. If at least one operator is found, the brackets are necessary.
//          : Example : (a+(b*c)) : Push (, a, +, (, b, *, c onto the stack.
//                    : When ) is encountered : Pop until ( is found. The popped elements contain b * c (which includes * operator), so these brackets are not redundant.
#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(const string& s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        // Push opening bracket & operators into stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } 
        else if (ch == ')') {  
            // Check for redundant brackets
            bool isRedundant = true;
            while (!st.empty() && st.top() != '(') { 
                char top = st.top();
                // If an operator is found, the brackets are NOT redundant
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
                st.pop();
            }
            // If stack is empty, it means there was an issue with bracket pairing
            if (!st.empty()) {
                st.pop();  // Pop the corresponding '('
            }
            if (isRedundant) {
                return true; // Redundant brackets found
            }
        }
    }
    return false;  // No redundant brackets found
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (findRedundantBrackets(expression)) {
        cout << "The expression has redundant brackets." << endl;
    } else {
        cout << "The expression does not have redundant brackets." << endl;
    }
    return 0;
}

// Question 8 : Minimum Cost to Make a String Valid (Bracket Reversal Problem)
//            : We are given a string consisting of only curly brackets { and }. The string is called valid if : Every opening bracket { has a corresponding closing bracket } after it.
//            : Examples of Valid Strings : "{}{}", "{ { } }" and "{ { }{ } }".
//            : Examples of Invalid Strings : "}{" (Closing bracket appears before opening), "{ } { }{ }" (Extra closing bracket at the end), "{ { }{ } }{" (Extra opening bracket { at the end).
//            : Goal : We need to convert the given invalid string into a valid one with the minimum cost.
//                   : Allowed operation: We can reverse any bracket { ↔ } at a cost of 1 unit per reversal and find the minimum cost needed to make the string valid.
// Approach : Step 1 : Check if a valid solution is possible : A valid string must have an even number of brackets. If the total number of brackets is odd, it is impossible to make it valid → Return -1.
//          : Step 2 : Use a Stack to Identify Misplaced Brackets : We process the string and use a stack to track unmatched brackets...
//                                                                : If we find an opening bracket {, we push it onto the stack.
//                                                                : If we find a closing bracket } : If the stack has an opening bracket {, we pop it (as it forms a valid pair).
//                                                                                                : Otherwise, we push the } onto the stack (it remains unmatched).
//                                                                : Overall, at the end, the stack will contain only unbalanced brackets (either { or }).
//          : Step 3 : Calculate the Minimum Cost : Suppose the stack has x { brackets and y } brackets left. We need to reverse pairs of these to balance them.
//                                                : Formula to calculate cost : (x + y + 1)/2.
//                                                : Every two unmatched { or } require one reversal. If there's an odd number of { or }, we need one extra reversal (cost = 2).
// Example Dry Run : Input : "}{{{}}"
//                 : Check length → Even
//                 : Stack processing : } → No { in stack → Push }. Stack : }
//                                    : { → Push {. Stack : } {
//                                    : { → Push {. Stack : } { {
//                                    : { → Push {. Stack : } { { {
//                                    : } → Matches with { → Pop {. Stack : } { {
//                                    : } → Matches with { → Pop {. Stack : } {
//                                    : Stack now contains: ["}", "{"].
//                 : Calculate Cost : One { and one } left → Requires one reversal each → Cost = 1 and Output: 1
#include <iostream>
#include <stack>
using namespace std;

int minCostToMakeValid(string s) {
    // Step 1 : If the length is odd, it's impossible to balance
    int n = s.length();
    if (n % 2 != 0) return -1;

    stack<char> st;
    // Step 2 : Process the string using a stack
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '{') {
            st.push(ch);
        }
        else { // ch == '}'
            if (!st.empty() && st.top() == '{') {
                st.pop(); // Valid pair found, remove it
            } else {
                st.push(ch); // Unmatched closing bracket
            }
        }
    }

    // Step 3 : Count unbalanced brackets
    int openBrackets = 0, closeBrackets = 0;
    while (!st.empty()) {
        if (st.top() == '{') {
            openBrackets++;
        } else {
            closeBrackets++;
        }
        st.pop();
    }

    // Step 4 : Calculate the minimum cost
    int cost = (openBrackets + closeBrackets + 1) / 2;
    return cost;
}

int main() {
    string s;
    cout << "Enter the string of curly brackets: ";
    cin >> s;
    
    int result = minCostToMakeValid(s);
    
    if (result == -1) cout << "Not possible to make valid" << endl;
    else cout << "Minimum cost to make the string valid: " << result << endl;
    return 0;
}
// Time Complexity : O(N) → We traverse the string once and process elements using a stack.
// Space Complexity : O(1) space → Using only a few integer variables and a stack.

// ---------------------------------------------------------- LECTURE 56 - Largest Rectangular Area in Histogram --------------------------------------------------------------------------------------------------------->
// Question 1 : Next smaller element!
//            : We are given an array and for each element in the array, we need to find the first smaller element to its right. If no such element exists, we return -1 for that position.
//            : Example : arr = [2, 1, 4, 3], Output : 2 (The first smaller element on its right is 1), 1 (No smaller element on its right, so -1), 4 (The first smaller element on its right is 3) and 3 (No smaller element on its right, so -1).
//            : Final Output : [1, -1, 3, -1]
// Approach 1 : Brute Force (Two Loops) : We fix each element one by one. For each element, check all elements on its right side. If we find a smaller element, store it. If no smaller element is found, store -1.
//                                      : Time Complexity : Since for each element we check all elements on its right, the time complexity is O(n^2) (bad for large n).
// Approach 2 : Stack-Based (Optimized) : Start from the last element (rightmost).
//                                      : Use a stack to store elements that could be possible answers.
//                                      : If the stack’s top is smaller than the current element, that is our answer.
//                                      : Otherwise, pop the stack until we find a smaller element or the stack becomes empty.
//                                      : If no smaller element is found, store -1.
//                                      : Push the current element into the stack for future checks.
//            : Example : Input : [2, 1, 4, 3]
//                      : Processing from right to left : Start with an empty stack, initialize ans = [].
//                                                      : Element 3 → No element to its right → Store -1 and push 3 into stack.
//                                                      : Element 4 → Stack top 3 is smaller → Store 3, push 4 into stack.
//                                                      : Element 1 → Stack top 4 is bigger → Pop 4, pop 3, stack is empty → Store -1, push 1 into stack.
//                                                      : Element 2 → Stack top 1 is smaller → Store 1, push 2 into stack.
//                      : Final Answer : [1, -1, 3, -1]
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n,-1);

    for(int i = n-1; i>=0; i--) {
        int curr = arr[i];
        while(s.top() >= curr) {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main() {
    vector<int> v1 = {2,1,4,3};
    int n = v1.size();
    vector<int> result = nextSmallerElement(v1, n);
    
    cout << "Next smaller elements for each element in the array are: ";
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// Question 2 : You are given a histogram where each bar represents a rectangle of the same width but with different heights. Your task is to find the largest rectangular area that can be formed using one or more consecutive bars.
//            : Let's say we have the following histogram with heights : heights[] = {2, 1, 5, 6, 2, 3}, visuallize it in form of bar graph! where each value of the array is a height of one bar!
//                                                                     : The largest rectangle that can be formed is the one covering heights 5 and 6, giving an area of 5 × 2 = 10.
// Brute Force (Naive Approach) : Steps : Consider each bar as a starting point.
//                                      : Try expanding left and right as far as possible while keeping the height of the smallest bar.
//                                      : Calculate the area of the rectangle formed using width × height.
//                                      : Keep track of the maximum area found.
//                              : Time Complexity : This approach takes O(N²) time because for every bar, we check its extension possibilities.
//                              : Example : For heights[] = {2, 1, 5, 6, 2, 3},
//                                        : Taking height = 5 at index 2 : Extend left until 1 at index 1.
//                                                                       : Extend right until 2 at index 4.
//                                                                       : Width = 4 - 1 - 1 = 2. Hence, area = 5 × 2 = 10.
//                                        : Although correct, this approach is inefficient for large histograms.
// Optimized Approach Using Stacks : We can only extend a bar until we find a smaller bar in either direction. So, for each bar, we need to find : Nearest Smaller Bar on the Left (Previous Smaller Element - PSE) and Nearest Smaller Bar on the Right (Next Smaller Element - NSE)
//                                 : Using these indices, we can determine the maximum width for which the current bar remains the minimum.
//                                 : Steps : Find Previous Smaller Element (PSE) for each bar : Use a monotonic increasing stack to store indices.
//                                                                                            : If a bar is smaller than the stack’s top, pop it.
//                                                                                            : The element left in the stack is the nearest smaller element’s index.
//                                         : Find Next Smaller Element (NSE) for each bar : Again, use a monotonic increasing stack but iterate right to left.
//                                                                                        : Find the nearest smaller element’s index on the right.
//                                         : Compute Width and Area : Width of the rectangle = NSE - PSE - 1
//                                                                  : Area = height[i] × width
//                                                                  : Keep track of the maximum area found.
//                                 : Time Complexity : The stack approach reduces the complexity to O(N) since each element is pushed and popped at most once.
// Implementation!
#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

vector<int> nextSmallerElement2(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement2(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans; 
}

int largestRectangularArea(vector<int> &heights) {
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement2(heights, n);
            
    vector<int> prev(n);
    prev = prevSmallerElement2(heights, n);
    
    int area = INT_MIN;
    for(int i=0; i<n; i++) {
        int l = heights[i];
        if(next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

int main() {
    vector<int> histogram = {2,4,5,6,1,2};
    cout<<"Largest rectangular area in the histogram : "<<largestRectangularArea(histogram);
} // TC : O(n) and SC : O(n)!
// revise all these questions and practice them again while revising along with the dry run and everything!

// ---------------------------------------------------------- LECTURE 57 - Celebrity Problem & more --------------------------------------------------------------------------------------------------------->
// Questions 1 : Celebrity Problem! Scenario : There is a party where there are 10 people and 1 is a celebrity! and the condition is that celebrity kisi ko nhi jaanta but sab celebrity ko jaante hai! and this scenario is mathematically represented in a matrix like...
// Suppose there are 3 people in party... and matrix of kon kisko jaanta hai ya nhi is represented below with...
//      1       2       3
// 1    0       1       0
// 2    0       0       0    
// 3    0       1       0
// So ab thing is, jo top-left to bottom-right vaala diagnol hai usko ignore krna hai! kyunki koi insaan apne aap ko toh jaanta hi hoga toh uske baare me baat krna illogical hai isliye unn sab jagah humare convention ke according 0 marked kiya hua hai!
// So, now lets see... 1 2 ko jaanta hai, 2 kisiko nhi jaanta, and 3 2 ko jaanta hai... so if we see, so here 2 is the celebrity! kyunki 2 kisiko nhi jaanta but 2 ko 1&3 jaante hai! now lets see the approach to solve this question!
// Approach 1 : From the brute force approach we can see that jo person celebrity hoga uski poori row 0 hogi and ek celebrity ka jo column hoga uska poora column 1 hoga except uska khud se khud ko jo relation hai vo 0 hoga baaki poora column 0 hoga! so what we will do is ki hum harr person ke liye uska harr column and harr row check krenge! means do loops chalengi! but yes this approach ki TC : O(n^2) which is high! so we will optimize it!
// Approach 2 : We will take a stack! and kya krenge ki pehle toh saare elements stack me daaldo! and then do do krke elements ko kisi variable me store krke pop krke check krte raho ki kya dono me se kya koi ek dusre ko jaanta hai! jo jaanta hai dusre ko vo celebrity toh nhi ho sakta kyunki celebrity toh kisiko nhi jaanta! so hum usko chhor ke dusre vaale ko vapis stack me daaldenge! and ye tab tak krte rahenge jab tak stack me koi ek element hi bss naa bachaa ho!
// So finally jo ek last element bachaa hoga stack me vo ek "potential" celebrity ho sakta hai! ab vo last element ko hum check krenge bss ki kya vo kisi aur ko jaanta hai && sab usko jaante hai na! if both of these conditions are true then the last element is the celebrity!
// Lets code...
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>> &m, int a, int b, int n) {
    if(m[a][b] == 1) {
        return true;
    }
    else {
        return false;
    }
}

int celebrity(vector<vector<int>> &m, int n) {
    stack<int> st;
    // Step 1 : Push all the elements in the stack
    for(int i = 0; i<n; i++) {
        st.push(i);
    }
    // Step 2 : Do do ke groups me banaa ke compare kr rhe hai!
    while(st.size() > 1) {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(m,a,b,n)) {
            st.push(b);
        }
        else {
            st.push(a);
        }
    }
    int potentialCandidate = st.top();
    // Step 3 : last one element is remaining in the stack, usko bhi finally verify krlo!
    // Row Check!
    bool rowCheck = false;
    int zeroCount = 0;
    for(int i = 0; i<n; i++) {
        if(m[potentialCandidate][i] == 0) {
            zeroCount++;
        }
    }
    if(zeroCount == n) {
        rowCheck = true;
    }

    // Column Check!
    bool ColumnCheck = false;
    int oneCount = 0;
    for(int i = 0; i<n; i++) {
        if(m[i][potentialCandidate] == 1) {
            oneCount++;
        }
    }
    if(oneCount == n-1) {
        ColumnCheck = true;
    }

    if(rowCheck == true && ColumnCheck == true) {
        return potentialCandidate;
    }
    else {
        return -1;
    }
}

int main() {
    vector<vector<int>> v1 = {{0,1,0},{0,0,0},{0,1,0}};
    int n = v1.size();
    cout<<"Celebrity element is : "<<celebrity(v1,n);
} // TC : O(n)
// There are more solutions to this problem while revising go through some of them!

// Question 2 : Find the maximum area of the formed by all the 1's in a binary matrix! it is similar to the largest area in histogram!
// Approach : So what we will do is ki hum matrix ki first row pakdenge pehle and then usko ek histogram ki tarah visualize krenge and then jaise pehle histogram ke case me bars ka maximum area nikala tha vaise hi iss case me nikalenge! and then jo maximum area ayega first row ka usko ek jagah save krlenge!
// Then we will move on to the next row! and upar aur neeche vaale elements ko add krke isko ek nayi histogram imagine krke firse max area niklenge! and pichli vaali ke jagah isko save krlenge! and so on jab tak saari rows cover nhi ho jaati! and then final answer print krdenge!
// Lets code this now...
#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

vector<int> nextSmallerElement3(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

vector<int> prevSmallerElement3(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }

int largestRectangularArea(int* heights, int n) {
    vector<int> next(n);
        next = nextSmallerElement3(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement3(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
    return area;
}

int maxArea(int M[][4], int n, int m) {
    // Compute area of first row...
    int area = largestRectangularArea(M[0],m);

    for(int i = 1; i<n; i++) {
        for(int j = 0; j<m; j++) {
            // Row update : rows update by previous rows value...
            if(M[i][j] != 0) {
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else {
                M[i][j] = 0;
            }
            // Entire row is updated now...
            area = max(area, largestRectangularArea(M[i],m));
        }
    }
    return area;
}

int main() {
    int arr[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    cout << "Maximum area is : " << maxArea(arr, 4, 4);
} // TC : O(n*m) n is number of rows and m is number of columns!

// ---------------------------------------------------------- LECTURE 58 - N Stacks in an array! --------------------------------------------------------------------------------------------------------->
// Question : N Stacks in an array! isme jaise humne 2 stacks ko implement kiye the array me! vaise hi hume iss baar N stacks krne hai implement! ek single array me!
// So kya kya krna hai ki, push(x,m) : iska mtlb ye hoga humare implementation me ki m stack me x element push krdo! and pop(m) iska mtlb hoga ki m stack me se pop krdo! and return -1 if the stack is empty! and returns the popped element!
// Approach 1 : Ab as we have done in two stack in one array! we have studied that there can be two approaches! like ek toh pehle hi array ko n equal parts me divide krlo and uske baad stack ke elements push krna shuru kro! isme ye dikkat thi ki isme memory ache se optimized way me use nhi ho rhi thi! so in this case we will move to another approach!
// Approach 2 : Lets understand this approach with an example, suppose you have an array of size 9 and you want to implement 3 stacks into it! so jaise humne pehle kiya tha two stacks ke case me that is usme 2 tops banaye the jo unn do stacks ke liye the! ab yahaa pr like N stacks hai toh hum ek do tops se kaam nhi chalega toh hum yahaa ek tops ka array banayenge! jisme hum unn sab stacks ke tops ko store krenge! like agar ek array me N stacks hai toh tops vaala jo array hoga vo N size ka hoga!
// And for this case, as yahaa pr hum ek array me 3 stacks implement krna chah rhe hai toh yahaa jo tops ka array hoga vo 3 size ka banega! and jo tops ka jo array hoga vo sab stacks ke top elements ka index darshaa rha hoga! toh chalo ek toh tops ka array hogya! but sirf isse kaam nhi chalega, toh overall top vaala array jo hai vo index bataa rha hai jiss index pr kisi stack ka top hai! so like if for example, maanlo hume ek 6 size ke array me 3 stacks implement krne hai toh hum ek top[] vaala array bhi 3 size ka banayenge kyunki isme sirf hume stack ke tops hi store krne hai! and jab tak kisi bhi stack me koi element nhi hoga tab tak hum top[3] ko -1 se initialize krdenge!
// Now, the thing is sirf isse kaam nhi chalega, we need a next[] array also! and iska kaam ye hoga ki... ye pehli baat toh vo freeslot batayega jo available hai after filling the current free slot! and dusra ye ye batayega ki jab kisi stack ka top element pop hojaye toh uske baad konsa element new top banega, ye next[] array ye bhi batayega!
// Lets understand this with an example... suppose we are asked to make an array of size = 6 and we have to implement 3 stacks in it! and we are asked to use 5 queries!
// So lets first create a main array of size = 6, arr[] = [   |   |   |   |   |   ]... now we have to implement 3 stacks S1 S2 S3 in the array! now we have 5 queries like : push(10,1), push(20,1), push(20,2), pop(1) and pop(2)...
// So now, so now lets first create a top array : top[] = [  |  |  ]
// And, we will create a next[] array! iska hum size main array vaala hi rakhenge kyunki isko harr element ka next available free slot store krna hai! so, next[] = [   |   |   |   |   |   ]
// And then, ab hum jab stacks ko initialize krenge tab hi top and next vaale arrays bhi initialize hojayenge! top vaala array toh -1 se hojayega initialize! kyunki at this moment main array me koi bhi value nhi hai mtlb koi bhi top kisi bhi stack ka store nhi hai! so Top[] = [ -1 | -1 | -1 ]... now Next[] = [ 1 | 2 | 3 | 4 | 5 | -1 ], iska mtlb ye ki jab main array me 0th index pr koi value ajaye! toh uske baad jo next free space hai available that is at index 1, toh bss hum vhi store kr rhe hai next array me! ki next konsa free space available hai main array me! jaise humne 0th index pr 1 store kiya mtlb ki we wanted to say that main array ke jab 0th index pr koi value ajaye toh uske baad jo next free space hoga that is at index 1 and similary baaki spaces ke liye! and 5th index ke baad koi free space nhi hai main array me toh humne 5th index pr next array me -1 store kiya hai!
// also hum ek freeSpot naam ka variable bhi banayenge jo ye batayega next array ki help se ki hume next kis free slot pr jaana hai!
// Chalo ab thora samajhte hai ki ye sab cheeze use kaise hongi...
// Suppose our query is push(10,1)... so first we will find the index where we can insert this value 10 for stack 1, and that space is stored in freespot variable, so int index = freespot; and ab current freespot toh allocate hogya value insert krne ke liye, toh ab next freespot ke liye we will use the next array! so for the next freespot, we will write freespot = next[index]; now its time to insert he value, so we will write arr[index] = x; toh abhi at this point the main array will be like, arr[] = [ 10 |   |   |   |   |   ] and now our next[] = [ 1 | 2 | 3 | 4 | 5 | -1 ], so means next array ke according next freeslot is available at index 1 of the main array! so now we have to update the next[], next[index] = top[m-1]; and now update the top, top[m-1] = index;
// Revise and understand and dry run this question again and more deeply while revising! and see different vdos!
// Lets code now....
#include<iostream>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;
    
    public:
    // Initialize your data structure.
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        //top initialise
        for(int i=0; i<n; i++) {
            top[i] = -1;
        }
        //next initialise
        for(int i=0; i<s; i++) {
            next[i] = i+1;
        }
        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freespot = 0;
    }
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        //check for overflow
        if(freespot == -1) {
            return false;
        }
        //find index
        int index = freespot;
        //insert element into array
        arr[index] = x;
        //update freespot
        freespot = next[index];
        //update next;
        next[index] = top[m-1];
        //update top
        top[m-1] = index;
        return true;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        int index= top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {
    // Create an NStack object with 3 stacks and capacity for 10 elements each
    NStack nStack(3, 10);

    // Push some elements into the stacks
    nStack.push(1, 1); // Push 1 into the first stack
    nStack.push(2, 1); // Push 2 into the first stack
    nStack.push(3, 2); // Push 3 into the second stack
    nStack.push(4, 2); // Push 4 into the second stack
    nStack.push(5, 3); // Push 5 into the third stack
    nStack.push(6, 3); // Push 6 into the third stack

    // Pop elements from the stacks
    cout << "Popped element from stack 1: " << nStack.pop(1) << endl; // Pop from first stack
    cout << "Popped element from stack 2: " << nStack.pop(2) << endl; // Pop from second stack
    cout << "Popped element from stack 3: " << nStack.pop(3) << endl; // Pop from third stack

    // Push some more elements
    nStack.push(7, 1); // Push 7 into the first stack
    nStack.push(8, 2); // Push 8 into the second stack
    nStack.push(9, 3); // Push 9 into the third stack

    // Pop elements from the stacks
    cout << "Popped element from stack 1: " << nStack.pop(1) << endl; // Pop from first stack
    cout << "Popped element from stack 2: " << nStack.pop(2) << endl; // Pop from second stack
    cout << "Popped element from stack 3: " << nStack.pop(3) << endl; // Pop from third stack

    // Trying to pop from empty stack
    cout << "Popped element from empty stack: " << nStack.pop(1) << endl; // Try to pop from first stack (empty)

    return 0;
} // TC : O(1) and SC : O(s+n)
// revist this question mustly while revising!


// ---------------------------------------------------------- LECTURE 59 - Design Special Stack Problem --------------------------------------------------------------------------------------------------------->
// Question : Design a stack which uses the getmin() function and finds the minimum element in O(1) TC and O(1) SC.
// So the situation should be like, suppose you have stack st1 with elements like : 4 2 8 3 5, where 5 us at the bottom and 4 is at the top! so agar hum abhi getmin() se minimum element nikale toh output will be 2. Okay now pop() now elements are 2 8 3 5, now use getmi() now the miniimum element is 2 again, now again pop() now elements are 8 3 5, now apply getmin() now the minimum element is 3, now again pop() now elements are 3 5 now the minimum element is 3 again, now pop again, noe element is 5 now minimum element is 5
// So as we can see jaise jaise pop krenge humara minimum change hojayega! so ye cheez dhyaan me rakhte hue stack ka getmin() function design krna hai! and ye O(1) TC me hona chahiye!
// Approach 1 : So now first we take an empty stack! now ek ek krke elements daalenge stack me and ek int mini = INT_MAX naam se variable bnaa ke isse compare krte rahenge elements ko! toh cgalo pehle humne 5 daala! and 5 ko compare kiya mini se ki konsa zyada chhota hai! so here 5 is smaller toh stack me gya 5, now humne 3 input me liya and now check kiya ki 3 ya 5 me se kon zyada chhota hai, toh ab stack me gya 3, 5 ke upar! now again ek aur input aaya 4 isko again humne compare kiya stack ke top se means 3 and 4 me comparison hua and 3 won so 3 again gya stack me! ab 5 ke upar 3 ke upar 3 hai stack me! ab again ek aur input aaya 2 and now again compare hua 2 and 3 me and iss baar andar gya 2 and similarly jab 4 input me aaya toh bhi 2 hi andar gya stack ke!
// So now the final stack is 2 2 3 3 5... toh iska ye mtlb ki jab hum getmin ko iss tareeke se banayenge ki harr comparsion ke liye ek nayaa stack bnaa le taaki har pop ke baad getmin() ye bataa de ki konsa minimum element hai toh uske liye getmin() simply ye vaala nayaa stack ko dekh kr answer dedega! toh isse humara ans toh ajayega also TC : O(1) but here humne extra space leliya hai and that O(n) where n is no. of elements in the stack! so this is not good!
// So overall is tarah ke stack ko design krne ke liye jo TC : O(1), me minimum element nikal de iske liye we will use functions like, push(), 1st stack me toh normal push krdega! and minimum value 2nd stack me push krdega! pop(), ye function dono stack se pop krdega! then, getmin() 2nd stack ka top return krdega!
// So this is not the approach which we want, bhale hi ye acha hai... but hume aur optimized approach chahiye!

// Lets dry run Approach 1 :
// Suppose you have elements to input in a stack are 5 3 8 2 4, now humne pehle ek int mini = INT_MAX bnaa liya, now humne pehle element 5 hai jisko push krna hai stack me toh usko humne ek curr naam dediya and isko push krdiya normally! and but ab humne mini ko update krna hoga, so we made a formula ki mini = min(mini, curr); toh ab mini and 5 ka minimum niklaa and vo 5 aagya toh at this point mini me 5 store hogya! and ab curr update hogya and now curr = 3, now 3 ko push kiya stack me! now again mini = min(mini, curr) which is min(3,5) and here the answer came out to be 3, means ab mini me 3 store hogya! now now again curr update hogya and mini again calculate hua and mini = 3 hogya again, curr again update hua now curr = 2 and mini again calculate hua and iss baar mini = 2 hogya kyunki 2<3, now curr update hua again and now curr = 4 and here mini again calculate hua and mini = 2 again as 2<4, so now, original stack me saari values input hogyi! and jo mini vaali saari values thi vo bhi ek alag stack me input hote jaa rhi thi!
// So the stacks are St1 = 4 2 8 3 5, St2 = 2 2 3 3 5, toh isse ye hua ki again poore stack St1 ko consider krke minimum value nikaloge toh St2 ka top hai vo! and jaise jaise pop krte jaoge St1 me se St2 me se bhi vaise vaise pop hote jayega and St1 ka minimum value ek particular level pr vo hoga jo St2 ka uss time pr top hoga! aise hi we have design this stack through approach 1.
// So codingly what we did is, push() me pehle toh normal push krdenge! then mini ko calculate krke update krdenge and usko 2nd stack me push krdenge! pop() me toh simply dono stack me se pop krdenge! also underflow check krenge hi but haa simply dono stack se pop krdenge! getmin() me jab bhi iski call aayegi tab 2nd stack ka top return krdenge!

// Approach 2 : Upar vaale me main dikkkat thi extra space ki, toh hume bss yahaa pr koi extra space use nhi krni! So what we will do is that ki pehle jo main stack hai vo bnaa li and jaise pehle ek int mini = INT_MAX tha, vo bhi bnaa diya!
// Ab jo push() operation hai vo aise hoga ki, 1) keep checking the stack overflow condition! 2) for 1st element normal push and then mini ko update krdo! 3) rest of the elements ke liye what we need to do is, ab dekho humare input me jo bhi elements aaye hume unko compare krke daalna hai stack me! taaki jo minimum vaale elements hai sirf vhi aaye stack me! so for the rest of the elements, if(curr<mini) write -> val = 2*curr - mini, where curr is that current element jisko stack me daalne ki baat ho rhi hai! and now push(val) inside the stack! and now again mini update krdo! and else me normal push krdena hai!
// Now for pop() operation, after pushing all the elements according to the above defintion! now we will pop(), and isme what we wil do is, 1) sabse pehle toh underflow vaali condition check krlena! 2) Agar jo curr value hai mtlb jo top hai vo agar mini se badaa hai toh normal pop krdo! otherwise in else condition we will write val = 2*mini - curr, and mini = val and then normal pop().
// Now lastly the getmini() function will just return the mini!

// Lets dry run Approach 2 :
// Suppose again you have those 5 elements to input in a stack 5 3 8 2 4, and yahaa hume SC : O(1) me solve krna hai means hum koi bhi stack list array vector map kuch bhi use nhi kr sakte! kyunki unn sab me O(n) SC lagega hi! means hume ye ek variable ki help se bss solve krna hai bss taaki SC O(1) rahe bss!
// Now lets start with creating a stack which is initially empty and we have 5 3 8 2 4 these elements to input in it! so pehle toh humne ek variable create krliya! int mini = INT_MAX; and now humara purpose ye hai ki hume ek aisa algorithm ya stack ki implementation krni hai jisse hum getmin() ek function ki help se minimum value nikal le harr level/portion of stack ki O(1) SC and O(1) TC me!
// So first lets talk about push() operation ki vo kaise implement kre taaki minimum value nikal paaye unn given conditions ke under! so what we can do is, pehle toh check the stack overflow condition!, then curr ko first input element pr rakho and first element ke liye normal push krdo and then mini ko update krdo normally jaise Approach me kiya tha mini = min(mini, INT_MAX) for first input, toh ab stack me gya 5.
// Now, baaki elements ke liye hum comparisons krenge like if(curr<mini) then ek calculation ke according which is val = 2*curr - mini; iske according stack me val ko push krdenge! and then mini ko min(mini, curr) formulae se update krdenge! and else part me normal push krdenge jo curr hai usko! lets see hua kya! abhi toh stack me 5 hai, so ab curr = 3 now, ab we have checked the condition if(curr<mini) and here 3<5 so this condition holds true, so now val = 2*curr - mini ke according val = 2*3 - 5 = 1, so stack me 1 push hogya! and now stack is like 1 5. and now mini update hoga so, mini = min(mini, curr) so min(3,5) me se 3 minimum hai toh mini = 3 hogya ab! so the current condition ke according stack me 1 5 stored hai and mini is updated from 5 to 3 now.
// Now, curr got updated and curr = 8 and now here if condition false hogyi toh yahaa vo sab cheeze nhi hongi and 8 normally push hojayega stack me! so now the stack is 8 1 5 and mini = 3
// Now, curr got updated to 2 and here if condition true hogyi so val = 2*curr - mini = 1 hogya so stack me 1 push hogya and mini = min(curr,mini) update hoke 2 hogyaso now the stack is 1 8 1 5 and mini = 2
// Now, curr got updated to 4 and here if condition false hogyi! and normally 4 stack me push hogya! so we can see that the final stack is 4 1 8 1 5 and mini = 2.
// And inn sabme getmin() ka sirf ye kaam hoga ki bss mini me jo bhi value hai usko return krdo! and isse ye hoga ki jab bhi koi bhi value push hoti hai stack me tab minimum simply getmin() se nikal jayega kyunki humari push() vaali operation simple ek mini naam se variable me har push ke baad minimum value store kr rhi hai toh jiss bhi instance pr hum getmin() call krdenge hume minimum value miljayegi! so this is the trick!
// Now lets implement the pop function taaki jab pop ho koi element tab pop function ki implementayion bhi iss mini value ka track rakhe apne mini vaale variable me!
// first thing first ki underflow condition check krlo! then if(curr>mini) then normal pop krdo! kyunki it means jo currently jo hum pop krna chah rhe hai vo already badaa hai uss instance pr jo minimum value hai! toh iske pop hone se koi fark nhi padega kyunki iska mtlb ye hoga ki vo mini value abhi bhi stack me hai hi! isliye humne normal pop kiya! now in otherwise case, which is else, where (curr<mini) then hume mini ko update krna padega! kyunki iska mtlb ye hoga ki jo mini value thi uss instance pr stack ke usko pop krne ke liye call aa chuki hai! toh ab mini ko update krna padega! and uske liye we will calculate val = 2*mini - curr; and then mini = val, here we have updated the mini! and then normally pop krdiya uss curr ko!
// lets do this, current stack is 4 1 8 1 5, so now on the first pop(), underflow toh nhi hai toh next is check if(curr>mini) agar yes toh normally pop krdo! toh curr = 4 and mini = 2 (ye variable harr function me apas me share hoga taaki record rahe mini ka, islie pop function ko ptaa hai ki mini kya hai iss instance pr), toh iss case me normally pop hojayega! so now the stack is 1 8 1 5 and mini = 2
// Now, curr got updated and curr = 1 and mini = 2 at this instance! and now again we have checked if(curr>mini) so false this time it is not true! now else will execeute as it means curr<mini, so yes 1<2 so else will execeute and it says pehle val nikalo from val = 2*mini - curr; and val = 3 and store this val in mini and now the mini got updated to 3 and the stack is now 8 1 5...so overall you got it how things are going!
// So bss yahaa bhi yhi hoga ki pop ki implementation me hi push ki tarah harr instance pr mini save ho rha hai taaki jab bhi getmin() function call kre mini ke liye seedha ye mini value usko return hojaye!

// So the thing is, basically hum kya kr rhe hai ki hume ek aisa stack chahiye jisme hum ek getmin() function bna paaye jo stack ka minimum value nikal paaye! agar initial stage me usme 5 elements hai toh unn 5 elements ki minimum value nikale, then agar humne pop kiya toh bachi hua 4 ka min value nikale and so on... and hume ye sab chahiye with TC : O(1) and SC : O(1) me!
// So to achieve this humne do approaches lagai! where in Approach 1 hum stack me elements input lete gye and ek alag se stack me jahaa pr sirf min values store ho rakhi thi usme daalte gye! like in the first case humne pehle input ko toh mini se compare kiya and then baakiyon ko stack ke top se! jo uss time pr top pr tha! and jo minimum ho rha tha usko 2nd stack me push krte gye! and tab hi vo 2nd stack bnaa! and this is how humne approach 1 ke through humne apna push() and pop() banaya taaki vo insertion ke time sirf insert na kre! balki 2nd stack me values compare krke smaller one push krta rahe! and then last me jab getmin() call hoga tab ye function bss uss 2nd stack ko dekhe ki usme kya kya stored hai! jab bhi push ya pop ho! baaki code me dekhenge toh aur clear hoga!
// Now, Approach 2 : Isme hume SC ko reduce krke O(1) pr laana tha toh isliye humne koi nayi stack nhi banai balki uss hi same stack me kuch calculations krke push and pop functions bnaa diye! taaki uss stack me values input hi aise ho ki jo mini vaala variable hai usme minimum value rahe stack ke harr portion ki after push and pop! and for that only we have used that val = 2*mini = curr ya val = 2*curr - mini...so abhi this is how this approach 2 worked! and in the end humne getmin() ke through mini ko return kraa diya!
// Now lets code....
#include<iostream>
#include<stack>
#include<climits>
// #include<limits.h> // Both of the above header files we can use!
using namespace std;

class specialStack {
    // Defining the data members...
    stack<int> st;
    int mini = INT_MAX;

    public:
    void push(int data) {
        if(st.empty()) {
            st.push(data);
            mini = data;
        }
        else {
            if(data<mini) {
                int val = 2*data - mini;
                st.push(val);
                mini = data;
            }
            else {
                st.push(data);
            }
        }
    }

    int pop() {
        if(st.empty()) {
            return -1;
        }
        int curr = st.top();
        st.pop();
        if(curr > mini) {
            return curr;
        }
        else {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(st.empty()) {
            return -1;
        }

        int curr = st.top();
        if(curr<mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    bool isEmpty() {
        return st.empty();
    }

    int getmin() {
        if(st.empty()) {
            return -1;
        }
        return mini;
    }
};

int main() {
    specialStack st;
    st.push(5);
    st.push(3);
    st.push(8);
    st.push(2);
    st.push(4);
    cout<<st.getmin(); // It is printing 2 as it should be!

    st.pop();
    st.pop();
    cout<<st.getmin(); // It is printing 3 as it should be!
} // Now here the TC and SC : O(1).

// ---------------------------------------------------------- LECTURE 60 - Queues --------------------------------------------------------------------------------------------------------->
// Queue (FIFO Data Structure)!
// A queue is a linear data structure that follows the FIFO (First In, First Out) principle. This means that the first element added to the queue is the first one to be removed, just like a waiting line at an ATM—the person who comes first is served first!
// Front & Rear : In a queue, elements are added from the rear (back) and removed from the front.
//              : Initially, both front and rear point to the same position.
//              : As elements are added, the rear moves forward to accommodate new elements.
//              : When elements are removed, they are always removed from the front.
// Queue vs Other Data Structures : In a list, we have head & tail. In a stack, we have top & bottom. In a queue, we have front & rear.
// Insertion & Deletion in Queue : Enqueue (Push) → Always happens at the rear. Dequeue (Pop) → Always happens from the front.
// STL Implementation of Queues!
#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q1; // Creating a queue

    // Pushing elements into the queue (Enqueue)
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout << "Front of the queue : " << q1.front() << endl; // Checking the front element
    cout << "Back of the queue : " << q1.back() << endl; // Checking the back element

    // Removing front element (Dequeue)
    q1.pop(); // Removes 1, now front will be 2
    cout << "Front of the queue after popping first element: " << q1.front() << endl;

    // Checking the size of the queue
    cout << "Size of the queue : " << q1.size() << endl;

    // Checking if the queue is empty
    if (q1.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    // Printing and emptying the queue
    while (!q1.empty()) {
        cout << q1.front() << " "; // Print front element
        q1.pop(); // Remove front element
    }
}

// Queue Implementation Using Arrays!
// A queue can be implemented using both arrays and linked lists. Right now, we will implement it using arrays.
// Understanding Queue Using Arrays : Initial Setup : We will use an array to store the queue elements.
//                                                  : Two important pointers : front → Points to the first element of the queue. and rear → Points to the last position where an element was inserted.
//                                                  : Initially, both front and rear are at index 0.
//                                  : Push Operation (enqueue) : When inserting an element, we follow these steps...
//                                                             : Step 1 : Check if the queue is full. A queue is full when rear == n (where n is the size of the array). If full, we cannot insert more elements.
//                                                             : Step 2 : Insert the new value at rear index.
//                                                             : Step 3 : Update rear by increasing it.
//                                  : Pop Operation (dequeue) : When removing an element, we follow these steps...
//                                                            : Step 1 : Check if the queue is empty. A queue is empty when front == rear (both pointers at the same position). If empty, there’s nothing to remove.
//                                                            : Step 2 : If not empty, move front forward to remove the element.
//                                  : Queue Full & Empty Conditions : Queue is Full → rear == n (Array is completely occupied)
//                                                                  : Queue is Empty → front == rear (No elements left)
#include <iostream>
using namespace std;

class QueueUsingArrays {
    int *arr; // Dynamic array for storing queue elements
    int queueFront; // Points to the front element of the queue
    int queueRear; // Points to the next available position for inserting an element
    int size; // Maximum size of the queue

public:
    // Constructor to initialize the queue
    QueueUsingArrays(int size) {
        this->size = size;
        arr = new int[size];
        queueFront = 0;
        queueRear = 0;
    }

    // Function to insert an element into the queue (enqueue)
    void enQueue(int data) {
        if (queueRear == size) { // Check if the queue is full
            cout << "Queue is full, cannot insert " << data << endl;
            return;
        }
        arr[queueRear] = data; // Insert element at rear index
        queueRear++; // Move rear forward
    }

    // Function to remove an element from the queue (dequeue)
    int deQueue() {
        if (queueFront == queueRear) { // Check if the queue is empty
            cout << "Queue is empty, cannot dequeue!" << endl;
            return -1;
        }
        int ans = arr[queueFront]; // Get front element
        arr[queueFront] = -1; // Optional: Mark as removed
        queueFront++; // Move front forward

        // If queue becomes empty after deletion, reset front and rear
        if (queueFront == queueRear) {
            queueFront = 0;
            queueRear = 0;
        }
        return ans;
    }

    // Function to get the front element of the queue
    int front() {
        if (queueFront == queueRear) { // If queue is empty
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[queueFront];
    }

    // Function to check if the queue is empty
    bool empty() {
        return (queueFront == queueRear);
    }

    // Function to check the current size of the queue
    int getSize() {
        return queueRear - queueFront;
    }

    // Destructor to free allocated memory
    ~QueueUsingArrays() {
        delete[] arr;
    }
};

int main() {
    QueueUsingArrays q1(5); // Creating a queue of size 5

    // Enqueue elements
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.enQueue(5);
    q1.enQueue(6); // This should print "Queue is full"

    // Display front element
    cout << "Front of the queue: " << q1.front() << endl;

    // Dequeue elements
    q1.deQueue(); // Removes 1
    cout << "Front of the queue after dequeue: " << q1.front() << endl;

    // Checking if the queue is empty
    if (q1.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    // Printing and emptying the whole queue
    cout << "Queue elements: ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.deQueue();
    }
    cout << endl;

    // Checking if queue is empty after processing
    if (q1.empty()) {
        cout << "Queue is now empty!" << endl;
    }

    return 0;
} // Time Complexity : O(1).

// Queue Implementation Using Linked List!
// Unlike an array-based queue, a linked list-based queue does not have a fixed size, so it can grow dynamically as needed.
// Uses nodes (instead of an array) to store elements.
// Does not require shifting elements (unlike an array, where shifting might be required after deletions).
// Understanding Queue Using Arrays : Each node contains : data → stores the value. and next → points to the next node in the queue.
//                                  : We maintain two pointers : front → Points to the first element of the queue. and rear → Points to the last element of the queue.
//                                  : Operations : enQueue(data) : Insert at the rear of the queue.
//                                               : deQueue() : Remove from the front of the queue.
//                                               : front() : Get the front element.
//                                               : empty() : Check if the queue is empty.
#include <iostream>
using namespace std;

// Node structure for the linked list queue
class NodeforQueue {
public:
    int data;
    NodeforQueue* next;

    NodeforQueue(int data) { // Constructor to initialize a node
        this->data = data;
        this->next = nullptr;
    }
};

// Queue class using a linked list
class QueueUsingLL {
    NodeforQueue* front; // Points to the front element
    NodeforQueue* rear;  // Points to the last element
    int count;   // Stores the number of elements in the queue

    public:
    // Constructor to initialize an empty queue
    QueueUsingLL() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // Function to insert (enqueue) an element at the rear of the queue
    void enQueue(int data) {
        NodeforQueue* newNode = new NodeforQueue(data); // Create a new node
        if (rear == nullptr) { // If queue is empty, both front and rear will point to newNode
            front = rear = newNode;
        } else {
            rear->next = newNode; // Link the last node to the new node
            rear = newNode; // Move rear to the new node
        }
        count++; // Increment queue size
    }

    // Function to remove (dequeue) an element from the front
    int deQueue() {
        if (front == nullptr) { // If queue is empty
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        NodeforQueue* temp = front; // Store the front node
        int value = temp->data; // Get the data of the front node
        front = front->next; // Move front to the next node

        if (front == nullptr) { // If queue becomes empty after deletion
            rear = nullptr;
        }

        delete temp; // Free memory
        count--; // Decrement queue size
        return value;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Function to get the rear (back) element of the queue
    int back() {
        if (rear == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return rear->data;
    }

    // Function to get the size of the queue
    int size() {
        return count;
    }

    // Function to check if the queue is empty
    bool empty() {
        return front == nullptr;
    }

    // Destructor to free memory when the queue object is destroyed
    ~QueueUsingLL() {
        while (!empty()) {
            deQueue();
        }
    }
};

int main() {
    QueueUsingLL q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    // Display front and back elements
    cout << "Front of the queue: " << q.getFront() << endl;
    cout << "Back of the queue: " << q.back() << endl;

    // Display queue size
    cout << "Queue size: " << q.size() << endl;

    // Dequeue elements
    q.deQueue();
    cout << "Front after dequeue: " << q.getFront() << endl;
    cout << "Back after dequeue: " << q.back() << endl;
    cout << "Queue size after dequeue: " << q.size() << endl;

    // Checking if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    // Printing and emptying the whole queue
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.getFront() << " ";
        q.deQueue();
    }
    cout << endl;

    // Checking size after emptying
    cout << "Queue size after emptying: " << q.size() << endl;

    return 0;
}

// Circular Queues!
// A Circular Queue is a special type of queue where, instead of reaching the end of an array and stopping, it wraps around to the beginning.
// This solves the issue of wasting space in a normal queue when elements are dequeued from the front.
// Key Differences from a Normal Queue : In a normal queue, once the rear reaches the last index, no more insertions are possible, even if there is space at the beginning.
//                                     : In a circular queue, when the rear reaches the last index, it wraps around to index 0 (if space is available).
// Understanding Circular Queue : Insertion : Step 1 : Check if the queue is full : If (front == 0 && rear == size-1) → Queue is full. OR if (rear == (front - 1) % (size - 1)) → Queue is full.
//                                          : Step 2 : If the queue is empty (front == -1), set front = rear = 0 and insert the element.
//                                          : Step 3 : If rear == size - 1 (end of the array) but front ≠ 0, set rear = 0 and insert the element at index 0 (wrap around).
//                                          : Step 4 : Otherwise, just do rear++ and insert the element.
//                              : Deletion : Step 1 : Check if the queue is empty (front == -1 && rear == -1).
//                                         : Step 2 : If there's only one element left (front == rear), after removing it, set front = rear = -1.
//                                         : Step 3 : If front is at the last index (size-1), wrap it to front = 0.
//                                         : Step 4 : Otherwise, just do front++.
// Why is Circular Queue Better : Efficiently uses space by reusing emptied slots. Prevents unnecessary shifting of elements. Works like a circular track, improving performance.
// Implementation!
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr; // Array to store elements
    int front; // Points to the first element
    int rear;  // Points to the last element
    int size;  // Maximum size of the queue

public:
    // Constructor to initialize the queue
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1; // Initially, queue is empty
    }

    // Destructor to free memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)));
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to insert an element into the queue
    bool enqueue(int value) {
        if (isFull()) { // If queue is full, return false
            cout << "Queue is Full. Cannot insert " << value << endl;
            return false;
        }

        if (isEmpty()) { // If inserting the first element
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) { // Circular condition: wrap around to 0
            rear = 0;
        }
        else { // Normal case: increment rear
            rear++;
        }

        arr[rear] = value; // Insert the element
        cout << "Inserted: " << value << endl;
        return true;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) { // If queue is empty, return -1
            cout << "Queue is Empty. Cannot dequeue." << endl;
            return -1;
        }

        int removedElement = arr[front]; // Element to be removed
        arr[front] = -1; // Mark it as removed

        if (front == rear) { // If single element was present, reset queue
            front = rear = -1;
        }
        else if (front == size - 1) { // Circular condition: wrap around to 0
            front = 0;
        }
        else { // Normal case: increment front
            front++;
        }

        cout << "Removed: " << removedElement << endl;
        return removedElement;
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        if (rear >= front) { // Case when rear is ahead of front
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        }
        else { // Circular case: print from front to size-1 and 0 to rear
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // Create a Circular Queue of size 5

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display(); // Display queue contents

    // Trying to insert into a full queue
    q.enqueue(60);

    // Dequeue some elements
    q.dequeue();
    q.dequeue();

    q.display(); // Display queue after deletions

    // Inserting again after removing elements
    q.enqueue(60);
    q.enqueue(70);

    q.display(); // Display final queue
    return 0;
}

// Circular Queue and its Variants!
// Circular Queue : A Circular Queue is a special type of queue where, The last position is connected to the first position, forming a circle. It avoids wastage of space when elements are removed. It uses modular arithmetic to maintain cyclic behavior.
//                : Operations in Circular Queue : enqueue(value) → Inserts an element at the rear. dequeue() → Removes an element from the front. Circular Movement : If the rear reaches the last position, it wraps around to the first position.
// Input Restricted Queue : An Input Restricted Queue allows insertion at only one end (rear), but deletion from both ends (front & rear).
//                        : Operations in Input Restricted Queue : push_back(value) → Insert an element at the rear (only way to insert).
//                                                               : pop_front() → Remove an element from the front.
//                                                               : pop_back() → Remove an element from the rear.
//                                                               : Insertion at the front is not allowed.
//                        : Use Case : Used when input should be regulated from one side only, but processing can be done from either end.
// Output Restricted Queue : An Output Restricted Queue allows removal of elements only from the front, but insertion at both ends (front & rear).
//                         : Operations in Output Restricted Queue : push_back(value) → Insert an element at the rear.
//                                                                 : push_front(value) → Insert an element at the front.
//                                                                 : pop_front() → Remove an element from the front (only way to remove).
//                                                                 : Deletion from the rear is not allowed.
//                                                                 : Use Case : Used when only the front is allowed for processing (removal), but elements can be added from both ends.
// Double-Ended Queue (Deque) : A Double-Ended Queue (Deque) is the most flexible queue, where insertion and deletion are allowed from both ends.
//                            : Operations in Deque : push_back(value) → Insert at the rear.
//                                                  : push_front(value) → Insert at the front.
//                                                  : pop_back() → Remove from the rear.
//                                                  : pop_front() → Remove from the front.
//                            : Use Case : Used in scheduling, undo operations, and efficient caching mechanisms (like LRU Cache).

// Double Ended Queue!
// A Deque (Double-Ended Queue) is a queue where insertion and deletion can happen from both ends (front and rear). It is useful in CPU Scheduling, Sliding Window problems, and OS process management.
// Operations in Deque : push_front() → Inserts an element at the front, push_rear() → Inserts an element at the rear, pop_front() → Removes an element from the front and pop_back() → Removes an element from the rear.
// Key Differences from Circular Queue : In Circular Queue, we only have enqueue() (rear insert) and dequeue() (front remove). In Deque, we have two ways to insert and delete elements.
//                                     : push_front() Logic : If the queue is empty, set front = rear = 0.
//                                                          : If front == 0, shift front to n-1 (circular nature). Else, simply front-- and insert.
//                                     : pop_back() Logic : If only one element is present, reset front = rear = -1.
//                                                        : If rear == 0, shift rear to n-1 (circular nature). Else, simply rear-- and remove.
// STL Implementation!
#include<iostream>
#include<queue>
using namespace std;

int main() {
    deque<int> q1; // Deque container from STL

    q1.push_front(12); // Insert 12 at the front
    q1.push_back(14);  // Insert 14 at the rear

    cout<<"Front of the queue: "<<q1.front()<<endl; // Prints 12
    cout<<"Back of the queue: "<<q1.back()<<endl;   // Prints 14

    q1.pop_front(); // Removes 12, leaving only 14

    cout<<"Front of the queue: "<<q1.front()<<endl; // Prints 14
    cout<<"Back of the queue: "<<q1.back()<<endl;   // Prints 14

    q1.pop_back(); // Removes 14, making the queue empty

    if(q1.empty()) {
        cout<<"Queue empty!";
    } else {
        cout<<"Queue not empty!";
    }
}

// Class Implementation!
#include<iostream>
using namespace std;

class Deque {
    int *arr;  // Array to store deque elements
    int front; // Front index
    int rear;  // Rear index
    int size;  // Maximum capacity

public:
    // Constructor to initialize deque of given size
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Insert an element at the front
    bool push_front(int x) {
        // Check if deque is full
        if (isFull()) return false;

        // If deque is empty, insert first element
        if (front == -1) {
            front = rear = 0;
        }
        // If front is at first position, move it to end (circular behavior)
        else if (front == 0) {
            front = size - 1;
        }
        // Normal case: Move front backward
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Insert an element at the rear
    bool push_rear(int x) {
        // Check if deque is full
        if (isFull()) return false;

        // If deque is empty, insert first element
        if (front == -1) {
            front = rear = 0;
        }
        // If rear is at the last position, move it to start (circular behavior)
        else if (rear == size - 1) {
            rear = 0;
        }
        // Normal case: Move rear forward
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Remove and return an element from the front
    int pop_front() {
        // Check if deque is empty
        if (isEmpty()) return -1;

        int ans = arr[front];
        arr[front] = -1;

        // If only one element was present, reset deque
        if (front == rear) {
            front = rear = -1;
        }
        // If front reaches the last position, wrap around
        else if (front == size - 1) {
            front = 0;
        }
        // Normal case: Move front forward
        else {
            front++;
        }
        return ans;
    }

    // Remove and return an element from the rear
    int pop_rear() {
        // Check if deque is empty
        if (isEmpty()) return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        // If only one element was present, reset deque
        if (front == rear) {
            front = rear = -1;
        }
        // If rear is at the first position, move it to the end
        else if (rear == 0) {
            rear = size - 1;
        }
        // Normal case: Move rear backward
        else {
            rear--;
        }
        return ans;
    }

    // Get the front element without removing it
    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    // Get the rear element without removing it
    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if deque is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % size));
    }
};

// Main function to test deque operations
int main() {
    Deque q1(10); // Create a deque of size 10

    q1.push_front(12); // Insert 12 at the front
    q1.push_rear(14);  // Insert 14 at the rear

    cout<<"Front of the queue:"<<q1.getFront()<<endl; // Prints 12
    cout<<"Back of the queue: "<<q1.getRear()<<endl;   // Prints 14

    q1.pop_front(); // Removes 12, front moves forward

    cout<<"Front of the queue: "<<q1.getFront()<<endl; // Prints 14
    cout<<"Back of the queue: "<<q1.getRear()<<endl;   // Prints 14

    q1.pop_rear(); // Removes 14, making the queue empty

    // Check if queue is empty
    if (q1.isEmpty()) {
        cout<<"Queue is empty!"<<endl;
    }
    else {
        cout<<"Queue is not empty!"<<endl;
    }

    // Check if queue is full
    if (q1.isFull()) {
        cout<<"Queue is full!"<<endl;
    }
    else {
        cout<<"Queue is not full!"<<endl;
    }
    return 0;
}