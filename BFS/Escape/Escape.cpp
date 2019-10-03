///  AC 代码

#include <queue>
#include <iostream>
using namespace std;
#include <cstring>
const int MAXN = 22;
char MAP[MAXN][MAXN];
int Meg[4]; // N S W E
struct Node
{
    int x1, x2, y1, y2, steps;
    Node(int x11 = 0, int y11 = 0, int x22 = 0, int y22 = 0, int s = 0)
    {
        x1 = x11;
        x2 = x22;
        y1 = y11;
        y2 = y22;
        steps = s;
    }
};
// N S W E
int opx[4] = {-1, 1, 0, 0};
int opy[4] = {0, 0, -1, 1};
bool visited[MAXN][MAXN][MAXN][MAXN];
int n, m;

Node bfs(Node now)
{
    if (now.x1 == now.x2 && now.y1 == now.y2)
        return Node(0);
    queue<Node> q;
    q.push(now);
    int px, py, hx, hy;
    while (!q.empty())
    {
        Node front = q.front();
        if (front.steps > 255)
            break;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            px = front.x1 + opx[i];
            py = front.y1 + opy[i];
            if (px >= 0 && px < n && py >= 0 && py < m && MAP[px][py] != '!' && MAP[px][py] != '#')
            {
                hx = front.x2 + opx[Meg[i]];
                hy = front.y2 + opy[Meg[i]];
                if (hx >= 0 && hx < n && hy >= 0 && hy < m && MAP[hx][hy] != '!')
                {
                    if (MAP[hx][hy] == '#')
                    {
                        hx = front.x2;
                        hy = front.y2;
                    }
                    if (!visited[px][py][hx][hy])
                    {
                        visited[px][py][hx][hy] = true;
                        if (front.x1 == hx && front.y1 == hy && front.x2 == px && front.y2 == py)
                        {
                            return Node(px, py, hx, hy, front.steps + 1);
                        }
                        else if (px == hx && py == hy)
                        {
                            return Node(px, py, hx, hy, front.steps + 1);
                        }
                        q.push(Node(px, py, hx, hy, front.steps + 1));
                    }
                }
            }
        }
    }
    return Node(0, 0, 0, 0, 256);
}
int main()
{
    //	freopen("E:\\Code\\C++\\soj\\a.txt", "r", stdin);
    while (cin >> n >> m)
    {
        Node now;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> MAP[i][j];
                if (MAP[i][j] == 'P')
                {
                    now.x1 = i;
                    now.y1 = j;
                }
                else if (MAP[i][j] == 'H')
                {
                    now.x2 = i;
                    now.y2 = j;
                }
            }
        }
        string s;
        cin >> s;
        for (int i = 0; i < 4; ++i)
        {
            if (s[i] == 'N')
                Meg[i] = 0; //Paris走时Helen的方向
            else if (s[i] == 'S')
                Meg[i] = 1;
            else if (s[i] == 'W')
                Meg[i] = 2;
            else if (s[i] == 'E')
                Meg[i] = 3;
        }
        now = bfs(now);
        if (now.steps > 255)
            cout << "Impossible" << endl;
        else
            cout << now.steps << endl;
    }
}
