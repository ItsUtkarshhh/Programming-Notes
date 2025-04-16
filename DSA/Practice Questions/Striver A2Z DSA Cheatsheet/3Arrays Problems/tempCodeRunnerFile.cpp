#include<iostream>
#include<vector>
using namespace std;

vector<int> intersectionOfArrays(vector<int> v1, vector<int> v2) {
    int i = 0; int j = 0;
    vector<int> ans;
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] == v2[j]) {
            ans.push_back(v1[i]);
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