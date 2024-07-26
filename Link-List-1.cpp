#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class Linklist {
public:
    Node* list_head;

    Linklist(){
        list_head = NULL;
    }

    ~Linklist() {
        while (list_head != NULL) {
            Node *temp = list_head;
            list_head = list_head->next;
            delete temp;
        }
    }

    void print() {
        for (Node *ptr = list_head; ptr != NULL; ptr = ptr->next) {
            cout << ptr->data << " ";
        }
        cout << endl;
    }

    void insert(int data, int id, bool before) {
        Node *new_node = new Node(data);
        if (list_head == NULL) {
            list_head = new_node;
            return;
        }

        Node *current = list_head;
        Node *previous = NULL;

        while (current != NULL && current->data != id) {
            previous = current;
            current = current->next;
        }

        if (current == NULL && !before) { // Insert at the end if not found and inserting after
            if (previous) previous->next = new_node;
        } else if (current == list_head && before) { // Insert at the beginning
            new_node->next = list_head;
            list_head = new_node;
        } else if (before) {
            new_node->next = current;
            if (previous) previous->next = new_node;
        } else {
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void del(int data) {
        if (list_head == NULL) {
            return;
        }

        if (list_head->data == data) {
            Node *temp = list_head;
            list_head = list_head->next;
            delete temp;
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
    }
};

void Command() {
    char cmd;
    Linklist list;
    int data, id;

    while (true) {
        cin >> cmd;
        if (cmd == 'A') { // "A 1 0" insert 1 after the node which has id 0
            cin >> data >> id;
            list.insert(data, id, false);
        } else if (cmd == 'I') { // "I 2 1" insert 2 before the node which has id 1
            cin >> data >> id;
            list.insert(data, id, true);
        } else if (cmd == 'D') { // "D 4" delete the node which has id 4
            cin >> id;
            list.del(id);
        } else if (cmd == 'E') { // "E" Exit
            break;
        }
        list.print();
    }
}

int main() {
    Command();
    return 0;
}