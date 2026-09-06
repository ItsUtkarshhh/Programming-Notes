// ------------------------------------------------------- Question 1 : Largest Element ----------------------------------------------------------------------------------------------------------->
// Brute Force : Sort the array and return the (n-1)th element of the array.
// Better : Perform a linear traversal and iteratively find the largest value.

// Better :
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    int maxi = INT_MIN;
    for(int i = 0; i < size; i++) {
        maxi = max(maxi, v[i]);
    }

    cout<<"Maximum Value : "<<maxi<<endl;
}

// ------------------------------------------------------- Question 2 : Second Largest Element ----------------------------------------------------------------------------------------------------------->
// Brute Force : Sort the array in ascending order and get the (n-2)th element
// Better : Traverse the array, and maintain two values largest and second largest at every iteration, and by the end of the array, you will get the second largest.

// Better :
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    int maxi = INT_MIN;
    int secondMaxi = maxi;
    for(int i = 0; i < size; i++) {
        if(v[i] > secondMaxi && v[i] > maxi) {
            secondMaxi = maxi;
            maxi = v[i];
        }
        else if(v[i] > secondMaxi && v[i] < maxi) {
            secondMaxi = v[i];
        }
    }

    if(secondMaxi == INT_MIN) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<"Second Maximum Value : "<<secondMaxi<<endl;
}

// ------------------------------------------------------- Question 3 : Check if an Array is Sorted (Ascending) ----------------------------------------------------------------------------------------------------------->
// Brute Force : Keep comparing the next element to its previous element and if at any moment the next element is smaller than the previous element, then simply return false/unsorted.

// Brute Force
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }

    for(int i = 0; i < size - 1; i++) {
        if(v[i] > v[i+1]) {
            cout<<"Unsorted Array!";
            return 0;
        }
    }
    cout<<"Sorted Array!";
    return 0;
}

// ------------------------------------------------------- Question 4 : Remove Duplicates in-place from Sorted Array ----------------------------------------------------------------------------------------------------------->
// Brute Force : (Not In Place) - Insert all the elemeents into a set and then insert back them into the original vector and decrease the size of the original vector to its new length.
// Better : As the is sorted, we can traverse using two pointers, one will take care of the last unique element and the other will traverse further over duplicates until a new unique element occurs & then will resize the vector accordingly.

#include<iostream>
#include<set>
using namespace std;

// Brute Force
void removeDuplicates1(vector<int> &v) {
    if(v.empty()) {
        cout<<"Array is empty!";
        return;
    }
    
    set<int> st(v.begin(), v.end());
    
    int i = 0;
    for(int val : st) {
        v[i++] = val;
    }
    
    v.resize(st.size);
}

// Better
void removeDuplicates2(vector<int> &v) {
    if(v.empty()) {
        cout<<"Array is empty!";
        return;
    }
    
    int i = 0; int j = i+1;
    while(j < v.size()) {
        if(v[i] != v[j]) {
            i++;
            v[i] = v[j];
        }
        j++;
    }
    
    v.resize(i+1);
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    removeDuplicates1(v);
    // removeDuplicates2(v);
    
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// ------------------------------------------------------- Question 5 : Left Rotate the Array by One ----------------------------------------------------------------------------------------------------------->
// Brute Force : Simply store the first value in a variable and shift the rest of the array by one towards left and update the last value with the stored value.
// Better : Conceptually divide the arrays into three sections, index0 - (k-1), k - indexN & index0 - indexN, and Reverse the three sections one by one.

// Brute Force
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force
void leftRotateByOneA(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }

    int val = v[0];
    for(int i = 0; i < v.size() - 1; i++) {
        v[i] = v[i+1];
    }

    v[v.size() - 1] = val;
}

// Better
void leftRotateByOneB(vector<int> &v, int k) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }
    
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    reverse(v.begin(), v.end());
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    int k;
    cin>>k;
    
    // leftRotateByOneA(v);
    leftRotateByOneB(v, k);

    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// ------------------------------------------------------- Question 6 : Move all Zeros to the end of the array (Mainting Relative Order) ----------------------------------------------------------------------------------------------------------->
// Brute Force : Input all values to temporary array & then append number of zeroes as present in the original array.
// Better : (Order not maintained) Use two pointers, keep one at starting & another at the end, and swap based on zero and non zero conditions.
// Optimal : Use the read & write pointer strategy, as similar as removing duplicates problem, where one pointer will keep the track of the last non zero value & read pointer will track the next zero values and will swap/assign.

#include<iostream>
#include<vector>
using namespace std;

// Better
void moveZeroesToEnd(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }
    
    int i = 0; int j = v.size() - 1;
    while(i < j) {
        if(v[i] == 0 && v[j] == 0) j--;
        else if(v[i] != 0 && v[j] == 0) j--;
        else if(v[i] != 0 && v[j] != 0) i++;
        else {
            swap(v[i], v[j]);
            i++; j--;
        }
    }
}

// Optimal
void moveZeroesToEnd(vector<int> &v) {
    if(v.empty()) {
        cout<<"Empty array!";
        return;
    }
    
    int i = 0; int j = 0;
    while(j < v.size()) {
        if(v[j] != 0) {
            swap(v[i], v[j]);
            i++;
        }
        j++;
    }
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    moveZeroesToEnd(v);
    
    for(int i = 0; i < size; i++) {
        cout<<v[i]<<" ";
    }
}

// ------------------------------------------------------- Question 7 : Linear Search ----------------------------------------------------------------------------------------------------------->
// Brute Force : Traverse the array linear way and compare it with the key at every iteration and if matches, return true or that element as per the need.

// Brute Force
#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int> &v, int key) {
    if(v.empty()) return false;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == key) return true;
    }
    return false;
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    int key;
    cin>>key;
    cout<<linearSearch(v, key);
}

// ------------------------------------------------------- Question 8 : Union of Two Sorted Arrays ----------------------------------------------------------------------------------------------------------->
// Brute Force : Traverse the first array, and traverse the second arrays nested to the first traversal, insert the value once in the result, and mark both of them traversed if matches found. Move forward
// Better : 

// Brute Force :
#include<iostream>
#include<vector>
using namespace std;

vector<int> unionOfTwoArrays(vector<int> v1, vector<int> v2) {
    if(v1.empty()) return v2;
    if(v2.empty()) return v1;

    vector<int> result;
    for(int i = 0; i < v1.size(); i++) {
        for(int j = 0; j < v2.size(); j++) {
            if(v1[i] != v2[j]) {
                result.push_back(v1[i]);
                result.push_back(v2[j]);
            }
            else if(v1[i] == v2[j]) {
                result.push_back()
            }
        }
    }
}

int main() {
    int size;
    cin>>size;
    
    vector<int> v(size);
    for(int i =  0; i < size; i++) {
        cin>>v[i];
    }
    
    
}