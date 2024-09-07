#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class process
{
public:
    string pid;
    int arrival;
    int Tservice;
    string status;

    process(string pid, int arrival, int Tservice, string status)
    {
        this->pid = pid;
        this->arrival = arrival;
        this->Tservice = Tservice;
        this->status = status;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<process> array;
    for (int i = 0; i < n; i++)
    {
        string pid = "";
        int arrival = 0;
        int Tservice = 0;
        cin >> pid >> arrival >> Tservice;
        array.push_back(process(pid, arrival, Tservice, "not"));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i].arrival > array[j].arrival)
            {
                swap(array[i], array[j]);
            }
        }
    }
    int start = 0;
    int Etime = 0;
    int new_start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int i = array[start].Tservice; i > 0; i--)
        {
            cout << array[start].pid << " : " << i << endl;
        }
        array[start].status = "done";
        Etime = Etime + array[start].Tservice;

        for (int k = 0; k < n; k++)
        {
            if (array[k].status == "not" && array[k].arrival == Etime)
            {
                new_start = k;
            }
        }
        if (start == new_start)
        {
            break;
        }
        start = new_start;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (array[i].status == "not")
        {
            for (int j = array[i].Tservice; j > 0; j--)
            {
                cout << array[i].pid << " : " << j << endl;
            }
        }
    }
    return 0;
};
