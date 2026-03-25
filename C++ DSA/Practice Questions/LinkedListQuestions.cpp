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
// Approach 3 : If one sorted and one unsorted, and your main reference list is the unsorted one!
Node* mergeTwoLists(Node* LL1, Node* LL2) {
    if(LL1 == NULL) return LL2;
    if(LL2 == NULL) return LL1;

}

Node* mergeTwoLists(Node* LL1, Node* LL2) {
    if(LL1 == NULL) return LL2;
    if(LL2 == NULL) return LL1;
}