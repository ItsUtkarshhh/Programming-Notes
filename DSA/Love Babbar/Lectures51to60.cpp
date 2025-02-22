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
    Node* random;
    
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
    NodeSLL2A* original = head;
    NodeSLL2A* cloneHead = new NodeSLL2A(original->data);
    NodeSLL2A* cloneTail = cloneHead;
    original = original->next;

    while (original) {
        NodeSLL2A* newNode = new NodeSLL2A(original->data);
        cloneTail->next = newNode;
        cloneTail = newNode;
        original = original->next;
    }

    // Step 2: Assign random pointers
    original = head;
    NodeSLL2A* cloned = cloneHead;

    while (original) {
        if (original->random) {
            // Step 3: Find the corresponding node in the cloned list
            NodeSLL2A* temp = head;
            NodeSLL2A* tempClone = cloneHead;
            while (temp) {
                if (temp == original->random) {
                    cloned->random = tempClone;
                    break;
                }
                temp = temp->next;
                tempClone = tempClone->next;
            }
        }
        original = original->next;
        cloned = cloned->next;
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
    head->random = head->next->next;  // 1 -> 3
    head->next->random = head;        // 2 -> 1
    head->next->next->random = head->next->next->next;  // 3 -> 4

    cout << "Original Linked List:\n";
    printList(head);

    NodeSLL2A* clonedList = cloneLinkedListSLL2A(head);

    cout << "\nCloned Linked List:\n";
    printListSLL2A(clonedList);

    return 0;
}


// Approach 2 : Using a Hash Map - O(n) Time Complexity (Optimized Approach)
//            : Create a copy of the linked list, storing the mapping of original nodes to cloned nodes in a hash map. Key: Original Node, Value: Corresponding Cloned Node
//            : Assign next and random pointers using the map : cloneNode->next = map[originalNode->next], cloneNode->random = map[originalNode->random]
//            : Why is this better? We traverse the list only twice, making it O(n) time complexity. We use a hash map for storing references, leading to O(n) space complexity.
// Implementation!
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
} // This code is entirely of ChatGPT and is giving the correct answer! its the same approach, bss love babbar ke code se thora alag hai, baaki approach is all same! go through the code to understand it!

// Approach 3 : Upar vaale me SC : O(n) aa rhi thi, iss approach me we will try to minimize this also! so we will not use maps!
// So means here we will change the links!
// Further approach you can see while revision of this topic! till you understood how to actually clone the list! throught the above two approaches! and for now that is enuf!

// ---------------------------------------------------------- LECTURE 53 - Merge Sort in LinkedList --------------------------------------------------------------------------------------------------------->
// We already know what is Merge sort! so bss vhi krna hai yahaa!
// Also we wont change the data! hum sirf links ko change krenge!
// So lets see how...
// Lets code and see...
#include<iostream>
using namespace std;

class Node34 {
    public :
    int data;
    Node34* next;

    Node34(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node34() {
        int value = this->data;
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertatHead(Node34* &head, int data) {
    Node34* temp = new Node34(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node34* &tail, int data) {
    Node34* temp = new Node34(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtAnyPosition(Node34* &head, Node34* &tail, int position, int data) {
    if(position == 1) {
        insertatHead(head,data);
        return;
    }

    Node34* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }

    Node34* NodetoInsert = new Node34(data);
    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
}

Node34* findMid(Node34* head) {
    Node34* slow = head;
    Node34* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node34* merge(Node34* left, Node34* right) {
    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }
    Node34* ans = new Node34(-1); // dummy node! and iske aage hi poori list ko sort krke lgaa denge and then iss ans ko hi update krke head pr le ayenge! and then finally ans ko hi return krdege!
    Node34* temp = ans;

    // Merge two sorted LL
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node34* mergeSort(Node34* head) { // We will use recursion here!
    // Base case...
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // now in otherwise cases we will break the LL and will apply merge sort recursively!
    // Ab hume LL ko do halves me todna hai, toh ye cheez arrays ke case me toh simple si thi ki mid find kiya and tod diya vahaa se! but in case of LL its a little difficult! ki mid alag se nikalo! so we better use slow and fast vaala method!
    Node34* mid = findMid(head);

    Node34* leftHalf = head;
    Node34* rightHalf = mid->next;
    mid->next = NULL; // Ye isliye kiya taaki left half ka tail NULL ko pint kr rha hai tab hi toh actually do halves me tootegi LL! jab dono LL ke tails NULL ko point kr rhe honge!

    // recursive calls to sort both halves!
    leftHalf = mergeSort(leftHalf);
    rightHalf = mergeSort(rightHalf);

    Node34* result = merge(leftHalf, rightHalf);
    return result;
}

void printNode(Node34* &head) {
    Node34* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    // Creating a Linkedlist LL1...
    Node34* node = new Node34(1);
    Node34* head = node;
    Node34* tail = head;
    cout<<"First node of LL1 : ";
    printNode(head);

    cout<<"Singly Linkedlist : ";
    insertAtAnyPosition(head, tail, 2, 3);
    insertAtAnyPosition(head, tail, 3, 4);
    insertAtAnyPosition(head, tail, 4, 1);
    insertAtAnyPosition(head, tail, 5, 0);
    printNode(head);

    Node34* result = mergeSort(head);
    cout<<"Sorted Linkedlist : ";
    printNode(result);
} // So that is we have done sorting using Merge Sort! TC : O(nlogn) and SC : O(logn)

// Question for Homework : Flatten Linkedlis! isme kya hota hai ki kuch aisi LL hoti hai!
// Node1 -> Node2 -> Node3 -> Node4 -> NULL
// and har node ke downward directions me bhi aur nodes linked hai! toh hume kya krna hai ki hume unn sab nodes ko ek seedh me lgaa dena hai! and that is called Flattened Linkedlist!
// For reference visit question name : Flatten A Linkedlist! on codestudio! link is given under Lovebabbar vdo!
// Approach is :
// flatten(head) {
//     node* down = head;
//     down->next = NULL;
//     node* right flatten(head->right);
//     node* ans = merge(down, right);
//     return ans;
// }
// Visit the LB vdo for proper explaination! and try this question while revision!

// ---------------------------------------------------------- LECTURE 54 - Introduction to Stacks --------------------------------------------------------------------------------------------------------->
// Visualize it as a stack of Plates! and sabse pehle sabse upar vaali plate uthate hai and then uske neeche vaali! and that is how we access the plates! this is called LIFO principle! which means Last In First Out!
// So like suppse you have stack and you have inserted data into stack 1,2,3,4 here the insertion operation is called push operation! and and yahaa 4 sabse upar hoga stack ke mtlb ki jab element ko remove ya access krne ki baari ayegi toh sabse pehle 4 hoga then 3,2,1 and that is how it will be done! and isme jo remove operation hota hai usko pop kehte hai!
// So here we have Push and Pop operations!
// Along with these two, we also have a Peek operation in stack which returns the top most element of the stack!
// Another operation is empty() function, jo batata hai ki stack empty hai ya nhi!
// But before starting with implementation, lets use Stack using STL!
#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s1;
    s1.push(1);
    s1.push(2);    
    s1.push(3);    
    s1.push(4);
    s1.push(5);
    // So right now the top most element will be 5 and the bottom most will be 1, as becoz 1 sabse pehle enter kiya tha toh vo isliye stack ke sabse neeche hoga!

    s1.pop(); // Here we are removing the element from stack, here we dont need to specify the element we want to remove kyunki sirf top most element hi nikal sakta hai stack me se! agar chaahe ki koi aur element nikalne ka then it will show error!
    // So here we have removed 5!

    cout<<"Printing the top most element : "<<s1.top()<<endl;; // here this works what the peek function does! it will return the top most element!
    
    // Empty function is checked
    if(s1.empty()) {
        cout<<"Stack is empty!"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }

    cout<<"Size of stack : "<<s1.size(); // For this case it will return 4
}

// Implementation of Stack Class!
// Now Stack can be implemented using Arrays and Linkedlists! try implementing stack using Linkedlist as homework! currently lets try with Arrays!
// Implementing Stack using Arrays!
// Approach : Kya kya chahiye hoga? pehle toh ek array chahiye hogi! then we will make a top and jaise jaise element dalte jayenge vaise vaise top change hota jayega! and once the top goes out of the size of array, then we will call it stack overflow, means aur elements ab insert nhi ho sakte!
// and top size ke bahar na chale jaaye iss cheez ko bhi track krne ke liye bhi size toh chahiye hi hoga! so till now as privatee members of the class we will need int* arr, int top and int size!
// Now lets see how to implement function!
// Push Function! : pehle toh we will check ki stack khaali hai ya nhi! agar khaali hai toh tab hi insert krenge vrna stack overflow boldenge! now agar jagah khaali hai element ke aane ki toh we will do something like this arr[top] = element and top++! and when top>=size, then it will be called stack overflow means aur element nhi aa sakte!
// Pop Function! : pehle we will check ki stack khaali toh nhi hai? agar khaali hai toh kya hi pop krenge! will just return stack is empty! (Stack underFlow) and otherwise, will just write top-- and we are done with pop! stack empty haui ya nhi ye check krne ke liye we will check that top>=0 or not! if yes means the stack is not empty! otherwise stack is empty!
// Empty Function! : agar top == -1 hu means stack is empty! Stack underflow
// Top Function! : isme pehle ye check krlena ki stack empty hai ya nhi! agar hai toh top = -1 hoga in that case return stack underflow! and jab top element chahiye hoag toh return arr[top];
// Now lets implement!
#include<iostream>
using namespace std;

class Stack{
    // properties!
    public:
    int top;
    int* arr;
    int size;

    // Behaviours!
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push Function...
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout<<"Stack Overflow";
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout<<"Stack Underflow";
        }
    }

    int peek() {
        if(top>=0) {
            return arr[top];
        }
        else {
            cout<<"Stack is empty!";
            return -1;
        }
    }

    bool empty() {
        if(top == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

int main() {
    Stack s1(5); // Here we have created a stack with size = 5! means isme hum maximum 5 elements daal payenge!
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    // The above operations will work just like the regular push operations!

    cout<<"The top most element is : "<<s1.peek()<<endl;
    if(s1.empty()) {
        cout<<"The stack is empty!"<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }
    s1.pop();
    cout<<"The top most element is : "<<s1.peek()<<endl;

    // Now lets try to add elements more than the size!
    s1.push(5);
    s1.push(6); // Here we are trying to add 6th element in the stack! and due to which yahaa pr Stack overflow vaali condition reach hojayegi! and hence adding this into stack will print Stack overflow becoz we have wrote it in our implementation!
}

// Question : Implement two stacks in an array!
// Approach : Pehli baat toh yahaa hume array ek hi leni hai! and then yahaa pr do tops lene padenge! and size bhi lena hoga! the two tops are the tops of individual stacks! 
// Toh ye krenge kaise ki do stacks hum ek hi array me daal de aur usme LIFO principle bhi follow ho paye! so for that hum uss array ke dono ends ko use krenge! ek end ko top1 bnaa denge stack1 ka and ek end ko top2 bnaa denge stack2 ka! and then elements insert krna shuru krenge! and jahaa pr tops equal hojaye vahaa pr aur elements insert nhi ho sakte! kyunki jo array ki memory fill hogyi!
// Lets code this approach and see...
#include<iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void Push1(int element) {
        if(top2-top1 > 1) {
            top1++;
            arr[top1] = element;
        }
        else {
            cout<<"Stack Overflow!"<<endl;
        }
    }

    void Push2(int element) {
        if(top2-top1 > 1) {
            top2--;
            arr[top2] = element;
        }
        else {
            cout<<"Stack overflow!"<<endl;
        }
    }

    int pop1() {
        if(top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    int pop2() {
        if(top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }
}; // Also, yahaa hum ye bhi kr sakte the ki array ko n/2 n/2 parts me tod ke fir dono stacks ko daalte raho usme! but ye ek acha tareeka nhi hota! kyunki kyunki maanlo agar ek stack ne poori n/2 space leli hai but ek ne sirf lets suppose bss n/4 hi space li hai toh in that case n/4 space waste hojaati! so this is not the optimal usage of space!

int main() {
    TwoStack s1(10); // using this we have created a common array for both the stack with memory space = 10.
    s1.Push1(1);
    s1.Push1(2);
    s1.Push1(3);
    s1.Push1(4);
    s1.Push1(5);
    s1.Push1(6); // Here these operations pushed 6 elements inside the array! means now for stack2 only 4 elements ke liye size bacha hai!

    s1.Push2(10);
    s1.Push2(20);
    s1.Push2(30);
    s1.Push2(40); // Here we have filled the entire array with 10 elements inside it!

    s1.Push1(10); // Here it will print Stack Overflow!
}

// ---------------------------------------------------------- LECTURE 55 - Questions on Stack! --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse a string using stack!
// Approach : Ab dekhha jaye toh ye toh stack ki property hi hai! kyunki if we see, jab bhi stack me kuch daalte hai! toh vo pop toh reverse order me hi hota hai! so we will do the same!
// Lets code...
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    string str1 = "Utkarsh";
    stack<char> st1;
    for(int i = 0; i<str1.length(); i++) {
        char ch = str1[i];
        st1.push(ch);
    }

    string ans = "";
    while(!st1.empty()) {
        char ch = st1.top();
        ans.push_back(ch);
        st1.pop();
    }
    cout<<"Answer is : "<<ans<<endl;
    return 0;
} // So that is how we have reversed the string using stack!
// We have done this using swap function earlier! and there TC : O(n) and SC : O(1) kyunki swap me humne koi extra space nhi liya tha! but here, we can see we needed another ans variable toh reverse the string! so here TC : O(n) and SC : O(n)! so ofc better approach pehle vaala hi hai! but ye just ek aur nayaa approach hai!

// Question 2 : Delete middle element of the stack!
// Approach : Jaise arrays ke case me krte hai vaise hi yahaa bhi krenge! ki pehle yaha mid nikal lenge and ek iterator se stack ke deep jaate rahenge and mid hum (stack.size())/2 se nikal lenge! and then jab uss element pr pohochenge tab usko pop krdenge! but yes yahaa itna easily pop nhi hoga kyunki yahaa pop krne ke liye pehle uske upar ke elements ko nikalna hoga toh hum uss mid ke upar ke elements ko nikal ke kahi store krte jayenge and then jab mid element pop krle then unn sab elements ko vapis daal denge!
// Lets code now....
#include<iostream>
using namespace std;

// Using implementation of stack rather than STL.
class Stack2{
    // properties!
    public:
    int top;
    int* arr;
    int size;

    // behaviours!
    Stack2(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Push Function...
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout<<"Stack Overflow";
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout<<"Stack Underflow";
        }
    }

    int peek() {
        if(top>=0) {
            return arr[top];
        }
        else {
            cout<<"Stack is empty!";
            return -1;
        }
    }

    bool empty() {
        if(top == -1) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

void solve(Stack2 &inputStack, int count, int size) {
    // Base case...
    if(count == size/2) {
        inputStack.pop();
        return;
    }
    int num = inputStack.peek();
    inputStack.pop();

    // Recusrive call...
    solve(inputStack, count+1, size);

    inputStack.push(num);
}

void deleteMiddle(Stack2 &inputStack, int n) {
    int count = 0;
    solve(inputStack, count, n);
}

int main() {
    Stack2 st1(5); // We need to add size kyunki humne ek paramterized constructor create kiya hua hai jo call hojayega jab bhi hum stack2 ka object create krenge isliye hume size daalna padega!
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    // Now lets find the middle element!
    deleteMiddle(st1, 5);

    // Printing remaining nodes...
    while (!st1.empty()) {
        cout << st1.peek() << " "; // Ye ulta stack print krega!
        st1.pop();
    }
}

// Question 3 : Valid Parentheses! we need to check here ki harr opening parantheses ke liye close parantheses hai ki nhi! for example, {}, {()}, {{[]}} all these are examples of valid parantheses!
// Approach : Hum jaise jaise input aayega usko stack me daalte rahenge and jab bhi koi aisa input ayega jiska open vaala bracket already stack me available hoga hum usko pop krdenge! and we will continue doing this! and agar end me stack empty milta hai! we will call that set of parantheses a valid one! otherwise not!
// Lets code it now...
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValidParantheses(string exp) {
    stack<char> st1;
    for(int i = 0; i<exp.length(); i++) {
        char ch = exp[i];
    // If opening bracket then push it into stack!
    // If closing bracket then check and pop!
        if(ch == '{' || ch == '(' || ch == '[') {
            st1.push(ch);
        }
        else {
            // for closing bracket
            if(!st1.empty()) {
                char top = st1.top();
                if( (ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                    st1.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
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

// Question 4 : Add an element at the bottom of the stack!
// Approach : Here we will use the similar approach what we did in the deleting the middle node of the stack! so bss vhi krenge ki stack ke top ko ek jagah save krte jayenge and jab stack empty hojaye tab jis element ko add krna hai usko push krdenge stack me and then jin elements ko store kiya tha unko vapis restore krdenge!
// Lets code...
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x ) {
    // Base case...
    if(s.empty()) {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    // recurive call...
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x) {
    solve(myStack, x);
    return myStack;
}

void printStack(stack<int> s) {
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
// Approach : So what we will do is pehle toh hum top most element ko ek jagah save krlenge and then jo remaining stack hai usko reverse krdenge using recursion! and then jis element ko save kiya tha usko insert at bottom krdenge!
// Lets code this approach!
#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x ) {
    // Base case...
    if(s.empty()) {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();

    // recurive call...
    solve(s, x);
    s.push(num);
}

stack<int> insertAtBottom(stack<int> &myStack, int x) {
    solve(myStack, x);
    return myStack;
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void reverseStack(stack<int> &myStack) {
    // Base case...
    if(myStack.empty()) {
        return;
    }
    int num = myStack.top();
    myStack.pop();

    reverseStack(myStack);
    insertAtBottom(myStack, num);
}

void printStack2(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    cout << "Original stack st1 : ";
    printStack2(st1);

    reverseStack(st1);

    cout << "After reversing the stack st1 : ";
    printStack2(st1);
}

// Question 6 : Sort a stack! Constraint is not to use loop!
// Approach : So what we will do is again hum pehle stack ke top ke elements ko save krte jayenge and pop krte jayenge and jab stack empty hojaye uske baad hum unn hi element ko vapis stack me daalte jayenge but iss baar in sorted manner!
// Lets code this approach...
#include<iostream>
#include<stack> // Here we are using STL again and again! but its good if we practice using the questions using stacks implementation!
using namespace std;

void sortedInsert(stack<int> &s, int num) {
    // Base case...
    if(s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();

    // recursive call
    sortedInsert(s, num);
    s.push(n);
}

void sortStack(stack<int> &s) {
    // Base case...
    if(s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();

    // recursive call...
    sortStack(s);
    sortedInsert(s, num);
}

void printStack3(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st1;
    st1.push(1);
    st1.push(5);
    st1.push(3);
    st1.push(2);
    st1.push(4);

    cout << "Original stack st1 : ";
    printStack3(st1);

    sortStack(st1);

    cout << "After sorting the stack st1 : ";
    printStack3(st1);
}

// Question 7 : Remove redudant brackets!
// Approach : So what we will do is ki koi bracket redundant kab hoga? jab opening and closing bracket ke beech me koi bhi useful operation nhi ho rha! like ((a+b)) isme bahar vaala opeing bracket ki koi zarurat thi! so these are redudant bracket! now agar opening and closing bracket ke beech me koi bhi operator aata hai toh vo redudant nhi hoga! operand se mtlb nhi hai vo aaye ya nhi aaye, but agar operator aata hai then then vo redudant bracket nhi hoga!
// So bss hum vhi krenge ki stack me input lenge string ka and opening and closing bracket ke beech me check krlenge ki kya koi operator hai ya nhi!
// Lets code...
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            //ch ya toh ')' hai or lowercase letter
            if(ch == ')') {
                bool isRedundant = true;
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true) {
                    return true;
                }
                st.pop();
            }
        } 
    }
    return false;
}

int main() {
    string s1 = "((a+b))";
    if(findRedundantBrackets(s1)) {
        cout<<"Redudant brackets present!";
    }
    else {
        cout<<"Not present";
    }
}
// Lets understand this approach, our string was ((a+b)), so what happened is, ki pehle humne stack me opening brackets jaise jaise milte gye humne unko push krte gye! and operands ki need nhi hai push krne ki kyunki logic wise hume mtlb hume sirf operator and brackets se mtlb hai! so now humne pehle pehla ( push kiya then dusra ( push kiya and then + push kiya stack me! and now we got pehla ) toh ab hum stack me check krenge ki kya iska koi pair opening bracket hai and agar hume iska pair opening bracket dhundte time koi operator mil jaata hai toh toh mtlb ki ye toh vo redudant bracket nhi hai! and vo closing bracket and vo operator dono hi stack me se pop krdenge!
// now we will move forward, now jo dusra vaala closing bracket pr pohoche toh again check krenge ki kya iska koi pair opening bracket hai ya nhi! and we got the pair in the stack and this time koi bhi operator beech me nhi aaya! means this is the redudant bracket! means we will say that ki string me redudant bracket hai!

// Question 8 : Minimum cost to make string valid or Minimum bracket reversal! Humare paas input me ek expression diya hua hoga! which will be set of curly brackets! and the string will be called valid if all the brackets are balanced! formally for each opening bracket there must be a closing bracket right to it!
// Toh pehle toh hume ye check krna hai ki string valid hai ya nhi! aur valid vhi hone jo logically bhi correct honge! like {}{}, {{}}, {{}{}} all these are valid, now unvalid are like }{}, {}}{{}, {{}}}{} all these are unvalids!
// Now hume kuch operations perform krne hai taaki hum jo unvalid strings hai unko valid bnaa paaye! and isme kuch operations use kr sakte hai like reversing the bracket! ek bracket ke reverse krne ki cost hogi 1, so hume minimum cost of making the expression valid nikalni hai!
// Approach : for a valid expression, no. of open brackets = no. of closed brackets! means even number of brackets hone chahiye!
// Practice this question while revising!

// ---------------------------------------------------------- LECTURE 56 - Largest Rectangular Area in Histogram --------------------------------------------------------------------------------------------------------->
// Question 1 : Next smaller element!
// We are given an array and hume uss array me jo elements diye hue hai unke right side ke remaining array me first smaller element konsa hai vo nikalna hai agar koi nhi hai toh -1 retrun krdo! example : [2,1,4,3], iss case me, 2 ke right side window me 1 is the smaller element! then 1 ke right me kuch nhi hai toh -1, then 4 ke right me 3, then 3 ke right me array ki khatam hogya toh -1. toh final answer is [1,-1,3,-1]
// Approach 1 : Ek tareeka toh ye ki 2 pointer approach me do loops chalaa le and then ek pointer ko ek jagah fix krke dusre pointer se right ki window traverse krke output dede! but iss case me TC : O(n^2) which is not very good! so we will go to the next approach!
// Approach 2 : Toh iske liye hume number of traversals kam krne hai na taaki TC kam ho! so we will traverse from the right most element! ab we know for our example the right most element is 3, and iske right me isse chhota element hai nhi toh we will print the output -1, toh ek kaam krtee hai ek stack bnaate hai usme already -1 store krke rakhte hai! and jab bhi koi element se chhoti value find kr rhe honge toh hum stack ke top ko dekhenge! agar stack ka top chhota hota hai humare current element se toh hum simply uss top ko ans me store krlenge and jo humara curr element hai usko stack me puch krdenge! but agar stack ka top badaa hai curr element se then hum stack me se pop krte rahenge jab tak hume chhota element na miljaye! and jab hume chhota element mil jaata hai toh hum usko ans me store krdenge and stack me vo current element push krdenge! here our TC : O(n) which is better than previous!
// Lets code this approach...
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
// try this question for previous smaller element during revision!

// Question 2 : Largest rectangualr area in histogram! imagine you have an histogram with multiple different heights of rectangles all of the same breadth tho! now... jo main question hai vo vdo se hi samajh lena becoz here it is tough to make it understood! so...
// Approach 1 : First is the brute firce approach where we will try to find the solution using normal tactics and later on we will optimize it! so its like hum harr rectangle ko left ya right side me expand krne ka try kre agar hojaata hai toh kro and then after the maximum expansion possible jiss rectangle ka maximum area hai vo nikal do and then that will our answer!
// Approach 2 (optimized approach) : So what we can see is that hum kisi bar ko tab tak extend kr sakte hai left ya right jab tak uske left ya right me usse koi chhota baar nhi mil jaata! jab usse chhota bar miljayega we will not be able to extend! so hume kisi bhi bar ke left ya right me jo chhote bars hai uske index nikalne hai, jisse we will know ki hum humarae curr bar ko kitna extend krna hai! jo right me jo chhota bar milega uske index ko we will call n (next) and left me jo chhota baar milega usko we will call p (previous)!
// So humari range of extension ban jayegi "n-p-1" which will be the maximum width jo ki vo humari curr bar extend ho sakti hai! agar right me koi bar hi nhi hai toh n = -1 and same for p if left me koi bar nhi hai! and now area nikalne ke liye length * breadth chahiye hoti hai so here we got the width and length toh sabki fixed hai!
// lets code this approach...
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

vector<int> prevSmallerElement2(vector<int> arr, int n) {
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
// Queue is a type of Data Structure that follow FIFO order, which is first in first out!
// An good example is line in front of an ATM!
// Jaise list me head and tail tha.. stacks me top and bottom tha.. queue me front and rare hota hai!
// So like agar humne maanlo 4 elements push krdiye queue me toh push humesha rare me hoga! and jab hum pop krenge toh vo toh FIFO order me hi pop hoga and pop humesha front se hoga!
// Starting me front and rare same jagah point kr rhe honge and jaise jaise elements aate jayenge vaise vaise rare shift hota rahega queue ke end tak!
// Lets use queue using STL...
#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q1;
    // pushing elements into queue!
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    // Queue front :
    cout<<"Front of the queue : "<<q1.front()<<endl;

    // popping elements from queue!
    q1.pop(); // It will remove 1 from the queue front! so now the front will change!
    cout<<"Front of the queue : "<<q1.front()<<endl;

    // lets check the size of the queue...
    cout<<"Size of the queue : "<<q1.size()<<endl;

    // lets check that whether the queue is empty or not!
    if(q1.empty()) {
        cout<<"Queue is empty!"<<endl;
    }
    else {
        cout<<"Queue is not empty!"<<endl;
    }

    // Printing the whole queue...
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.pop();
    }
}

// Now queue can be implemented using arrays and lists both! so we will implement it using arrays, while revising try implementing it using lists!
// So firstly we will take an array and pehle toh front and rare dono hi index 0 pr honge and then in the push operation hum pehle toh vhi ki queue full toh nhi ho gyi pehle ye check krenge! and then vhi value push krenge uske andar and rare ko update krdenge! full ki condition ye hogi ki jab rare = n hojaye! and empty ki jab front and rare dono equal hojaye!
// and then in pop() operation we will check ki queue empty hai ya nhi agar empty hai tab toh koi insert ya remove krne ka sense banta nhi! and agar empty nhi hai toh simply front ko aage badhaa denge!
// But okay lets see the code...
#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int queueFront;
    int queueRear;
    int size;

    public :
    Queue() { // Jab bhi koi object create hoga iss class se tab hi ye default constructor call hojayega and Queue ko create krdega! 
        size = 10001;
        arr = new int[size];
        queueFront = 0;
        queueRear = 0;
    }
    void enQueue(int data) {
        if(queueRear == size) { // Queue is already full
            cout<<"Queue is full";
        }
        else {
            arr[queueRear] = data;
            queueRear++;
        }
    }
    int deQueue() {
        if(queueFront == queueRear) { // Queue is already empty
            return -1;
        }
        else {
            int ans = arr[queueFront];
            arr[queueFront] = -1;
            queueFront++;
            if(queueFront == queueRear) { // So this condition means, like jab ek queue ko hum full krdenge toh rear toh out of the array kisi index pr point kr rha hoga toh suppose humara array agar 10 size ka hai toh and 0-9 indexing hai toh rear toh 10th index pr point kr rha hoga kyunki push krte krte aage badh gya hoga! and jab hum pop krte krte jab last element ko pop krne pr ayenge toh front iss time 9th index pr hoga! and rear 10th index pr! and then jab hum last element ko bhi pop krdenge toh rear and front dono hi 10th index pr ajayenge! but iss condition me aur elements insert nhi ho payenge! toh isliye humne front and rear ko 0 par daaldiya taaki firse elements ko insert kr paaye!
                queueFront = 0;
                queueRear = 0;
            }
            return ans;
        }
    }
    int front() {
        if(queueFront == queueRear) {
            return -1;
        }
        else {
            return arr[queueFront];
        }
    }
    bool empty() {
        if(queueFront == queueRear) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Queue q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.enQueue(5);
    // Queue front :
    cout<<"Front of the queue : "<<q1.front()<<endl;

    // popping elements from queue!
    q1.deQueue(); // It will remove 1 from the queue front! so now the front will change!
    cout<<"Front of the queue : "<<q1.front()<<endl;

    // lets check that whether the queue is empty or not!
    if(q1.empty()) {
        cout<<"Queue is empty!"<<endl;
    }
    else {
        cout<<"Queue is not empty!"<<endl;
    }

    // Printing the whole queue...
    while(!q1.empty()) {
        cout<<q1.front()<<" ";
        q1.deQueue();
    }
} // TC : O(1)

// Circular Queue!
// So yahaa ye hota hai ki suppose you have an array with size 6 and usme elements insert krte gye! maanlo at some point in time, humara front index 0 pr hai! and rear index 4 pr hai! and now humne ab pop krdiya! toh front humara index 1 pr ajayega! and then again pop krdiya! toh ab front index 2 pr ajayega!
// So normal queue me kya hota tha ki agar hum koi aur element push krenge toh vo rear pr jaata tha and rear array ke size ke bahar jaake kisi imaginary 6th index ko point kr rha hota tha! but circular queue me aisa nhi hota hai iss case me jab hum last element push krenge toh rear imaginary index pr jaane ke bajaye seedha 0th index pr chalaa jayega! and then vahaa se push hona shuru hoga!
// So yaha ajo changes honge vo mostly enQueue me hi honge! so kya kya krna hoga like... pehle toh front and rear = -1 rahenge! and then pehle hum check krenge ki kya front == 0 hai && rear == size-1 hai! agar aisa hai means queue full hai! also agar rear == (front-1)%(size-1) hai tab bhi it means ki queue full hai! means koi bhi insertion possible nhi hai!
// Then, agar front == -1 hai toh means abhi hum apna first element insert kr rhe hai! toh iss case me hum front and rear ko = 0 krdenge! then, arr[rear] = value; now agar in other case agar rear == size-1 means agar rear end me hai! and front != 0 means agar front 0 pr nhi hai toh! in that case, rear = 0 krdo and arr[rear] = value krdo! and lastly agar rear++ krdo and arr[rear] = val; daaldo! so this will be our enQueue condition!
// Now, deQueue krne ke liye we will first check ki kya queue kahin empty toh nhi hai! for that we will check ki kya front and rear == -1 hai ya nhi! then, if the queue contains single element (at the starting of the queue) and we want to remove even that one, then in that case jaisa humne enQueue krte time kiya tha ki front = rear = 0 krdiya tha single element ke case me, toh bss vhi krenge ki front and rear kp vapis -1 krdenge! and then agar maanlo pop krte krte hum array ke end me aagye, then in that case simply front = 0 krdena taaki firse elements ko future me insert kr paaye! then in the last case agar aisa kuch hi hai toh simply front++ krdena and return krdena jo element remove kiya hai!
// Rest everything is same! lets implement it...
#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //to check whether queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            //cout << "Queue is Full";
            return false;
        }
        else if(front == -1) //first element to push
        {
			front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }
};

int main() {
    CircularQueue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    cout<<"Removed element : "<<q1.dequeue()<<endl; // It removed 1 from the circular queue!
} // So this is the logic of the implementation of circular queue! yahaa jo humne kiya hai that is from the question perspective but while actually implementing the circular queue hume krna basically yhi hai! with some changes in it!

// Now there are two types of queue, one is input restricted queue! jisme input restricted rehta hai and means hum kisi ek hi side se input kr sakte hai! but output dono side se possible hota hai!, so in this queue, there is a push_back() operation which pushes element at the rear end! and a pop_back() and pop_front() operation, where it pops elements from the front or back!
// Now there is also a queue which is called output restricted queue! isme ulta hota hai! output restricted rehta hai means hum sirf front se hi pop kr sakte hai! and push hum dono side se kr sakte hai! means there are pop_front() function hota hai jo front se pop krta hai! and push_front() and push_back() operations hote hai jo front and rear end se push krte hai elements ko!
// Another is double ended queue! which says ki hum kahin se bhi pop ya push kr sakte hai queue me!

// Doubly Ended Queue :
// These queues are used in CPU Scheduling like what we have studied in OS
// Now this doubly ended queue is possible through STL and through basic implementation also!
// In Implementation what we do is, that pehle toh hum ek front and ek rear bnaa dete hai! and then dekha jaaye toh ye circular queue ki tarah hi hai nss ye antar hai ki yahaa push ke do operations hai and pop ke bhi! front se and rear se dono!
// And isme hum 4 operations create krenge, push_front, push_rear, pop_front and pop_back.. inn sab me se humne push_rear and pop_front toh humne dekh li thi toh bss usko hi yahaa bhi use krenge!
// So lets talk about push_front and pop_back...
// Push_front : Here hum kuch inn given conditions me insert krenge... Pehle toh front and rear ko = -1 kiya! and now check kiya ki queue full hai ki nhi! now, agar nhi hai toh insert kr sakte hai vrna nhi!
//            : Now in case of insertion of first element, iski condition toh ye hogi ki front = -1 hona chahiye which shows ki queue abhi empty tha and ye pehla element hai jo hum insert krne jaa rhe hai! and iss time front and rear dono = 0 hojayenge! and vo element insert jojayega jo krna chah rhe the!
//            : But now after first element insertion agar hum firse push_front use krenge toh jaise hum normal push jo hota tha that was push_back/rear jisme hum insert krke front++ krdete the! but iss case me as hum push_front kr rhe hai toh hum front-- krenge! and iss case me jahaa abhi hum first element hi insert kr rhe hai, yahaa se hum front ko seedha n-1 pr lejayenge! kyunki yahaa front-- krne pr array se hi bahar chalaa jayega front! isliye hum push_front krne pr front ko next insertion ke liye seedha n-1 pr lejayenge! kyunki logically push_front ka mtlb hi yhi hua ki aage se push kr rhe ho! and isse vo circular queue bhi maintain rahegi!
//            : Then, kastly in normal cases me normal push hoga and front-- hota rahega!
// Pop_back : Again vahi ki agar queue hi empty hai toh no pop!
//          : And agar sirf single element hai queue me toh simply front and rear ko -1 set krdena hoga!
//          : Agar first element of the queue ko pop_back se remove krna hai toh simply rear ko n-1 pr le jao, jaise normally pop jo hota hai vo pop_front hota hai usme rear aage badhta jaata hai mtlb rear++ hota jaata hai but yahaa pop_rear/back ho rha hai means isme rear-- hota jayega! and agar first element ko pop krna hai toh -- toh ho nhi sakta vrna vo out of range chalaa jayega and cyclic nature maintain nhi rahega! toh rear = n-1 hojayega!
//          : And then lastly baaki normal conditions me simply rear-- hota rahega

// Now the above is the implementation of the doubly ended queue! but lets first try STL of it!
#include<iostream>
#include<queue>
using namespace std;

int main() {
    deque<int> q1; // Doubly ended queue ke liye library vhi hoti hai queue vaali hi bss isme deque keyword use krte hai doubly ended queue bnane ke liye!
    q1.push_front(12); // Here front = 0 hojayega and array me ek single element push hojayega! which is 12
    q1.push_back(14); // Isme humne back se push kiya hai toh yaha simply front ek aage badh jayega and front = 1 hojayega and 14 push hojayega!

    cout<<"Front of the queue : "<<q1.front()<<endl; // Will print 12
    cout<<"Back of the queue : "<<q1.back()<<endl; // Will print 14

    q1.pop_front(); // Ye array me se 12 hataa dega! and front ek aage badh jayega! and iss time front and rear dono hi 14 pr honge! and array will something like this, [  | 14 |   |   |....], toh first place khaali hai! and sirf 1st index pr ek value padi hai 14
    cout<<"Front of the queue : "<<q1.front()<<endl; // Will print 14
    cout<<"Back of the queue : "<<q1.back()<<endl; // Will print 14
    // both will print same values!

    q1.pop_back(); 
    // q1.pop_front(); // Dono me se koi bhi use kro vo 14 vaala element pop ho hi jayega! its just about ki hum front and rear ko correct way me idhar udhar ghumaye!

    if(q1.empty()) {
        cout<<"Queue empty!";
    }
    else {
        cout<<"Queue not empty!";
    }
}

// Now, lets implement it...
#include<iostream>
using namespace std;

class Deque {
    int *arr;
    int front;
    int rear;
    int size;

    public :
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool push_front(int x) {
        // Checking whether the queue is empty or not...
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            return false;
        }
        else if(front == -1) { // Insertion of first element
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        }
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool push_rear(int x) {
        // Checking whether the queue is empty or not...
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
            return false;
        }
        else if(front == -1) { // Insertion of first element
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int pop_front() {
        if(front == -1){ //to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    int pop_rear() {
        if(front == -1){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }

    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) )) {
            return true;
        }
        return false;
    }
};

int main() {
    Deque q1(10);
    q1.push_front(12);
    q1.push_rear(14);

    cout<<"Front of the queue : "<<q1.getFront()<<endl; // Will print 12
    cout<<"Back of the queue : "<<q1.getRear()<<endl; // Will print 14

    q1.pop_front(); // Ye array me se 12 hataa dega! and front ek aage badh jayega! and iss time front and rear dono hi 14 pr honge! and array will something like this, [  | 14 |   |   |....], toh first place khaali hai! and sirf 1st index pr ek value padi hai 14
    cout<<"Front of the queue : "<<q1.getFront()<<endl; // Will print 14
    cout<<"Back of the queue : "<<q1.getRear()<<endl; // Will print 14
    // both will print same values!

    q1.pop_rear(); 
    // q1.pop_front(); // Dono me se koi bhi use kro vo 14 vaala element pop ho hi jayega! its just about ki hum front and rear ko correct way me idhar udhar ghumaye!

    if(q1.isEmpty()) {
        cout<<"Queue empty!";
    }
    else {
        cout<<"Queue not empty!";
    }

    if(q1.isFull()) {
        cout<<"Queue is Full!";
    }
    else {
        cout<<"Queue is not Full!";
    }
} // Explaination is same as STL one!