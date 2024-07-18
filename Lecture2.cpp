#include<iostream>
using namespace std;

class Queue {
    public:
        int Array[6];
        int size = 6;
        int front = -1;
        int rear = -1;

        bool empty(){
            return (front == -1 && rear == -1);
        }

        bool full(){
            return (rear == size - 1);
        }

        void enqueue(int data) { // stack same push 
            if (!full()) {
                rear++;
                Array[rear] = data;

                if (!empty()){
                    front++;
                }
            } 
                
        }

        int dequeue() { // stack same pop
            if (!empty()) {
                int temp = Array[front];
                front++;
                return temp;
            }
            return -1;
        }

        void print() {
            if (empty()) {
                cout << "Queue is empty" << endl;
            } else {
                for (int i = front; i <= rear; i++) {
                    cout << Array[i] << " ";
                }
                cout << endl;
            }
        }
};

int main () {
    Queue q;
    
    return 0;
}