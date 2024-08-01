#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Linklist {
public:
    Node* list_head;

    Linklist() {
        list_head = NULL;
    }

    void print() {
        for(Node *prt = list_head; prt != NULL; prt = prt->next) {
            cout << prt->data << " ";
        }
        cout << endl;
    }

    bool contains(int data) {
        Node* current = list_head;
        while (current != NULL) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertBefore(int data, int id) {
        if (contains(data)) {
            return;
        }

        Node* new_node = new Node(data);
        if (list_head == NULL || list_head->data == id) {
            new_node->next = list_head;
            list_head = new_node;
        } else {
            Node* current = list_head;
            Node* previous = NULL;
            while (current != NULL && current->data != id) {
                previous = current;
                current = current->next;
            }
            new_node->next = current;
            if (previous != NULL) {
                previous->next = new_node;
            }
        }
        print();
    }

    void insertAfter(int data, int id) {
        if (contains(data)) {
            return;
        }

        Node* new_node = new Node(data);
        Node* current = list_head;
        while (current != NULL && current->data != id) {
            current = current->next;
        }
        if (current != NULL) {
            new_node->next = current->next;
            current->next = new_node;
        } else {
            if (list_head == NULL) {
                list_head = new_node;
            } else {
                current = list_head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = new_node;
            }
        }
        print();
    }

    void del(int data) {
        if (list_head == NULL) {
            return;
        }

        if (list_head->data == data) {
            Node *temp = list_head;
            list_head = list_head->next;
            delete temp;
            print();
            return;
        }

        Node *current = list_head;
        Node *previous = NULL;

        while (current != NULL && current->data != data) {
            previous = current;
            current = current->next;
        }

        if (current != NULL) {
            previous->next = current->next;
            delete current;
        }
        print();
    }
};

void Command() {
    char cmd;
    int data, id;
    Linklist list;

    while (true) {
        cin >> cmd;
        if (cmd == 'A') { // "A 1 0" insert 1 after the node which has id 0
            cin >> data >> id;
            list.insertAfter(data, id);
        } else if (cmd == 'I') { // "I 2 1" insert 2 before the node which has id 1
            cin >> data >> id;
            list.insertBefore(data, id);
        } else if (cmd == 'D') { // "D 4" delete the node which has id 4
            cin >> id;
            list.del(id);
        } else if (cmd == 'E') { // "E" Exit
            break;
        }
    }
}

int main() {
    Command();
    return 0;
}