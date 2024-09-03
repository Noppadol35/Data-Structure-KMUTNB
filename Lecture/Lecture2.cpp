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
                if (empty()){
                    front = 0;
                }
                rear++;
                Array[rear] = data;
            } 
            else {
                cout << "Queue is full" << endl;
            }
        }

        int dequeue() { // stack same pop
            if (!empty()) {
                int temp = Array[front];
                if (front == rear){
                    front = rear = -1;
                } else {
                    front++;
                }
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
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.print();
    return 0;
}