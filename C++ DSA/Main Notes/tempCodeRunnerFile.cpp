#include<iostream>
using namespace std;

int main() {
    {
        cout << "Answer of first block : ";
        int a, b = 1;
        a = 10;
        if (++a) {
            cout << b;
        } else {
            cout << ++b;
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of second block : ";
        int a = 1;
        int b = 2;
        if (a-- > 0 && ++b > 2) {
            cout << "Stage 1 - Inside If ";
        } else {
            cout << "Stage 2 - Inside Else ";
        }
        cout << a << " " << b;
    }
    cout << endl << endl;
    {
        cout << "Answer of third block : ";
        int a = 1;
        int b = 2;
        if (a-- > 0 || ++b > 2) {
            cout << "Stage 1 - Inside If ";
        } else {
            cout << "Stage 2 - Inside Else ";
        }
        cout << a << " " << b;
    }
    cout << endl << endl;
    {
        cout << "Answer of fourth block : ";
        int a = 1;
        int b = 2;
        if (a-- > 0 || ++b > 2) {
            cout << "Stage 1 - Inside If ";
        } else {
            cout << "Stage 2 - Inside Else ";
        }
        cout << a << " " << b;
    }
    cout << endl << endl;
    {
        cout << "Answer of fifth block : ";
        int number = 3;
        cout << 25 * (++number);
    }
    cout << endl << endl;
    {
        cout << "Answer of sixth block : ";
        int a = 1;
        int b = a++;
        int c = ++a;
        cout << a << " " << b << " " << c;
    }
    cout << endl << endl;
    {
        cout << "Answer of seventh block : ";
        for (int i = 0; i <= 5; i++) {
            cout << i << " ";
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of eighth block : ";
        for (int i = 0; i <= 5; ++i) {
            cout << i << " ";
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of ninth block : ";
        for (int i = 0; i <= 15; i += 2) {
            cout << i << " ";
            if (i & 1) {
                continue;
            }
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of tenth block : ";
        for (int i = 0; i < 5; i++) {
            for (int j = i; j <= 5; j++) {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << endl << endl;
    {
        cout << "Answer of eleventh block : ";
        for (int i = 0; i < 5; i++) {
            for (int j = i; j <= 5; j++) {
                if (i + j == 10) {
                    break;
                }
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}