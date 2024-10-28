#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=n) {
            if(i==1 || i==n || j==1 || j==n) {
                cout<<"*"<<" ";
            }
            else {
                cout<<" ";
            }
            j++;
        }
        cout<<endl;
        i++;
    }
}

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = 1;
    while(i<=n) {
        int j = 1;
        while(j<=i) {
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}


#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i = n;
    while(i>=1) {
        int j = 1;
        while(j<=i) {
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i--;
    }
}