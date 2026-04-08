// ------------------------------------------------------- Linked List Questions ------------------------------------------------------------------------>
// ------------------------------------------------------- Question 1 : Reverse a Linkedlist ------------------------------------------------------------------------>
// Pattern Recognition : "In-place Reversal"
// Approach, Techniques & Sub-Patterns : "LL Fundamentals" + "Pointer Manipulation" + "Recursion"
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
// Pattern Recognition : "Two Pointers"
// Approach, Techniques & Sub-Patterns : "Fast & Slow Pointer"
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
// Pattern Recognition : "In-place Reversal"
// Approach, Techniques & Sub-Patterns : "Segmentation" + "Pointer Manipulation" + "Recursion"
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

// ------------------------------------------------------- Question 4 : Check whether a LinkedList is Circular or Not ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers"
// Approach, Techniques & Sub-Patterns : "Fast Slow Pointer" + "Hashing"
//                     : Hashing
// Difficulty : Easy
// Understand the Problem : A Linked List is said to be circular if during traversal we never encounter NULL. Instead, the traversal either loops back to the starting node or enters a cycle.
//                        : There are two possible cases of circular nature in a Linked List : Completely Circular Linked List : The last node points back to the head (first node).
//                                                                                                                             : While traversing from the head, if we reach the head again, it confirms that the list is completely circular.
//                                                                                                                             : If we encounter NULL instead, then the list is not circular.
//                                                                                           : Partially Circular (Cycle in Linked List) : The list contains a cycle, but it does NOT necessarily link back to the head.
//                                                                                                                                       : While traversing, we never reach NULL. Instead, we keep visiting the same set of nodes repeatedly. This indicates the presence of a loop (cycle) somewhere in the list.
//                        : Key Insight : If traversal reaches NULL → Not circular
//                                      : If traversal revisits any node → Circular (either complete or partial)
// Edge cases : Empty list
//            : Single node pointing to its own self.
//            : Handle fast correctly, as it will go NULL earlier if the loop does not exist
// Case 1 (Complete Circular) : Approach 1 (Basic Force) : Start traversing from the head node -> Continue moving to next nodes -> If during traversal we reach NULL → the list is NOT circular -> If we reach the head node again → the list is circular.
//                                                       : TC = O(n) & SC = O(1).
//                            : Approach 2 (Optimal) : If a tail pointer is available, directly check : tail->next == head? If true → the list is circular. If false → the list is not circular.
//                                                   : TC = O(1) & SC = O(1)
// Case 2 (Incomplete Circular) : Approch 1 (Basic Brute Force) : (Hashing) Use a unordered map/set to store the visited nodes while traversing, and if at any node you traversed and is marked true in the map, its a circular loop (you can check for complete circular & incomplete circular later on) otherwise if you reached NULL, means no circular loop.
//                                                              : TC = O(n) && SC = O(n)
//                              : Approach 2 (Optimal) : Take two pointers fast which moves two times & slow which moves one time, Traverse the list until fast reaches the end of the list or tail of the list.
//                                                     : Now, finally if fast == slow, means the circular nature exists otherwise no!
//                                                     : Why this works : Let L = distance from head to start of cycle, C = length of cycle, After entering the cycle, if slow moved "t" distance, then fast has moved "2t" distance.
//                                                                      : And inside the loop, the distance moved will be "mod C", now means slow position : (t-L) % C and fast position : (2t-L) % C.
//                                                                      : Now, the meeting condition will be (t-L) % C = (2t-L) % C - which gives us t = 0 or can be interpreted as "t = kC"
//                                                                      : "t = kC" means two things - Slow has completed full cycles & Fast has gained exactly one full lap over slow. That is why they meet!
//                                                     : Intuition : If two cyclist are running on a same track, one with a "t" speed and one with a "2t" speed, they will obviously meet, this is the logic used to check whether the loop exists or not!
bool checkCircular(Node* head) { // Only for complete circle
    if(head == NULL || head->next == NULL) return false;

    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        if(temp == head) return true;
    }
    return false;
}

bool detectLoop(Node* head) {
    if(head == NULL || head->next == NULL) return false;

    unordered_set<Node*> visited;
    Node* temp = head;

    while(temp != NULL) {
        if(visited.find(temp) != visited.end()) {
            return true;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool detectLoop2(Node* head) {
    if(head == NULL || head->next == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        if(fast == slow) return true;
    }
    return false;
}

// ------------------------------------------------------- Question 5 : Finding the starting node of the Loop inside the List ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers"
// Approach, Techniques & Sub-Patterns : "Fast Slow Pointer" + "Hashing"
// Difficulty : Easy
// Understand the Problem : Now to actually find the starting node of the loop of the list, for that first we need to check whether the loop exist or not! 
//                        : Now, after confirming the list exists, then we need to find the starting node, where this loop actually starts.
//                        : This problem is more of a mathematical problem than a Linked List problem or any data structure problem.
// Edge case : Empty list
//           : Single node in the list (Not too neccessary)
//           : Handle fast correctly, as it will go NULL earlier if the loop does not exist
// Approach 1 (Brute Force) : (Hashing) Use a unordered set, store every node address you visit, and then keep traversing and whenever you find that the node you are visiting is also present in the set, means that is a starting point.
//                          : Here, we can use a ordered/un-ordered map or ordered set too, its just that as we do not have any concern with the order of the nodes getting stored in the map or set, that is why we can use unordered set/map!
//                          : TC = O(n) && SC = O(n)
// Approach 2 (Optimal) : We first the intersection of the two nodes using the previous method, now we initiate a node at the starting of the list, and another from the intersection point, and simply traverse them one step at a time. And when the eventually meet, that will be the starting node.
//                      : Mathematics proves it : Lets mark some distances : L (From starting of the list to starting of the cycle), C (Length of the cycle), x (distance moved by slow pointer from starting of loop to intersection point) & y (distance between point of intersection & starting of the cycle).
//                                              : From the above markings, we can say that - slow moved : L + x distance
//                                                                                         - fast moved : 2(L + x) distance
//                                                                                         - Now, we understand that fast has completed a full laps in the cycle by the the time it meets slow, which means : 2(L + x) = L + x + nC
//                                                                                         - Now, we can simplify to also interpret that, L + x = nC, which can be rearrange to interpret it : L = nC - x and this can be easily interpreted as : L = y, that is why this algorithm works here!
//                      : Intuition : At this point, its fine to getting intuition about why it works, but for now just understand the mathematics and approach it uses, as maths can never be wrong, it can only be interpreted wrong. Will figure out the intuition later on.
//                      : TC = O(n) && SC = O(1)
Node* getIntersection(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    unordered_set<Node*> visited;
    Node* temp = head;

    while(temp != NULL) {
        if(visited.find(temp) != visited.end()) {
            return temp;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    return NULL;
}

Node* getIntersection2(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        if(fast == slow) return slow;
    }
    return NULL;
}

Node* getStartingNode(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* intersection = getIntersection2(head);
    Node* temp = head;

    while(temp != intersection) {
        temp = temp->next;
        if(intersection != NULL) intersection = intersection->next; // Need to check firth that whether the intersection is NULL, otherwise NULL->next does not makes sense
    }
    return temp; // or intersection
}

// ------------------------------------------------------- Question 6 : Remove the Loop! ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers"
// Approach, Techniques & Sub-Patterns : "Fast Slow Pointer" + "Hashing"
// Understand the Problem : Problem is simple, just remove the loop whether complete loop or internal loop!
// Difficulty : Easy
// Edge case : Empty list
//           : Single node (Not too neccessary)
// Approach 1 (Brute Force) : (Hashing) You can simply traverse the list, using two pointers prev and curr, by maintaining a hash of visited nodes, the moment your curr pointer reaches the repeated node, you can simply adjust the pointer of the prev node to NULL. Can do it with single pointer too, but use two just for convenience.
//                          : TC = O(n) && SC = O(n)
// Approach 2 : Simply first detect loop, and then get the starting point, and just reach just before starting point and point that node to NULL - Works for both complete loop or internal loop!
//            : TC = O(n) && SC = O(1)
Node* getIntersection2(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL) fast = fast->next;

        if(fast == slow) return slow;
    }
    return NULL;
}

Node* getStartingNode(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;
    
    Node* intersection = getIntersection2(head);
    Node* temp = head;
    
    while(temp != intersection) {
        temp = temp->next;
        if(intersection != NULL) intersection = intersection->next;
    }
    return temp;
}

void removeLoop(Node* &head) {
    if(head == NULL || head->next == NULL) {
        cout<<"No Loop Exist!";
        return;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    unordered_set<Node*> visited;

    while(curr != NULL) {
        if(visited.find(curr) != visited.end()) {
            prev->next = NULL;
            return;
        }
        visited.insert(curr);
        prev = curr;
        curr = curr->next;
    }
    return;
}

void removeLoop2(Node* &head) {
    if(head == NULL || head->next == NULL) {
        cout<<"No Loop Exist!";
        return;
    }
    
    Node* startingNode = getStartingNode(head);
    if(startingNode == NULL) return;
    
    Node* temp = startingNode;
    
    while(temp->next != startingNode) {
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}

// ------------------------------------------------------- Question 7 : Remove duplicates from a Linked List - Sorted ------------------------------------------------------------------------>
// Pattern Recognition : "Traversal & Basic Manipulation"
// Approach, Techniques & Sub-Patterns : "Pointer Manipulation" + "Adjacent Comparision" + "Pointer Skipping"
// Understand the problem : You are given the head of a sorted singly linked list where elements are arranged in non-decreasing order. Remove all duplicate elements such that each value appears only once, and return the modified linked list.
//                        : Since the list is sorted, duplicate values will always appear consecutively (adjacent to each other), which allows local comparison between nodes.
// Difficulty : Easy
// Edge case : Empty list
//           : Single Node
// Approach 1 (Brute Force) : Traverse the linked list and insert each node’s value into a set (to keep only unique elements).
//                          : Then, create a new linked list using the values stored in the set.
//                          : TC = O(n) && SC = O(n)
// Approach 2 (Another Brute Force) : For every node, traverse the remaining list and remove all nodes having the same value. This uses a nested loop structure to eliminate duplicates.
//                                  : TC = O(n^2) && SC = O(1)
// Approach 3 (Optimal) : The most optimal approach comes from identifying the right pattern and leveraging the given constraints or properties of the problem to reduce time and space complexity.
//                      : Since the list is sorted, duplicate elements appear consecutively. Traverse the list and compare each node with its next node.
//                      : If they are equal, skip the duplicate node by adjusting pointers. Otherwise, move forward.
//                      : TC = O(n) && SC = O(1)
Node* deleteDuplicates(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    set<int> st;
    Node* temp = head;
    while(temp != NULL) {
        st.insert(temp->data);
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

Node* deleteDuplicates2(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* lastUnique = head;

    while(lastUnique != NULL) {
        Node* prev = lastUnique;
        Node* curr = lastUnique->next;
        while(curr != NULL) {
            if(prev->data == curr->data) {
                Node* ntd = curr;
                prev->next = curr->next;
                curr = curr->next;
                ntd->next = NULL;
                delete ntd;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        lastUnique = lastUnique->next;
    }
    return head;
}

Node* deleteDuplicates(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* lastUnique = head;
    Node* curr = head->next;

    while(curr != NULL) {
        if(lastUnique->data == curr->data) {
            curr = curr->next;
        }
        else {
            lastUnique->next = curr;
            lastUnique = curr;
            curr = curr->next;
        }
    }
    lastUnique->next = NULL;
    return head;
}

// ------------------------------------------------------- Question 8 : Remove duplicates from a Linked List - UnSorted ------------------------------------------------------------------------>
// Pattern Recognition : "Traversal & Basic Manipulation"
// Approach, Techniques & Sub-Patterns : "Pointer Manipulation" + "Hashing"
// Understand the problem : You are given the head of an unsorted singly linked list.
//                        : Remove all duplicate nodes such that only the first occurrence of each value is retained, and return the modified linked list.
//                        : Since the list is not sorted, duplicate values may appear at any position, so duplicates cannot be detected using only local comparisons.
// Difficulty : Medium
// Edge case : Empty list
//           : Single Node
// Approach 1 (Brute Force) : When dealing with an unsorted linear structure (like a linked list or array), and no additional constraints or extra space are used, a common brute force approach is to use a nested traversal.
//                          : For each node, we traverse the remaining list and remove all nodes that have the same value as the current node. This ensures that only the first occurrence of each element is retained.
//                          : TC = O(n^2) && SC = O(1)
// Approach 2 (Better Brute Force) : Since the list is unsorted, we can first sort the linked list using an efficient sorting algorithm (like Merge Sort for linked lists).
//                                 : Once the list becomes sorted, all duplicate elements will be adjacent, allowing us to remove them using a simple linear traversal (as in the sorted case).
//                                 : When a problem becomes easier on sorted data, we can first sort the data to exploit that structure and then apply a simpler linear solution
//                                 : TC = O(nlogn) && SC = O(1) / O(logn) - recursive stack
// Approach 3 (Optimized Solution) : Now, if take some extra space to reduce some time taken, that can be a possible trade of which we can do to optimize the final outcome!
//                                 : We can use a set, to input the data inton the list every time we traverse the list and eventually delete the nodes which getting repeated after they are first time inserted into the set.
Node* deleteDuplicatesUnsorted(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* temp1 = head;

    while(temp1->next != NULL) {
        Node* temp2 = temp1->next;
        while(temp2 != NULL) {
            
        }
    }
}


// Here the nested approach will still work! As the nested loop does not care for any sorted structure!
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