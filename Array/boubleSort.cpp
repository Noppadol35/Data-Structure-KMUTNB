#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class process{
    public:
        string pid;
        int arrival;
        int Tservice;
        int index;

        process(string pid, int arrival, int Tservice, int index){
            this->pid = pid;
            this->arrival = arrival;
            this->Tservice = Tservice;
            this->index = index;
        }

};

int main(){

    int size;
    cin >> size;
    vector<process> arr;
    for(i = 0; i < n; i++){
        string pid;
        int arrival;
        int Tservice;
        cin >> pid >> arrival >> Tservice;
        arr.pushback(process(pid,arrival,Tservice,i))
    }

    cout 

    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            if(arr[i].arrival > arr[j].arrival){
                swap(arr[j],arr[i]);
            }
        }
    }



    for(int i = 0; i < 3 ; i++){
        cout << "Process : " << arr[i].pid << endl;
    }
}