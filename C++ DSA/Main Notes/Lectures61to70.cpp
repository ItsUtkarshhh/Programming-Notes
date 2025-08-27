// ---------------------------------------------------------- LECTURE 61 - Queues Questions --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse a Queue
// Approach 1 : We have studied stack previously! and we know that, ki stack me agar kuch element daalo and jab nikalte hai toh vo reverse order me nikaalte hai! so we can use stack! so what we need to do is we will create a atscak and will push all elements of the queue into the stack! and then stack to back to queue! this will reverse the order!
// Approach 2 : We can use recursion here! ek case solve krlo baaki recursion khud sambhal lega!
// Lets solve it using the approach 1... Approach 2 try while on your own while revising
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> rev(queue<int> q) { // Yaa toh yahaa & lagao q ke aage taaki original queue hi reverse hojaye! otherwise jo reversed queue hai usko tumko int main me jaake kahin store krna padega! ab chahe tum vo original queue me hi store krdo yaa alag se koi aur q2 bnaa ke.
    stack<int> s;

    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main() {
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout<<"Queue before reversing : ";
    printQueue(q1);

    cout<<endl;
    q1 = rev(q1);

    cout<<"After reversing : ";
    printQueue(q1);
}

// Question 2 : Find first negative integer in every window of size k
// Approach : We will use here a doubly ended queue! So what we will do is ki we will push first k element of the first window and will find answer from there! then window shoft krne time kya ho rha hai ki ek nayaa element add ho rha hai and ek purana element remove ho rha hai! toh yahaa hum easily doubly ended queue ka push_back and pop_front function use kr sakte hai! isliye we are using doubly ended queue's logic!
// lets code and then will make it clear!
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    // Processing first window of size K...
    for(int i = 0; i<K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }
    // Store ans of first K size window...
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    }
    else {
        ans.push_back(0);
    }

    // processing remaining windows...
    for(int i = K; i<N; i++) {
        //first pop out of window element
        if(!dq.empty() && (i - dq.front())>=K ) {
            dq.pop_front();
        }
        //then push current element
        if(A[i] < 0)
            dq.push_back(i);
        // put in ans
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    // Sample input array
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = sizeof(A) / sizeof(A[0]);
    long long int K = 3;

    // Function call to get the first negative integer in each window of size K
    vector<long long> result = printFirstNegativeInteger(A, N, K);

    // Displaying the result
    cout << "First negative integers in each window of size " << K << " are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
} // but yes this is not the optimal approach to solve this problem! you need to find that optimal approach!

// Question 3 : Reverse the first K elements of the queue.
// Approach : Like suppose the queue is like, 1 2 3 4 5, and K = 3, so the output will be like, 3 2 1 4 5... So first we will fetch first K elements of the stack and then will put them into the stack! so what we did we took out 1 2 3 one by one and pushed them into the stack! toh stack me toh ye aise jayenge ki 1 will be at the bottom and 3 will be at the topmost!
// And now ab hum stack me se pop krke vapis queue me daalenge! and abhi queue me already 4 5 hai! so at this point the queue will be, 4 5 3 2 1.
// But this is not the output we want! so we will proceed with the 3rd step! so thing is jo number stack me pehle push nhi hue the vo K size ke nhi the! toh unka size kya tha? toh agar jo stack me gye the vo K size ke the! and poora queue N size ka hai! toh jo remaining 4 5 the queue me unka size N-K hojayega! toh hume sirf itna krna hai ki unn N-K size vaale elements kao fetch krke end me lgaa dena hai! and then we will get the output!
// Lets code this approach...
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    // Algorithm...
    // Step 1 : pop first K elements from the queue and put them into the stack
    stack<int> s;
    for(int i = 0; i<k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // Step 2 : fetch from stack and push them into the queue.
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // Step 3 : fetch n-k elements from queue and push_back them into the queue!
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

void printQueue(queue<int> q) {
    while(!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main() {
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout<<"Queue before any reversing : ";
    printQueue(q1);

    cout<<endl;
    q1 = modifyQueue(q1,3);

    cout<<"Queue after any reversing : ";
    printQueue(q1);
} // TC : O(n).

// Question 4 : Find the first non-repeating characters in the string!
// Understanding the question, ek stream of strings aa rhi hogi input me! and jaise jaise hume input ayenge vaise vaise hume output krna hai ki konsa character repeat nhi ho rha hai unn sab characters ko note krte jaana hai! Jaise maanlo koi stream of string hai, which has aabcbd, now ek ek krte krte ye input me ayenge! and toh jab pehli value aai hume dekha 'a' aaya! toh abhi toh ye repeat toh hui nhi! toh we will just we will store 'a'... now ab dusri value aai 'a' ab ye toh jo input jo current string hai vo toh 'aa' hogyi hai toh iss case me hum output vaal string me '#' daal dena hai toh abhi output vaali string will be 'a#', so aise hi aage badhte jaana hai jab value no repeating ho toh usko input me daaldo! and jab repeating ho toh # daaldo output string me!
// And in the end in output we have to print the first non-repeating character in the final output string!
// Approach : So hume ek tarah se count store krna hoga pehle toh ki konsa character kitni baar aa rha hai! so for that we will need to store the count! so we will create a data structure! jo count store krega harr character ka! so we can create a map <char,int> count; jo jiss character ka count store krna hai uske hisaab se count store krta jayega! iske bajaye hum ye bhi kr sakte the ki ek array bnaa lo of size 26 and 0 a ko represent kr rha hota and 25 z ko! and hum index ke basis pr count store krlete! but okay we will do with the help of map! and then jiska count 1 hoga means vo character ek hi baar aaya hai! and then we will take a queue!
// and jo jo string ki stream input me aa rhi hogi usko hum queue me daalte jaynge! and then uske count ko ++ krte jayenge map me! and uss char ko queue me push krdenge! and then hum queue ka front check krlenge ki kya vo repeating hai ya non-repeating! agar repeating hai toh pop krdo and non-r hai toh print krdo! and agar queue hi empty hai toh return #;
// lets code...
#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

string FirstNonRepeating(string A){
	map<char, int> m;
	string ans = "";
	queue<char> q;
	for(int i=0; i<A.length(); i++) {
		char ch = A[i];
		q.push(ch);
	    m[ch]++;
		        
		while(!q.empty()) {
		    if(m[q.front()] > 1) {
		        q.pop();
		    }
		    else {
		        ans.push_back(q.front());
		        break;
		    }
		}
		if(q.empty()){
		    ans.push_back('#');
		}
	}
	return ans;
}

int main() {
    string s1 = "aabc";
    string ans = FirstNonRepeating(s1);
    for(int i = 0; i<s1.length(); i++) {
        cout<<ans[i];
    }
}

// Question 5 : Circular Tour Question! There is a circular path! where there are some petrol pumps! now we are in a truck! now in the input we are given with 2 values which are, Amount of petrol every petrol pump has! and Distance from that petrol pump to the next petrol pump!
// So now suppose we have a situation like, [ (4,6) | (6,5) | (7,3) | (4,5) ]... now, jab truck index 0 pr hai! then at that time, truck me 4 unit of petrol bharaa gya and usko 6 unit distance cover krna hai! so 4-6 = -2, means travel is not possible agar hum yahaa se start krenge toh! kyunki petrol kam pad jaa rha hai! so humara start hum ek aage badhaa denge! and now the start is at index 1, which is (6,5), now the truck is at index 1 which has 6 units of petrol and 5 unit of distance for the next petrol pump! and 6-5 = 1, means yahaa pr travel possible hai so ab truck travel krega from index 1 to 2 and index 2 pr pohochte pohochte uske paas 1 unit of petrol bahaa hua rahega! and 7 aur add hoga! means now the truck has 8 units of petrol! now ab 7-3 = 4, means again travel is possible! so now 3 units travel krke truck will be at index 3 and here 4 units of petrol aur add hoga!
// and means total petrol is 8 now! and now next petrol pump is 5 unit distance door! so 8-5 = 3, means again the travel is possible! so ab ghum ke vapis truck index 0 vaale petrol pump pr aajayega! and then vahaa tak pohochte pohochte uske paas 3 unit petrol bacha rahega and 4 unit aur add hoga! and cycle complete krne ke liye isko index 1 vaale petrol pump pr jaana hoga which is 6 unit distance door! so now 7-6 = 1, now the truck will reach at index 1! and here the loop completes! and we are asked to find the final petrol left after the whole loop completion! and it is 1 so the answer is 1.
// Approach 1 : According to brute force approch, harr jagah se start krke dekhlo! but uske TC : O(n^2), which is bad, so we will move to more optimized path!
// Approach 2 : We will use queue based approach! and jaise upar jo tha array type ka usko hum ek queue bnaa ke use krenge! and our front and rear will be at first position! and now algo says, if Petrol-Distance >= 0, then travel is possible! and rear++ krdena! and agar front == rear hojaye means circle is completed! and then final petrol left ko output krdenge! but agar travel possible nhi hua! in that case, hum front ko aage badha denge! by doing front = rear+1! front++ nhi krenge, kyunki front++ krne ka fayeda nhi hai! if you wanna know why, visit the vdo its a short explaination jo khud samajh jaoge jab dry run kroge toh!
// the front = rear+1 vaali thing isliye ki kyunki dekha jaaye toh next petrol pump tak jaane ke liye jo petrol ka contribution hai vo ek toh vo petrol pump kr rha hai and ek jo previous petrol pump se jo petrol liya tha and then jo distance travel krne ke baad jo balance bachaa uspe depend kr rha hai na! isliye agar maanlo humne index 0 se start kiya and then index 1 tak travel kr paaye and then index 2 tak bhi travel kr paaye but then index 3 tak travel nhi kr paaye! so means ab agar hum front++ krenge sirf toh uska koi fayeda nhi hai kyunki jab previous teeno petrol pump ke contributions pr bhi index 3 tak nhi pohoch paaye toh front ko sirf ek baar aage badhaa ke petrol pump 2nd se start krne pr kya fayeda hojayega! its like jab 3 petrol pump milke nhi pohocha paaye toh ab 2 kaise pohocha denge! isliue front++ krne se acha hai ki front = rear+1 krdo taaki ab next petrol pump se start krte hai! and now the thing is, hum nhi chahte ki hum ek petrol pump ko do baar traverse kre toh what we will do is jaise iss case me abhi hum petrol pump number 4 pr pohoch chuke hai! toh maanlo ab jab hum next vapis ghum ke index 0 pr jayenge toh isse pehle hum aage badhe ki hum check krlenge ki kya jo prvious petrol pump se jo balance hai + jo index 0 vaale pr amount of petrol hai kya vo >= 0 hai! agar haa tab hi aage travel krenge otherwise nhi! lets code to understand further!
// lets code this...
// { Driver Code Starts
#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class Solution{
  public:
    //Function to find the starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
    int tour(vector<petrolPump>& p, int n) {
        int deficit = 0;
        int balance = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            if(balance < 0) {
                start = i + 1;
                deficit += balance;
                balance = 0;
            }
        }
        
        if(balance + deficit >= 0) {
            return start;
        }
        else {
            return -1;
        }
    }
};

int main() {
    int t;
    cin >> t; // For test cases!
    while(t--) {
        int n;
        cin >> n;
        vector<petrolPump> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
    return 0;
}

// Question 6 : Interleaving the first half and second half of the queue, from GFG! Jaise agar ek queue ho like, 11 12 13 14 15 16 17 18, now we will be given a queue with even number of elements, now humara output aana chahiye ki, 11 15 12 16 13 17 14 18! alternatively dono halfs ke elements ko utha ke ek ke aage ek lgaate jaana hai!
// Approach 1 : Isme what we can do is pehle toh ki pehle jo queue ko do half me tora hai uske first half ko ek newQ me daaldo! and then alternatively new queue and old queue ke elements ko alternatively original queue me daalte jao end me! and ye tab tak kro jab tak newQ empty na hojaye! but isme TC : O(n) and SC : O(n)
// Approach 2 : Question constraint! only a stack can be used as an auxillary space! so pehle toh first half of the queue ko stack me daaldo! and then saare elements ko stack se vapis queue me daaldo so ab the scenario will be like, 15 16 17 18 14 13 12 11, now first half of the queue ko queue se pop kro and push krdo isse kya hoga ki 14 13 12 11 15 16 17 18, ab first half ko firse stack me daaldo! and again queue me daaldo! and iss baar original order me aajayenge! but yahaa hum aise hi vapis queue me push nhi krenge iss baar jab vapis queue me push kr rhe honge toh pehle stack ke element ko push krenge then queue ke hi front ko queue ke end me push krenge and aise alternatively isse we will get our final answer! dry run krke dekhlo hojayega aise!
// Attemp both these question on your own while revision!

// Practice Question : Implement Queue using Stack! and Stack using Queue!

// Question 7 : Implement 'k' queues in the array! ab maanlo for our example k = 3 hai, means hume 3 queues implement krni hai array ke andar! so what we will do is, hum pehle array ko 3 equal parts me divide krdenge! of n/k size each!
// Approach 1 : Ab pehli approach toh vhi hai ki array ko k parts me divide krdo! and then front and rear harr division ke starting me lgaa denge! But yess this is not a very optimzal solution kyunki yahaa pr space ache se use nhi ho rhi hai! same cheez humne stack me bhi dekhi thi! so what we will do is we will use another approach!
// Approach 2 : Ab hume ek hi array me K queues daalne hai toh hum pehle toh K size ka front array banayenge and ek K size ka rear array bnayenge! jinme hum harr queue ke front and rear ka index store krte chalenge taaki track rahe ki konsa queue kahaa khatam ho rha hai and kahaa se shuru ho rha hai! So initially hum front and rear ke array ko -1 se initiallize krdenge! ye tab ho rha hai jab array me koi bhi queue abhi ke liye nhi banai gyi hai!
// Now we will make an array with name next[n] and iska size hoga jo original array ka size hai jisme hum queue implement kr rhe hai! and ye ye darshata hai ki current block ke baad next free block konsa hoga! toh like agar original array me maanlo ki koi value index 0 pr stored hai toh next[] vaali array ye darshayegi ki next konsa freespace kahaa hai! and agar original array abhi empty hai toh next vaala array ye darshayega ki next free spot konsa hai! overall next bss itna btaa rha hai ki original array me kaha kahaa free slots available hai!
// Lets understand this, maanlo abhi original array khaali hai! array[] = [   |   |   |   |   |   |   ] toh ab next next me values aise store rahengi ki jaise 0th index of next array will be representing that ki original array ke 0th index ke baad konsa next free slot khaali hai! and similalry for other indexes! so the next[] = [ 1 | 2 | 3 | 4 | 5 | 6 | -1 ], ab 7th index ke baad koi space free hi nhi hai original array me toh humne isme -1 daal diya! and then ek freespot naa se variable hoga jo ye batayega ki abhi currently konsa free spot available hai! and that is = 0. initially jab original array abhi khaali! jaise jaise bharegi vaise vaise konsi next freespots hai uska index isme save hojayega!
// So, ye upar ki 4 cheeze hume chahiye hoti hai aisi queues implement krne ke liye ek hi array me! so ab hume push, pop and baaki operations likni hai jisse hum ye upar ki saari conditions achieve kr paaye! just with normal push and pop operations! alag se kuch nhi krna hai! bss push and pop and other operations aise bnaane hai jisse K queues automatically array me implement ho jaye!
// So for Push() operations : First we will check the overflow condition! ye tab hoga jab array full hojaye! or in otherwords freespot == -1. Then find index where we want to insert! then ye index kahaa milega jahaa freespot hoga! so we will write index = freespot! and then will update the freespot using the next array! freespot = next[index];
//                          : Now first element insert krna hai (first element insert krna isliye alag hai kyunki initially front and rear arrays = -1 hote hai! so first element ko push krne ke liye hum front and rear arrays ko update krenge!) now, what we will do is, ki agar front[Qn] means front of the queue jisko hum abhi daal rhe hai array me vo agar -1 hai then front ko update krke current index ke equal krdo! kyunki ab first element current index pr aa chuka hai! means yahaa hume first index fill krdiya first queue ka!
//                          : But ab agar first element already hai and ab hume kabhi beech me koi element insert krna hai jab already array me elements hai toh uss time humare paas uss queue ka jo last element insert hua tha uska next hona chahiye! and vo kahaa se milega vo milega next[] array se! and then hum next[rear[Qn]] = index; krdenge.
// Ab lets visuallize ki cheeze ho kaise rhi hai! so the things is array me elements aise push ho rhe hai! array[] = [   |   |   |   |   |   |   |   |   ]; ab maanlo hume kahaa jaaye ki queue1 me 2 3 push krdo toh array will be like, array[] = [ 2 | 3 |   |   |   |   |   |   |   ], now ab kahaa jaaye ki queue2 ke 6 7 push krdo, so now the array will be, array[] = [ 2 | 3 | 6 | 7 |   |   |   |   |   ], now ab firse kahaa jaaye ki queue1 me 10 push krdo, so the array will be like, array[] = [ 2 | 3 | 6 | 7 | 10 |   |   |   |   ], ab the thing is 2 3 10 ek hi queue ke hai but iss array me continuos manner me nhi hai toh koi toh link hona chahiye unme taaki ptaa chale ki konsa element kis queue ka hai! so that we will use the next array!
// Lets code it and then will dry run! overall you got the thing is basically ho kya rha hai!
#include<iostream>
using namespace std;

class Kqueue {
    public :
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public :
    Kqueue(int n, int k) {
        this-> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i<k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i = 0; i<n; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int[n];
        freespot = 0;
    }

    void enQueue(int data, int Qn) {
        // Check Overflow
        if(freespot == -1) {
            cout<<"No empty freespot!";
            return;
        }
        // Find first free index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        if(front[Qn - 1] == -1) {
            front[Qn -1] = index;
        }
        else {
            // Link new element with the previous element
            next[rear[Qn-1]] = index;
        }
        // Update next
        next[index] = -1;

        // Update rear
        rear[Qn-1] = index;

        // Push element
        arr[index] = data;
    }

    int deQueue(int qn) {
        //underflow 
        if(front[qn-1] == -1) {
            cout << "Queue UnderFlow " << endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //front ko aage badhao
        front[qn-1] = next[index];

        //freeSlots ko manage karo
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {

    Kqueue q(10, 3);
    q.enQueue(10, 1);
    q.enQueue(15,1);
    q.enQueue(20, 2);
    q.enQueue(25,1);

    cout << q.deQueue(1) << endl;
    cout << q.deQueue(2) << endl;
    cout << q.deQueue(1) << endl;
    cout << q.deQueue(1) << endl;

    cout << q.deQueue(1) << endl;

    return 0;
} // Try the dry run on your own! during revision!

// Question 8 : Sum of maximum and minimum elements of all sub arrays! of size K. Understanding : Ki ek array diya hoga usko K parts ke window me jo maximum and minimum numbers nkalne honge and then unka sum return krna hoga!
// Approach 1 : We can use two pointer approach and K ki windows bnaa bnaa ke hum unka max and min nikale jayenge! and unka sum return krte jayenge! toh yahaa do loops chalengi! so yahaa TC : O(n*k) ek loop chalegi n times and ek andar vaali k times!
// Approach 2 : So we will take two double ended queues! and inme ek maxi hoga and ek mini! now, maxi me hum decreasing order me elements ko rakhenge! like pehle K size ke elements nikale and then unka max daaldiya doubly ended queue me! and then same cheez ki mini me isme bss sabse minimum element daalte gye! and then unka sum nikal ke output krdenge!
// Lets code the approach...
#include<iostream>
#include<deque>
using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition in case of first K size window
    for(int i=0; i<k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {      
        // heading to next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;
} // Dry run this question and understand the approach and code on your own, its simple nothing tough here!

// ---------------------------------------------------------- LECTURE 62 - Trees and Binary Trees --------------------------------------------------------------------------------------------------------->
