#include <iostream>
#include <string>

using namespace std;


struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, string v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 17; 
    Node* table[TABLE_SIZE];          

    
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    
    void add(int key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode; 
        } else {
            
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    
    string find(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "-";
    }

    
    void print() {
        bool isEmpty = true;
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            if (current == nullptr) {
                cout << "(-1,-) ";
            } else {
                while (current != nullptr) {
                    cout << "(" << current->key << "," << current->value << ") ";
                    current = current->next;
                }
                isEmpty = false;
            }
        }
        cout << endl;
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht;
    string command;
    int key;
    string value;

    while (true) {
        cin >> command;
        if (command == "a") {
            cin >> key >> value;
            ht.add(key, value);
        } else if (command == "p") {
            ht.print();
        } else if (command == "s") {
            cin >> key;
            cout << ht.find(key) << endl;
        } else if (command == "e") {
            break;
        }
    }

    return 0;
}