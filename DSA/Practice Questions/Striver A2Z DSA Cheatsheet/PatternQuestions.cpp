// Pattern 1 : Simple square/rectangle * pattern! * * * * * -> * * * * * -> * * * * * -> * * * * * ...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 2 : One sided * triangle pattern! * -> * * -> * * * -> * * * * ...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 3 : One sided triangle number pattern! 1 -> 1 2 -> 1 2 3 -> 1 2 3 4 ...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Pattern 4 : One sided triangle number pattern! 1 -> 2 2 -> 3 3 3 -> 4 4 4 4 ...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

// Pattern 5 : Horizontally Reverse * traingle pattern! * * * * -> * * * -> * * -> * ...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n+1-i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 6 : Horizontally Reverse counting traingle pattern! 1 2 3 4 -> 1 2 3 -> 1 2 -> 1 ...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n+1-i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Pattern 7 : * pyramid!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 8 : Reverse * pyramid!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = n; i>=1; i--) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = (2*i)-1; j>=1; j--) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 9 : Mixture of reverse and un-reverse * pyramid! - Diamond Shape!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
    for(int i = n; i>=1; i--) {
        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }

        for(int j = (2*i)-1; j>=1; j--) {
            cout<<"*"<<" ";
        }

        for(int space = 0; space<n-i; space++) {
            cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 10 : 90 deg rotated Pyramid!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=(n-i); j++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }    
}

// Pattern 11 : Print pattern like 1 -> 0 1 -> 1 0 1 -> 0 1 0 1...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int binary = 1;
    for(int i = 1; i<=n; i++) {
        if(i%2 != 0) {
            binary = 1;
        }
        else {
            binary = 0;
        }
        for (int j = 1; j<=i; j++) {
            cout<<binary<<" ";
            binary = 1 - binary;
        }
        cout<<endl;
    }
}

// Pattern 12 : Print pattern like 1 -> 0 1 -> 1 0 1 -> 0 1 0 1...
