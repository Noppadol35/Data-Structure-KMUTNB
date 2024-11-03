#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class graph
{
public:
    int edges[100][100];
    int s_v;
    graph(int n)
    {
        s_v = n;
        for (int i = 0; i < s_v; i++)
        {
            for (int j = 0; j < s_v; j++)
            {
                edges[i][j] = 0;
            }
        }
    }
    void add_edge(int x, int y, int w)
    {
        edges[x][y] = w;
    }
    void print()
    {
        for (int i = 0; i < s_v; i++)
        {
            cout << i << ":";
            for (int j = 0; j <= s_v; j++)
            {
                if (edges[i][j] > 0)
                {
                    cout << j << "," << edges[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    void bft(int start)
    {
        bool visited_bft[100];
        for (int i = 0; i < 100; i++)
            visited_bft[i] = 0;
        visited_bft[start] = 1;
        vector<int> q;
        q.push_back(start);
        while (!q.empty())
        {
            int front = q.front();
            cout << front << " ";
            q.erase(q.begin());
            for (int y = 0; y < s_v; y++)
            {
                if (visited_bft[y] == 0 && edges[front][y] > 0)
                {
                    visited_bft[y] = 1;
                    q.push_back(y);
                }
            }
        }
    }
    bool visited_dft[100];
    void sub_dft(int start)
    {
        cout << start << " ";
        visited_dft[start] = 1;
        for (int y = 0; y < s_v; y++){
            if (visited_dft[y] == 0 && edges[start][y] > 0)
                sub_dft(y);
        }
    }
    void dft(int start)
    {
        for (int i = 0; i < 100; i++)
            visited_dft[i] = 0;
        sub_dft(start);
    }

    void sub_graph()
    {
        int num_subgraph = 1;
        for (int i = 0; i < 100; i++)
        {
            visited_dft[i] = 0;
        }
        for (int y = 0; y < s_v; y++)
        {
            if (visited_dft[y] == 0)
            {
                cout << "\nsub graph = " << num_subgraph << ": ";
                sub_dft(y);
                num_subgraph = num_subgraph + 1;
            }
        }
    }
    int n_in_degree[100];
    int t_edges[100][100];
    void in_degree()
    {
        for (int i = 0; i < s_v; i++)
        {
            n_in_degree[i] = 0;
            for (int j = 0; j < s_v; j++)
            {
                for (int k = 0; k < s_v; k++)
                {
                    if (t_edges[j][k] == 1)
                    {
                        n_in_degree[k]++;
                    }
                }
            }
        }
    }
} ;

int main()
{
    graph g(5); // Create a graph with 5 vertices

    // Add some edges with weights
    g.add_edge(0, 1, 10);
    g.add_edge(0, 4, 5);
    g.add_edge(1, 2, 8);
    g.add_edge(2, 3, 7);
    g.add_edge(3, 4, 12);
    g.add_edge(4, 1, 2);

    // Print the adjacency matrix
    g.print();

    cout << "\nBreadth-First Traversal from vertex 0:\n";
    g.bft(0);

    cout << "\n\nDepth-First Traversal from vertex 0:\n";
    g.dft(0);

    return 0;
}