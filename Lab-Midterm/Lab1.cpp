#include <bits/stdc++.h>
using namespace std;
class process
{
public:
    string id;
    int arrive;
    int service;
    int index;
    string status;

    process(string id, int arrive, int service, string status)
    {
        this->id = id;
        this->arrive = arrive;
        this->service = service;
        this->status = status;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<process> arr;
    for (int i = 0; i < n; i++)
    {
        string id = "";
        int arrive = 0;
        int service = 0;
        cin >> id >> arrive >> service;
        arr.push_back(process(id, arrive, service, "not"));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].arrive > arr[j].arrive)
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    int start = 0;
    int new_start = 0;
    int Time = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = arr[start].service; i > 0; i--)
        {
            cout << arr[start].id << " : " << i << endl;
        }
        arr[start].status = "done";
        Time = Time + arr[start].service;
        for (int k = 0; k < n; k++)
        {
            if (arr[k].status == "not" && arr[k].arrive == Time)
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
        if (arr[i].status == "not")
        {
            for (int j = arr[i].service; j > 0; j--)
            {
                cout << arr[i].id << " : " << j << endl;
            }
        }
    }
}