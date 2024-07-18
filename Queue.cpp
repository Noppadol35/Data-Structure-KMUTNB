#include <iostream>
using namespace std;

class Queue {
    public:
        int size_arr;
        int *Array = new int[size_arr];
        int front = -1;
        int rear = -1;

        Queue(){
            size_arr = 6;
        }

        Queue(int s) {
            size_arr = s;
        }

        bool empty() {
            return front == -1 && rear == -1 ;
        }

        bool full() { 
            return rear == size_arr - 1;
        }

        void enqueue(int data) { // stack same push 
            if (!full()) {
                if (empty()) {
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
                }  else {
                    front++;
                }
                return temp;
            }
            return -1;
        }

        void print() {
            for (int i = front; i <= rear; i++){
                cout << Array[i]<< " ";
            }
            cout << endl;
        }

        int currentSize() {
            return rear - front + 1;
        }

        int getFront() {
            cout << Array[front] << " ";
            if (!empty()) {
                return Array[front];
            } else {
                cout << "Queue is empty" << endl;
                return -1;
            }
        }

        int getRear() {
            cout << Array[rear] << endl;
            if (!empty()) {
                return Array[rear];
            } else {
                cout << "Queue is empty" << endl;
                return -1;
            }
        }
};

void CmdChar() {
    Queue q;
    char cmd;
    int data;

    while (true) {
        cin >> cmd;
        if (cmd == 'e') { // Add to the queue
            cin >> data;
            q.enqueue(data);
        } else if (cmd == 'd') { // Dequeue data from the queue and show that data
            int temp = q.dequeue();
            if (temp != -1) {
                cout << temp << endl;
            }
        } else if (cmd == 'p') { // Show all data in the queue from the first until last data in the queue
            q.print();
        } else if (cmd == 'n') { // Show queue size
            cout << q.currentSize() << endl;
        } else if (cmd == 's') { // Show first and last data of the queue
            q.getFront();
            q.getRear();
        } else if (cmd == 'x') {
            break;
        }
    }
}

int main() {
    CmdChar();
    return 0;
}