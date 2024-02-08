#include <iostream>
using namespace std;

class Queue {
    int size = 1000;
    int *arr;
    int front = -1;
    int rear = -1;

public:
    Queue() {
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

    bool enque(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            return false; // Queue is full
        } else {
            if (front == -1) {
                front = rear = 0; // If the queue was empty, set front and rear to 0
            } else {
                rear = (rear + 1) % size;
            }
            arr[rear] = value;
            return true;
        }
    }

    int deque() {
        if (front == -1) {
            return -1; // Queue is empty
        } else {
            int x = arr[front];
            if (front == rear) {
                front = rear = -1; // If there was only one element in the queue, reset front and rear
            } else {
                front = (front + 1) % size;
            }
            return x;
        }
    }
};

int main() {
    Queue q1;
    q1.enque(21);
    q1.enque(22);
    q1.enque(23);
    int ele = q1.deque();
    cout << "Dequeued element: " << ele << endl;

    return 0;
}
