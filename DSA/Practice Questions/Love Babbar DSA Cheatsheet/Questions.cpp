// Array!
// Question 1 (GFG) : Reverse an Array!
#include<iostream>
using namespace std;

void printArray(int* arr, int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverseArray(int* arr, int n) {
    if(n == 0) {
        cout<<"Empty array!";
        return;
    }
    int s = 0;
    int e = n-1;
    while(s<e) {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    printArray(arr,n);
}

int main() {
    int n;
    cin>>n;
    int* arr1 = new int[n]();
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    reverseArray(arr1,n);
    delete[] arr1;
}

// Question 2 (GFG) : Max/Min Number of an Array!
#include<iostream>
#include<climits>
#include<utility> // For pair
using namespace std;

pair<int,int> MaxMin(int* arr, int n) {
    pair<int,int> ans(0,0); // pair constructor to initialise values.
    // pair<int,int> ans = make_pair(0,0); // Or can use make_pair() method.
    if(n == 0) {
        cout<<"Empty array!";
        return ans;
    }
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    for(int i = 0; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    ans.first = min;
    ans.second = max;
    return ans;
}

int main() {
    int n;
    cin>>n;
    int* arr1 = new int[n]();
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    pair<int,int> res = MaxMin(arr1,n);
    cout<<"Minimum Value : "<<res.first<<endl;
    cout<<"Maximum Value : "<<res.second<<endl;
    delete[] arr1;
}

// Question 3 (GFG) : Find Kth Smallest Element of the array!
#include<iostream>
#include<climits>
using namespace std;

int partition(int* arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1; i<e; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[s],arr[pivotIndex]);

    int i = s; int j = e-1;
    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i] < arr[pivotIndex]) {
            i++;
        }
        while(arr[j] > arr[pivotIndex]) {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i++],arr[j--]);
        }
    }
    cout<<"Pivot Index : "<<pivotIndex<<endl;
    return pivotIndex;
}

int KthSmallestElement(int* arr, int s, int e, int k) {
    if(s<=e) {
        int pivotIndex = partition(arr,s,e);
        if(pivotIndex == k-1) {
            return arr[pivotIndex];
        }
        else if(pivotIndex > k-1) {
            return KthSmallestElement(arr,s,pivotIndex,k);
        }
        else {
            return KthSmallestElement(arr,pivotIndex+1,e,k);
        }
    }
    return INT_MAX;
}

int main() {
    int n;
    cin>>n;
    int* arr1 = new int[n]();
    for(int i = 0; i<n; i++) {
        cin>>arr1[i];
    }
    int k;
    cin>>k;
    cout<<KthSmallestElement(arr1,0,n,k);
}

// Question 4 (GFG) : Find Kth Largest Element of the array!


// Strings!
// Question 1 : Palindrome!
#include<iostream>
#include<string>
using namespace std;

char lowercase(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool valid(char ch) {
    if(ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z') {
        return true;
    }
    return false;
}

bool Palindrome(string str) {
    if(str.length() == 0) return false;
    if(str.length() == 1) return true;
    string temp = "";
    for(int i = 0; i<str.length(); i++) {
        if(valid(str[i])) {
            temp.push_back(str[i]);
        }
    }
    for(int i = 0; i<temp.length(); i++) {
        temp[i] = lowercase(temp[i]);
    }

    int s = 0;
    int e = temp.length()-1;
    while(s<e) {
        if(temp[s] == temp[e]) {
            s++;
            e--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cin>>str; // Use getline(cin,str); for long strings with gaps
    if(Palindrome(str)) {
        cout<<"Palindrome!";
    }
    else {
        cout<<"Not a Palindrome!";
    }
}

// Question 2 : Reverse a string!
#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int start = 0;
    int end = s.size()-1;
    while(start<end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main() {
    int n;
    cin>>n;
    vector<char> str(n);
    for(int i = 0; i<n; i++) {
        cin>>str[i];
    }
    reverseString(str);
    for(int i = 0; i<str.size(); i++) {
        cout<<str[i];
    }
}

// Question 3 : Find all duplicate characters in a string!
#include<iostream>
#include<string>
using namespace std;

void printDuplicates(string str) {
    int count[26] = {0};
    int index = 0;
    for(int i = 0; i<str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            index = str[i] - 'a';
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            index = str[i] - 'A';
        }
        else {
            continue;
        }
        count[index]++;
    }

    bool foundDuplicate = false;
    cout << "Duplicate characters : ";
    for(int i = 0; i<26; i++) {
        if(count[i] > 1) {
            cout<<char('a'+i)<<" ";
            foundDuplicate = true;
        }
    }

    if(!foundDuplicate) {
        cout<<"None";
    }
}

int main() {
    string str;
    cin>>str;
    printDuplicates(str);
}

// Bit Manipulation!
// Question 1 : Count number of set bits! (Bits that are 1)
#include<iostream>
using namespace std;

int setBits(int n) {
    int count = 0;
    while(n!=0) {
        if(n&1) {
            count++;
        }
        n = n>>1;
    }
    return count;
}

int main() {
    int n;
    cin>>n;
    cout<<setBits(n);
}

// Question 2 (GFG) : Non Repeating Numers!
// Submitted Approach!
#include<vector>
#include<iostream>
using namespace std;

vector<int> singleNumber(vector<int>& arr) {
    int max = INT_MIN;
    for(int i = 0; i<arr.size(); i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    int* count = new int[max+1]();
    for(int i = 0; i<arr.size(); i++) {
        count[arr[i]]++;
    }
    
    vector<int> ans;
    for(int i = 0; i<=max; i++) {
        if(count[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> ans = singleNumber(arr);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}

// Optimized Approach :
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> singleNumber(vector<int>& arr) {
    unordered_map<int, int> count;
    for (int num : arr) {
        count[num]++;
    }
    vector<int> ans;
    for (const auto& entry : count) {
        if (entry.second == 1) { // Element appears exactly once
            ans.push_back(entry.first);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans = singleNumber(arr);
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
