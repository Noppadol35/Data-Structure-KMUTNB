#include <iostream>
using namespace std;

class heap
{
public:
    int q[1000]; // Heap array, q[0] will store the number of elements in the heap

    heap()
    {
        q[0] = 0; // Initialize heap size to 0
    }
    void add(int n)
    {
        q[0] = q[0] + 1; // Increase heap size
        int size = q[0];
        q[size] = n; // Add element at the end of the heap
    }
    void insert(int n)
    {
        add(n);
        heapify();
    }
    void heapify()
    {
        int size = q[0];
        for (int i = (size / 2); i >= 1; i--)
        { // process from the Last Non-Leaf Up to the Root
            int parent = i;
            while (parent <= (size / 2))
            {
                int leftChild = 2 * parent;
                int rightChild = leftChild + 1;
                int pointer = parent;

                if (leftChild <= size && q[leftChild] > q[largest])
                {
                    pointer = leftChild;
                }
                if (rightChild <= size && q[rightChild] > q[largest])
                {
                    pointer = rightChild;
                }
                if (largest != parent)
                {
                    swap(q[parent], q[largest]);
                    parent = pointer;
                }
                else
                {
                    break;
                }
            }
        }
    }
    int deleteMax()
    {
        if (q[0] == 0)
        {
            return 0; // Heap is empty
        }

        int DeletedElement = q[1];
        q[1] = q[q[0]]; // Move the last element to the root
        q[0]--;         // Reduce the heap size
        int size = q[0];

        // Fix the heap if the root element is smaller than its children
        int parent = 1;
        while (parent <= size)
        {
            int leftChild = 2 * parent;
            int rightChild = leftChild + 1;
            int pointer = parent;

            if (leftChild <= size && q[leftChild] > q[largest])
            {
                pointer = leftChild;
            }
            if (rightChild <= size && q[rightChild] > q[largest])
            {
                pointer = rightChild;
            }
            if (largest != parent)
            {
                swap(q[parent], q[largest]);
                parent = pointer;
            }
            else
            {
                break;
            }
        }

        return DeletedElement;
    }

    void print()
    {
        for (int i = 1; i <= q[0]; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.add(55);
    h.add(14);
    h.add(50);
    h.add(20);
    h.add(5);
    h.add(15);
    h.add(30);
    h.add(31);
    h.add(60);
    h.add(28);
    h.print();
    h.heapify();
    h.print();

    cout << "del " << h.deleteMax() << ": ";
    h.print();
    cout << "del " << h.deleteMax() << ": ";
    h.print();
    cout << "del " << h.deleteMax() << ": ";
    h.print();
    cout << "del " << h.deleteMax() << ": ";
    h.print();

    h.insert(15);
    h.print();

    h.insert(13);
    h.print();

    h.insert(9);
    h.print();

    h.insert(20);
    h.print();

    h.insert(8);
    h.print();

    h.insert(11);
    h.print();

    h.insert(30);
    h.print();

    h.insert(2);
    h.print();
    return 0;
}