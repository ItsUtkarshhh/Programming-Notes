// Addition of two matrices!
#include<iostream>
using namespace std;

int** Addition(int** m1, int** m2, int rows, int cols) {
    int** result = new int*[rows];
    for(int i = 0; i<rows; i++) {
        result[i] = new int[cols];
        for(int j = 0; j<cols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
    delete[] result;
}

int main() {
    int row;
    int col;
    cin>>row>>col;

    // Matrix1
    int** Matrix1 = new int*[row];
    for(int i = 0; i<row; i++) {
        Matrix1[i] = new int[col];
    }
    // Matrix1 input!
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>Matrix1[i][j];
        }
        cout<<endl;
    }

    // Matrix2
    int** Matrix2 = new int*[row];
    for(int i = 0; i<row; i++) {
        Matrix2[i] = new int[col];
    }
    // Matrix2 input!
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>Matrix2[i][j];
        }
        cout<<endl;
    }

    int** ans = Addition(Matrix1,Matrix2,row,col);

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    delete[] Matrix1;
    delete[] Matrix2;
}

// Multiplication of Two Matrix :
#include<iostream>
using namespace std;

int** productOfMatrix(int** Matrix1, int rowM1, int colM1, int** Matrix2, int rowM2, int colM2) {
    // Resultant matrix created!
    int** result = new int*[rowM1];
    for(int i = 0; i < rowM1; i++) {
        result[i] = new int[colM2];
    }

    // Matrix multiplication logic
    for(int i = 0; i < rowM1; i++) {
        for(int j = 0; j < colM2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < colM1; k++) {
                result[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rowM1;
    int colM1;
    cout<<"Enter number of rows and cols for M1 ";
    cin>>rowM1>>colM1;

    int rowM2;
    int colM2;
    cout<<"Enter number of rows and cols for M2 ";
    cin>>rowM2>>colM2;

    if(colM1 != rowM2) {
        cout<<"Matrices can not be multiplied!";
        return 0;
    }

    int** Matrix1 = new int*[rowM1];
    for(int i = 0; i<rowM1; i++) {
        Matrix1[i] = new int[colM1];
    }
    
    int** Matrix2 = new int*[rowM2];
    for(int i = 0; i<rowM2; i++) {
        Matrix2[i] = new int[colM2];
    }

    // Input in M1
    for(int i = 0; i<rowM1; i++) {
        for(int j = 0; j<colM1; j++) {
            cin>>Matrix1[i][j];
        }
    }

    // Input in M2
    for(int i = 0; i<rowM2; i++) {
        for(int j = 0; j<colM2; j++) {
            cin>>Matrix2[i][j];
        }
    }

    int** result = productOfMatrix(Matrix1,rowM1,colM1,Matrix2,rowM2,colM2);;

    for(int i = 0; i<rowM1; i++) {
        for(int j = 0; j<colM2; j++) {
            cout<<result[i][j]<<" ";
        }
    }
}

// Transpose of a matrix
#include<iostream>
using namespace std;

int** transpose(int** Matrix, int row, int col) {
    int** result = new int*[col];
    for(int i = 0; i<col; i++) {
        result[i] = new int[row];
    }

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            result[j][i] = Matrix[i][j];
        }
    }
    return result;
}

int main() {
    int row;
    int col;
    cout<<"Enter number of rows and cols ";
    cin>>row>>col;

    int** Matrix = new int*[row];
    for(int i = 0; i<row; i++) {
        Matrix[i] = new int[col];
    }

    for(int i = 0; i<row; i++) {
        for(int j = 0; j<col; j++) {
            cin>>Matrix[i][j];
        }
        cout<<endl;
    }

    int** result = transpose(Matrix,row,col);

    for(int i = 0; i<col; i++) {
        for(int j = 0; j<row; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    // Freeing allocated memory!
    for(int i = 0; i < row; i++) {
        delete[] Matrix[i];
    }
    delete[] Matrix;

    for(int i = 0; i < col; i++) {
        delete[] result[i];
    }
    delete[] result;
}

// Swapping three numbers
#include<iostream>
using namespace std;

void cyclicOrder(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a,b,c;
    cin>>a>>b>>c;

    cyclicOrder(a,b,c);

    cout<<a<<b<<c;
}