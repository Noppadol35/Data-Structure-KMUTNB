#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node {
public:
    int vertex;
    int weight;
    node *next;
    node(int v, int w) {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class graph {
public:
    int s_v;
    node *vertex[1000];
    
    graph(int n) {
        s_v = n;
        for (int i = 0; i < s_v; i++) {
            vertex[i] = new node(1, 0);  // Dummy head node for each vertex
        }
    }

    void add_edge(int x, int y, int w) {
        node *n = new node(y, w);
        node *v = vertex[x];
        while (v->next != NULL) {
            v = v->next;
        }
        v->next = n;
    }

    void print() {
        node *r;
        for (int i = 0; i < s_v; i++) {
            r = vertex[i];
            cout << i << ":";
            while (r->next != NULL) {
                cout << r->next->vertex << "," << r->next->weight << " ";
                r = r->next;
            }
            cout << endl;
        }
    }
};

int main() {
    graph g(5);

    // Add edges
    g.add_edge(0, 1, 10);
    g.add_edge(0, 4, 5);
    g.add_edge(1, 2, 8);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 4, 12);
    g.add_edge(4, 1, 2);

    // Print the adjacency list
    g.print();

    return 0;
}