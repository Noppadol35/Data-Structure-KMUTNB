
# Lab 1

An operating system developer would like to develop Process Scheduling algorithm using Last

In First Out concept to choose processes in an operating system. Each process contains **Process
ID (PID), Arrival Time (A) and Service time (T)**.

This scheduling algorithm is **nonpreemptive,** which means when a process is executed until **Service time (T) = 0,** and the process which is

recently added to this algorithm will be chosen for the execution. If Service time (T) of the

process is equal to 0, that process is **terminated.**

#### The student should help him to write the LIFO process scheduling algorithm.

  

### **Input**

- Line 1: N is number of processes (1≤N<100),

- Lines 2 to N+1 contain Process ID (1000 < PID < 9999), Arrival time (0 ≤ A ≤ 100) and Service

time (0 ≤ T < 100), respectively which are divided by newline.

- There are no processes which are spawned at the same Arrival time.

- If new process is spawned, that process is pushed before choose the process to execute.

  

### **Output**

Process IDs’ in the order of execution : Remaining Service time. One ID for each line.

| Input1 | Output1 | Input2 | Output2 | Input3 | Output3 | Input4 | Output4 | Input5 | Output5 |
|---|---|---|---|---|---|---|---|---|---|
| 2  |  3010 : 4 | 3  |  1010 : 3 | 4 |  1010 : 2 |  5 |  1010 : 2 |  4 |  2002 : 4 |
| 3010   |  3010 : 3 | 1010  |  1010 : 2 | 1010  |  1010 : 1 |  1010  |  1010 : 0 |  1010  |  2002 : 3 |
| 0   | 3010 : 2 | 0  |  1010 : 1 | 0  |  1010 : 0 |  0  |  2002 : 2 |  0  |  2002 : 2 |
| 4   | 3010 : 1 | 3  |  3030 : 5 | 3  |  3030 : 4 |  3  |  3030 : 3 |  3  |  2002 : 1 |

