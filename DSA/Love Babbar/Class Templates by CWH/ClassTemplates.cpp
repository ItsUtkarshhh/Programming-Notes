// -------------------------------------------------------------- Lecture 63 : Introduction to Templates ------------------------------------------------------------------------------------------------------------------>
// Templates : In C++, a template is a feature that allows functions and classes to operate with generic types. This enables code reusability and type safety, as the same code can work with different data types without being rewritten for each type. There are two main types of templates: function templates and class templates.
// Like problem kya ho rhi thi, jiske kaaran hume ye laana pada is, Suppose humne ek class banai "vector" ki and now uss class ke data members hai like, int* arr; int size and so on... ab ye class ko hum use kr sakte hai int type ke vectors class ke objects create krne ke liye! but now, suppose, hume ek vector chahiye float type ka ya char type ka ya kisi aur type ka, toh what we do is, hum vector ki aur dusri classes bnaa lenge jisme int* arr ki jagah float* arr; ya char* arr; hoga!
// And aise hum different types ke vectors bnaa payenge!
// But, now ye krne ka ek isse better ye tareeka hai ki, we use templates! templates ek tarah se generalized cheez hai jo different tarah ke classes create kr sakti hai! Jiss tarah se objects ke kya features hai and vo konse features use kr sakta hai vo uski class se define hote hai! vaise hi ek class ke kya features hai and vo konse features use kr sakta hai vo hum uske template se define kr sakte hai!

// Syntax : Class templates bnaane ke liye sirf itna krna hota hai ki, "template <typename T>" iss line ko add krdo class create krne se pehle and T ki jagah jo data type chahte ho vo likhdo!
// Example :
#include<iostream>
using namespace std;

template <typename T> // "template <class T>" Isko hum aise bhi likh sakte hai koi difference nhi hai, but its a good practice ki hum "typename" use kre taaki zyada clarity rahe!
class Number {
    T num;
    public:
    Number(T v) : num(v) {}
    T dislay() {
        return num;
    }
};

int main() {
    Number<int> Num1(5);
    cout<<Num1.dislay()<<" ";

    Number<float> Num2(5.2);
    cout<<Num2.dislay()<<" ";

    Number<char> Num3('H');
    cout<<Num3.dislay()<<" ";
} // Hence we can see that it can print anything, we just need to change the data type!

// -------------------------------------------------------------- Lecture 64 : Writing First C++ Templates ------------------------------------------------------------------------------------------------------------------>
// This is normal class where we are finding dot product of two vectors of int type!
#include <iostream>
using namespace std;
 
class vector {
    public:
        int *arr;
        int size;
        vector(int m) {
            size = m;
            arr = new int[size];
        }
    int dotProduct(vector &v) {
        int d=0;
        for (int i = 0; i < size; i++) {
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
};
 
int main()
{
    vector v1(3); // vector 1
    v1.arr[0] = 4;
    v1.arr[1] = 3;
    v1.arr[2] = 1;
    vector v2(3); // vector 2
    v2.arr[0]=1;
    v2.arr[1]=0;
    v2.arr[2]=1;
    int a = v1.dotProduct(v2);
    cout<<a<<endl;
    return 0;
} // But now if we want to find dot product of float vectors, do we need to write another class for that? no, we will make templates now!

// Vectors using templates!
#include <iostream>
using namespace std;
 
template <class T> // We have just added this line and replaced all the data types with T!
class vector {
    public:
        T *arr;
        int size;
        vector(int m) {
            size = m;
            arr = new T[size];
        }
    T dotProduct(vector &v){
        T d=0;
        for (int i = 0; i < size; i++) {
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
};
 
int main()
{
    vector<float> v1(3); // vector 1 with a float data type
    v1.arr[0] = 1.4;
    v1.arr[1] = 3.3;
    v1.arr[2] = 0.1;
    vector<float> v2(3); // vector 2 with a float data type
    v2.arr[0]=0.1;
    v2.arr[1]=1.90;
    v2.arr[2]=4.1;
    float a = v1.dotProduct(v2);
    cout<<a<<endl;
    return 0;
}

// -------------------------------------------------------------- Lecture 65 : Templates with multiple pointers! ------------------------------------------------------------------------------------------------------------------>
// Now we can also make templates with multiple parameters! like for example suppose hume ek aisa class chahiye jisme hume 2 arrays chahiye ek int type ka and ek float type ka, in that cases hume iski need hai!
// This is an ordinary example! ki agar do different data types ki value print krni hai toh kaise krenge! abhi ke liye we have taken only int and char!
#include<iostream>
using namespace std;

class myClass {
    public:
        int data1;
        char data2;
    void display(){
        cout<<this->data1<<" "<<this->data2;
    }
}; // Chalo theek hai iss class se int and char type ki values print ho jayengi but what about int float, float char and so on... ab harr alag alag ke liye class thori bnayenge, so we will use templates now!

// using templates with multiple parameters (comma separated!) and also there can be more than 2 parameters of the class!
#include<iostream>
using namespace std;

template<class T1, class T2>
class myClass {
    public:
        T1 data1;
        T2 data2;
        myClass(T1 a,T2 b) {
            data1 = a;
            data2 = b;
        }
    void display() {
        cout<<this->data1<<" "<<this->data2<<endl;
    }
};

int main() {
    myClass<int,float> obj1(1,1.5);
    obj1.display();

    myClass<int,char> obj2(1,'A');
    obj2.display();

    myClass<float,char> obj3(1.5,'A');
    obj3.display();
}
// Here, we can also go wild, by passing classes name in the T1 and T2, but that will go more complex, but keep that under consideration! but for now let it sink in!

// -------------------------------------------------------------- Lecture 66 : Templates with default parameters! ------------------------------------------------------------------------------------------------------------------>
// Jaise functions ke case me default arguments and parameters the, vaise hi yahaa bhi hai!
#include<iostream>
using namespace std;

template <typename T1=int, typename T2=float, typename T3=char> // Ye likhne ke baad agar mai int main me class ke objects ko use krte time koi data type specify nhi krunga toh automatically first value ko int, second value ko float and third ko char data type alot hojayega!
class myClass {
    T1 value1;
    T2 value2;
    T3 value3;
    public :
    myClass(T1 v1, T2 v2, T3 v3) {
        value1 = v1;
        value2 = v2;
        value3 = v3;
    }
    void display() {
        cout<<"Value of value1 : "<<value1<<endl;
        cout<<"Value of value2 : "<<value2<<endl;
        cout<<"Value of value3 : "<<value3<<endl;
    }
};

int main() {
    myClass<> obj1(1,2.5,'A'); // Here humne koi data type specify nhi kiya isliye seedha jo default arguments the vo display hogye!
    obj1.display();

    cout<<endl;

    myClass<float, char, int> obj2(2.5,'A',1);
    obj2.display();
}