// Problem Statement : Imagine you are given an array like : [1, 2, 1, 3, 2] and Now, someone asks : "How many times does 1 appear?" or "How many times does 2, 3, 4, or even 10 appear?"
//                   : The brute-force way would be : Use a count variable. Loop through the whole array every time you want to count how many times a number appears.
//                   : So if : Array size = n, You want to check frequency of q numbers. Then the Time Complexity becomes : O(n) for each number → Total = O(q * n)
//                   : Now Think : If both n and q are large (like 10⁵), then: Total operations = 10^5 * 10^5 = 10^10 But we know: 10^8 operations ≈ 1 second, So, 10¹⁰ operations ≈ 100 seconds (Too slow!)
//                   : Solution : Hashing (PreStore and Fetch)
//                              : Let’s say the maximum number in the array is 12.
//                              : Step 1 : Create a new array called hash of size 13 (to include index 0 to 12).
//                              : Step 2 : Initialize it with zeros: hash = [0, 0, 0, ..., 0] (13 times)
//                              : Step 3 : Loop through the original array. For every element, do: hash[element]++, This means you're counting how many times each number appears and storing it in the hash array.
//                              : Now, whenever someone asks : "How many times does 1 appear?" → Just check hash[1], "How many times does 4 appear?" → Just check hash[4]
//                              : Its Super fast! Just O(n) time for pre-processing and after that, each query takes O(1) time.
// Question 1 : Count frequency of each element in the array
// Using array hashing!
#include <iostream>
#include <vector>
using namespace std;

// Brute-force function
void bruteForceFrequency(vector<int>& arr, vector<int>& queries) {
    cout << "Brute Force Method:\n";
    for (int q : queries) {
        int count = 0;
        for (int num : arr) {
            if (num == q) count++;
        }
        cout << "Frequency of " << q << " is: " << count << endl;
    }
}

// Hashing function
void hashingFrequency(vector<int>& arr, vector<int>& queries, int maxVal) {
    cout << "\nHashing Method:\n";
    vector<int> hash(maxVal + 1, 0); // Step 1: Create hash array of size maxVal+1
    for (int num : arr) { // Step 2: Preprocessing - count frequency
        hash[num]++;
    }
    for (int q : queries) { // Step 3: Answering queries in O(1)
        cout << "Frequency of " << q << " is: " << hash[q] << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 2};
    vector<int> queries = {1, 2, 3, 4, 10};
    int maxVal = 12; // Given or assumed max element value

    bruteForceFrequency(arr, queries); // Brute Force

    hashingFrequency(arr, queries, maxVal); // Hashing

    return 0;
}
// Here we did, number hashing, same way we can do character hashing! like we could be given a string and then we may be asked to print the frequency of certain characters that also we can do just by character - 'a' or character - 'A', this all we have already done!

// Problem with hash-array : Let’s say you are given an array like: arr[] = {1, 2, 3, 2, 1, 12}; Now if you want to count the frequency of each element, a simple way is to create a hash-array of size 13 (because max element = 12), and store the counts at respective indices.
//                         : hash[1] = 2, hash[2] = 2, hash[3] = 1, hash[12] = 1. So later, if someone asks how many times 1 occurs, just do hash[1] and you get the answer 2. This method is fast — time complexity is O(N) — but the space required can be a problem.
//                         : What if elements are large? Now suppose an element in your array is as big as 10^9. Then you’d need a hash-array of size 10^9 + 1. This is not possible, because: Maximum size of an integer array inside main() is around 10^6, In global scope, you can go up to 10^7. For boolean arrays, you can go up to 10^7 (in main) or 10^8 (in global scope)
//                         : So clearly, creating a large hash-array for values like 10^9 is not feasible.

// Solution : Use Maps or Unordered Maps (Hash Maps)
//          : To solve this, we use: map / unordered_map in C++ STL, HashMap in Java
//          : With maps, you don’t need to store all values from 0 to max number. You only store the numbers that actually exist in the array — which saves a lot of space!
//          : For example, for array {1, 2, 3, 2, 1, 12}, map will store: 1->2, 2->2, 3->1, 12->1, Only 4 keys instead of using size 13.
//          : Time Complexity : For map (ordered map): Insertion: O(log N) and Fetching: O(log N). Internally uses: Red-Black Tree
//                            : For unordered_map: Insertion: Average case O(1), Worst case O(N) and Fetching: Average case O(1), Worst case O(N). Internally uses: Hash Table
//                            : In most cases, unordered_map is preferred because of its average case speed O(1), which is much faster than O(log N) of map.
//                            : Only use map if: You need sorted order or unordered_map is giving Time Limit Exceeded (TLE) (rare, but possible due to collisions)
//          : Why do collisions happen in unordered_map? Let’s understand with a small example using the Division Method of hashing : array = {2, 5, 16, 28, 139} and hash size = 10 (just for example, you can scale it for larger values and sizes)
//                                                                                                                                  : Doing ar[i]%10 for each element, the hash-array will be [_, _, 2, _, _, 5, 16, _, 28, 139]. Now, if you want to find frequency of 139, you just do 139 % 10 = 9, and check index 9. and you will get the start of the LL, and then you can use any optimal sorting or searching algo to find the count of it!
//                                                                                                                                  : Problem with Collisions : Let’s take a case where many elements give the same modulo result : array = {8, 18, 28, 38, 48, 58, 68, 78, 88, 98, 1008, 10008, 1000008}
//                                                                                                                                  : In this case, everything gets stored at index 8 of the hash-array like this: hash[8] = 8 → 18 → 28 → 38 → ... → 1000008. Index 8 becomes a long linked list, and searching in that becomes linear (O(N)) instead of O(1). This is what causes the worst-case time complexity of O(N) in unordered_map.
// Using Maps!
#include <iostream>
#include <map>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 1, 12};
    int n = 6;
    map<int, int> mpp; // Ordered map
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++; // Count frequency
    }
    for (auto it : mpp) {
        cout << "Element: " << it.first << " -> Frequency: " << it.second << endl;
    }
    return 0;
}

// Using Unordered-Maps!
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 2, 1, 12};
    int n = 6;
    unordered_map<int, int> mpp; // Unordered map
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++; // Count frequency
    }
    for (auto it : mpp) {
        cout << "Element: " << it.first << " -> Frequency: " << it.second << endl;
    }
    return 0;
}

// Question 2 : Find the highest/lowest frequency element
#include<iostream>
#include<map>
#include<climits>
#include<vector>
using namespace std;

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    map<int,int> freq;
    for(int i = 0; i<6; i++) {
        freq[arr[i]]++;
    }

    for(auto i : freq) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    vector<int> maxFE;
    int maxF = INT_MIN;
    vector<int> minFE;
    int minF = INT_MAX;
    
    for(auto i : freq) {
        if(i.second > maxF) {
            maxF = i.second;
            maxFE.clear(); // clear old elements
            maxFE.push_back(i.first);
        }
        else if(i.second == maxF) {
            maxFE.push_back(i.first);
        }

        if(i.second < minF) {
            minF = i.second;
            minFE.clear();
            minFE.push_back(i.first);
        }
        else if(i.second == minF) {
            minFE.push_back(i.first);
        }
    }
    cout << "Max frequency element(s): ";
    for(auto val : maxFE) cout << val << " ";
    cout << "\n";

    cout << "Min frequency element(s): ";
    for(auto val : minFE) cout << val << " ";
    cout << "\n";
}