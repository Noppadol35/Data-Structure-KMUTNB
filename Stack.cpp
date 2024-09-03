#include <iostream>
using namespace std;

class Stack {
public:
    char array[10000];
    int top = -1; 
    
    // CHECK EMPTY
    bool empty() {
        return (top == -1);
    }
    
    // CHECK FULL
    bool full() {
        return (top == 9999);
    }
    
    // PUSH DATA TO STACK
    void push(char data) {
        if (!full()) {
            top++;
            array[top] = data;
        }
    }
    
    // POP DATA FROM STACK
    char pop() {
        if (!empty()) {
            char temp = array[top];
            top--;
            return temp;
        }
        return -1;
    }
};

bool checkBracket() {
    string input;
    getline(cin, input);
    Stack s;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            s.push(input[i]);
        } else if (input[i] == ')') {
            if (s.empty() || s.pop() != '(') {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() {
    if (checkBracket()) {
        cout << "Pass" << endl;
    } else {
        cout << "Error" << endl;
    }
    
    return 0;
}
