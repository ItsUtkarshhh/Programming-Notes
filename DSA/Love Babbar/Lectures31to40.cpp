// ---------------------------------------------------------- LECTURE 31 - Recursion Day-1 --------------------------------------------------------------------------------------------------------->
// Recursion : When a function calls itself!
// In other words, Jab kisi badi problem ka solution, depend krta hai uss hi type ki choti problems pr!
// In recursion we have base cases!
// Suppose a problem of factorial, 5! = 5 * 4! and 4! = 4 * 3! and 3! = 3 * 2! and 2! = 2 * 1! and 1! = 1 * 0, after this we need to stop! isme we can see ek relation dikh rha hoga, and that is "f(n) = n * f(n-1)" and this is called recurrence relation! and in this we have a base case! and that is when n = 0, we need to stop! so 0 is the base case!
// lets code the factorial using recursion!
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n);
} // So we get that recursion krne ke liye ek base case pta hona chahiye! and recurrence relation ptaa hona chahiye!
// Agar base case nhi daalenge toh like agar factorial(6) humne nikalna chaha toh pehle 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 -> -1 -> -2 -> -3 and it will go on until stack overflow na hojaye and which will result in segmentation fault!
// And that is why base case is important!

// Now apart from base condition and recurrence relation, there is another component of recursion and that is processing (this is optional but rest two are mandatory!), like any updation or printing we are doing while doing recursion...
// If the flow of recursion is like this... "Base case -> Processing -> Recurrence Relation" this is called Tail Recursion and if the flow is like this... "Base case ->  Recurrence Relation -> Processing" then this is called Head Recursion!
// Solving power of 2 using recursion (2^n)...
#include <iostream>
using namespace std;

int powerOf2(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return 2 * powerOf2(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << powerOf2(n);
}
// There is also a recursion tree which is the visual representation of recursion!
// Another example... print counting...
#include <iostream>
using namespace std;

void printCounting1(int n) { // Head Recursion!
    if (n == 0) { // Base case!
        return;
    }
    printCounting1(n - 1); // Recurrence relation!
    cout << n << endl; // Processing!
}
// Lets understand with example of n = 3. printCounting1(3) -> printCounting1(2) -> printCounting1(1) -> printCounting1(0) -> returned nothing and came back -> then printCounting1(1) me jo cout hoga usne 1 print krdiya, then stack me se printCounting1(1) hatt gya then printCounting1(2) me jo cout tha usne 2 print krdiya and so on... isliye 1,2,3,4.... aise counting print ho rhi hai!

void printCounting2(int n) { // Tail Recursion!
    if (n == 0) { // Base case
        return;
    }
    cout << n << endl; // Processing!
    printCounting2(n - 1); // Recurrence Relation!
}
// Lets understand with example of n = 3. printCounting1(3) isne 3 print krdiya! then printCounting1(2) call hua jisne 2 print krdiya then printCounting1(1) call hua jisne 1 print krdiyaa and then printCounting1(0) call hua jo kuch return toh kr nhi rha isliye here the code terminated!
int main()
{
    int n;
    cin >> n;
    printCounting1(n);
    printCounting2(n);
} // We can visuallize this using the recursive tree as well!

// ---------------------------------------------------------- LECTURE 32 - Recursion Day-2 --------------------------------------------------------------------------------------------------------->
// lets see another example...suppose there is a source who wants to reach a destination home, write the code for this scenario using recursion!
#include <iostream>
using namespace std;

void reachHome(int src, int dest)
{
    cout << "Source : " << src << " Destination : " << dest << endl;
    if (src == dest)
    {
        cout << "Reached!" << endl;
        return;
    }

    src++;
    reachHome(src, dest);
}

int main()
{
    int src, dest;
    cin >> src >> dest;
    reachHome(src, dest);
} // My thought : Aise hi hum kuch cheeze automate kr sakte hai like cars and all!

// Question 1 : Fibonacci Series! : Find the nth fibonacci element!
#include <iostream>
using namespace std;

int fibNum(int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        return fibNum(n - 1) + fibNum(n - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << fibNum(n);
} // Here we have used nth term for to access fibonacci elements, hum index se bhi access kr sakte hai fibonacci elements in that case we just need to replace n==1 & n==2 to n==0 & n==1

// Question 2 : Climb Stairs Question from CodeStudio!
// You have been given a number of stairs, initially you are 0th stair, and you need to reach the nth stair, each time you can either climb 1 or 2 steps! you are supposed to return the number of distinct ways in which you can climb from 0th step to nth step!
// Approach : Hume isme bss ek recurrence relation nikalna hai, which deals with the final state and here the final state is when we reach the destination, so hum sabse top vaali stairs pr do tareeko se aa sakte hai, yaa toh hum ek neeche vaali seedhi se upar aye honge ya toh do neeche vaali seedhi se upar aye honge! and hume number of ways nikalne hai toh we will add both of them! hence our recurrence relation is "f(n) = f(n-1) + f(n-2)"
// Now lets find the base condition, n is that stair jiss tak hume jaana hai, means it is the destination! so pehli base condition toh ye hogi ki agar n = -ve then in that case it is invalid seedhi so we will return 0 as becoz aisi koi seedhi toh exist nhi krti, and then when n == 0 means hume 0th seedhi pr jaana hai toh in this case number of ways iss seedhi pr jaane ke sirf ek hi hoga so we will return 1! kyunki initially jo src hai vo 0th pr hi khada hai!
#include <iostream>
using namespace std;

int countDistinctWaysToClimbStairs(long long nstairs)
{
    // Base case
    if (nstairs < 0)
    {
        return 0;
    }
    else if (nstairs == 0)
    {
        return 1;
    }
    else
    {
        return countDistinctWaysToClimbStairs(nstairs - 1) + countDistinctWaysToClimbStairs(nstairs - 2);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << countDistinctWaysToClimbStairs(n);
} // Why this works : If nstairs < 0: There are no ways to climb negative steps, so return 0. If nstairs == 0: There is exactly one way to stay at the ground level without taking any steps, so return 1.
// For any other number of steps nstairs, the number of ways to climb the stairs is the sum of : The number of ways to climb nstairs - 1 steps (taking one step from nstairs - 1 to nstairs). & The number of ways to climb nstairs - 2 steps (taking two steps from nstairs - 2 to nstairs).
// Each step can be reached either by taking a single step from the previous step or by taking two steps from two steps below. This means every combination of steps to reach nstairs is the sum of the combinations to reach nstairs - 1 and nstairs - 2.
// By breaking down the problem into smaller subproblems (i.e., nstairs - 1 and nstairs - 2), and summing their solutions, the function builds up the solution for nstairs.
// This code can be more optimized through Dynamic Programming, but that we will study very later!

// Question 3 : Say Digits, here if you get the input 412 you have to print four one two!
// Approach : Pehle hum ek array bnaa ke usme saare digits ko map karaa lenge! and then individual digits nikalne ke liye hum n%10 krenge and then number chhota krne ke liye we will do n/10, lets code now!
#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    // Base Case
    if (n == 0)
    {
        return;
    }
    // Processing
    int digit = n % 10;
    n = n / 10;

    // Recursive call
    sayDigit(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cin >> n;
    sayDigit(n, arr);
} // Draw the recursion tree and function stack, it will clear the concept more!

// ---------------------------------------------------------- LECTURE 33 - Recursion Day-3 : Recursion and Binary Search --------------------------------------------------------------------------------------------------------->
// We will implement binary search using Recursion, we have done it with loops, but lets do it with recursion!
// So we have find that whether the array we got in the input is sorted or not!

// Check whether the array is sorted or not!
#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    { // Base case humne ye bnaa diya!
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, size - 1); // Isse humne pehle ke do indexes check krne ke baad baaki saare array ko check krne ke liye recursion use krliya!
    }
}

int main()
{
    int arr[5] = {3, 2, 5, 4, 1};
    int size = 5;
    cout << isSorted(arr, size);
}

// Question 2 : Find the sum of all the elements of an array! using recursion!
#include <iostream>
using namespace std;

int findSum(int arr[], int size)
{
    if (size == 0)
    { // This is the base case!
        return 0;
    }
    else
    {
        return arr[size - 1] + findSum(arr, size - 1); // Here we have used recursion
    }
}

int main()
{
    int arr[5] = {2, 3, 4, 5, 1};
    int size = 5;
    cout << findSum(arr, size);
}

// Question 3 : Do linear search using recursion!
#include <iostream>
using namespace std;

bool findElement(int arr[], int size, int target)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == target)
    {
        return true;
    }
    else
    {
        return findElement(arr + 1, size - 1, target); // So hum kya kr rhe hai ki harr baar 0th index ke element ko check krke function call me ek index aage se elements ko pass kr de rhe hai! taaki saare elements check ho sake,
        // and ek time aisa ayega jab saare elemenst check hojayenge and size = 0 hojayega and that is where our base condition will help to stop the recursion!
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int target = 5;
    cout << findElement(arr, size, target);
}

// Now lets implement binary search using recursion!
#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key)
{
    // Base case!
    // If element not found
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    // If element found
    if (arr[mid] == key)
    {
        return true;
    }
    // Recursion call for changing the state space!
    if (arr[mid] > key)
    {
        return binarySearch(arr, s, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, e, key); // We did the same thing jo hum pehle loops ki help se krte the bss iss baar Recursion ka use kiya hai!
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int start = 0;
    int end = size - 1;
    int key = 10;
    cout << binarySearch(arr, start, end, key);
}

// ---------------------------------------------------------- LECTURE 34 - Recursion Day-4 : Recursion with Strings --------------------------------------------------------------------------------------------------------->
// Question 1 : Reverse a string using recursion!
#include <iostream>
#include <string>
using namespace std;

void reverseString(string &s1, int s, int e)
{ // Isme agar s1 ko refernce nhi krenge toh jo bhi changes honge string me vo sirf iss function ke andar andar ho jayenge, toh int main me unn changes ko laane ke liye we need to reference it!
    if (s > e)
    {
        return;
    }
    swap(s1[s], s1[e]);
    s++;
    e--;
    reverseString(s1, s, e); // We used the same approach, ki ek case humne handle krliya and baaki sabke liye recursive call krdiya!
}

int main()
{
    string s1 = "Utkarsh";
    int s = 0;
    int e = s1.length() - 1;
    reverseString(s1, s, e);
    cout << s1;
}

// Question 2 : Check for a palindrome! using recursion! approach is same ki pehle string ko reverse krke and then dono strings ko compare krlenge ki kya dono same hai if yes then its a palindrome!
#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s1, int i, int j)
{
    if (i > j)
    {
        return true; // Here we mean by saying that agar poori string traverse hoke i>j hojaye mtlb ki kahin pr palindrome hone ki condition false nhi hui, toh mtlb ki haa ye palindrome hai toh iss case me true return krdo!
    }
    if (s1[i] != s1[j])
    {
        return false; // One case we handled!
    }
    else
    {
        return checkPalindrome(s1, i + 1, j - 1); // rest will be handled by recursion!
    }
}

int main()
{
    string s1 = "babbab";
    if (checkPalindrome(s1, 0, s1.length() - 1))
    {
        cout << "Its a palindrome!";
    }
    else
    {
        cout << "Its not a palindrome";
    }
}

// Question 3 : Calculating power using Recursion! here we will use the fast exponentiation method to calculate it!
// lets see how... suppose we have a^b and b is even, then we will do -> a^b = a^(b/2) * a^(b/2)
// and if b is odd, then we will do -> a^b = a * (a^(b/2) * a^(b/2))...now we will use recursion to solve it... lets now code it...
// So like for example maanlo agar hume 2^1024 ki value nikalni hoti, toh hum pehle 2^1024 ke liye (2^512)^2 nikalte then iske liye hum (2^256)^2 nikalte then iske liye (2^128)^2 -> (2^64)^2 -> (2^32)^2 -> (2^16)^2 -> (2^16)^2 -> (2^8)^2 -> (2^4)^2 -> (2^2)^2 -> (2^1)^2... so in from this method humne 11 times me answer nikal liya, but agar proper loops ko use krte toh 1024 times me answer aata kyunki vahaa iterations hoti yahaa hum recursively answer itna optimize kr sakte hai!
#include <iostream>
using namespace std;

int power(int a, int b)
{
    // Base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    // calculated and stored it in the ans
    int ans = power(a, b / 2);

    // checked for b is odd or even, so yes again we did the same thing ki ek case ke liye solve krliya and then baaki ke liye recursive call krdiya!
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
}

// Question 4 : Implementing bubble sort using Recursion!
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    // Base Case
    if (size == 0 || size == 1)
    {
        return;
    }
    // Solved for one case
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    // Rest will be handled by recursion
    bubbleSort(arr, size - 1);
}

int main()
{
    int arr[5] = {4, 3, 4, 2, 1};
    int size = 5;
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}

// ---------------------------------------------------------- LECTURE 35 - Recursion Day-5 : Merge Sort using Recursion --------------------------------------------------------------------------------------------------------->
// It is the fastest storing algorithm we have studied till now!
// Now lets see how it works! : Suppose you have an array in the input [38,27,43,3,9,82,10]...
// Now what we will do is we will find the mid using mid = (s+e)/2 or s + (e-s)/2... and then we will keep dividing the array into single blocks!
// Lets see... first we have calculated mid which came out to be, mid = (s+e)/2 and we got 3 now we have divided the array into 2 parts which are [38,27,43,3] & [9,82,10] then similary we will continuing doing it...
// [38,27,43,3,9,82,10] mid = 3 -> [38,27,43,3] mid = 1 & [9,82,10] mid = 1 -> [38,27] mid = 0 & [43,3] mid = 0 & [9,82] mid = 0 & [10] -> [38] & [27] & [43] & [3] & [9] & [82] & [10]
// Now once we reach this stage, now we will sort and combine all of them, and this will go like... [27,38] & [3,43] & [9,82] & [10] then... [3,27,38,43] & [9,10,82] then... [3,9,10,27,38,43,82] and that is how it get sorted!
#include <iostream>
using namespace std;

// Here we are merging two arrays!
// The merge two arrays we have studies earlier so refer that lecture to understand it better
void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // Doing this to free the Dynamic allocated memory as we have studied earlier!
    delete[] first;
    delete[] second;
}

// Here we are doing the recursive calls!
void mergeSort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // left part sort karna h
    mergeSort(arr, s, mid);

    // right part sort karna h
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

int main()
{
    int arr[15] = {3, 7, 0, 1, 5, 8, 3, 2, 34, 66, 87, 23, 12, 12, 12};
    int n = 15;
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
// Space Complexity : O(n) kyunki yaha humne array ko do parts me divide kiya, so overall O(n) hi ayegi!
// Practice and Solve : Inversion Count Problem from GFG, its asked in interviews!
// Time Complexity : O(nlogn)
// Merge sort achieves a time complexity of O(nlogn) due to its divide-and-conquer strategy. Divide: In the divide step, the array is divided into two halves recursively until each sub-array contains only one element. This takes O(logn) time because the array is halved in each recursive call.
// Conquer: In the conquer step, the merge operation takes place. This involves merging the sub-arrays in sorted order. Merging two sorted arrays of n/2 elements each takes O(n) time.
// This makes merge sort one of the most efficient comparison-based sorting algorithms for large data sets. Its O(nlogn) time complexity holds both in the average and worst-case scenarios.

// ---------------------------------------------------------- LECTURE 36 - Recursion Day-6 : Quick Sort using Recursion --------------------------------------------------------------------------------------------------------->
// Lets understand the logic... so we have an array... now hum pehle iska sabse first element lete hai and then check krte hai ki kya poore array me isse chhote jitne bhi elements hai unko count krliya and uss count ke hisaab se iss first element ko uske sahi index pr bhejdete hai!
// And now ab yahaa se hum partition krdete hai array ki, like jiss element ko humne uske sahi index pr bheja uske right side me jitne bhi elements hai vo sab uss element se bade hone chahiye and left ke saare chhote hone chahiye!
// Now we have done our one job the rest we will apply recursion to do the same in the right and left side of the partition!
// Lets see with an example, suppose you have array : [3,1,4,5,2]... now here the first element is 3 and there are 2 elements less than 3 so we will put 3 at the index = s + count, means here the s = 0 and count = 2 so the 3 will be swapped with the element at index 2 which is 4, so our new array will be...[4,1,3,5,2]...
// Now we will make 3 as the pivot element and now we will use two pointer approach i and j, using them hum ye jo condition thi na ki pivot element ke right side saare elements bade hone chahiye and left side saare chhote hone chahiye! usko hum ab iss 2 pointer approach se achieve krenge!
// So now... i will point at 4 and j will point at 2... now we will compare both the elements with the pivot element and if i > pivot element && j < smaller than pivot element, we will swap! and then ye baaki elements ke saath bhi krenge and then we will get the final array...[2,1,3,5,4] and this will called our First Pass!
// So now humne itna solve krliya and now baaki hum ab recursion ke thru solve krlenge!
// Also remember this for dry run and understanding purposes ki partition ka mtlb ye nhi ki humne array ko kaata hai ya aisa kuch, its just that ki humne apna range of elements ko cater krna change krliya, so the indexes vaisi hi rahengi jaisi pehle thi!
// Now lets code...
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part sambhal lete hai
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
// 4 1 3 5 2

// So yahaa toh humne recursion call krdiye! ki jo cheez humne partition function me kri hai pivot element ke saath original array me vhi same cheez tum baaki saari jo sub arrays banegi unn sab me krdo thru recursion!
void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;
    // partition karenge
    int p = partition(arr, s, e); // Here p means pivot index
    // left part sort karo
    quickSort(arr, s, p - 1);
    // right wala part sort karo
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {3, 1, 4, 5, 2};
    int n = 5;
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
// So overall Quick Sort Algorithm does two things : Partition and Recursion... partition provides the pivot index jiske help se recursion call hoti hai and uss recursion call me firse partition function call hota and this thing continues jab tak saare elements sort na hojaye! or should say jab tak base case reach na hojaye! and then we can print the output from the int main!
// Quick sort is an in-place sorting technique, meaning it doesn't require additional memory proportional to the size of the input. It achieves this by sorting elements within the original array itself, using swapping operations to reorder elements as needed. This characteristic makes it memory-efficient, particularly for large datasets, compared to algorithms like merge sort which may require additional memory for temporary arrays.
// However, regarding stability, quick sort is not inherently stable. A sorting algorithm is considered stable if it preserves the relative order of equal elements in the sorted output as they appeared in the original input. In quick sort, the partitioning step does not ensure stability. Equal elements might not necessarily maintain their original order after the sorting process. This instability arises because quick sort relies on comparison-based partitioning and swapping operations, which may interchange elements without considering their original order.
// Stabilty ke baare me we have studied earlier also so refer that or use chatGPT to better understand it...in short is that if like there are 2 elements in the array 3 and 3, then after the sorting operations the first 3 should be before the second 3 and if this happens then the algo is considered stable otherwise not stable! overall identical elements ka original order preserve nhi rehta hai sorting ke baad!
// That said, variations of quick sort, such as three-way quick sort or dual-pivot quick sort, can be modified to maintain stability. These variations introduce additional checks and adjustments during the partitioning process to preserve the order of equal elements. However, the basic form of quick sort itself is not stable.

// For arrays Quick Sort is prefered more than Merge Sort!
// For linkedlists Merge Sort is prefered over Quick Sort!

// Space Complexity : O(n) in Worst Case & O(logn) in Best Case!
// Time Complexity : O(nlogn) in average and Best Case & O(n^2) in Worst Case!

// ---------------------------------------------------------- LECTURE 37 - Recursion Day-7 : Subsets and Subsequence --------------------------------------------------------------------------------------------------------->
// Question 1 : Given an array of unique elements, return all possible subsets (the power set)... leetcode question 78 : Subsets
// Approach : Now suppose there is an array {1,2,3} now iska powerset hoga... {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}}
// So to solve this we will consider our original array, an output array and a pointer which will be used to iterate on the original array!
// Now ab isko solve kaise krenge, so we will take a pointer which will be pointing at the index = 0 of the array and now we have to decide to whehther include it to the output array or not! agar include krna hoga toh we will push it in the output array! otherwise we will move to the next iteration!
// To imagine it better re watch the lecture from Youtube!
// Now lets code...
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) { // yahaa humne ans ko ek refernce ki tarah use kiya hai vrna ek copy ban jayegi jo ki bss iss function ke andar andar hi ans nikal dega usko hum bahar display nhi kar payenge... vhi jo normally jiske liye hum reference use krte hai!
    // base case
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main() {
    // Input vector
    vector<int> nums = {1, 2, 3};

    // Generating subsets
    vector<vector<int>> result = subsets(nums);

    // Printing subsets
    cout << "Subsets:\n";
    for (const auto &subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
// Overall we have created subsets of the given array and we have used above approach as mention before the code... if any more trouble in imagining the approach then just refer to the lecture on youtube!

// Question 2 : Subsequences of a string! maanlo you have a string abc, then you have to find the number of subsequences it can have, like for this case the subsequences are... "a" "b" "c" "ab" "bc" "ac" " "... so it can have 7 subsequences
// To solve this problem we will follow the same approach as of the subsets one... they both are same questions bss ek arrays ke upar hai and ek string ke upar!
// So vhi krna hai include and exclude and string given hogi and ek output string me hum include ya exclude krte rahenge and then final output string print krdenge!
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, string str, string output, int i) {
    // base case
    if (i >= str.length()) {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }

    // exclude
    solve(ans, str, output, i + 1);
    // include
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    solve(ans, str, output, 0);
    return ans;
}

int main() {
    string str = "abc";
    vector<string> result = subsequences(str);
    cout << "Subsequences:\n";
    for (const auto &subseq : result) { // This is a range-based for loop, a simplified and more readable way to iterate over elements in a container like a vector in C++.
        cout << subseq << endl;
    }
    return 0;
}
// const : Indicates that each subseq element is constant and cannot be modified within the loop.
// auto : Allows the compiler to automatically deduce the type of each element. In this case, it will deduce the type of subseq to match the type of elements stored in the result vector.
// & : Indicates that subseq is a reference to each element in result, meaning it doesn't make a copy of each element, improving efficiency.
// : result : Specifies the range over which the loop will iterate. In this case, it's the vector result.


// ---------------------------------------------------------- LECTURE 38 - Recursion Day-8 : Phone Keypad Problem --------------------------------------------------------------------------------------------------------->
// Question : Leetcode question : 17...
// So basically what we have to do is... phone keypad me jo numbers hote hai unke corresponding kuch alphabets hote hai jaise 2 ke corresponding abc, 3 -> def and similarly...
// Now user can type any number between 2-9 and now you have to fund the numbers of combinations possible that these numbers could represent!
// Approach : It will mostly similar to the above two questions! so we will again follow the inclusive and exclusive technique and we will have na input array and we will push values into an output array!
// for more clear visualizationa and recursion tree rewatch the lecture on youtube!
// Lets code...
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
    
    //base case
    if(index >= digit.length()) {
        ans.push_back(output);
        return;
    }
    
    int number = digit[index] - '0';
    string value = mapping[number];
    
    for(int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, output, index+1, ans, mapping); // Here we have done the recursive call!
        // Here we are backtracking, taaki hum changes previous state me hi kre! vrna inconsistency ban jayegi!
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length()==0) {
        return ans;
    }
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    solve(digits, output, index, ans, mapping);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);
    cout << "Letter Combinations: ";
    for (const auto &combo : combinations) { // We have done the same thing as we have dono in the previous two questions!
        cout << combo << " ";
    }
    cout << endl;
    return 0;
} // Try the dry run and you will understand the concept very clearly! and also rewatch the vdo if not get the visuallization the solution!


// ---------------------------------------------------------- LECTURE 39 - Recursion Day-9 : Permutations in a string! --------------------------------------------------------------------------------------------------------->
// Question : Leetcode question : 46 and CodeStudio Question : Permutations opf a string!... isme hume input me ek string di hogi and hume uske kitne number of permutations possible hai vo nikalne hai and here yet again hume vhi technique use krni hai which we are using since last three questions! but here bss ek difference hoga ki yahaa hum koi alag se output string nhi liye hai balki uss hi input string me hi changes kr rhe hai! and yes vo ek pointer i toh liya hi hai... baaki bss yahaa swap kr rhe hai!
// Rest is the same methodology, ek cheez solve kro and rest of the part of the question me uss hi ko recursion ke thru call krdo!
// Lets code!
// Again saying refer the lecture vdo from youtube if agar visuallize nhi hua toh... its easy and simple... nothing very tough!
// This code is for the Leetcode Question 46
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
    // Base case...
    if(index >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    for(int j = index; j<nums.size(); j++) {
        swap(nums[index], nums[j]);
        solve(nums, ans, index+1);
        // Backtracking! taaki hum previous permutation pr jaa sake taaki hum aur dsure permuations bhi explore kr sake! vrna inconsistency ban jayegi and which will give the wrong answer!
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);
    return ans;
}

int main() {
    // Input sequence of integers
    vector<int> nums;
    int num;
    cout << "Enter a sequence of integers (type any non-integer character to stop): ";
    while (cin >> num) {
        nums.push_back(num);
    }
    // Generate permutations
    vector<vector<int>> permutations = permute(nums);
    // Output permutations
    cout << "Permutations: " << endl;
    for (const auto& permutation : permutations) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
// More or less focus on the logic of the functions created! and try the dry run and rewatch the vdo if not clearly visuallized the solution!
// Most important is the logic!


// ---------------------------------------------------------- LECTURE 40 - Recursion Day-10 : Rat in a Maze Problem! --------------------------------------------------------------------------------------------------------->
// Question : Rat in a maze, Visit GFG to solve this question, what it says is...
// You have a rat and a maze and that maze is in a form of matrix which has n rows and n columns, and in the intial state the rat is at (0,0) and this rat wants to got to the (n-1,n-1)!
// Now their are some sections in the maze where it is marked 0 and on some sections it is marked 1, and the rat can move only on the sections which is marked as 1... so we need to find all the possible paths this rat can travel to get to the final section which is (n-1,n-1)... an d the possible movements a rat can do is U,D,L,R
// Approach : Sabse pehle lets assume a 2D matrix...
// Matrix (M)
//        0   1   2   3       
// 0 -> | 1 | 0 | 0 | 0 |
// 1 -> | 1 | 1 | 0 | 1 |
// 2 -> | 1 | 1 | 0 | 0 |
// 3 -> | 0 | 1 | 1 | 1 |
// So we will use the above matrix to understand the problem and the solution!
// First we know that there could be several movements possible and they are, UP which can be represented as (x-1,y) as becoz row is decreasing and column remains the same! similary for DOWN (x+1,y), RIGHT (x,y+1), LEFT (x,y-1), where x is the row number and y is column number!
// So we have found the number of rows and columns movements possible!
// Now, we take a src variable which will represent our rat and at initial state the src is at (0,0) means srcx = 0 and srcy = 0, and we are going to follow the recursion here so we need to fund the one solution to see kya kya constraints hai and then baaki saare answers recursive call krke hi nikal jayenge!
// So lets see...  so the rat at (0,0) can move D/U/L/R...now in the maze above, we can see pehle rat sirf ye check krega ki kahaa move kr rsata hai, so agar rat right move krta hai toh vahaa toh 0 hai so that is not possible and then U and L me toh matrix hi khatam ho jaa rha hai toh vahaa bhi move nhi kr sakta! so the only option left is DOWN, so rat D move kiya and now rat ke path me abhi "D" save hogya, now same condition check krte krte rat kuch iss tarah ke path pr move kiya...Path : "DDRDR",
// now ab ye cheez hai ki rat kya pta jab (3,2) pr pohoche toh vo R ki jagah vapis L jaane lage, toh uss case me vo aise path pr vapis move krne lagega jo vo already visit kr chuka hai toh yahaa pr hume ek visited vaala matrix bhi banana padega taaki rat unn paths pr vapis na ajaye jo vo already visit kr chuka hai! so we will create another matrix with name visited jisko hum initially 0 se initiallize krdenge and jaise jaise jin jin path pr rat visit kr chuka hoga unko hum 1 set krdenge!
// Now visited array jo hai usko hum rat ke movement ke hisaab se 1 ya 0 marks krte rahenge, so ab rat jab (0,0) se D gya toh visited array ke (0,0) pr 1 mark hogya, then jab vo ek baar aur D gya toh visited array ke (1,0) pr bhi 1 mark hogya! and aise hi krte krte jin jin sections pr rat move krta gya toh unn unn sections ke corresponding jo visited array me sections the unpr 1 mark hote gya!
// and in the end jo path aaya that was Path : "DDRDRR" and visited array inn corresponding sections '1' se marked honge! So this was one pass or solution!
// So what we can conclude from this is that whenever we move from one section to other we chcek some safety factors like, 1) Next moevement hum jis section me krna chah rhe hai vo section matrix ke andar honi chaiye! 2) jo next section pr hum jaana chah rhe hai vo section M[k][l] = 1 hona chahiye! 3) jis next section pr mai rat jaa rha hai vo section Visited array me 0 marked hona chahiye means, Visited[k][l] = 0. Then whenever we move from one section to another then uss section ke corresponding section ko hum 0 mark krdete hai visited array me!
// Now, jab ek baar humne ek path poora nikal liya toh next path ke liye ab humara rat vapis (n-1,n-1) se (0,0) pr jayega, toh jab vapis rat jaa rha hoga toh uss time unn sab sections jisse rat pehli baar me end tak aaya tha unn sabko vapis 0 mark krdena hai visited array me, taaki hum dusra path nikal sake! from this we mean it when function call returns then we mark that path back to '0' -> This is the backtracking vaala portion!
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>>& m ) {
    // Now basically hum iss function ki help se bss ye check krenge ki konse sections visit kr sakte hai konse nhi
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}

void solve(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) { // this is the recursion function!
    // Now when you enter this function means you have started the journey means currently you are (0,0)
    // Lets first create the base case!
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }
    // Ab yahaa pehle hum (0,0) ke liye visited ko 1 mark krdete hai!
    visited[x][y] = 1;
    // Now yahaa se hum ab D/U/L/R jaa sakte hai!
    // For Down...
    int newx = x+1;
    int newy = y;
    // Now lets check that ki kya DOWN jaana safe hai ki nhi? for that lets create a function!
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back(); // Ye tab hoga jab hum hum ek path end to end nikal chuke hai then ab dusri possible path dhundne ke liye hume pehle is path variable me jo pehle vaali path stored hai usko nikalna padega, so bss vhi pop kr rhe hai hum! 
    }

    // For Up...
    newx = x-1;
    newy = y;
    // Now lets check that ki kya UP jaana safe hai ki nhi? for that we have again used the safe function!
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    // For Left...
    newx = x;
    newy = y-1;
    // Now lets check that ki kya UP jaana safe hai ki nhi? for that we have again used the safe function!
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    // For Right...
    newx = x;
    newy = y+1;
    // Now lets check that ki kya UP jaana safe hai ki nhi? for that we have again used the safe function!
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }

    // Now ab final ke baar jab saare paths discover hojaye toh vapis visited array ko 0 mark krdo...
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>>& m, int n) { // here m is the maze and n is the size of the maze (number of rows and columns)
    // We are adding a safe condition that agar jo (0,0) hai vo khud hi 0 padaa hua ho toh toh mtlb ki source bhi nhi aa sakta! in that case we will return ki no path possible!
    vector<string> ans;
    if(m[0][0] == 0) {
        return ans;
    }
    int srcx = 0;
    int srcy = 0;
    // Creating the visited array...
    vector<vector<int>> visited(n, vector<int>(n, 0));
    // And initiallizing it with 0
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            visited[i][j] = 0;
        }
    }
    // Creating a string to save path...
    string path = "";
    solve(m,n,ans,srcx,srcy,visited,path);
    // Now we want our answer sorted, so for this we will use a inbuild function of string to sort the final ans!
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    };
    int size = maze.size();
    
    // Find path
    vector<string> paths = findPath(maze, size);
    cout << "Possible paths: " << endl;
    for(int i = 0; i < paths.size(); ++i) {
        cout << paths[i] << endl;
    }
}
// So this is how you solved the Rat Maze Problem!
// Try the dry run it will be lengthy but you will learn!