#include<iostream>
#include<vector>
#include<algorithm> // To use the sort function
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr1, int n) {
    vector<vector<int>> ans;
    for(int i=0; i<arr1.size(); i++) {
        for(int j=i+1; j<arr1.size(); j++) {
            if(arr1[i] + arr1[j] == n) {
                vector<int> temp;
                temp.push_back(min(arr1[i], arr1[j]));
                temp.push_back(max(arr1[i], arr1[j]));
                ans.push_back(temp); // isme agar tum ye socho ki 1D vector ko 2D vector me kaise input kiya, toh iska answer ye hai ki, ans is vector of vectors, toh ye input me 1D vectors ko hi store krega! isko aise samajh lo ki jaise normal 1D vector me atomic int values store hoti hai! vaise hi 2D vector me linear vectors store hote hai! toh agar initially ans = [[]] aise tha, toh jab first time temp input hua hoga, toh iske andar ek vector gya hoga! toh ab ye update hoke ans = [[a,b]] ban jayega! and then jab dusri iteration me firse pair of values temp me store hoke ek vector ke form me and vaale 2D vector me store hone ayengi toh firse ans vector update hojayega with ans = [[a,b],[c,d]] and so on... 
            }
        }
    }
    sort(ans.begin(), ans.end()); // ye dusri vaali condition ki, list of pairs should be sorted primarily by the first value of the pairs, and if two pairs have the same first value, they should be sorted by the second value ye cheez sort function khud hi handle kr le rha hai! we dont need to do something else more!
    return ans;
}

int main() {
    int value;
    cin>>value;
    int size1;
    cin>>size1;
    vector<int> arr1(size1);
    for(int i=0; i<size1; i++) {
        cin>>arr1[i];
    }
    vector<vector<int>> result = pairSum(arr1, value);
    cout << "Intersection: ";
    for (vector<int> pair : result) {
        cout << "(" << pair[0] << ", " << pair[1] << ") ";
    }
}