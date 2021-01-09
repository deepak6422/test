//CSES Graphs Counting Rooms Problem
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfsUtil(vector<vector<char>> &arr, int i, int j, int n, int m, vector<vector<int>> moves)
{

   arr[i][j] = '#';

    for (auto &dr : moves)
    {
        int dx = i + dr[0];
        int dy = j + dr[1];

        if (dx >= 0 && dx < n && dy >= 0 && dy < m && arr[dx][dy] != '#')
        {
            dfsUtil(arr, dx, dy, n, m, moves);
        }
    }
}

int main()
{

    long long int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            arr[i].push_back(ch);
        }
    }

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int rooms = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == '.') {
                dfsUtil(arr, i, j, n, m, directions);
                rooms++;
            }
        }
    }

    cout << rooms << endl;

    return 0;
}