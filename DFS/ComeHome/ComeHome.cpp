#include <iostream>
#include <cstring>
using namespace std;
int map[31][31];
bool visited[31];
int ANS, TEMP, m, n;
void DFS(int now)
{
    if (now == n)
    {
        if (TEMP < ANS)
            ANS = TEMP;
        return;
    }
    if (visited[now])
        return;
    visited[now] = true;
    for (int i = 1; i < 31; ++i)
    {
        if (map[now][i] != -1)
        {
            TEMP += map[now][i];
            DFS(i);
            TEMP -= map[now][i];
        }
    }
    visited[now] = false;
}
int main()
{
    int x, y, l;
    bool first = true;
    while (cin >> m >> n)
    {
        if (!first)
        {
            cout << endl;
        }
        else
        {
            first = false;
        }
        memset(map, -1, sizeof(map));
        ANS = 1 << 30;
        TEMP = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y >> l;
            if (map[x][y] == -1 || map[x][y] > l)
            {
                map[x][y] = l;
            }
        }
        DFS(0);
        cout << ANS;
    }
}
