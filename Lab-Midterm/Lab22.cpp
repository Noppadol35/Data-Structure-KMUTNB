#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Process
{
public:
    string id;
    int arrive;
    int service;
    int remaining;
    string status;

    Process(string id, int arrive, int service, string status)
    {
        this->id = id;
        this->arrive = arrive;
        this->service = service;
        this->remaining = service;
        this->status = "not";
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Process> array;

    for(int i = 0; i < n; i++)
    {
        string id;
        int arrive;
        int service;
        cin >> id >> arrive >> service;
        array.push_back(Process(id, arrive, service, "not"));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i].arrive > array[j].arrive)
            {
                swap(array[i], array[j]);
            }
        }
    }

    int start = 0;
    bool processesLeft = true;

    while (processesLeft)
    {
        processesLeft = false;

        for (int i = 0; i < n; i++)
        {
            // Check if process has arrived and is not completed
            if (array[i].arrive <= start && array[i].remaining > 0)
            {
                cout << array[i].id << " : " << array[i].remaining << endl;
                array[i].remaining--;
                start++;
                processesLeft = true;

                // Check if any new process arrives during this time unit
                for (int j = 0; j < n; j++)
                {
                    if (array[j].arrive == start && array[j].remaining > 0)
                    {
                        processesLeft = true; // To continue looping if new processes arrive
                    }
                }
            }
        }
    }

    return 0;
}