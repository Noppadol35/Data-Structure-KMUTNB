#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Heap {
public:
    int q[1000];
    void insert(int n) {
        if (q[0] < 999) {
            q[0] += 1;
            q[q[0]] = n;
            int i = q[0];
            // Upheap to maintain max-heap property
            while (i > 1 && q[i] > q[i / 2]) {
                swap(q[i], q[i / 2]);
                i = i / 2;
            }
        }
    }

    // Function to remove the maximum element from the heap
    int remove() {
        if (q[0] > 0) {
            int removedValue = q[1];
            q[1] = q[q[0]];
            q[0] -= 1;

            // Downheap to maintain max-heap property
            int p = 1;
            while (p <= q[0]) {
                int l = p * 2;
                int r = p * 2 + 1;
                int largest = p;

                if (l <= q[0] && q[l] > q[largest])
                    largest = l;
                if (r <= q[0] && q[r] > q[largest])
                    largest = r;

                if (largest != p) {
                    swap(q[p], q[largest]);
                    p = largest;
                } else {
                    break;
                }
            }
            return removedValue;
        } else {
            cout << "Heap is empty" << endl;
            return INT_MIN; // Return a sentinel value indicating failure
        }
    }

    // Function to print all elements of the heap
    void print() {
        if (q[0] == 0) {
            cout << "This Heap is empty!" << endl;
            return;
        }
        for (int i = 1; i <= q[0]; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;
    char choice;
    int value;

    while (true) {
        cin >> choice;
        if (choice == 'a') {
            cin >> value;
            h.insert(value);
        } else if (choice == 'p') {
            h.print();
        } else if (choice == 'd') {
            cout << h.remove() << endl;
        } else if (choice == 'e') {
            break;
        }
    }

    return 0;
}