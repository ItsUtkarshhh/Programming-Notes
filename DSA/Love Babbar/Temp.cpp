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