// Average of numbers
#include<iostream>
using namespace std;

double average(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum)/n;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<average(arr,n);
}

// Largest element of the array!
#include<iostream>
#include<climits>
using namespace std;

int largestValue(int* arr, int n) {
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i]>maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<largestValue(arr,n);
}

// Find standard deviation
#include<iostream>
#include<cmath>
using namespace std;

double average2(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum)/n;
}

double variance(int* arr, int n) {
    double mean = average2(arr, n);
    double sumOfSquares = 0; // Use double for more precision

    for(int i = 0; i < n; i++) {
        double diff = arr[i] - mean;
        sumOfSquares += diff * diff;
    }
    return sumOfSquares / (n - 1);
}

double morePrecision(int value, int tempSol) {
    int ans = tempSol;
    int factor = 1;
    for(int i = 0; i<3; i++) {
        factor = factor/10;
        for(int j = ans; j*j<value; j=j+factor) {
            ans = j;
        }
    }
    return ans;
}

double squareRoot(double value) {
    if (value < 0) return -1; // Negative value case

    double s = 0;
    double e = value;
    double mid = s + (e - s) / 2.0;
    double ans = 0.0;

    while (s <= e) {
        double square = mid * mid;
        if (abs(square - value) < 0.00001) {  // Precision threshold
            return mid;
        }
        if (square < value) {
            s = mid + 0.00001;
        } else {
            e = mid - 0.00001;
        }
        mid = s + (e - s) / 2.0;
    }
    return ans;
}

double standardDeviation(double varianceValue) {
    return squareRoot(varianceValue);
}

int main() {
    int size;
    cin>>size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++) {
        cin>>arr[i];
    }
    double varianceVal = variance(arr,size);
    cout<<standardDeviation(varianceVal);
}

// Simpler Method
#include <iostream>
#include <cmath>
using namespace std;

float calculateSD(float data[]) {
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;
    for(i = 0; i < 10; ++i) {
        sum += data[i];
    }
    mean = sum/10;
    for(i = 0; i < 10; ++i) {
        standardDeviation += pow(data[i] - mean, 2);
    }
    return sqrt(standardDeviation / 10);
}

int main() {
    int i;
    float data[10];
    cout << "Enter 10 elements: ";
    for(i = 0; i < 10; ++i) {
        cin >> data[i];
    }
    cout << endl << "Standard Deviation = " << calculateSD(data);
    return 0;
}

// Accessing elements using pointers!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    for(int i = 0; i<n; i++) {
        cout<<*(arr+i)<<" ";
    }
}