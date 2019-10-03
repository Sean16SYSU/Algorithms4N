#include <iostream>
using namespace std;
#include <cstring>
const int MAX = 100 + 5;
char G[MAX][MAX];
bool visited[MAX][MAX];
int m, n, id;
void DFS(int x, int y)
{
    if (visited[x][y])
        return;
    visited[x][y] = true;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if (x + i >= 0 && x + i < m && y + j >= 0 && y + j < n && !visited[x + i][y + j] && G[x + i][y + j] == '@')
            {
                DFS(x + i, y + j);
            }
        }
    }
}
int main()
{
    while (cin >> m >> n)
    {
        id = 0;
        for (int i = 0; i < m; ++i)
            cin >> G[i];
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!visited[i][j] && G[i][j] == '@')
                {
                    id++;
                    DFS(i, j);
                }
        cout << id << endl;
    }
}