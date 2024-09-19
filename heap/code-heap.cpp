#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class heap
{
public:
    int q[1000];
    void add(int n)
    {
        q[0] = q[0] + 1;
        q[q[0]] = n;
        int i = q[0];
    }
    void heapify()
    {
        int j = q[0];
        if (j % 2 == 0)
        {
            q[j + 1] = INT_MAX;
        }
        else
        {
            j = j - 1;
        }
        while (j >= 1)
        {
            int i = j;
            while (i <= q[0])
            {
                int p = i / 2;
                int r = i + 1;
                int l = i;
                if (q[l] >= q[r] && q[l] > q[p])
                {
                    int t = q[l];
                    q[l] = q[p];
                    q[p] = t;
                    i = 2 * l;
                }
                else if (q[r] > q[l] && q[r] > q[p])
                {
                    int t = q[r];
                    q[r] = q[p];
                    q[p] = t;
                    i = 2 * r;
                }
                else
                {
                    break;
                }
            }
            j = j - 2;
        }
    }
    void insert(int n)
    {
        if (q[0] < 999)
        {
            q[0] = q[0] + 1;
            q[q[0]] = n;
            int i = q[0];
            while (i > 1 && q[i / 2])
            {
                int t = q[i / 2];
                q[i / 2] = q[i];
                q[i] = t;
                i = i / 2;
            }
        }
    }
    int delete()
    {
        if (q[0] > 0)
        {
            int s = q[1];
            q[1] = q[q[0]];
            q[0] = q[0] - 1;
            int p = 1;
            while (p <= q[0])
            {
                int l = p * 2;
                int r = (p * 2) + 1;
                if (l <= q[0] && q[l] > q[p] && q[l] >= q[r])
                {
                    int t = q[l];
                    q[l] = q[p];
                    q[p] = t;
                    p = l;
                }
                else if (r <= q[0] && q[r] > q[p] && q[r] > q[l])
                {
                    int t = q[r];
                    q[r] = q[p];
                    q[p] = t;
                    p = r;
                }
                else
                {
                    break;
                }
            }
            return s;
        }
        else
        {
            return NULL;
        }
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

    return 0;
}