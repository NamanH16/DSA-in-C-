#include <bits/stdc++.h>
using namespace std;

// Approach 3: Dynamic Programming
int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }
    //Fill the last cell(destination)
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // Fill last row(right to left manner)
    for (int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // Fill the last column
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // Fill remaining cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }

    return output[0][0];
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;

    return 0;
}