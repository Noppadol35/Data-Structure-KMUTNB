#include <iostream>
using namespace std;

class Queue {
    public:
        int Array[6];
        int size = 5;
        int front = 0;
        int rear = -1;

        bool empty() {
            return front > rear;
        }

        bool full() { 
            return rear == size - 1;
        }

        void enqueue(int data) {
            if (!full()) {
                rear++;
                Array[rear] = data;
            } else {
                cout << "Queue overflow" << endl;
            }
        }

        int dequeue() {
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
            int dequeued = q.dequeue();
            if (dequeued != -1) {
                cout << dequeued << endl;
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