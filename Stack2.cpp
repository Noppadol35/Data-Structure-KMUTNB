#include <iostream>
using namespace std;

class Stack {
public:
    int size_arr;
    int *Array = new int[size_arr];
    int top = -1;

    Stack(){
        size_arr = 5;
    }

    Stack(int s) {
        size_arr = s;
    }
    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == size_arr - 1;
    }

    void push(int data) {
        if (!full()) {
            top++;
            Array[top] = data;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    int pop() {
        if (!empty()) {
            int temp = Array[top];
            top--;
            return temp;
        } else {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            cout << Array[i] << " ";
        }
        cout << endl ;
    }

    int getTop() {
        if(!empty()){
            cout << Array[top] << endl;
            return Array[top];
        }
    }

    int getSize() {
        return top + 1;
    }
};

void CmdChar() {
    char cmd;
    Stack s;
    int data;

    while (true) {
        cin >> cmd;
        if (cmd == 'U') {
            cin >> data;
            s.push(data);
        } else if (cmd == 'O') { // pop data from the stack and show that data
            int temp = s.pop();
            if (temp != -1) {
                cout << temp << endl;
            }
        } else if (cmd == 'T') { // show top position of the stack
            s.getTop();
        } else if (cmd == 'P') { // show all data in the stack from the first until last data in the stack
            s.print();
        } else if (cmd == 'N') { // show stack size
            cout << s.getSize() << endl;
        } else if (cmd == 'X') { // exit the loop
            break;
        } else {
            cout << "Invalid command" << endl; //  if the command is not valid
        }
    }
}

int main() {
    CmdChar();
    return 0;
}