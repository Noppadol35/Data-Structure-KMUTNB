#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a process
struct Process {
    int PID;   // Process ID
    int arrival; // Arrival time
    int service; // Service time
};

// Custom comparator to sort processes by arrival time
bool compareArrival(const Process &a, const Process &b) {
    return a.arrival < b.arrival;
}

int main() {
    int N;
    cin >> N; // Number of processes

    vector<Process> processes(N);
    for (int i = 0; i < N; ++i) {
        cin >> processes[i].PID >> processes[i].arrival >> processes[i].service;
    }

    // Sort processes by their arrival time
    sort(processes.begin(), processes.end(), compareArrival);

    stack<Process> lifoStack;
    int time = 0;   // Current time index
    int i = 0;      // Index to track processes

    // While there are still processes to schedule or stack is not empty
    while (i < N || !lifoStack.empty()) {
        // Push all processes that have arrived by the current time
        while (i < N && processes[i].arrival <= time) {
            lifoStack.push(processes[i]);
            i++;
        }

        // If stack is not empty, execute the top process
        if (!lifoStack.empty()) {
            Process current = lifoStack.top();
            lifoStack.pop();
            
            // Process execution step
            cout << current.PID << ": " << current.service - 1 << endl;
            current.service--;

            // If the process still has service time remaining, push it back onto the stack
            if (current.service > 0) {
                lifoStack.push(current);
            }
        }

        // Move to the next time unit
        time++;
    }

    return 0;
}