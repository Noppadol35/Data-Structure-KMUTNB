#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Heap
{
public:
    int q[1000];

    Heap()
    {
        q[0] = 0; // ตำแหน่ง 0 เก็บขนาดของ heap
    }

    // ฟังก์ชันในการเพิ่มค่า n ลงใน heap
    void insert(int n)
    {
        q[0] += 1;   // เพิ่มขนาด heap
        q[q[0]] = n; // เพิ่มค่าใหม่ที่ตำแหน่งท้ายสุด
        heapify();   // เรียกใช้ heapify เพื่อจัดการ heap
    }

    // ฟังก์ชัน heapify เพื่อจัดการ heap ให้เป็น max-heap
    void heapify()
    {
        int size = q[0]; // ขนาดของ heap
        // เริ่มจาก node non-leaf จากท้ายสุดไปจนถึง root
        for (int i = size / 2; i >= 1; i--)
        {
            int parent = i;
            while (parent <= size / 2)
            {
                int leftChild = 2 * parent;
                int rightChild = leftChild + 1;
                int largest = parent;

                // เปรียบเทียบ parent กับ left child
                if (leftChild <= size && q[leftChild] > q[largest])
                {
                    largest = leftChild;
                }
                // เปรียบเทียบ largest กับ right child
                if (rightChild <= size && q[rightChild] > q[largest])
                {
                    largest = rightChild;
                }

                // ถ้า largest ไม่ใช่ parent, สลับค่า
                if (largest != parent)
                {
                    swap(q[parent], q[largest]);
                    parent = largest;
                }
                else
                {
                    break;
                }
            }
        }
    }

    // ฟังก์ชันค้นหาค่าที่ตำแหน่ง k ใน heap
    void findAtPosition(int k)
    {
        if (k > 0 && k <= q[0])
        {
            cout << "Value at position " << k << " is: " << q[k] << endl;
        }
        else
        {
            cout << "Invalid position!" << endl;
        }
    }

    // ฟังก์ชันลบค่า root ออกจาก heap
    int remove()
    {
        if (q[0] > 0)
        {
            int removedValue = q[1]; // ค่า root
            q[1] = q[q[0]];          // ย้ายค่าท้ายสุดมาเป็น root
            q[0] -= 1;               // ลดขนาด heap
            heapify();               // เรียก heapify เพื่อจัดการ heap ใหม่
            return removedValue;
        }
        else
        {
            cout << "Heap is empty" << endl;
            return INT_MIN; // ส่งคืนค่าที่บ่งบอกว่า heap ว่าง
        }
    }

    // ฟังก์ชันแสดงผลค่าทั้งหมดใน heap
    void print()
    {
        if (q[0] == 0)
        {
            cout << "This Heap is empty!" << endl;
            return;
        }
        for (int i = 1; i <= q[0]; i++)
        {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;
    char choice;
    int value;

    while (true)
    {
        cin >> choice;
        if (choice == 'a')
        { // เพิ่มค่า
            cin >> value;
            h.insert(value);
        }
        else if (choice == 'p')
        { // แสดงผล
            h.print();
        }
        else if (choice == 'd')
        { // ลบค่า root
            cout << h.remove() << endl;
        }
        else if (choice == 'k')
        { // ค้นหาค่าที่ตำแหน่ง k
            int k;
            cin >> k;
            h.findAtPosition(k);
        }
        else if (choice == 'e')
        { // ออกจากโปรแกรม
            break;
        }
    }

    return 0;
}
