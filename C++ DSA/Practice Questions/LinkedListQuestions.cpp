// ------------------------------------------------------- Linked List Questions ------------------------------------------------------------------------>
// ------------------------------------------------------- Question 1 : Reverse a Linkedlist ------------------------------------------------------------------------>
// Pattern Recognition : "Linked List Traversal & Pointer Manipulation" - Very Common Pattern, used in every next question you solve for Linked List.
//                     : "Three pointers - prev, curr, forward" - Not so common as first one, but yes used oftenly for the specified use cases.
// Difficulty : Easy
// Understand the problem : Reversing a linked list means changing the direction of the links between nodes. Unlike arrays, we cannot swap elements using indices because linked lists do not support random access.
// Special case handling : Empty list
//                       : Single node
// Approach 1 (Brute Force) : If the problem is that arrays have indexes, so they are easy & intuitive to reverse using random access.
//                          : So, simply insert all the nodes into an array, and reverse the array, and either rebuild a new list or change the values of the original list starting from first node.
//                          : TC = O(n) & SC = O(n)
// Approach 2 (Optimized) : Approach 1 is taking extra space, so need to think of some solution in-place!
//                        : For that, we know, each node contains a pointer (next) that determines the order of the list. So, reversing the list means : Updating every node’s next pointer to point to its previous node instead of the next one.
//                        : The main challenge was : While reversing the pointers, we risk losing access to the remaining part of the list.
//                        : But, as a solution, we can use three pointers : pointer 1 : pointer where we are going to point the current node to reverse the order - prev
//                                                                        : pointer 2 : tracking current pointer, which pointer is going to be manipulated - curr
//                                                                        : pointer 3 : temporarily stores the next node (to avoid losing the list) - forward
//                        : TC = O(n) & SC = O(1)
// Approach 3 (Recursive Reversal) : In the recursive approach, we reverse the linked list by breaking the problem into smaller subproblems.
//                                 : Instead of explicitly maintaining prev, curr, and next like in iteration, recursion uses the call stack to manage state.
//                                 : Reverse the rest of the list first, then fix the current node. Assume that all nodes after the current node are already reversed. Then adjust the current node to fit into the reversed structure
//                                 : Key Insight : Recursion works in two phases - Going down → reach last node (base case) & Coming back → reverse links step by step
//                                               : Although, recursion is working here, but there is no practical advantage of using recursion for reversing a linked list compared to the iterative approach, in this case.
//                                 : TC = O(n) & SC = O(n) - Extra space due to recursion call stack.
//                                 : Recursion is not required here for optimization, but it demonstrates an alternative way of solving the problem using divide-and-conquer and backtracking. However, iterative is more space-efficient and preferred.
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

// Problems with similar pattern : Reverse Linked List 2 ()
//                               : Reverse Nodes in K Group
//                               : Palindrome Linked List
//                               : Rotate List
// ------------------------------------------------------- Question 2 : Find Middle of the Linked List! ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers using Fast & Slow pointer" - Primary pattern
//                     : "Linked List Traversal" - Secondary pattern
// Difficulty : Easy
// Understand the problem : In arrays, finding the middle element is straightforward : We can directly access index = n/2 in O(1) time.
//                        : However, in a linked list, random access is not possible. We must traverse the list sequentially to reach any position.
// Special case handling : Empty List
//                       : Single node
// Approach 1 (Brute Force) : Now, again if the problem is the data structure itself, we can simply change the data structure and input the values in an array and simply give the answer by finding the length in O(1).
//                          : TC = O(n) && SC = O(n)
// Approach 2 (Optmized Brute Force) : Instead of using extra space, we can : Find length of the linked list & Traverse again to reach middle (len/2).
//                                   : Start counter with 0, and traverse the list, until the count < (len/2) condition is true!
//                                   : Rule of traversal, while traversing in LL or any data structure, just think about : What is the condition where I need to stop! or What is the last valid condition!
//                                   : TC = O(n) && SC = O(1)
// Approach 3 (Optimized Solution) : But, still the above approach is traversing the LL twice.
//                                 : Here comes a two pointers using fast & slow ppointer technique - Where on moving one pointer two times and one only one time, and when the fast one becomes NULL or reaches last node, whichever comes first, the slow will pointing at the middle node!
//                                 : Why it works : Because think about it - If you are moving one pointer with x speed and one with 2x speed, so its obvious by the time faster one will cover d distance, the slower one will only be able to cover d/2 distance, that is the core logic of it!
//                                 : TC = O(n) & SC = O(1)
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

// Problems with similar patterns : Split Linked List into Two Halves
//                                : Linked List Cycle Loop
//                                : Find Start of Cycle
//                                : Palindrome Linked List
//                                : Remove Nth Node from End
//                                : Intersection of Two Linked Lists
// ------------------------------------------------------- Question 3 : Reverse the Linked List in a group of size K! ------------------------------------------------------------------------>
// Pattern Recognition : "Linked List Traversal & Pointer Manipulation"
//                     : ""
// Approach 1 (Iterative Approach) : Approach is simple, you want to traverse the full list in K groups, and you are going to reverse every group, you can see its demanding two nested loops!
//                                 : We use while(true) because the stopping condition depends on checking whether k nodes exist ahead, which can only be determined inside the loop after traversal. So instead of pre-checking, we use an internal break for cleaner and efficient logic.
//                                 : And then we create a dummyNode, because we are not sure about the new head! then few important pointers like prevGroupEnd to track the end of previus group which will be helpful while linking previous group to the new group.
//                                 : Now another is, groupStart which determines the current group start and kth pointer which is technically curr groupEnd, but will become prevGroupEnd when we move forward.
//                                 : Now in a similar manner, we simply keep traversing the list one by one! until we do find K nodes!
// Approach 2 (Recursive Approach) : In order to think in the recursive way, we need to think about minimizing the problem to least! and then building it at every step by increasing the number of nodes!
//                                 : Means, what will I do if there is no nodes, I will return NULL, and what if there are "n" nodes, and k = 2, thinking in recursion would be, I will break the linkedlist into K parts with each recursion call! where this recursive stack will behave as a hidden memory to save my progress kind of stuff.
//                                 : And I will reverse that every K size list in every recursive call until we reaches the base case of recursion, which will be curr == NULL, and when it does that, we start returning, for the first time we will simply return NULL, and as the moment when base case was hit, was when were dealing with the last k size list, and we have applied the logic in such a way, that after recursive call returns, the returned node (whether NULL/Non-NULL) will be attached to the next of the previous list's head. And after that when recursion unbinds, every previous head will get connected to the prev.
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

// Problem 4 : Check whether a LinkedList is Circular or Not.
// Approach 1 : If we want to check for the full circle, its simple just check whether after traversing some temp node in a list moving forward, does it ever become NULL or again points at head, in either of the case we have our answer!
// Approach 2 (Floyd's Cycle Algorithm) : For Incomplete circle : Intuitive thinking will be, if there are two cycles on a track - one's speed is twice the other's, then while cycling on a circular track, they will eventually meet.
//                                      : Mathematically, what's happening is : Let L be distance (number of nodes) to reach the start of circular track.
//                                                                            : Let t be the number steps (nodes) traversed by slow & Let C be the length of the circular track.
//                                                                            : Now, if slow traversed "t" distance, fast must already traversed "2t" distance, and within the circular track the distance will be calculated with "(mod)C".
//                                                                            : And distance covered inside the circular track will be "t-L" for slow & "2t-L" for fast. Overall total distance travelled by both slow and fast will be "(t-L)modC" by slow & "(2t-L)modC" by fast. And meeting condition should be (t-L)modC = (2t-L)modC.
//                                                                            : Which gives t = 0, which means "t = kC" - this equation can confirm that "Fast has gained exactly one full lap over slow." & can also be interpreted as "slow has traversed kC distance from start of the List"
// Approach 3 (Hashing) : Simply traverse the list, if the current node is marked as visited, return true, otherwise first mark it as true and then move forward. And keep doing it until the list end.
bool checkCircular(Node* head) {
    if(head == NULL) return false;

    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        if(temp == head) {
            return true;
        }
    }
    return false;
}

bool checkLoop(Node* head) {
    if(head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        if(slow == fast) {
            return true;
        }
    }
    return false;
}

bool checkLoop2(Node* head) {
    if(head == NULL) return false;

    unordered_map<Node*, bool> visited; // Also can use unordered_set - as order or duplicates does not matter!
    Node* temp = head;

    while(temp != NULL) {
        if(visited[temp]) return true;
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Problem 5 : Finding the starting node of the Loop inside the List!
// Approach 1 (Hashing) : We cab simply use the hashing, as while traversing, if we again meet the visited node, then that is the starting point of the loop!
// Approach 2 (Floyd's Cycle Algorithm) : Intuition is basically, if two runners are running on a track, and from the point of their meeting, if another runner starts running at the same pace as of the two runners already running in the circular path, they will eventually meet at the starting point in of circular path.
//                                      : Mathematics proves it : 1. Suppose L - Distance from head to starting point of the circular path, M - Distance from the starting point to the meeting point, C - Total length of the circular path.
//                                                              : 2. We know that, slow total distance is = L + M= kC (as slow meets fast first time after fast exactly completes its first full round), so effectively = slow total distance = L + M = C
//                                                              : 3. Now, from equation - L + M = kC, we know "k" is just some full circles, so effectively, L + M = C, hence L = C - M - Which means : Distance from head to cycle start = Distance from meeting point to cycle start.
//                                      : Which creates symmetry, hence the algorithm based on this logic works.
Node* checkLoop(Node* head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

Node* startingNode(Node* head) {
    if(head == NULL) return NULL;

    unordered_map<Node*, bool> visited; // Also can use unordered_set - as order or duplicates does not matter!
    Node* temp = head;

    while(temp != NULL) {
        if(visited[temp]) return temp;
        visited[temp] = true;
        temp = temp->next;
    }
    return NULL;
}

Node* startingNode2(Node* head) {
    if(head == NULL) return NULL;

    Node* intersection = checkLoop(head);
    if(intersection == NULL) return NULL; 

    Node* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Problem 6 : Remove the Loop!
// Approach 1 (Hashing using sets/maps) : We can simply can check the next node to be visited or not, by marking the first item already visited, and then traversing until the end. And when the next node is visited then we can simply cur the loop link from there.
// Approach 2 (Use Floyd Algorithm) : Simply get the starting node of the loop, and traverse until the temp->next != starting, and then simply break the list from there. This solution works because the Floyd's Algorithm in startingNode & checkLoop actually works.
Node* checkLoop(Node* head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

Node* startingNode(Node* head) {
    if(head == NULL) return NULL;

    Node* intersection = checkLoop(head);
    if(intersection == NULL) return NULL; 

    Node* slow = head;

    while(slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node* removeLoop(Node* head) {
    if(head == NULL) return NULL;

    unordered_set<Node*> visited;
    Node* temp = head;

    while(temp != NULL && temp->next != NULL) {
        if(visited.find(temp->next) != visited.end()) {
            temp->next = NULL;
            return head;
        }
        visited.insert(temp);
        temp = temp->next;
    }

    return head;
}

Node* removeLoop(Node* head) {
    if(head == NULL) return NULL;

    Node* starting = startingNode(head);
    if(starting == NULL) return NULL;
    Node* temp = starting;

    while(temp->next != starting) {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

// Problem 7 : Remove duplicates from a Linked List - Sorted
// Approach 1 : Simplest approach would be insert all the nodes inside a ordered set and then simply re-iterate it to create a new list. It will cost extra space tho.
// Approach 2 : Simply iterate the list in a nested loop structure, and remove duplicate nodes.
// Approach 3 : The best and most optimal approach would be, iterating using two pointers, one will be to tell that till where the list has no duplicates & another will be actually use to track duplicates and we will just keep adjusting links to always point at the temp.
//            : Here, there is no point to use a dummyNode, as because dummy nodes are used generally when we are not sure whether the head of the list will be remain there or not, we only use it when the head of the list may change due to deletion, traversal or any operation.
Node* deleteDuplicates(Node* head) {
    if(head == NULL) return NULL;

    set<int> st;
    Node* temp = head;
    while(temp != NULL) {
        st.insert(temp->val);
        temp = temp->next;
    }

    Node* dummyHead = new Node(INT_MIN);
    Node* dummyTail = dummyHead;
    for(int x : st) {
        Node* newNode = new Node(x);
        dummyTail->next = newNode;
        dummyTail = newNode;
    }
    return dummyHead->next;
}

Node* deleteDuplicates(Node* head) {
    if(head == NULL) return NULL;

    Node* curr = head;
    while(curr != NULL) {
        Node* temp = curr;
        Node* tempNext = curr->next;
        while(tempNext != NULL) {
            if(temp->val == tempNext->val) {
                Node* ntd = tempNext;
                temp->next = tempNext->next;
                tempNext = tempNext->next;
                ntd->next = NULL;
                delete ntd;
            }
            else {
                temp = temp->next;
                tempNext = tempNext->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

Node* deleteDuplicates(Node* head) { // Here you can also choose to delete the duplicate node, but just chose to adjust the links around it
    if(head == NULL) return NULL;

    Node* correct = head;
    Node* temp = correct->next;

    while(temp != NULL) {
        if(correct->val == temp->val) {
            correct->next = temp->next;
        }
        else {
            correct = temp;
        }
        temp = temp->next;
    }
    return head;
}

// Problem 8 : Remove duplicates from a Linked List - UnSorted
// Approach 1 : Here the nested approach will still work! As the nested loop does not care for any sorted structure!
// Approach 2 : Sort the list using merge or quick sort and then simply follow the previous sorted linkedlists approach! - Here everything will be same as above one, just the difference will be for merge sort, that will practice when question comes.
// Approach 3 : Use Hashing : using unordered set, iterate through the list and store elements in the set and once you visit a value which is already there in the set, simply remove it by adjusting pointers accordingly.
Node* deleteDuplicates(Node* head) {
    if(head == NULL) return NULL;

    Node* curr = head;
    while(curr != NULL) {
        Node* temp = curr;
        Node* tempNext = curr->next;
        while(tempNext != NULL) {
            if(temp->val == tempNext->val) {
                Node* ntd = tempNext;
                temp->next = tempNext->next;
                tempNext = tempNext->next;
                ntd->next = NULL;
                delete ntd;
            }
            else {
                temp = temp->next;
                tempNext = tempNext->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

Node* deleteDuplicates(Node* head) {
    if(head == NULL) return NULL;

    unordered_set<int> exist;
    Node* prev = head; // Here you need to understand an important insight into problem solving : Which is - When you build a logic, you try to follow every instruction of it, and change your direction of thinking/execution/or writing code for some special cases like here!
    // Here, its fine, Node* prev = head works fine, but it breaks the "logical" consistency of the problem, we used this method where we meant to make prev pointer a pointer which will denote the large "processed" & "unique" node of the list! but we initially only before processing if we put prev = head, means we are breaking the logocal consistency!
    // It may not break correctness in simple cases, but it weakens the invariant, which can lead to bugs in other variations or extensions!
    Node* curr = prev;
    while(curr != NULL) {
        if(exist.find(curr->data) != exist.end()) {
            prev->next = curr->next;
        }
        else {
            exist.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
}

// Problem 9 : Sort 0s 1s 2s - Linked List
// Approach 1 : Simply insert all the elements into an array, sort and retrieve again in the same list!
// Approach 2 : Simply use the merge sort algorithm!
// Approach 3 : Simply insert in an array and use the Dutch National Flag Algorithm!
// Approach 4 : Simply count the 0s, 1s, 2s and then just modify the values in the lists!
// Approach 5 : We can simply create a new list while traversing the original list and creating a new list using the original list values!
// Approach 6 : Simple iterate over the list using three dummy pointers, one for 1s, 2s & 3s and so on. And then just build there separate lists and then merge them together! - Here we can use dummynodes because we are not sure about the head, that which will be the head!
Node* sort012(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* zeroHead = new Node(INT_MIN);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(INT_MIN);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(INT_MIN);
    Node* twoTail = twoHead;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if(temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        }
        else {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = temp->next;
    }

    if(oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// Problem 10 : Merge Two Linked Lists
// Approach 1 : If both the lists are sorted : Simply traverse using two pointers L1 & L2 and simply compare and modify the links between the nodes!
// Approach 2 : If both the lists are unsorted : Sort them and apply the previous approach!
// Approach 3 : If one sorted and one unsorted, and your main reference list is the unsorted one! Then simply pick each node from the unsorted list and keep inserting it into the sorted list in sorted manner!
Node* mergeTwoLists(Node* LL1, Node* LL2) {
    if(LL1 == NULL) return LL2;
    if(LL2 == NULL) return LL1;

    Node* dummyHead = new Node(INT_MIN);
    Node* dummyTail = dummyHead;

    while(LL1 != NULL && LL2 != NULL) {
        if(LL1->data < LL2->data) {
            dummyTail->next = LL1;
            dummyTail = LL1;
            LL1 = LL1->next;
        }
        else {
            dummyTail->next = LL2;
            dummyTail = LL2;
            LL2 = LL2->next;
        }
    }

    if(LL1 != NULL) dummyTail->next = LL1;
    if(LL2 != NULL) dummyTail->next = LL2;

    return dummyHead->next;
}

Node* insertNode(Node* head, Node* nodeToInsert) {
    if(head == NULL || head->data >= nodeToInsert->data) {
        nodeToInsert->next = head;
        head = nodeToInsert;
        return head;
    }

    Node* temp = head;

    while(temp->next != NULL && temp->next->data < nodeToInsert->data) {
        temp = temp->next;
    }

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    return head;
}

Node* mergeTwoLists2(Node* LL1, Node* LL2) {
    if(LL1 == NULL) return LL2;
    if(LL2 == NULL) return LL1;

    Node* temp = LL1;

    while(temp != NULL) { // LL1 is unsorted
        Node* remainingList = temp->next;
        temp->next = NULL;
        
        LL2 = insertNode(LL2, temp);

        temp = remainingList;
    }
    return LL2;
}