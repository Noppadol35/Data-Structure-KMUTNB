#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int edges[100][100]; // Adjacency matrix to store edge weights
    int num_vertices;
    bool traversal_started = false;

    Graph(int n)
    {
        num_vertices = n;
        for (int i = 0; i < num_vertices; i++)
        {
            for (int j = 0; j < num_vertices; j++)
            {
                edges[i][j] = 0; // Initialize edges to 0 (no edges)
            }
        }
    }

    void add_edge(int x, int y, int w)
    {
        if (!traversal_started)
        {
            edges[x][y] = w;
        }
        else
        {
            cout << "Cannot add edges after traversal has started." << endl;
        }
    }

    void bft(int start)
    {
        bool visited[100] = {0};
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < num_vertices; i++)
            {
                if (!visited[i] && edges[vertex][i] > 0)
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    bool visited_dft[100];
    void sub_dft(int vertex)
    {
        cout << vertex << " ";
        visited_dft[vertex] = true;

        for (int i = 0; i < num_vertices; i++)
        {
            if (!visited_dft[i] && edges[vertex][i] > 0)
            {
                sub_dft(i);
            }
        }
    }

    void dft(int start)
    {
        fill(visited_dft, visited_dft + 100, false);
        sub_dft(start);
        cout << endl;
    }

    void start_traversal()
    {
        traversal_started = true;
    }
};

void InputWithvalue()
{
    int sizeVertex, vertex1, vertex2, weight, start;
    char command;

    cin >> sizeVertex; // Input the number of vertices
    Graph g(sizeVertex);

    while (true)
    {
        cin >> command;
        if (command == 'e')
        {
            cin >> vertex1 >> vertex2 >> weight;
            g.add_edge(vertex1, vertex2, weight);
        }
        else if (command == 'd')
        {
            cin >> start;
            g.dft(start);
        }
        else if (command == 'b')
        {
            cin >> start;
            g.bft(start);
        }
        else if (command == 's')
        {
            g.start_traversal();
        }
        else if (command == 'q')
        {
            break; // Exit
        }
    }
}

int main()
{
    InputWithvalue();
    return 0;
}
