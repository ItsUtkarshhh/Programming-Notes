// ------------------------------------------------------------ Lec 1 : Easy ---------------------------------------------------------------------------------------------->
// Question 1 : Largest element in the array!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    cout<<"Max value of the array : "<<maxVal;
} // TC : O(n) and SC : O(1) rest all methods will be overkill.

// Question 2 : Find the largest element in the array!
#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int max1 = arr[0];
    int max2 = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] < max1 && arr[i] > max2) {
            max2 = arr[i];
        }
    }
    if(max2 == INT_MIN) {
        cout<<-1;
    }
    else {
        cout<<"Second largest element of the array : "<<max2;
    }
}

// Question 3 : Check if an array is sorted or not!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool sorted = true;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            sorted = false;
            break;
        }
    }
    if(sorted) {
        cout<<"Array is sorted!";
    }
    else {
        cout<<"Not sorted!";
    }
}

// Generalise it for ascending and descending order!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bool ascending = true;
    bool descending = true;
    for(int i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            ascending = false;
        }
        if(arr[i] < arr[i+1]) {
            descending = false;
        }
    }
    if(ascending) cout<<"Array is sorted in ascending order!";
    else if(descending) cout<<"Array is sorted in ascending order!";
    else cout<<"Not sorted at all!";
}

// Question 4 : Remove Duplicates in-place from Sorted Array!
#include<iostream>
#include<vector>
using namespace std;

vector<int> removeDuplicates(vector<int> v) {
    vector<int> ans;
    vector<bool> dupExist(v.size(), true);
    for(int i = 0; i<v.size(); i++) {
        int val = v[i];
        for(int j = i+1; j<v.size(); j++) {
            if(val == v[j] && i != j) {
                dupExist[j] = false;
            }
        }
    }
    for(int i = 0; i<dupExist.size(); i++) {
        if(dupExist[i]) {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    vector<int> res = removeDuplicates(v);
    for(int i = 0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
} // Not optimal solution! as TC : O(n^2) and as here two vectors are created hence the SC : O(n)! and primarily it is not in-place!

// Better solution : As the array is sorted! we can do the in-place sorting!
//                 : Actually what we wanted to do is : Remove duplicates in-place such that each element appears only once and return the new length. It does not matter what you leave beyond the new length.
//                                                    : Means, as per our constraints, we just need to return a new length of the sorted array where there is no duplicates also it must be in-place means no extra space should be used! 
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &v) {
    int i = 0; int j = 1;
    for(int j = 1; j<v.size(); j++) {
        if(v[i] != v[j]) {
            i++;
            v[i] = v[j];
        }
    }
    return i+1; // Returning the new size!
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int newSize = removeDuplicates(v);
    for(int i = 0; i<newSize; i++) { // The duplicates are still there in the array! its just that we have combined the unique elements together and returned the size accordingly so that we dont encounter duplicates anymore!
        cout<<v[i]<<" ";
    }
}

// Question 5 : Left rotate an array by one place!
// Approach 1 : Using reverse trick!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void leftRotate(vector<int> &v) {
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.end()-1);
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    leftRotate(v);
    for(int i = 0; i<n; i++) {
        cout<<v[i]<<" ";
    }
}

// Approach 2 : Using simple logic or shifting!
#include<iostream>
#include<vector>
using namespace std;

void leftRotate(vector<int> &v) {
    int temp = v[0];
    for(int i = 0; i<v.size()-1; i++) {
        v[i] = v[i+1];
    }
    v[v.size()-1] = temp;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++) {
        cin>>v[i];
    }
    leftRotate(v);
    for(int i = 0; i<n; i++) {
        cout<<v[i]<<" ";
    }
}

// Question 6 : Rotate array by K elements left or right!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateArray(vector<int>& v, char side, int k) {
    int n = v.size();
    if(n == 0) return;
    k = k % n; // Handle large k

    if(side == 'L') {
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
        reverse(v.begin(), v.end());
    }
    else if(side == 'R') {
        reverse(v.begin(), v.end());
        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
    }
    else {
        cout << "Enter valid side!" << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int places;
    cout << "How many places? : ";
    cin >> places;
    char side;
    cout << "Which side? (L/R): ";
    cin >> side;
    
    rotateArray(v, side, places);
}

// Question 7 : Move zeroes to the end!
#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int> &v) {
    int i = 0;
    int j = v.size() - 1;
    while(i < j) {
        if(v[i] == 0 && v[j] == 0) {
            j--;
        }
        else if(v[i] != 0 && v[j] != 0) {
            i++;
        }
        else if(v[i] == 0 && v[j] != 0) {
            swap(v[i], v[j]);
            i++; j--;
        }
        else {
            i++; j--;
        }
    }
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    return;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    moveZeroes(v);
} // Problem with it is that it disrupts the relative order of elements!

// Better approach :
#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& v) {
    int lastNonZeroIndex = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != 0) {
            swap(v[i], v[lastNonZeroIndex]);
            lastNonZeroIndex++;
        }
    }
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    return;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    moveZeroes(v);
}

// Question 8 : Linear Search in C
#include<iostream>
#include<vector>
using namespace std;

void linearSearch(vector<int> v, int key) {
    for(int i = 0; i<v.size(); i++) {
        if(key == v[i]) {
            cout<<"Key present at "<<i<<endl;
            return;
        }
    }
    cout<<"Key not found!";
    return;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int key;
    cout<<"Enter key : ";
    cin>>key;
    linearSearch(v, key);
}

// Question 9 : Union of Two Sorted Arrays!
#include<iostream>
#include<vector>
using namespace std;

vector<int> unionOfArrays(vector<int> v1, vector<int> v2) {
    int i = 0, j = 0;
    vector<int> ans;
    
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            if(ans.empty() || ans.back() != v1[i]) 
                ans.push_back(v1[i]);
            i++;
        }
        else if(v2[j] < v1[i]) {
            if(ans.empty() || ans.back() != v2[j]) 
                ans.push_back(v2[j]);
            j++;
        }
        else { // Equal elements
            if(ans.empty() || ans.back() != v1[i]) 
                ans.push_back(v1[i]);
            i++;
            j++;
        }
    }
    
    while(i < v1.size()) {
        if(ans.empty() || ans.back() != v1[i]) 
            ans.push_back(v1[i]);
        i++;
    }
    
    while(j < v2.size()) {
        if(ans.empty() || ans.back() != v2[j]) 
            ans.push_back(v2[j]);
        j++;
    }
    
    return ans;
}

int main() {
    int n1, n2;
    cout << "Enter the size 1 : ";
    cin >> n1;
    cout << "Enter the size 2 : ";
    cin >> n2;

    vector<int> v1(n1), v2(n2);
    
    cout << "Enter array elements of array 1 : ";
    for(int i = 0; i < n1; i++) {
        cin >> v1[i];
    }
    
    cout << "Enter array elements of array 2 : ";
    for(int i = 0; i < n2; i++) {
        cin >> v2[i];
    }
    
    vector<int> res = unionOfArrays(v1, v2);
    
    cout << "Union of arrays: ";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}


// Question 9.2 : Intersection of Two Sorted Arrays!
#include<iostream>
#include<vector>
using namespace std;

vector<int> intersectionOfArrays(vector<int> v1, vector<int> v2) {
    int i = 0; int j = 0;
    vector<int> ans;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] == v2[j]) {
            if(ans.empty() || ans.back() != v1[i]) {
                ans.push_back(v1[i]);
            }
            i++; j++;
        }
        else if(v1[i] > v2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    return ans;
}

int main() {
    int n1, n2;
    cout << "Enter the size 1 : ";
    cin >> n1;
    cout << "Enter the size 2 : ";
    cin >> n2;

    vector<int> v1(n1), v2(n2);
    
    cout << "Enter array elements of array 1 : ";
    for(int i = 0; i < n1; i++) {
        cin >> v1[i];
    }
    
    cout << "Enter array elements of array 2 : ";
    for(int i = 0; i < n2; i++) {
        cin >> v2[i];
    }
    
    vector<int> res = intersectionOfArrays(v1, v2);
    
    cout << "Union of arrays: ";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}