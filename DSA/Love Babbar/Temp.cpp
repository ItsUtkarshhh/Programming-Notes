#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[], int size) {
    int j;
    for(int i = 1; i < size; i++) {
        int temp = arr[i];
        for(int j = i-1; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
    printArray(arr,size);
}

int main() {
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    insertionSort(arr,10);
    // insertionSort2(arr,10);
}


#include<iostream>
using namespace std;

void merge(int* arr, int s, int e) {
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - s;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArrayIndex = s;
    for(int i = 0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = s;
    int index1 = 0;
    int index2 = 0;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(int* arr, int s, int e) {
    if(s>=e) {
        return;
    }
    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}


int main() {
    int size;
    cin>>size;

    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }

    mergeSort(arr, 0, size);
    for(int i = 0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

#include<iostream>
using namespace std;

void pattern1(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<n; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern2(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void pattern3(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern4(int n) {
    int count = 1;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

void pattern5(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern6(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void pattern7(int n) {
    int count = 1;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

void pattern8(int n) {
    for(int i = 1; i<=n; i++) {
        int count = i;
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

void pattern8B(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i+(j-1)<<" ";
        }
        cout<<endl;
    }
}

void pattern9(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i-(j-1)<<" ";
        }
        cout<<endl;
    }
}

void pattern10(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<char('A'+(j-1))<<" ";
        }
        cout<<endl;
    }
}

void pattern11(int n) {
    char val = 'A';
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<val<<" ";
        }
        val++;
        cout<<endl;
    }
}

void pattern12(int n) {
    for(int i = 1; i<=n; i++) {
        char val = 'A';
        for(int j = 1; j<=n; j++) {
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void pattern13(int n) {
    char val = 'A';
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void pattern14(int n) {
    for(int i = 0; i<n; i++) {
        char val = 'A'+i;
        for(int j = 0; j<=i; j++) {
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void pattern15(int n) {
    char val = 'A';
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<val<<" ";
        }
        val++;
        cout<<endl;
    }
}

void pattern16(int n) {
    char val = 'A';
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void pattern17(int n) {
    for(int i = 0; i<n; i++) {
        char val = 'A'+i;
        for(int j = 0; j<=i; j++) {
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void pattern18(int n) {
    for(int i = 1; i<=n; i++) {
        char val = 'A'+(n-i);
        for(int j = 1; j<=i; j++) {
            cout<<val<<" ";
            val++;
        }
        cout<<endl;
    }
}

void pattern19(int n) {
    for(int i = 1; i<=n; i++) {
        for(int space = n-i; space>0; space--) {
            cout<<" "<<" ";
        }
        for(int j = 1; j<=n-(n-i); j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern20(int n) {
    for(int i = 1; i<=n; i++) {
        for(int j = n; j>=i; j--) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void pattern21(int n) {
    for(int i = 1; i<=n; i++) {
        int space = i-1;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        for(int j = n-i; j>=0; j-- ) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    pattern1(n);
    cout<<endl;
    pattern2(n);
    cout<<endl;
    pattern3(n);
    cout<<endl;
    pattern4(n);
    cout<<endl;
    pattern5(n);
    cout<<endl;
    pattern6(n);
    cout<<endl;
    pattern7(n);
    cout<<endl;
    pattern8(n);
    cout<<endl;
    pattern8B(n);
    cout<<endl;
    pattern9(n);
    cout<<endl;
    pattern10(n);
    cout<<endl;
    pattern11(n);
    cout<<endl;
    pattern12(n);
    cout<<endl;
    pattern13(n);
    cout<<endl;
    pattern14(n);
    cout<<endl;
    pattern15(n);
    cout<<endl;
    pattern16(n);
    cout<<endl;
    pattern17(n);
    cout<<endl;
    pattern18(n);
    cout<<endl;
    pattern19(n);
    cout<<endl;
    pattern20(n);
    cout<<endl;
    pattern21(n);
}

#include<iostream>
using namespace std;

void fibseries(int n) {
    if(n == 0) {
        cout<<0;
    }
    if(n == 1) {
        cout<<0<<" "<<1;
    }
    int first = 0;
    int second = 1;
    int next = first + second;
    cout<<0<<" "<<1<<" ";
    while(next <= n) {
        cout<<next<<" ";
        first = second;
        second = next;
        next = first + second;
    }
}

int main() {
    int n;
    cin>>n;
    fibseries(n);
}

#include<iostream>
using namespace std;

int main() {
    int n1, n2;
    cin>>n1>>n2;
    int result = min(n1,n2);
    while(result > 0) {
        if(n1 % result == 0 && n2 % result == 0) {
            break;
        }
        result--;
    }
    cout<<result;
}

#include<iostream>
using namespace std;

int add(int n1) {
    int ans = 0;
    while(n1 != 0) {
        int digit = n1 % 10;
        ans = ans + digit;
        n1 = n1/10;
    }
    return ans;
}

int prod(int n1) {
    int ans = 1;
    while(n1 != 0) {
        int digit = n1 % 10;
        ans = ans * digit;
        n1 = n1/10;
    }
    return ans;
}

int finalans(int n1) {
    if(add(n1) > prod(n1)) {
        return add(n1) - prod(n1);
    }
    else {
        return prod(n1) - add(n1);
    }
}

int main() {
    int n1;
    cin>>n1;
    cout<<finalans(n1);
}


#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int count = 0;
    while(n != 0) {
        if(n & 1) {
            count++;
        }
        n = n>>1;
    }
    cout<<count;
}

#include<iostream>
#include<math.h>
using namespace std;

int dtob1(int n) {
    int ans = 0;
    int i = 0;
    while(n != 0) {
        int digit = n%2;
        ans = (ceil(pow(10,i)) * digit) + ans;
        i++;
        n = n/2;
    }
    return ans;
}

int dtob2(int n) {
    int ans = 0;
    int i = 0;
    while(n != 0) {
        int digit = n&1;
        ans = (ceil(pow(10,i)) * digit) + ans;
        i++;
        n = n>>1;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<dtob1(n);
    cout<<endl;
    cout<<dtob2(n);
}

#include<iostream>
using namespace std;

void printBin(int n) {
    for(int i = sizeof(n)*8 - 1; i>=0; i--) {
        cout<<((n >> i) & 1);
    }
}

int main() {
    int n;
    cin>>n;
    printBin(n);
}

#include<iostream>
#include<math.h>
using namespace std;

void btod(int n) {
    int ans = 0;
    int i = 0;
    while(n != 0) {
        int digit = n%10;
        if(digit) {
            ans = ceil(pow(2,i)) + ans;
        }
        i++;
        n = n/10;
    }
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    btod(n);
}

#include<iostream>
#include<climits>
using namespace std;

void reverse(int n) {
    int ans = 0;
    while(n != 0) {
        if(ans*10 > INT_MAX || ans*10 < INT_MIN) {
            cout<<0;
        }
        int digit = n%10;
        ans = (ans * 10) + digit;
        n = n/10;
    }
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    reverse(n);
}

#include<iostream>
using namespace std;

void complement(int n) {
    int mask = 0;
    int temp = n;
    while(temp != 0) {
        mask = (mask << 1) | 1;
        temp = temp >> 1;
    }
    int ans = (~n) & mask;
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    complement(n);
}

#include<iostream>
using namespace std;

void swapalt(int arr[], int n) {
    for(int i = 0; i<n; i = i+2) {
        if(i+1 < n) {
            swap(arr[i], arr[i+1]);
        }
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[1000] = {0};
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    swapalt(arr,n);
}

#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = (int*)calloc(n,sizeof(n));
    int max_element = INT_MIN;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        max_element = max(arr[i], max_element);
    }

    int* freq = (int*)calloc(max_element+1,sizeof(n));
    for(int i = 0; i<n; i++) {
        freq[arr[i]]++;
    }
    int ans = 0;
    bool found = false;
    for(int i = 0; i<=max_element; i++) {
        if(freq[i] == 1) {
            ans = i;
            found = true;
            break;
        }
    }
    cout<<ans;
    if(found == false) {
        cout<<"No Unique Element found!";
    }
}

#include<iostream>
#include<map>
using namespace std;

int main() {
    int n;
    cin>>n;
    map<int,int> mp;
    int num;
    for(int i = 0; i<n; i++) {
        cin>>num;
        mp[num]++;
    }
    for(auto it:mp) {
        cout<<"Occurence of :"<<it.first<<" is : "<<it.second<<endl;
    }
}

#include<iostream>
using namespace std;

void findUniq(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i<n; i++) {
        ans = ans^arr[i];
    }
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    findUniq(arr,n);
}

#include<iostream>
using namespace std;

findDuplicate(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i<n; i++) {
        ans = ans^i;
    }
    for(int i = 0; i<n; i++) {
        ans = ans^arr[i];
    }
    cout<<ans;
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    findDuplicate(arr,n);
}

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> intersection(vector<int> arr1, int size1, vector<int> arr2, int size2) {
    vector<int> temp;
    for(int i = 0; i<size1; i++) {
        int element = arr1[i];
        for(int j = 0; j<size2; j++) {
            if(element < arr2[i]) {
                break;
            }
            if(element == arr2[j]) {
                temp.push_back(element);
                arr1[i] = INT_MIN;
                break;
            }
        }
    }
    return temp;
}

int main() {
    int size1;
    cin>>size1;
    vector<int> arr1(size1);
    for(int i = 0; i<size1; i++) {
        cin>>arr1[i];
    }

    int size2;
    cin>>size2;
    vector<int> arr2(size2);
    for(int i = 0; i<size2; i++) {
        cin>>arr2[i];
    }

    vector<int> ans = intersection(arr1, size1, arr2, size2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}


#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> intersection(vector<int> arr1, int size1, vector<int> arr2, int size2) {
    vector<int> temp;
    int i = 0; int j = 0;
    while(i<size1 && j<size2) {
        int element = arr1[i];
        if(element == arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(element < arr2[i]) {
            i++;
        }
        else {
            j++;
        }
    }
    return temp;
}

int main() {
    int size1;
    cin>>size1;
    vector<int> arr1(size1);
    for(int i = 0; i<size1; i++) {
        cin>>arr1[i];
    }

    int size2;
    cin>>size2;
    vector<int> arr2(size2);
    for(int i = 0; i<size2; i++) {
        cin>>arr2[i];
    }

    vector<int> ans = intersection(arr1, size1, arr2, size2);
    for(int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> pairsum(vector<int> arr, int n, int sum) {
    vector<vector<int>> pair;
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            if(arr[i] + arr[j] == sum) {
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                pair.push_back(temp);
            }
        }
    }
    sort(pair.begin(), pair.end());
    return pair;
}

int main() {
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    vector<vector<int>> ans = pairsum(arr, n, sum);
    for(vector<int> pair : ans) {
        cout<<"("<<pair[0]<<","<<pair[1]<<")"<<endl;
    }
}

#include<iostream>
using namespace std;

void sort01(int arr[], int n) {
    int i = 0;
    int j = n-1;
    while(i<j) {
        while(arr[i] == 0 && i<j) {
            i++;
        }
        while(arr[j] == 1 && i<j) {
            j--;
        }
        if(i<j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[1000];
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    sort01(arr,n);
}

#include<iostream>
#include<math.h>
using namespace std;

void series(int n) {
    cout<<1<<" ";
    for(int i = 1; i<n; i++) {
        int seq = ((i+1) * ceil(pow(10,i))) + (i+1);
        cout<<seq<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    series(n);
}

#include<iostream>
using namespace std;

int peakElement(int arr[], int size) {
    if(size==0) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[size-1] > arr[size-2]) return arr[size-1];
    int s = 0;
    int e = size-1;
    int mid = s + (e-s)/2;
    while(s<=e) {
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return arr[mid];
        }
        else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) {
            s = mid + 1;
        }
        else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<peakElement(arr,n);
}

#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    int start = s;
    int end = e-1;
    int mid = start + (end-start)/2;
    while(start<=end) {
        if(arr[mid] == key) {
            return mid;
        }
        if(arr[mid] > key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int pivot(int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] <= arr[0]) {
            e = mid;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int findElement(int arr[], int n, int key) {
    int pivotElement = pivot(arr,n);
    int s = 0;
    int e = n-1;
    if(key > arr[0] && key < arr[pivotElement]) {
        return binarySearch(arr,0,pivotElement-1,key);
    }
    else {
        return binarySearch(arr,pivotElement,e,key);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<findElement(arr,n,key);
}

#include<iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end-start)/2;
    while(start<=end) {
        if(arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int pivot(int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int findElement(int arr[], int n, int key) {
    int pivotIndex = pivot(arr,n);
    if(key >= arr[pivotIndex] && key <= arr[n-1]) {
        cout<<"HI";
        return binarySearch(arr,pivotIndex,n-1,key);
    }
    else {
        return binarySearch(arr,0,pivotIndex-1,key);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<"Index of the key : "<<findElement(arr, n, key);
}


#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    int minIndex = 0;
    for(int i = 0; i<n; i++) {
        minIndex = i;
        for(int j = i+1; j<n; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void BubbleSort(int arr[], int n) {
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void InsertionSort(int arr[], int n) {
    
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    SelectionSort(arr,n);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }

    BubbleSort(arr,n);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}


#include<iostream>
using namespace std;

void bubbleSort2(int arr[], int n) {
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j<n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
    swap(arr[minIndex], arr[i]);
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[], int n) {
    int j;
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        for(j = i-1; j>=0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    bubbleSort2(arr,n);
    selectionSort(arr,n);
    insertionSort(arr,n);
}

#include<iostream>
using namespace std;

void reverseAfter(int arr[], int n, int m) {
    int s = m;
    int e = n-1;
    while(s<e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int after;
    cin>>after;
    reverseAfter(arr,n,after);
}


#include<iostream>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2) {
    int n3 = n1 + n2;
    int* arr3 = new int[n3];
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<n1 && j<n2) {
        if(arr1[i] <= arr2[j]) {
            arr3[k++] = arr1[i++]; 
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while(i<n1) {
        arr3[k++] = arr1[i++];
    }
    while(j<n2) {
        arr3[k++] = arr2[j++];
    }
    for(int i = 0; i<n3; i++) {
        cout<<arr3[i]<<" ";
    }
}

int main() {
    int arr1[1000] = {0};
    int n1;
    cin>>n1;
    for(int i = 0; i<n1; i++) {
        cin>>arr1[i];
    }

    int arr2[1000] = {0};
    int n2;
    cin>>n2;
    for(int i = 0; i<n2; i++) {
        cin>>arr2[i];
    }
    mergeArrays(arr1,n1,arr2,n2);
}

#include<iostream>
using namespace std;

void moveZeroes(int arr[], int n) {
    int j = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    moveZeroes(arr,n);
}

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int> v, int k) {
    vector<int> temp(v.size());
    for(int i = 0; i<v.size(); i++) {
        temp[(k+i)%v.size()] = v[i];
    }
    v = temp;
    for(int i : v) {
        cout<<i<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v1(n);
    for(int i = 0; i<n; i++) {
        cin>>v1[i];
    }
    int k;
    cin>>k;
    rotate(v1,k);
}




#include<iostream>
using namespace std;

int pivot(int arr[], int n) {
    if(n == 0) return -1;
    if(arr[n-1] > arr[0]) return 0;

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

bool SortedandRotated(int arr[], int n) {
    if(n == 0) return false;
    int pivotIndex = pivot(arr, n);
    if (pivotIndex == 0) {
        return true;
    }

    for(int i = 0; i<pivotIndex-1; i++) {
        if(arr[i] > arr[i+1]) return false;
    }
    for(int i = pivotIndex; i<n-1; i++) {
        if(arr[i] > arr[i+1]) return false;
    }
    if (arr[n - 1] > arr[0]) return false;
    return true;
}

int main() {
    int n;
    cin>>n;
    int arr[1000] = {0};
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<SortedandRotated(arr,n);
}

#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& v) {
    int s = 0;
    int e = v.size()-1;
    while(s<e) {
        swap(v[s],v[e]);
        s++;
        e--;
    }
}

void sum(int arr1[], int n1, int arr2[], int n2) {
    int carry = 0;
    int i = n1-1; int j = n2-1;
    int value = 0;
    vector<int> v;
    while(i >= 0 && j >= 0) {
        int val1 = arr1[i];
        int val2 = arr2[j];
        value = carry + val1 + val2;
        value = value%10;
        carry = value/10;
        v.push_back(value);
        i--;
        j--;
    }
    while(i >= 0) {
        int val1 = arr1[i];
        value = carry + val1;
        value = value%10;
        carry = value/10;
        v.push_back(value);
        i--;
    }
    while(j >= 0) {
        int val2 = arr2[j];
        value = carry + val2;
        value = value%10;
        carry = value/10;
        v.push_back(value);
        j--;
    }
    while(carry != 0) {
        v.push_back(carry%10);
        carry = carry/10;
    }
    reverse(v);
    for(int i : v) {
        cout<<i;
    }
}

int main() {
    int n1,n2;
    cin>>n1>>n2;
    int arr1[100] = {0};
    int arr2[100] = {0};
    for(int i = 0; i<n1; i++) {
        cin>>arr1[i];
    }
    for(int i = 0; i<n2; i++) {
        cin>>arr2[i];
    }
    sum(arr1,n1,arr2,n2);
}


#include<iostream>
using namespace std;

bool isValid(string s1) {
    int i = 0;
    if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9') {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string str = "utka&%$$%&aktu";
    if(isPalindrome(str)) {
        cout<<"it is a Palindrome!";
    }
    else {
        cout<<"Not a palindrome!";
    }
}