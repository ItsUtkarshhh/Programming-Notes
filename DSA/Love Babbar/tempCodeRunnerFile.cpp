#include<iostream>
using namespace std;

class Deque {
    int *arr;  // Array to store deque elements
    int front; // Front index
    int rear;  // Rear index
    int size;  // Maximum capacity

public:
    // Constructor to initialize deque of given size
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Insert an element at the front
    bool push_front(int x) {
        // Check if deque is full
        if (isFull()) return false;

        // If deque is empty, insert first element
        if (front == -1) {
            front = rear = 0;
        }
        // If front is at first position, move it to end (circular behavior)
        else if (front == 0) {
            front = size - 1;
        }
        // Normal case: Move front backward
        else {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Insert an element at the rear
    bool push_rear(int x) {
        // Check if deque is full
        if (isFull()) return false;

        // If deque is empty, insert first element
        if (front == -1) {
            front = rear = 0;
        }
        // If rear is at the last position, move it to start (circular behavior)
        else if (rear == size - 1) {
            rear = 0;
        }
        // Normal case: Move rear forward
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Remove and return an element from the front
    int pop_front() {
        // Check if deque is empty
        if (isEmpty()) return -1;

        int ans = arr[front];
        arr[front] = -1;

        // If only one element was present, reset deque
        if (front == rear) {
            front = rear = -1;
        }
        // If front reaches the last position, wrap around
        else if (front == size - 1) {
            front = 0;
        }
        // Normal case: Move front forward
        else {
            front++;
        }
        return ans;
    }

    // Remove and return an element from the rear
    int pop_rear() {
        // Check if deque is empty
        if (isEmpty()) return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        // If only one element was present, reset deque
        if (front == rear) {
            front = rear = -1;
        }
        // If rear is at the first position, move it to the end
        else if (rear == 0) {
            rear = size - 1;
        }
        // Normal case: Move rear backward
        else {
            rear--;
        }
        return ans;
    }

    // Get the front element without removing it
    int getFront() {
        return isEmpty() ? -1 : arr[front];
    }

    // Get the rear element without removing it
    int getRear() {
        return isEmpty() ? -1 : arr[rear];
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if deque is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % size));
    }
};

// Main function to test deque operations
int main() {
    Deque q1(10); // Create a deque of size 10

    q1.push_front(12); // Insert 12 at the front
    q1.push_rear(14);  // Insert 14 at the rear

    cout << "Front of the queue: " << q1.getFront() << endl; // Prints 12
    cout << "Back of the queue: " << q1.getRear() << endl;   // Prints 14

    q1.pop_front(); // Removes 12, front moves forward

    cout << "Front of the queue: " << q1.getFront() << endl; // Prints 14
    cout << "Back of the queue: " << q1.getRear() << endl;   // Prints 14

    q1.pop_rear(); // Removes 14, making the queue empty

    // Check if queue is empty
    if (q1.isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    // Check if queue is full
    if (q1.isFull()) {
        cout << "Queue is full!" << endl;
    } else {
        cout << "Queue is not full!" << endl;
    }

    return 0;
}