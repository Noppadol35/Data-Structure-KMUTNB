#include <iostream>
using namespace std;

class Node {
    public:
        Node* next;
        int value;
        Node(int v){
            value = v;
            next = NULL;
        }
};

class Linklist {
    public:
        Node* list_head;
        int size = 0;

        Linklist(int value){
            list_head = new Node(value);
            list_head -> next = NULL;
            size = 1;
        }

        void print(){
            for(Node *prt = list_head; prt != NULL; prt = prt -> next){
                cout << prt -> value << " ";
            }
            cout << endl;
        }

        void insert(int i, int value){
            if(0 <= i&&i <= size){
                if(i == 0){
                    Node *n_before = new Node(value);
                    n_before -> next = list_head;
                    list_head = n_before;
                }else {
                    Node *n_before = list_head;
                    for(int ptr_i = 1; ptr_i < i; ptr_i++){
                        n_before = n_before -> next;
                    }
                    Node *n_new = new Node(value);
                    n_new -> next = n_before -> next;
                    n_before -> next = n_new;
                }
            }
            size++;
        }

        void del(int i){
            if(0 <= i&&i < size && size>1){
                if(i==0){
                    list_head = list_head -> next;
                } else {
                    Node *n_before = list_head;
                    for(int ptr_i = 1; ptr_i < i; ptr_i++){
                        n_before = n_before -> next;
                    }
                    n_before -> next = n_before -> next -> next;
                }
                size --;
            }
        }
};

int main(){
    Linklist list(10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 50);
    list.print();
    list.insert(2, 60);
    list.print();
    list.del(2);
    list.print();
    list.del(0);
    list.print();

    return 0;
}