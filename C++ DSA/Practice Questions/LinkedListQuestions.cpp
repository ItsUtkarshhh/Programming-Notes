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
// Pattern Recognition : "Linked List Traversal & Pointer Manipulation" with "Segmentation"
// Difficult : Hard
// Understand the problem : You have a linked list, and you have reverse each node to point to the previous self, right? But with a catch, we have to do it in chunks/groups of size K!
//                        : Reversing in size K, what can we imply from it, it means that every group's first element after reversing will point to the previous group's last element - LET THAT SINK IN.
//                        : As because, linked list with this : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL and reversal in size 2, will give this result : NULL <- 2 <- 1 <- 4 <- 3 <- 6 <- 5 which will be seen as this : 5 -> 6 -> 3 -> 4 -> 1 -> 2 -> NULL
//                        : How can we achieve it? Lets see the problems with the previous approaches and what to do next.
// Edge Case Handling : Empty List
//                    : Single Node
//                    : Group of size < K
// Approach 1 (Iterative Approach) : This approach is an improved version of the basic 3-pointer reversal technique. To understand it properly, we must first identify the issue in the naive approach.
//                                 : Problem with naive approach : If we reverse each K-sized group independently using the standard 3-pointer technique (prev, curr, next) with a counter (count < K), then after each group reversal, 'prev' will point to the head of that reversed group.
//                                                               : However, since we are not maintaining connections between consecutive groups, the previously reversed groups become disconnected.
//                                                               : As we continue this process, 'prev' keeps getting updated and finally points As we continue this process, 'prev' keeps getting updated and finally points Therefore, although all groups are reversed in memory, only the last group remains accessible, while earlier groups are effectively lost due to missing links.
//                                 : Fixing the problem : To maintain the structure of the linked list, we need to track : The end of the previous group → to connect it with the current reversed group
//                                                                                                                       : The start of the current group → which becomes the end after reversal
//                                                      : So, we need to manage connections between : (previous group end) & (current group start after reversal)
//                                                      : Additionaly, Before reversing a group, we must ensure that K nodes exist ahead. If the remaining nodes are less than K, we should not reverse them and simply leave them as it is.
//                                                      : Important dry run : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
//                                                                          : 2 -> 1 -> 3 -> 4 -> 5 -> 6 -> NULL
//                                                                          : 2 -> 1 -> 4 -> 3 -> 5 -> 6 -> NULL
//                                                                          : 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> NULL
//                                                      : Don't think like this, it will confuse you : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
//                                                                                                   : NULL <- 1 <- 2 <- 3 <- 4 <- 5 <- 6 (You actually reversed the whole list)
//                                 : TC = O(n) & SC = O(1)
// Approach 2 (Recursive Approach) : This approach is mainly to understand how recursion fits into this problem.
//                                 : First, while thinking recursively, we break the problem into smaller parts. We are given a linked list, and we need to process it in groups of size K.So the idea is: reverse the first K nodes, and then recursively solve remaining list.
//                                 : But there are some important catches and insights : We cannot assume that every group will always have K nodes. So at every recursive step, we must first check whether K nodes exist. If not, we simply return the remaining list as it is.
//                                 : Now, assuming that a valid group of size K exists : We reverse the first K nodes using the standard 3-pointer technique.
//                                                                                     : After reversing, 'prev' will point to the new head of this group, and 'head' (original head) will become the tail of this group.
//                                                                                     : Now the question is : Where do we attach the remaining list? After reversal, the current group's tail (which is the original head) will be pointing to NULL temporarily. So we need to connect it to the result of the recursive call.
//                                                                                     : That is why we do : head->next = reverseRecursion(nextGroupStart, k); Here, the recursive call will process the remaining list in the same way, and return the head of the next processed (reversed or untouched) part.
//                                 : As recursion continues, we eventually reach the base case : If no nodes are left → return NULL, If nodes are less than K → return them as it is
//                                                                                             : Then, while the recursion stack unwinds, each group gets correctly connected to the next group using head->next.
//                                                                                             : So effectively : Each recursive call reverses one group & And connects it with the result of the next recursive call
//                                                                                             : This is how the recursive solution builds the final list step by step.
//                                 : TC = O(n) && SC = O(n) - (due to recursion stack)
Node* reverseLL(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        Node* kth = prevGroupEnd->next;
        Node* currGroupStart = prevGroupEnd->next;
        int count = 1;

        while(count < k && kth != NULL) {
            // count == K && kth == NULL - Not possible condition! both together can't happen!
            // count == K and kth != NULL - Possible condition! "more nodes after the current node" condition
            // count != K and kth != NULL - Possible condition! "loop running" condition
            // count != K && kth == NULL - Possible condition! "No more groups further" condition
            kth = kth->next;
            count++;
        }

        if(kth == NULL) break; // No groups available condition
        Node* nextGroupStart = kth->next;
        kth->next = NULL; // Isolated the group to be reversed

        Node* prev = NULL;
        Node* curr = currGroupStart;
        Node* forward = NULL;

        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        // Now actual linking starts
        currGroupStart->next = nextGroupStart;
        prevGroupEnd->next = prev;
        prevGroupEnd = currGroupStart;
    }

    return dummyNode->next;
}

Node* reverseLL2(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        Node* kth = prevGroupEnd->next;
        Node* currGroupStart = prevGroupEnd->next;
        int count = 1;

        while(count < k && kth != NULL) {
            // count == K && kth == NULL - Not possible condition! both together can't happen!
            // count == K and kth != NULL - Possible condition! "more nodes after the current node" condition
            // count != K and kth != NULL - Possible condition! "loop running" condition
            // count != K && kth == NULL - Possible condition! "No more groups further" condition
            kth = kth->next;
            count++;
        }

        if(kth == NULL) break; // No groups available condition
        Node* nextGroupStart = kth->next;
        // kth->next = NULL; // Isolated the group to be reversed

        Node* prev = nextGroupStart;
        Node* curr = currGroupStart;
        Node* forward = NULL;

        while(curr != nextGroupStart) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        // Now actual linking starts
        // currGroupStart->next = nextGroupStart; // Now we don't need this condition as already handled in the above case!
        prevGroupEnd->next = prev;
        prevGroupEnd = currGroupStart;
    }

    return dummyNode->next;
}

Node* reverseRecursion(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    int count = 1;
    Node* temp = head;
    while(count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    count = 1;

    // Important things to note here :
    // First condition : Condition here is count <= K, unlike in the previous approach of using multiple pointers, we simply traversed with the condition count < k, there also count was initiated with 1 only, but still the condition there was count < k only. Why?
    //                 : Reason being, in the previous question, we were simply traversing the list with kth pointer, that's it! We were not doing any manipulation operations within the loop! So it didn't bothered us at that time even if the count becomes equals K, it will satisfy our needs, because we just needed to REACH the last node of the group.
    //                 : But here, we do not just need to REACH the last of the group, we are going to do some operations for that last node too, that is why we needed count <= K
    // Second condition : In the previous approach we checked for group existence using Kth pointer with the same condition of curr != NULL, so earlier I was assuming that curr != NULL will also do the same thing which it did in the last use case, but no here it didn't! Reason?
    //                  : Because again, last time we were just "traversing" but there, but here we are also doing pointer manipulation too with each node while traversing!
    //                  : That's why we handled that group existence check logic in the earlier code block, and then moved further. But this may raise a question, that why do we even need the curr pointer now in the condition? As the existence is already checked earlier!
    //                  : This is where comes the SRP principle : Which says, design systems with enabling it to only handle one single responsibility! Also, even if you have handled the edge case in the previous code blocks, you should still make sure nothing breaks and your code stays robust!
    //                  : This is how we achieve separation of concerns! Its not about the code, the code will be correct even if you remove the condition curr != NULL. but from industry stand point its important and interviewers may see that, whether you are thinking to make robust systems or just you know it won't break, so you are staying with that truth of yours
    while(count <= k && curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    if(curr != NULL) {
        head->next = reverseRecursion(curr, k);
    }
    return prev;
}

// ------------------------------------------------------- Question 3 : Check whether a LinkedList is Circular or Not ------------------------------------------------------------------------>
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