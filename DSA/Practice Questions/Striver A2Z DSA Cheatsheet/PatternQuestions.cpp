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
    for(int i = 1; i<=n; i++) {
        if(i%2 != 0) {
            int start = 1;
            for(int j = 1; j<=i; j++) {
                cout<<start<<" ";
                start = 1 - start;
            }
        }
        if(i%2 == 0) {
            int start = 0;
            for(int j = 1; j<=i; j++) {
                cout<<start<<" ";
                start = 1 - start;
            }
        }
        cout<<endl;
    }
}

// Pattern 12 : Print a pattern like 1 _ _ _ _ 1 -> 1 2 _ _ 2 1 -> 1 2 3 3 2 1 and similarly!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<j<<" ";
        }
        int space = 2*n - 2*i;
        while(space) {
            cout<<" "<<" ";
            space = space - 1;
        }
        for(int j = i; j>=1; j--) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Pattern 13 : Print a pattern counting 1 to n.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int count = 1;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}

// Pattern 14 : Print a pattern A -> A B -> A B C -> A B C D and so on
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<i; j++) {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 15 : Print a pattern A B C D E -> A B C D -> A B C -> A B -> A.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 0; j<=(n-i); j++) {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 16 : Print a pattern A -> B B  -> C C C and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=i; j++) {
            cout<<char('A'+i)<<" ";
        }
        cout<<endl;
    }
}

// Pattern 17 : Print a pattern pytramid A -> A B A -> A B C B A and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        int space = n-i;
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        char ch = 'A';
        for(int j = 1; j<=(2*i)-1; j++) {
            cout<<ch<<" ";
            if(j <= i-1) ch++;
            else ch--;
        }

        space = n-i;
        while(space) {
            cout<<" "<<" ";
            space--;
        }
        cout<<endl;
    }
}

// Pattern 18 : Print a pattern right angled pytramid E -> D E -> C D E and so on...
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        char ch = 'A'+(n-i);
        for(int j = 1; j<=i; j++) {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

// Pattern 19 : Print a pattern Anti-diamond!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }

        for(int space = 1; space<(2*i)-1; space++) {
            cout<<" "<<" ";
        }

        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i = n; i>=1; i--) {
        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }

        for(int space = (2*i)-1; space>1; space--) {
            cout<<" "<<" ";
        }

        for(int star = 0; star<=n-i; star++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

// Pattern 20 : Print a butterfly pattern!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        int star = i;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }

        int space = (2*n) - (2*i);
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        star = i;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }
        cout<<endl;
    }
    for(int i = 0; i<n; i++) {
        int star = (n-i)-1;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }

        int space = 2*i+2;
        while(space) {
            cout<<" "<<" ";
            space--;
        }

        star = (n-i)-1;
        while(star) {
            cout<<"*"<<" ";
            star--;
        }
        cout<<endl;
    }
}

// Pattern 21 : Print square stroke patterns!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        if(i == 1) {
            int stars = n;
            while(stars) {
                cout<<"*"<<" ";
                stars--;
            }
        }

        if(i > 1 && i < n) {
            cout<<"*"<<" ";
            int spaces = n - 2;
            while(spaces) {
                cout<<" "<<" ";
                spaces--;
            }
            cout<<"*"<<" ";
        }

        if(i == n) {
            int stars = n;
            while(stars) {
                cout<<"*"<<" ";
                stars--;
            }
        }
        cout<<endl;
    }
}

// Better Approach!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(i == 1 || i == n || j == 1 || j == n) {
                cout<<"*"<<" ";
            }
            else cout<<" "<<" ";
        }
        cout<<endl;
    }
}

// Pattern 22 : Print a unique numerical pattern, go to sheet to see the pattern!
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i<(2*n-1); i++) {
        for(int j = 0; j<(2*n-1); j++) {
            int top = i;
            int left = j;
            int bottom = (2*n - 2) - i;
            int right = (2*n - 2) - j;
            cout<<(n - min(min(top,bottom), min(right,left)))<<" ";
        }
        cout<<endl;
    }
} // Re-solve this again, after sometime!