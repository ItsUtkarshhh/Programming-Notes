// ------------------------------------------------------------ Lec 2 : Medium ---------------------------------------------------------------------------------------------->
// Question 1 : Two Sum!
//            : Variant 1 : Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
//            : Variant 2 : Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
//            : Conditions : You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
// Approach (Brute Force) for V1 : Try every valid pair (i, j) and check if v[i] + v[j] == k.
//                               : Time : O(n²) → Slow for large arrays
//                               : Space : O(1)
#include<iostream>
#include<vector>
using namespace std;

bool twoSum1_V1(vector<int> v, int k) {
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] + v[j] == k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    if(twoSum1_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Better Approach) for V1 : Store frequency of each element in a map. (ordered/unordered) - better if unordered!
//                                   : For each number, check if k - num exists in the map.
//                                   : Time : O(n) average (with unordered_map)
//                                   : Space : O(n)
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

bool twoSum2_V1(vector<int> v, int k) {
    int n = v.size();
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[v[i]]++;
    }
    
    for(int i = 0; i < n; i++) {
        int complement = k - v[i];
        if(mp.count(complement)) {
            if(complement != v[i] || mp[v[i]] > 1) {
                return true;
            }
        }
    }
    return false;
}

bool twoSum3_V1(vector<int> v, int k) {
    int n = v.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[v[i]]++;
    }

    for(int i = 0; i < n; i++) {
        int complement = k - v[i];
        if(mp.count(complement)) {
            if(complement != v[i] || mp[v[i]] > 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    if(twoSum2_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";

    if(twoSum3_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Optimal Approach) for V1 : While traversing, check if k - num is already seen.
//                                    : Time : O(n) average
//                                    : Space : O(n)
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool twoSum4_V1(vector<int> v, int k) {
    unordered_set<int> seen;
    for (int num : v) {
        if (seen.count(k - num)) return true;
        seen.insert(num);
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    if(twoSum4_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Optimal Solution) for V1 when array is sorted! : Two pointers!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool twoSum5_V1(vector<int> v, int k) {
    sort(v.begin(), v.end());
    int n = v.size();
    int i = 0; int j = n - 1;
    int sum = 0;
    while(i < j) {
        sum = v[i] + v[j];
        if(sum == k) return true;
        if(sum > k) j--;
        else i++;
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    if(twoSum5_V1(v, k)) cout<<"Yes exist!";
    else cout<<"No!";
}

// Approach (Brute Force) for V2 : Try every valid pair (i, j) and check if v[i] + v[j] == k.
//                               : Time : O(n²) → Slow for large arrays
//                               : Space : O(1)
#include<iostream>
#include<vector>
using namespace std;

pair<int, int> twoSum1_V2(vector<int> v, int k) {
    int n = v.size();
    pair<int, int> valPair;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] + v[j] == k) {
                valPair.first = i;
                valPair.second = j;
                return valPair;
            }
        }
    }
    return {-1, -1};
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    pair<int, int> ans = twoSum1_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}

// Approach (Better Solution) for V2 : Traverse the array, and keep checking whether its complement exists! if no then insert it with its index!
//                                   : Otherwise, if the complement exists, then simply return the pair!
//                                   : Time Complexity : O(n)
//                                   : Space Complexity : O(n)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int, int> twoSum2_V2(vector<int> v, int k) {
    unordered_map<int, int> seen;
    for(int i = 0; i < v.size(); i++) {
        int val = v[i];
        if(seen.find(k - val) != seen.end()) {
            return {seen[k - val], i};
        }
        seen[val] = i;
    }
    return {-1, -1};
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    pair<int, int> ans = twoSum2_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}

// // Approach (Optimal Solution) for V2 when array is sorted! : Two pointers!
#include<iostream>
#include<vector>
using namespace std;

pair<int, int> twoSum2_V2(vector<int> v, int k) {
    int n = v.size();
    vector<pair<int, int>> arr;  // {value, original index}
    for (int i = 0; i < n; i++) {
        arr.push_back({v[i], i});
    }

    sort(arr.begin(), arr.end());

    int i = 0; int j = n - 1;
    while(i < j) {
        int sum = arr[i].first + arr[j].first;
        if (sum == k) return {arr[i].second, arr[j].second}; // return indices of original array!
        if(sum > k) j--;
        else i++;
    }
    return {-1, -1};
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int k;
    cin>>k;
    pair<int, int> ans = twoSum2_V2(v, k);
    cout<<"["<<ans.first<<", "<<ans.second<<"]"<<endl;
}