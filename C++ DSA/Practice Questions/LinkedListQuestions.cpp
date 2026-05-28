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

// Approach 1 :
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

// Approach 2 : 
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

// Approach 3 :
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

// Approach 1 : 
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

// Approach 2 : 
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

// Approach 1 :
Node* reverseLL(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    Node* dummyNode = new Node(INT_MIN);
    dummyNode->next = head;
    Node* prevGroupEnd = dummyNode;

    while(true) {
        // Another possible condition : "while(prevGroupEnd != NULL && prevGroupEnd->next != NULL)"
        // We can also use while(true) here because the actual stopping condition is whether a complete group of k nodes exists,and that logic is determined inside the loop itself.
        // So the choice mainly depends on coding style and readability. Using while(true) often makes the algorithm cleaner and more, natural to express, but using an explicit loop condition is also completely fine if written correctly.
        Node* kth = prevGroupEnd->next;
        Node* currGroupStart = prevGroupEnd->next;
        int count = 1;

        while(count < k && kth != NULL) {
            // count == K && kth == NULL - Possible condition! "less number of nodes than k"
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

// Approach 2 :
Node* reverseRecursion(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    int count = 1;
    Node* temp = head;
    while(count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) return head; // if you write "break;" here, it will cause compile time error, as break statement can be used only in 3 cases : Inside a Loop, Inside Switch statements & Inside if-else block if if-else block itself is inside a loop or a switch statement.

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

// Case 1 : Approach 1 : 
bool checkCircular(Node* head) { // Only for complete circle
    if(head == NULL || head->next == NULL) return false;

    Node* temp = head;

    while(temp != NULL) {
        temp = temp->next;
        if(temp == head) return true;
    }
    return false;
}

// Case 2 : Approach 1 : 
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

// Case 2 : Approach 2 : 
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
// Approach 2 (Optimal) : We first find the intersection of the two nodes using the previous method, now we initiate a node at the starting of the list, and another from the intersection point, and simply traverse them one step at a time. And when the eventually meet, that will be the starting node.
//                      : Mathematics proves it : Lets mark some distances : L (From starting of the list to starting of the cycle), C (Length of the cycle), x (distance moved by slow pointer from starting of loop to intersection point) & y (distance between point of intersection & starting of the cycle).
//                                              : From the above markings, we can say that - slow moved : L + x distance
//                                                                                         - fast moved : 2(L + x) distance
//                                                                                         - Now, we understand that fast has completed a full laps in the cycle by the the time it meets slow, which means : 2(L + x) = L + x + nC
//                                                                                         - Now, we can simplify to also interpret that, L + x = nC, which can be rearrange to interpret it : L = nC - x and this can be easily interpreted as : L = y, that is why this algorithm works here!
//                      : Intuition : At this point, its fine to getting intuition about why it works, but for now just understand the mathematics and approach it uses, as maths can never be wrong, it can only be interpreted wrong. Will figure out the intuition later on.
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
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

// Approach 2 :
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

// Approach 1 :
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

// Approach 2 :
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

// Approach 1 :
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

// Approach 2 :
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

// Approach 1 :
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
//                                 : TC = O(n) && SC = O(n)

// Approach 1 :
Node* deleteDuplicatesUnsorted(Node* &head) {
    if(head == NULL || head->next == NULL) return head;

    Node* temp1 = head;
    while(temp1 != NULL) {
        Node* temp2 = temp1;
        while(temp2->next != NULL) {
            if(temp1->data == temp2->next->data) {
                temp2->next = temp2->next->next;
            }
            else {
                temp2 = temp2->next; // Earlier I have kept it without else, but that is wrong, as it will update the temp2 always which might end up skipping the actual duplicate nodes for the case when you are having adjacent duplicate nodes!
            }
        }
        temp1 = temp1->next;
    }
    return head;
}

// Approach 3 :
Node* deleteDuplicatesUnsorted2(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    unordered_set<int> st;
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL) {
        if(st.find(curr->data) != st.end()) {
            prev->next = curr->next;
        }
        else {
            st.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

// ------------------------------------------------------- Question 9 : Sort 0s 1s 2s in Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Dummy Node"
// Approach, Techniques & Sub-Patterns : "Pointer Manipulation"
// Understand the problem : You are given the head of a singly linked list where each node contains a value of either 0, 1, or 2. Rearrange the nodes of the linked list such that all nodes with value 0 come first, followed by nodes with value 1, and then nodes with value 2.
//                        : The relative order within each group does not necessarily need to be preserved, but the final list should be grouped by values in sorted order.
//                        : Since the list contains only a limited set of distinct values (0, 1, 2), the problem can be approached by grouping or counting elements instead of applying a general sorting algorithm.
// Difficulty : Medium
// Edge case : Empty list
//           : Single Node 
// Approach 1 (Brute Force) : Sort the list, with some sorting algorithms like merge sort.
//                          : TC = O(nlogn) && SC = O(n)
// Approach 2 (Brute Force) : Count all 0s, 1s, 2s and simply traverse the original list and over write the values.
//                          : TC = O(n) && SC = O(1)
// Approach 3 (Optimal) : Traverse the linked list and create three separate lists using dummy nodes: one for nodes with value 0, one for 1, and one for 2.
//                      : For each node, append it to the corresponding list based on its value. After traversal, connect the three lists in order (0s → 1s → 2s) to form the final sorted list.
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
Node* sort012A(Node* &head) {
    if(head == NULL || head->next == NULL) return head;
    
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else count2++;
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL) {
        if(count0) {
            temp->data = 0;
            count0--;
        }
        else if(count1) {
            temp->data = 1;
            count1--;
        }
        else {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

// Approach 2 :
Node* sort012A(Node* &head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
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
        oneTail->next = twoHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// ------------------------------------------------------- Question 10 : Merge Two Linked Lists ------------------------------------------------------------------------>
// Pattern Recognition : "Dummy Node" + "Two Pointers"
// Approach, Techniques & Sub-Patterns : "Pointer Manipulation" 
// Understand the problem : You are given the heads of two singly linked lists. Your task is to merge them into a single linked list such that the resulting list maintains a meaningful order based on the input conditions.
//                        : The nature of merging depends on the structure of the given lists : Case 1 : If both linked lists are sorted, then the goal is to merge them into a single sorted linked list by comparing elements and placing them in order.
//                                                                                            : Case 2 : If the lists are unsorted, then there is no inherent order to preserve, so merging can simply mean appending one list to another, or optionally sorting afterward if required.
//                                                                                            : Case 3 : If one list is sorted and the other is not, then to merge in ascending order, we either have two choices : 1) Insert every node of the unsorted list in between the nodes of the sorted list.
//                                                                                                                                                                                                                : 2) Sort the unsorted list, and finally merge both the lists into one.
// Difficulty : Medium
// Edge case : Empty list
//           : Single Node
// Case 1 (Both Sorted) : Approach 1 : Use two pointers for both lists and iteratively compare nodes. Attach the smaller node to the result list and move the corresponding pointer forward, ensuring the merged list remains sorted.
//                                   : TC = O(n + m) && SC = O(1)
// Case 2 (Both Unsorted) : Approach 1 : Since there is no order to preserve, first append one list to the other, and then sort the combined list using an efficient linked list sorting algorithm (like merge sort).
//                                     : TC = O((n+m)log(n+m)) && SC = O(log(n+m))
//                        : Approach 2 : The problem with the approach 1 is that the time complexity can be reduced, if we sort the individual lists first and then merge them using two pointer approach. As the resultant time complexity will be : O(n log n + m log m) which is < O((n + m) log(n + m))
//                                     : TC = O(nlogn + mlogm) && SC = O(1)
// Case 3 (One Sorted & One Unsorted) : Approach 1 : Traverse the unsorted list, and for each node, insert it into the correct position in the sorted list.
//                                                 : TC = O(n*m) && SC = O(1)
//                                    : Approach 2 : First sort the unsorted list, then apply the standard merge two sorted lists approach.
//                                                 : TC = O(mlogm) && SC = O(logm)

// Case 1 : Approach 1 :
Node* mergeTwoLists1(Node* LL1, Node* LL2) {
    if(LL1 == NULL) return LL2;
    if(LL2 == NULL) return LL1;

    Node* dummyNode = new Node(INT_MIN);
    Node* temp = dummyNode;

    while(LL1 != NULL && LL2 != NULL) {
        if(LL1->data <= LL2->data) {
            temp->next = LL1;
            temp = LL1;
            LL1 = LL1->next;
        }
        else {
            temp->next = LL2;
            temp = LL2;
            LL2 = LL2->next;
        }
    }

    if(LL1 != NULL) temp->next = LL1;
    if(LL2 != NULL) temp->next = LL2;

    return dummyNode->next;
}

// Case 3 : Approach 1 :
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

// ------------------------------------------------------- Question 11 : Check palindrome in a Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "In-place Reversal" + "Two Pointers"
// Difficulty : Medium
// Understand the problem : Given the head of a singly linked list, determine whether the linked list represents a palindrome sequence. A palindrome is a sequence that reads the same forward and backward.
//                        : Return true if the linked list is a palindrome, otherwise return false.
//                        : Actual problem : In linked list we do not have indexed based access, also its a singly linked list we are talking about where we cannot traverse the list backwards.
//                                         : Also we do not know the length of the linked list, also we have to solve this in O(1) space complexity
// Approach 1 (Brute force) : Traverse the linked list and store all node values in an auxiliary data structure (such as an array or vector). Then, use a two-pointer technique on this structure to check whether the sequence is a palindrome.
//                          : TC = O(n) && SC = O(n)
// Approach 2 (Optimal) : Use the fast and slow pointer technique to find the middle of the linked list. Then, reverse the second half of the list in-place. After that, compare the first half and the reversed second half node by node.
//                      : Finally, restore the list to its original structure before returning the result.
//                      : TC = O(n) && SC = O(1)

// Approach 2 :
Node* reverseLLs(Node* head) {
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

bool checkPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) return true;
    
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* newHead = slow->next;
    slow->next = NULL;
    
    Node* revHead = reverseLLs(newHead);
    
    Node* temp1 = head;
    Node* temp2 = revHead;
    bool isPalindrome = true;
    
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data != temp2->data) {
            isPalindrome = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    slow->next = reverseLLs(revHead);
    return isPalindrome;
}

// ------------------------------------------------------- Question 12 : Add Two Number as Linked Lists ------------------------------------------------------------------------>
// Pattern Recognition : "Traversal & Basic Manipulation"
// Difficulty : Medium
// Understand the problem : You are given two non-empty singly linked lists representing two non-negative integers. Add the two numbers and return the sum as a linked list.
//                        : The actual problem : No indexed based access, need a proper and careful carry handling across nodes, its not a full number, the digits of the number are spread across the nodes.
//                                             : Need to build a new linked list dynamically on the basis of the sum between each nodes.
//                                             : Also, need to manage the unequal linked list cases carefully.
// Approach 1 (Brute Force) : Convert the linked list into an array/vector, and then add the numbers there and then recreate a linked list using that final answer sum.
//                          : Finally, construct a new linked list from the computed result.
//                          : TC = O(n + m) && SC = O(n + m)
// Approach 2 (Optimal) : Traverse both linked lists simultaneously while maintaining a carry value initialized to 0. At each step, take the current node values (if present; otherwise treat as 0), add them along with the carry, and create a new node with the digit equal to sum % 10.
//                      : Update the carry as sum / 10 and move forward in both lists. After one list ends, continue processing the remaining list along with the carry.
//                      : If a carry remains after traversal, create an additional node for it. The result list is formed in the correct order during traversal, so no reversal is required.
//                      : TC = O(n + m) && SC = O(1) - Excluding the output list, as that was a requirement

// Approach 2 :
Node* reverseLLs(Node* head) {
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

void insertNode(Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(tail == NULL) {
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

Node* findSum(Node* LL1, Node* LL2) {
    if(LL1 == NULL) return LL2;
    if(LL2 == NULL) return LL1;
    
    Node* revLL1 = reverseLLs(LL1);
    Node* revLL2 = reverseLLs(LL2);
    
    int carry = 0;
    Node* temp1 = revLL1;
    Node* temp2 = revLL2;
    int sum = 0;

    Node* dummyHead = new Node(INT_MIN);
    Node* dummyTail = dummyHead;
    
    while(temp1 != NULL || temp2 != NULL || carry != 0) {
        int val1 = 0;
        int val2 = 0;
        
        if(temp1 != NULL) val1 = temp1->data;
        if(temp2 != NULL) val2 = temp2->data;
        
        sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        insertNode(dummyTail, digit);

        if(temp1 != NULL) temp1 = temp1->next;
        if(temp2 != NULL) temp2 = temp2->next;
    }
    
    Node* finalAns = reverseLLs(dummyHead->next);
    return finalAns;
}

// ------------------------------------------------------- Question 13 : Clone a linked list with Random Pointer ------------------------------------------------------------------------>
// Pattern Recognition : "Traversal & Basic Manipulation" + "Hashing" + "Inplace Interleaving"
// Difficulty : Medium
// Understand the problem : You are given the head of a singly linked list where each node contains : An integer value val, A pointer next to the next node in the list & A pointer random which can point to any node in the list or NULL.
//                        : Your task is to create a deep copy of this linked list.
//                        : The deep copy should consist of entirely new nodes such that : Each node in the new list has the same value as the corresponding node in the original list.
//                                                                                       : The next pointers form the same sequence as the original list.
//                                                                                       : The random pointers correctly point to the corresponding nodes in the new list (not the original list).
//                        : Primary challenges : How do we know which node the random pointer should point to in the new list?
//                                             : Cloning a graph-like structure where each node has both linear and arbitrary connections
// Approach 1 (Brute Force) : I need to create a deep copy where both next and random pointers are preserved.
//                          : Each node has : next & random pointers, so the problem becomes - How do I map an original node’s random pointer to the correct cloned node?
//                          : Thought process - We don’t have a direct mapping (like hashmap), But we notice that Clone list is built in the same order & which means the positions corresponds.
//                                            - So the idea is if I can find the position of the random node in original list, I can reach the same position in clone list.
//                          : Now for each node, we simulate a mapping by traversing both lists simultaneously to locate the corresponding random node.
//                          : TC = O(n^2) && SC = O(1)
// Approach 2 (Optimal Brute Force) : Key idea is, if I can directly map each original node to its cloned node, I can easily assign both next and random pointers.
//                                  : Overall, We first clone nodes, then use a hashmap to maintain a direct mapping from original nodes to cloned nodes, which allows us to assign random pointers in constant time.
//                                  : TC = O(n) && SC = O(n) due to hashmap
// Approach 3 (Optimal) : I need to map each original node to its cloned node, but I don’t want to use extra space (like a hashmap)
//                      : What if I place the cloned node right next to its original node?
//                      : We interleave cloned nodes within the original list to implicitly maintain mapping, use this structure to assign random pointers in O(1), and then separate both lists
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
Node* cloneRandom(Node* head) {
    if(head == NULL) return NULL;
    
    // Step 1 : Clone the original list, without random pointers
    Node* originalHead = head;
    Node* cloneHead = new Node(originalHead->data);
    Node* cloneTail = cloneHead;
    
    Node* temp = originalHead->next;
    while(temp != NULL) {
        Node* newNode = new Node(temp->data);
        cloneTail->next = newNode;
        cloneTail = newNode;
        temp = temp->next;
    }
    
    // Step 2 : Re-traverse the original to set the random pointers
    Node* original = originalHead;
    Node* clone = cloneHead;
    
    while(original != NULL) {
        if(original->random != NULL) {
            Node* tempOrg = original;
            Node* tempClone = clone;
            
            while(tempOrg != NULL && tempOrg != original->random) {
                tempOrg = tempOrg->next;
                tempClone = tempClone->next;
            }
            clone->random = tempClone;
        }
        original = original->next;
        clone = clone->next;
    }
    
    return cloneHead;
}

// Approach 2 :
Node* cloneRandom(Node* head) {
    if(head == NULL) return NULL;
    
    // Step 1 : Clone the original list, without random pointers
    Node* originalHead = head;
    Node* cloneHead = new Node(originalHead->data);
    Node* cloneTail = cloneHead;
    
    Node* tempOrg = originalHead->next;
    while(tempOrg != NULL) {
        Node* newNode = new Node(tempOrg->data);
        cloneTail->next = newNode;
        cloneTail = newNode;
        tempOrg = tempOrg->next;
    }
    
    // Step 2 : Map each node of the original list with the cloned list
    tempOrg = originalHead;
    Node* tempClone = cloneHead;
    unordered_map<Node*, Node*> hash;
    while(tempOrg != NULL) {
        hash[tempOrg] = tempClone;
        tempOrg = tempOrg->next;
        tempClone = tempClone->next;
    }
    
    // Step 3 : Finally traverse the cloned list & set the random pointers
    tempClone = cloneHead;
    tempOrg = originalHead;
    
    while(tempClone != NULL) {
        if(tempOrg->random != NULL) tempClone->random = hash[tempOrg->random];
        tempOrg = tempOrg->next;
        tempClone = tempClone->next;
    }
    
    return cloneHead;
}

// Approach 3 :
Node* cloneRandom(Node* head) {
    if(head == NULL) return NULL;
    
    // Step 1: Interleave clone nodes
    Node* curr = head;
    while(curr != NULL) {
        Node* next = curr->next;
        Node* clone = new Node(curr->data);

        curr->next = clone;
        clone->next = next;
        
        curr = next;
    }

    // Step 2: Set random pointers
    curr = head;
    while(curr != NULL) {
        if(curr->random != NULL)
        curr->next->random = curr->random->next;
    
    curr = curr->next->next;
}

// Step 3: Separate lists
curr = head;
Node* cloneHead = head->next;

while(curr != NULL) {
    Node* clone = curr->next;
    curr->next = clone->next;
    
    if(clone->next != NULL)
    clone->next = clone->next->next;

curr = curr->next;
}

return cloneHead;
}

// ------------------------------------------------------- Question 14 : Merge Sort in Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Divide, Merge & Structural Transformation" & "Two Pointers"
// Difficulty : Medium
// Understand the problem : You are given the head of a singly linked list containing n nodes. Each node contains an integer value.
//                        : Your task is to sort the linked list in ascending order using the merge sort algorithm and return the head of the sorted linked list.
// Approach 1 (Brute Force) : Take each element and put them into an array and then sort the array by any means of sorting , Whether Bubble sort, Insertion Sort, Selecction Sort, Merge Sort or Quick Sort. And finally rewrite the original list itself and return the head.
//                          : TC = O(nlogn)/O(n^2) && SC = O(n) 
// Approach 2 (Merge Sort) : When deciding which sorting algorithm to use for a linked list, the key is to understand the constraints of the data structure.
//                         : Limitations : Do not support random access (no indexing like arr[i])
//                                       : Require sequential traversal (node by node)
//                                       : Make swapping nodes costly, since it involves pointer manipulation rather than simple value swaps
//                         : Problems with other sorting algorithms : Bubble Sort - In arrays → swapping is easy, but in linked lists → swapping requires changing pointers → messy and inefficient.
//                                                                  : Insertion Sort / Selection Sort - Require frequent repositioning of elements. In linked lists → involves complex pointer updates
//                                                                  : Quick sort - Works well on arrays due to direct index access. In linked lists : No random access → partitioning becomes inefficient & Pointer manipulation becomes complex.
//                         : How merge sort fits best : Merge Sort aligns perfectly with linked list properties - Does not require random access, Splitting is easy using slow & fast pointer, Merging can be done efficiently using pointer manipulation (no swapping needed), Guaranteed O(n log n) time complexity & Stable and clean to implement.
//                         : Thinking : Problem is we are given an unsorted linked list, and we need to sort it efficiently.
//                                    : Use the slow and fast pointer technique to find the middle node. Split the list into two halves : Left half → from head to mid
//                                                                                                                                      : Right half → from mid->next to end
//                                                                                                                                      : Then break the link : mid->next = NULL;
//                                    : Apply the same process on both halves. Keep dividing until : Each sublist contains only one node.
//                                    : Now, Start merging starts during recursion backtracking, not specifically at “two nodes” .
//                                    : Now, as recursion returns : You start merging two sorted linked lists, Use the standard merge two sorted lists approach.
//                                    : And during the backtracking, in the end the whole list is sorted.
//                         : TC = O(nlogn) && SC = O(nlogn)
Node* middleNode(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL || fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node* mergeList(Node* left, Node* right) {
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    Node* temp1 = left;
    Node* temp2 = right;
    
    Node* dummyHead = new Node(-1);
    Node* dummyTail = dummyHead;
    
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data <= temp2->data) {
            dummyTail->next = temp1;
            dummyTail = temp1;
            temp1 = temp1->next;
        }
        else {
            dummyTail->next = temp2;
            dummyTail = temp2;
            temp2 = temp2->next;
        }
    }

    if(temp1 == NULL) dummyTail->next = temp2;
    if(temp2 == NULL) dummyTail->next = temp1;
    
    return dummyHead->next;
}

Node* sortList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    Node* mid = middleNode(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    
    left = sortList(left);
    right = sortList(right);
    
    return mergeList(left, right);
}

// ------------------------------------------------------- Question 15 : Flattening a Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Divide, Merge & Structural Transformation" & "Two Pointers"
// Difficulty : Hard
// Understand the problem : You are given a linked list where each node has two pointers : next → points to the next node in the main list & down → points to a sorted linked list.
//                        : Each down list is sorted in ascending order.
//                        : Let, N = total number of nodes & k = number of lists
// Approach 1 (Basic Brute Force) : When the linked list structure is complex to manipulate directly, we can simplify the problem by using an auxiliary data structure like an array.
//                                : Traverse the entire linked list (including all down chains) -> Store all node values into an array -> Sort the array using an efficient sorting algorithm -> Reconstruct a new flattened linked list from the sorted values.
//                                : TC = O(nlogn) && SC = O(n)
// Approach 2 (Brute Force) : To flatten the linked list, we treat each vertical (down) chain as an individual sorted list and merge them one by one.
//                          : Idea : We maintain three pointers : prev : represents the current merged list.
//                                                              : curr : represents the next list to be merged
//                                                              : forward : keeps track of the remaining lists
//                          : Initialize prev = head & curr = head->next,
//                          : Iterate while curr != NULL & Store next list with forward = curr->next;
//                          : Merge prev and curr using the merge of two sorted linked lists (via down pointers)
//                          : Update pointers : prev = mergedHead → new merged list & curr = forward → move to next list
//                                            : Continue until all lists are merged.
//                          : Finally : prev will point to the fully flattened and sorted list
//                          : TC = O(n*k) && SC = O(1)
// Approach 2.2 (Brute Force - Striver) : Whatever we have done earlier, will do this time using recursion, and will start merging from the end.
//                                      : TC = O(n*k) && SC = O(1)
// Approach 3 (Optimal Approach) : Instead of merging lists one by one, split the problem into smaller parts → solve → merge results.
//                               : If we merge sequentially like in the above two approaches, one list keeps growing & Repeated work.
//                               : Algorithmic flow will be : Find middle of list -> Split into 2 halves -> Recursively flatten both halves -> Merge both sorted lists
//                               : TC = O(Nlogk) && SC = O(log k) due to recursion call stack

// Approach 2 :
Node* mergeList(Node* l1, Node* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    Node* temp1 = l1;
    Node* temp2 = l2;
    
    Node* dummyHead = new Node(-1);
    Node* dummyTail = dummyHead;
    
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data <= temp2->data) {
            temp1->next = NULL;
            dummyTail->down = temp1;
            dummyTail = temp1;
            temp1 = temp1->down;
        }
        else {
            temp2->next = NULL;
            dummyTail->down = temp2;
            dummyTail = temp2;
            temp2 = temp2->down;
        }
    }
    
    if(temp1 == NULL) dummyTail->down = temp2;
    if(temp2 == NULL) dummyTail->down = temp1;
    
    return dummyHead->down;
}

Node* flattenList(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* prev = head;
    Node* curr = head->next;
    Node* forward = NULL;
    
    while(curr != NULL) {
        forward = curr->next;
        Node* temp1 = prev;
        Node* temp2 = curr;
        
        Node* mergedHead = mergeList(temp1, temp2);
        prev = mergedHead;
        curr = forward;
    }
    
    return prev;
}

// Approach 2.2 :
Node* mergeList(Node* LL1, Node* LL2) {
    if (LL1 == NULL) return LL2;
    if (LL2 == NULL) return LL1;
    
    Node* dummyNode = new Node(-1);
    Node* result = dummyNode;
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

Node* flattenList(Node* head) {
    if (head == NULL || head->next == NULL)
    return head;

    Node* mergeHead = flatten(head->next);
    return mergeList(head, mergeHead);
}

// Approach 3 : 
Node* mergeList(Node* l1, Node* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    
    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            tail->down = l1;
            l1 = l1->down;
        } else {
            tail->down = l2;
            l2 = l2->down;
        }
        tail = tail->down;
        tail->next = NULL; // IMPORTANT: break horizontal links
    }
    
    if(l1) tail->down = l1;
    if(l2) tail->down = l2;
    
    return dummy->down;
}

Node* flattenList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    // Step 1: Split into two halves
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* second = slow->next;
    slow->next = NULL; // break into two halves
    
    // Step 2: Recursively flatten both halves
    Node* left = flattenList(head);
    Node* right = flattenList(second);
    
    // Step 3: Merge both sorted lists
    return mergeList(left, right);
}

// ------------------------------------------------------- Question 16 : Intersection of Two Linked Lists ------------------------------------------------------------------------>\
// Pattern Recognition : "Two Pointer"
// Difficulty : Medium
// Understand the problem : You are given the heads of two singly linked lists, headA and headB.
//                        : Return the node at which the two lists intersect. If the two linked lists have no intersection, return NULL.
//                        : Important Conditions : Intersection is based on reference, not value
//                                               : The lists may have different lengths
//                                               : After intersection point, both lists share the same tail
// Approach 1 (Brute Force) : Store all nodes of the first linked list in a hash-based data structure.
//                          : Then traverse the second list and check : Have I already seen this node? -> The first common node encountered is the intersection point.
//                          : TC = O(n + m) && SC = O(n);
// Approach 2 (Optimal) : Idea is, If two linked lists have different lengths, the longer list has extra nodes at the beginning.
//                      : Remove this extra part so that both lists become equal in remaining length. Then traverse both together — the first common node is the intersection.
//                      : TC = O(n + m) && SC = O(1)

// Approach 1 :
Node* intersectionOfLists(Node* headA, Node* headB) {
    if(headA == NULL || headB == NULL) return NULL;

    Node* temp = headA;
    unordered_map<Node*, bool> visited; // Can also use unordered set.

    while(temp != NULL) {
        visited[temp] = true;
        temp = temp->next;
    }

    temp = headB;
    while(temp != NULL) {
        if(visited[temp]) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Approach 2 :
int getLen(Node* head) {
    if(head == NULL) return 0;

    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* intersectionOfLists(Node* headA, Node* headB) {
    if(headA == NULL || headB == NULL) return NULL;

    int len1 = getLen(headA);
    int len2 = getLen(headB);

    if(len1 < len2) {
        int diff = len2 - len1;
        Node* temp = headB;
        while(diff--) {
            headB = headB->next;
        }
    }
    else {
        int diff = len1 - len2;
        Node* temp = headA;
        while(diff--) {
            headA = headA->next;
        }
    }

    Node* temp1 = headA;
    Node* temp2 = headB;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1 == temp2) {
            return temp1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

// ------------------------------------------------------- Question 17 : Rotate a Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Structural Transformation"
// Difficulty : Medium
// Understand the problem : You are given a singly linked list, You need to rotate it to the right by k positions.
//                        : Last k nodes will come to the front, Order of nodes must remain same & Large k values → repetitive rotations → optimize using modulo.
// Approach 1 (Brute Force) : Rotate the list one step at a time, k times. Repeat k times : Traverse to last node & Remove last node, Insert it at the front.
//                          : But inefficient for large k & Repeated traversal → unnecessary work.
//                          : TC = O(n*k) && SC = O(1)
// Approach 2 (Optimal) : Convert list into a circle, then break it at correct point.
//                      : First find length n, and then normalize k
//                      : Make list circular : Last node → point to head, Find new head and Move (n - k) steps & Break the link and the new head becomes answer.
//                      : TC = O(n) && SC = O(1).

// Approach 1 :
int getLen(Node* head) {
    if(head == NULL) return 0;

    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* rotateRight(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    int n = getLen(head);
    k = k % n; // To normalise large values of K

    while(k--) {
        Node* prev = NULL;
        Node* curr = head;
        while(curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        curr->next = head;
        prev->next = NULL;
        head = curr;
    }

    return head;
}

// Approach 2 : 
int getLen(Node* head) {
    if(head == NULL) return 0;

    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* rotateRight(Node* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    int n = getLen(head);
    k = k % n; // To normalise large values of K

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    Node* prev = NULL;
    Node* curr = head;
    int steps = n - k;

    while(steps > 0) {
        prev = curr;
        curr = curr->next;
        steps--;
    }

    head = curr;
    prev->next = NULL;

    return head;
}

// ------------------------------------------------------- Question 18 : Delete all occurrences of a key in DLL ------------------------------------------------------------------------>
// Pattern Recognition : 
// Difficulty : Medium
// Understand the problem : You are given the head of a doubly linked list (DLL) and an integer key. Delete all nodes in the list whose value is equal to key, and return the updated head of the list.
//                        : The deletion must be done in-place, maintaining the integrity of both next and prev pointers.
//                        : Idea : This list can be - Sorted → all occurrences of key will be adjacent & Unsorted → occurrences can be anywhere.
//                               : In both cases, after deletion - The list should remain valid, No broken links (prev / next) & Head may change.
// Okay so that thing, is the DLL can be sorted or unsorted! Now, if the list is sorted we can solve it simply by traversing the list and finding the key value, if it exists? then all the keys will be adjacenet to each other and we cab simply pass them all at once! And now, as the list is sorted, means once the node value surpasses the key value, we can simply break it and tell the key does nto exist!
//                        : Another, for the unsorted list, we can simply traverse the list using two pointers, prev and curr, everytime we are having a curr value equals to key value, we can simply remove that from the list! and adjust the pointers
// Approach 1 (Brute Force) : Keep searching for the key repeatedly and delete one occurrence at a time.
//                          : Traverse the list to find a node with value = key → delete it → restart traversal again from head → repeat until no key is found.
//                          : TC = O(n^2) && SC = O(1)
// Approach 2 (Optimal) : Traverse the list once and delete nodes on the go using DLL properties.
//                      : Move a pointer curr from head to end - If curr->data == key : Update links - If curr->prev exists → connect it to curr->next
//                                                                                                   - If curr->next exists → connect it to curr->prev
//                                                             - If curr is head → move head forward, Move to next node safely.
//                      : TC = O(n) && SC = O(1)
// Approach 2.2 (Optimal - Special Case) : For sorted DLL - If the list is sorted : Once curr->data > key → you can stop early & Slight optimization, but worst case still O(n)
//                                       : TC = O(n) && SC = O(1)

// Approach 2 :
Node* deleteAllOccurence(Node* head, int key) { // Unsorted
    if(head == NULL) return NULL;

    Node* temp = head;
    while(temp != NULL) {
        Node* nextNode = temp->next;

        if(temp->data == key) {
            if(temp->prev == NULL) {
                head = head->next; // Optionally can : head = temp->next; - More consistent logic, as we are already deleting temp (ChatGPT recommended)
                if(head != NULL) head->prev = NULL;
            }
            else {
                temp->prev->next = temp->next;
                if(temp->next != NULL) temp->next->prev = temp->prev;
            }
            delete temp;
        }
        temp = nextNode;
    }
    return head;
}

// Approach 2.2 :
Node* deleteAllOccurence(Node* head, int key) { // Sorted
    if(head == NULL) return NULL;

    Node* temp = head;
    while(temp != NULL) {
        Node* nextNode = temp->next;

        if(temp->data == key) {
            if(temp->prev == NULL) {
                head = head->next; // Optionally can : head = temp->next; - More consistent logic, as we are already deleting temp (ChatGPT recommended)
                if(head != NULL) head->prev = NULL;
            }
            else {
                temp->prev->next = temp->next;
                if(temp->next != NULL) temp->next->prev = temp->prev;
            }
            delete temp;
        }
        else if(temp->data > key) {
            break;
        }
        temp = nextNode;
    }
    return head;
}

// ------------------------------------------------------- Question 19 : Find Pairs with Given Sum in Doubly Linked List - Sorted ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers"
// Difficulty :
// Understand the problem : Given a Doubly Linked List (DLL) and an integer target, find all unique pairs of nodes (a, b) such that a + b == target. Return the pairs as a list of {min, max} ordered tuples. Each node value may be used only once, and each pair should be reported only once.
// Approach 1 (Brute Force) : Case 1 (Sorted/Unsorted - +ve/-ve) : Traverse the list using a pointer (temp1) from head to end. For each node, use another pointer (temp2) starting from temp1->next.
//                                              : Check every pair: if (temp1->data + temp2->data == target), store the pair. Continue until all pairs are checked.
//                                              : TC = O(n^2) && SC = O(1)
//                          : Case 2 (Sorted - +ve) : Traverse list with temp1 from head. For each temp1, traverse temp2 = temp1->next. Calculate sum : If sum == target → store pair & If sum > target → break inner loop (since sorted). Then move temp1 forward and repeat.
//                                                  : TC = O(n^2) && SC = O(1)
// Approach 2 (Optimal) : Case 1 (Sorted/Unsorted - +ve/-ve) : Traverse the list once with a single pointer temp. For each node, check if (target - temp->data) already exists in the hash set. If yes → store the pair {target - temp->data, temp->data}. If no → insert temp->data into the set. Move temp forward and repeat until end.
//                                                           : TC = O(n) && SC = O(n)
//                      : Case 2 (Sorted - +ve) : Find the end node by traversing to the tail. Place start at head and end at tail. While start != end and end->next != start (to handle crossing): compute currSum = start->data + end->data. If currSum == target → store pair, move start forward & end backward. If currSum > target → move end backward. If currSum < target → move start forward.
//                                              : TC = O(n) && SC = O(1)

// Approach 1 :
// Case 1 : (Sorted/Unsorted - +ve/-ve)
vector<pair<int, int>> pairSum(Node* head, int sum) { // Unsorted
    if(head == NULL || head->next == NULL) {
        return {};
    }

    Node* temp1 = head;
    vector<pair<int, int>> ans;

    while(temp1->next != NULL) { // Can write : while(temp1 != NULL) for better consistency.
        Node* temp2 = temp1->next;
        int currSum = temp1->data + temp2->data;
        while(temp2 != NULL) {
            if(currSum == sum) {
                ans.push_back({min(temp1->data, temp2->data), max(temp1->data, temp2->data)});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}

// Approach 1 :
// Case 2 : (Sorted - +ve)
vector<pair<int, int>> pairSum(Node* head, int sum) { // Sorted & all positive
    if(head == NULL || head->next == NULL) {
        return {};
    }

    Node* temp1 = head;
    vector<pair<int, int>> ans;

    while(temp1->next != NULL) { // Can write : while(temp1 != NULL) for better consistency.
        Node* temp2 = temp1->next;
        int currSum = temp1->data + temp2->data;
        while(temp2 != NULL) {
            if(currSum == sum) {
                ans.push_back({min(temp1->data, temp2->data), max(temp1->data, temp2->data)});
            }
            else if(currSum > sum) {
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}

// Approach 2 :
// Case 1 : (Sorted/Unsorted - +ve/-ve)
vector<pair<int, int>> pairSum(Node* head, int sum) {
    if(head == NULL || head->next == NULL) {
        return {};
    }

    unordered_set<int> seen;
    vector<pair<int,int>> ans;

    Node* temp = head;

    while(temp != NULL) {
        int val = temp->data;
        int required = sum - val;

        if(seen.count(required)) {
            ans.push_back({min(val, required), max(val, required)});
        }

        seen.insert(val);
        temp = temp->next;
    }

    return ans;
}

// Approach 2 :
// Case 2 : (Sorted - +ve)
vector<pair<int, int>> pairSum(Node* head, int sum) {
    if(head == NULL || head->next == NULL) {
        return {};
    }

    Node* end = head;
    while(end->next != NULL) {
        end = end->next;
    }

    Node* start = head;
    vector<pair<int,int>> ans;
    while(start != end && start->prev != end) {
        int currSum = start->data + end->data;

        if(currSum == sum) {
            ans.push_back({min(start->data, end->data), max(start->data, end->data)});
            start = start->next;
            end = end->prev;
        }
        else if(currSum > sum) {
            end = end->prev;
        }
        else {
            start = start->next;
        }
    }

    return ans;
}

// ------------------------------------------------------- Question 20 : Remove duplicates from sorted DLL ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers" / "Hashing" + "Adjacent Comparions"
// Difficulty : Medium
// Understand the problem : Given the head of a sorted doubly linked list, remove all duplicate nodes such that each element appears only once. Return the head of the modified list.
// Approach 1 (Brute Force) : Since the list is sorted, duplicates are guaranteed to be neighbors. You only need to compare the current node with its direct successor.
//                          : Start at the head with a pointer (e.g., curr). and another pointer next to it inside a nested loop, and once you found a curr and curr->next value equal just readjust the pointer for next and previous nodes and move the inner pointer forward, and repeat it until all the nodes are deleted.
//                          : TC = O(n) && SC = O(1)
// Approach 2 (Brute Force with Extra Space) : Traverse the given DLL and store all values in a set (sorted set)
//                                           : And due to set, it automatically removed duplicates and also maintains the sorted order.
//                                           : TC = O(nlogn) && SC = O(n)
// Approach 3 (Optimal) : Core Idea - The DLL is already sorted, So duplicate values will always be adjacent, Compare each node with its next node & If equal → delete the next node.
//                      : Start from head using pointer curr, Traverse the list while curr and curr->next exist & at each step if curr->data == curr->next->data simply delete that next node and when not equal simply move the curr pointer forward. 
//                      : Key Observation : Do not move curr just after deletion, as it will cause you skip duplicate nodes too.
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
Node* removeDuplicateSortedDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp1 = head;
    while(temp1 != NULL) {
        Node* temp2 = temp1->next;
        while(temp2 != NULL) {
            if(temp1->data == temp2->data) {
                Node* ntd = temp2;
                if(temp2->next) temp2->next->prev = temp2->prev;
                temp2->prev->next = temp2->next;
                temp2 = temp2->next;
                ntd->next = ntd->prev = NULL;
                delete ntd;
            }
            else {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
    return head;
}

// Approach 2 :
void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL || tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return;
}

Node* removeDuplicateSortedDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    set<int> uniqueNodes;
    Node* temp = head;
    while(temp != NULL) {
        uniqueNodes.insert(temp->data);
        temp = temp->next;
    }

    Node* newHead = NULL;
    Node* newTail = NULL;
    for(int value : uniqueNodes) {
        insertNode(newHead, newTail, value);
    }

    return newHead;
}

// Approach 3 :
Node* removeDuplicateSortedDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL; // You can use it, or remove to helping alot, and then simply traverse with condition - while(curr != NULL && curr->next != NULL)
    Node* curr = head;
    while(curr->next != NULL) {
        if(curr->data == curr->next->data) {
            Node* ntd = curr->next;
            curr->next = ntd->next;
            if(ntd->next != NULL) ntd->next->prev = curr;
            ntd->next = ntd->prev = NULL;
            delete ntd;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

// ------------------------------------------------------- Question 21 : Remove duplicates from unsorted DLL ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers" / "Hashing"
// Difficulty : Medium
// Understand the problem : Given the head of an unsorted doubly linked list, remove all duplicate nodes such that only the first occurrence of each value is retained. Return the head of the modified list.
// Approach 1 (Brute Force) : Same as above
// Approach 2 (Optimal) : Traverse the list while maintaining a hash set of seen values. For each node, if its value already exists in the set, delete it by relinking its neighbors and freeing the memory.
//                      : Otherwise, insert its value into the set and move forward.
//                      : TC = O(n) && SC = O(n)

// Approach 2 :
Node* removeDuplicateUnsortedDLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;
    unordered_set<int> uniqueNodes;

    while(curr != NULL) {
        if(uniqueNodes.find(curr->data) != uniqueNodes.end()) { // Duplicates nodes
            Node* ntd = curr;
            curr = ntd->next;
            if(ntd->prev != NULL) ntd->prev->next = ntd->next;
            if(ntd->next != NULL) ntd->next->prev = ntd->prev;
            ntd->next = ntd->prev= NULL;
            delete ntd;
        }
        else {
            uniqueNodes.insert(curr->data);
            curr = curr->next;
        }
    }
    return head;
}

// ------------------------------------------------------- Question 22 : Segregate odd and even nodes in Linked List ------------------------------------------------------------------------>
// Pattern Recognition : "Dummy Node" + "Traversal & Basic Manipulation"
// Difficulty : Medium
// Understand the problem : Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
//                        : The first node is considered odd, and the second node is even, and so on. Note that the relative order inside both the even and odd groups should remain as it was in the input.
//                        : You must solve the problem in O(1) extra space complexity and O(n) time complexity.
// Approach 1 (Brute Force) : Store odd and even indexed elements separately, then rebuild the list.
//                          : Traverse the list with index (1-based), Store - Odd index values → odd list & Even index values → even list.
//                          : Create a new list - First add all odd values, Then add all even values.
//                          : TC = O(n) && SC = O(n)
// Approach 2 (Optimal) : Rearrange nodes by changing links without extra space.
//                      : Traverse the list - Separate nodes into one Odd list & Even list. While moving a node, save next node & break its old link (next = NULL)
//                      : Attach it to odd/even list, finally connect - oddTail → evenHead
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
Node* segregateOddEven(Node* head) {
    if(head == NULL) return NULL;

    vector<int> oddVector;
    vector<int> evenVector;

    Node* temp = head;
    int index = 1;

    while(temp != NULL) {
        if(index % 2 != 0) {
            oddVector.push_back(temp->data);
        }
        else {
            evenVector.push_back(temp->data);
        }
        temp = temp->next;
        index++;
    }

    Node* oddList = new Node(INT_MIN);
    Node* oddListTail = oddList;
    
    Node* evenList = new Node(INT_MIN);
    Node* evenListTail = evenList;

    for(int i = 0; i < oddVector.size(); i++) {
        Node* newNode = new Node(oddVector[i]);
        oddListTail->next = newNode;
        oddListTail = newNode;
    }
    for(int i = 0; i < evenVector.size(); i++) {
        Node* newNode = new Node(evenVector[i]);
        evenListTail->next = newNode;
        evenListTail = newNode;
    }

    oddListTail->next = evenList->next;
    return oddList->next;
}

// Approach 1 (Better Readability) :
Node* segregateOddEven(Node* head) {
    if(head == NULL) return NULL;

    vector<int> oddVector;
    vector<int> evenVector;

    Node* temp = head;
    int index = 1;

    while(temp != NULL) {
        if(index % 2 != 0) {
            oddVector.push_back(temp->data);
        } else {
            evenVector.push_back(temp->data);
        }
        temp = temp->next;
        index++; 
    }

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    for(int val : oddVector) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    for(int val : evenVector) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    return dummy->next;
}

// Approach 2 :
Node* segregateOddEven(Node* head) {
    if(head == NULL) return NULL;

    Node* oddHead = new Node(INT_MIN);
    Node* oddTail = oddHead;
    
    Node* evenHead = new Node(INT_MIN);
    Node* evenTail = evenHead;

    Node* temp = head;
    int index = 1;
    while(temp != NULL) {
        Node* nextNode = temp->next;
        temp->next = NULL;
        if(index % 2 != 0) {
            oddTail->next = temp;
            oddTail = temp;
        }
        else {
            evenTail->next = temp;
            evenTail = temp;
        }
        temp = nextNode;
        index++;
    }

    oddTail->next = evenHead->next;
    return oddHead->next;
}

// ------------------------------------------------------- Question 23 : Remove Nth node from the back of the LL ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers" - "Lagging Pointer"
// Difficulty : Medium
// Understand the problem : Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Approach 1 (Brute Force) : Find the length of the list and convert the problem into removing a node from a specific position from start.
//                          : Traverse the list → compute length, Calculate - steps = length - n. If steps == 0, delete head node. 
//                          : Else : Move steps times from head, Keep track of prev and curr, Delete curr node.
//                          : TC : O(2n) && SC = O(1)
// Approach 2 (Optimal) : Maintain a gap of N nodes between two pointers so that when one reaches end, the other is at the correct position.
//                      : Initialize two pointers: curr and prev, move curr N steps ahead - if curr == NULL, delete head node.
//                      : Else - Move both curr and prev together, stop when curr->next == NULL, delete prev->next.
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
int getLen(Node* head) {
    if(head == NULL) return 0;

    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* removeNthNodeFromLast(Node* head, int n) {
    if(head == NULL) return NULL;

    int len = getLen(head);
    int steps = len - n;
    
    if(n == len) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    
    Node* prev = NULL;
    Node* temp = head;
    while(steps > 0) {
        prev = temp;
        temp = temp->next;
        steps--;
    }
    
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}

// Approach 2 :
Node* removeNthNodeFromLast(Node* head, int n) {
    if(head == NULL) return NULL;
    
    int steps = n;
    Node* curr = head;
    while(steps > 0) {
        curr = curr->next;
        steps--;
    }
    
    if(curr == NULL) {
        Node* ntd = head;
        head = head->next;
        delete ntd;
        return head;
    }

    Node* prev = head;
    while(curr->next != NULL) {
        prev = prev->next;
        curr = curr->next;
    }
    
    Node* ntd = prev->next;
    prev->next = ntd->next;
    ntd->next = NULL;
    delete ntd;
    
    return head;
}

// ------------------------------------------------------- Question 24 : Delete the middle node in LL ------------------------------------------------------------------------>
// Pattern Recognition : "Two Pointers" - "Fast & Slow Pointer"
// Difficulty : Medium
// Understand the problem : You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
//                        : The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
//                        : For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
// Approach 1 (Brute Force) : This method relies on knowing the exact "address" (index) of the middle node.
//                          : Steps : Traverse the entire list to find the total length (N). Calculate the middle index: mid = N / 2.
//                                  : Traverse again from the head, stopping exactly at the node before the middle. Update the next pointer of the current node to skip the middle node.
//                          : TC = O(n) + O(n/2) = O(n) && SC = O(1)
// Approach 2 (Optimal) : Initialize two pointers: slow at head and fast at head->next. Move slow by one step and fast by two steps.
//                      : Because fast travels twice as fast, when it hits the end of the list, slow will naturally be at the node immediately before the middle.
//                      : Bridge the gap: slow->next = slow->next->next.
//                      : TC = O(n) && SC = O(1)

// Approach 1 :
int getLen(Node* head) {
    if(head == NULL) return 0;

    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* deleteMiddle(Node* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) {
        Node* ntd = head;
        head = head->next;
        delete ntd;
        return NULL;
    }

    int len = getLen(head);
    int mid = len/2;

    Node* prev = NULL;
    Node* curr = head;

    for(int i = 0; i < mid; i++) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return head;
}

// Approach 2 :
Node* deleteMiddle(Node* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) {
        Node* ntd = head;
        head = head->next; // Or rather, you can simply "delete head", as its just one node, but this is also fine, but yes this minor twik can be done.
        delete ntd;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* ntd = slow->next;
    slow->next = ntd->next;
    ntd->next = NULL;
    delete ntd;
    return head;
}

// ------------------------------------------------------- Question 25 : Add 1 to a number represented by LL ------------------------------------------------------------------------>
// Pattern Recognition : "Linked List Arithematic"
// Difficulty : Medium
// Understand the problem : Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on.
//                        : The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.
//                        : The number will contain no leading zeroes except when the value represented is zero itself.
// Approach 1 (Brute Force) : Convert the Linked List into a number, add 1, then reconstruct the Linked List.
//                          : Store digits in a vector, convert vector to integer, add 1 into the final integer value and then finally create new Linked List. Finally create a new Linked List.
//                          : TC = O(n) && SC = O(n)
// Approach 2 (Better Brute Force) : Simulate manual addition using carry, just like we do on paper.
//                                 : Addition starts from last digit, but LL is in forward order, so first reverse the Linked List.
//                                 : Reverse the Linked List, initialize carry, traverse and add, handle remaining carry & reverse again.
//                                 : TC = O(n) && SC = O(n)
// Approach 3 (Optimal 1) : The idea is identifying the last non 9 node.
//                        : Core Idea : When we add +1, carry propagates from right to left, But carry only continues through digits = 9 & It stops at the first digit (from right) that is NOT 9.
//                                    : Carry propagates only through trailing 9s and stops at the first non-9 digit.
//                        : We don’t need to process entire list backward, we just need to stop at the node where carry will STOP (Rightmost node which is NOT 9)
//                        : Cases : Case 1 : All 9s - Create a new head with value 1 & update all the next values with 0
//                                : Case 2 : At least one non-9 exists - Increament last non 9 node and then simply update all the remaining nodes with 0.
//                                : Case 3 : No trailing 9s - Just increament the last non 9 node (which will be the last node in this case) by 1 value.
//                        : TC = O(n) && SC = O(1)
// Approach 4 (Optimal 2) : Another approach can be the recursive method, where as we cannot access the last node of the list, so we can traverse there using recursion and then add the values by 1 while backtracking.
//                        : Key Insight : Recursion allows us to simulate reverse traversal in a singly linked list
//                        : TC = O(n) && SC = O(n) - Recursive Call Stack

// Approach 1 :
void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

Node* reverseLL(Node* head) {
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

Node* add1ToLL(Node* head) {
    if(head == NULL) {
        Node* newNode = new Node(1);
        return newNode;
    }
    if(head->next == NULL) {
        int sum = head->data + 1;
        if(sum > 9) {
            head->data = 1;
            Node* newNode = new Node(0);
            head->next = newNode;
            return head;
        }
        else {
            return head;
        }
    }

    vector<int> num;
    Node* temp = head;
    while(temp != NULL) {
        num.push_back(temp->data);
        temp = temp->next;
    }

    // Forming a decimal number 
    int finalNumber = 0;
    for(int i = 0; i < num.size(); i++) {
        int digit = num[i];
        finalNumber = finalNumber*10 + digit;
    }

    finalNumber += 1;
    Node* dummyHead = new Node(INT_MIN);
    Node* dummyTail = dummyHead;

    while(finalNumber) {
        int digit = finalNumber % 10;
        insertNode(dummyHead, dummyTail, digit);
        finalNumber = finalNumber / 10;
    }

    Node* finalList = reverseLL(dummyHead->next);

    return finalList;
}

// Approach 2 :
Node* reverseLL(Node* head) {
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

void insertNode(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

Node* add1ToLL(Node* head) {
    if(head == NULL) return NULL;

    Node* reversedHead = reverseLL(head);
    Node* temp = reversedHead;

    int carry = 1;

    Node* dummyHead = NULL
    Node* dummyTail = NULL;

    while(temp != NULL || carry != 0) {
        int val = (temp != NULL) ? temp->data : 0;
        int total = val + carry;

        carry = total / 10;
        int digit = total % 10;

        insertNode(dummyHead, dummyTail, digit);
        if(temp != NULL) temp = temp->next;
    }

    return reverseLL(dummyHead);
}

// Approach 3 :
Node* add1ToLL(Node* head) {
    if(head == NULL) return NULL;

    Node* lastNon9 = NULL;
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data != 9) lastNon9 = temp;
        temp = temp->next;
    }

    // Case 1 - All 9s
    if(lastNon9 == NULL) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
        temp = head->next;
        while(temp != NULL) {
            temp->data = 0;
            temp = temp->next;
        }
        return head;
    }
    else if(lastNon9->next == NULL) { // No trailing 9s
        lastNon9->data += 1;
        return head;
    }
    else {
        lastNon9->data += 1;
        temp = lastNon9->next;
        while(temp != NULL) {
            temp->data = 0;
            temp = temp->next;
        }
        return head;
    }
} // Suggestion : You can reduce the code by merging the else if and else condition in one.

// Approach 4 :
int helper(Node* head) {
    if(head == NULL) return 1;

    int carry = helper(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}

Node* add1ToLL(Node* head) {
    // if(head == NULL) return NULL;
    if(head == NULL) return new Node(1);

    int carry = helper(head);

    if(carry) {
        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}