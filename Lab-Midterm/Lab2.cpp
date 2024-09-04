#include <iostream>
using namespace std;

class Stack {
    public:
        int size_arr;
        char* Array;
        int top;

        Stack(int s = 100) {
            size_arr = s;
            Array = new char[size_arr];
            top = -1;
        }

        bool empty() {
            return top == -1;
        }

        bool full() {
            return top == size_arr - 1;
        }

        void push(char data) {
            if (!full()) {
                top++;
                Array[top] = data;
            } else {
                cout << "Overflow" << endl;
            }
        }

        char pop() {
            if (!empty()) {
                char temp = Array[top];
                top--;
                return temp;
            } else {
                cout << "Underflow" << endl;
                return '\0';
            }
        }
};

bool programMatch() {
    string input;
    getline(cin, input);
    Stack s;
    int match = 0;

    for (int i = 0; i < input.length(); i++) {
        char current = input[i];

        // Push opening brackets
        if (current == '(' || current == '[' || current == '{' || current == '<') {
            s.push(current);
        } else if (current == ')' || current == ']' || current == '}' || current == '>') {
            // Check for corresponding closing brackets
            if (s.empty()) {
                cout << "Not matched" << endl;
                cout << match << " matched" << endl;
                return false;
            }

            char last = s.pop();
            if ((current == ')' && last != '(') ||
                (current == ']' && last != '[') ||
                (current == '}' && last != '{') ||
                (current == '>' && last != '<')) {
                cout << "Not matched" << endl;
                cout << match << " matched" << endl;
                return false;
            }
            match++;
        }
        // i need to check special case << >>
    }

    if (s.empty() && match > 0) {
        cout << match << " matched" << endl;
        return true;
    } else {
        cout << "Not matched" << endl;
        cout << match << " matched" << endl;
        return false;
    }
}

int main() {
    programMatch();
    return 0;
}