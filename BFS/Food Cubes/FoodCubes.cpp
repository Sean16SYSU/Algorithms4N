#include <iostream>
using namespace std;
#include <queue>
#include <cstring>
#include <algorithm>
#define INF 1 << 30
#define MINF 1 << 31
bool map[103][103][103];     // true 表示是障碍，否则就不是障碍
bool visited[103][103][103]; // true表示访问过
int ans;
struct Node
{
    int x, y, z;
    Node(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c){};
};
int op[][6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int main()
{
    int t, time, x, y, z, a, b, c, maxx, minx, maxy, miny, maxz, minz;
    bool wrong;
    cin >> t;
    while (t--)
    {
        cin >> time;
        memset(map, false, sizeof(map));
        memset(visited, false, sizeof(visited));
        ans = 0;
        maxx = maxy = maxz = MINF;
        minx = miny = minz = INF;
        while (time--)
        {
            cin >> x >> y >> z;
            map[x][y][z] = true; //设置障碍
            maxx = max(x, maxx);
            maxy = max(y, maxy);
            maxz = max(z, maxz);
            minx = min(x, minx);
            miny = min(y, miny);
            minz = min(z, minz);
        }
        for (x = minx; x <= maxx; ++x)
            for (y = miny; y <= maxy; ++y)
                for (z = minz; z <= maxz; ++z)
                {
                    if (!map[x][y][z] && !visited[x][y][z])
                    {
                        queue<Node> q;
                        q.push(Node(x, y, z));
                        wrong = false;
                        visited[x][y][z] = true;
                        while (!q.empty())
                        {
                            Node now = q.front();
                            q.pop();
                            for (int i = 0; i < 6; ++i)
                            {
                                a = now.x + op[i][0];
                                b = now.y + op[i][1];
                                c = now.z + op[i][2];
                                if (a < minx || b < miny || c < minz || a > maxx || b > maxy || c > maxz)
                                {
                                    wrong = true;
                                }
                                else if (!map[a][b][c] && !visited[a][b][c])
                                {
                                    q.push(Node(a, b, c));
                                    visited[a][b][c] = true;
                                }
                            }
                        }
                        if (!wrong)
                        {
                            ans++;
                        }
                    }
                }
        cout << ans << endl;
    }
}