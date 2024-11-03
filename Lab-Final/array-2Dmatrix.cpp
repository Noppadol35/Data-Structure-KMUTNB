#include <iostream>
using namespace std;

int main()
{
    int num, n, m;
    cin >> num >> n >> m;

    int matrix[n][m] = {0};
    int values[num];
    for (int i = 0; i < num; ++i)
    {
        cin >> values[i];
    }

    int index = 0; 
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (index < num)
            {
                matrix[i][j] = values[index++];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int row_sum = 0;
        for (int j = 0; j < m; ++j)
        {
            cout << matrix[i][j] << " ";
            row_sum += matrix[i][j];
        }
        cout << "= " << row_sum << endl;
    }

    int col_sum = 0;
    int total_sum_col = 0;
    for (int i = 0; i < m; ++i)
    {
        col_sum = 0;
        for (int j = 0; j < n; ++j)
        {
            col_sum += matrix[j][i];
        }
        cout << col_sum << " ";

        total_sum_col = col_sum + total_sum_col;
    }
    cout << "= " << total_sum_col << endl;

    return 0;
}
