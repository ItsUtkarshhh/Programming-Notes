// Implementation of Stack using Arrays!
#include<iostream>
using namespace std;

class Stack {
    private:
    int size;
    int* arr = NULL; // Thi
    int top;

    public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    Stack(const Stack &other) {
        this->size = other.size;
        this->top = other.top;

        this->arr = new int[size];
        for(int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if(this == &other) return *this;

        delete[] arr;

        size = other.size;
        top = other.top;

        arr = new int[size];

        for(int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }

        return *this;
    }

    ~Stack() {
        delete []arr;
    }

    void push(int val) {
        if(top == size - 1) {
            cout<<"Stack Overflow";
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop() {
        if(top < 0) {
            cout<<"Stack Underflow";
            return;
        }
        top--;
    }

    int peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack2 {
    private:
    Node* top;

    public:
    Stack2() {
        this->top = NULL;
    }

    Stack2(const Stack2 &other) {
        if(other.top == NULL) {
            this->top = NULL;
            return;
        }

        this->top = new Node(other.top->data);
        Node* currThis = top;
        Node* currOther = other.top->next;

        while(currOther != NULL) {
            currThis->next = new Node(currOther->data);
            currOther = currOther->next;
            currThis = currThis->next;
        }
    }

    Stack2& operator=(const Stack2& other) {
        if(this == &other) {
            return *this;
        }

        while(top != NULL) {
            Node* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }

        if(other.top == NULL) {
            this->top = NULL;
            return *this;
        }

        this->top = new Node(other.top->data);
        Node* currThis = top;
        Node* currOther = other.top->next;

        while(currOther != NULL) {
            Node* newNode = new Node(currOther->data);
            currThis->next = newNode;
            currThis = newNode;
            currOther = currOther->next;
        }
        return *this;
    }

    ~Stack2() {
        while(top != NULL) {
            Node* temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == NULL) {
            cout<<"Stack Underflow";
            return;
        }
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }

    int peek() {
        return top->data;
    }

    int stackSize() {
        int len = 0;
        Node* temp = top;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    bool isEmpty() {
        return top == NULL;
    }
}

int main() {
    Stack st1(5);

    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);


}