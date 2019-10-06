#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

//bool MAP[10000][10000];
vector<int> MAP[10000];
int ANS, TEMP, t;
bool visited[10000];
void DFS(int now)
{
    if (visited[now])
    {
        if (TEMP > ANS)
            ANS = TEMP;
        return;
    }
    visited[now] = true;
    TEMP++;
    if (TEMP > ANS)
        ANS = TEMP;
    for (int i = 0; i < MAP[now].size(); ++i)
    {
        if (!visited[MAP[now][i]])
        {
            DFS(MAP[now][i]);
        }
    }
    TEMP--;
}
int main()
{
    //    freopen("C://Users//b402//Desktop//1.txt","r",stdin);
    int n, v, xa, xb;
    bool first = true;
    string a, b;
    while (cin >> n)
    {
        if (!first)
        {
            cout << endl;
        }
        else
        {
            first = false;
        }
        for (int i = 0; i < t; ++i)
        {
            MAP[i].clear();
        }
        t = ANS = TEMP = 0;
        map<string, int> G;
        map<string, int>::iterator it;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            it = G.find(a);
            if (it != G.end())
            {
                xa = it->second;
            }
            else
            {
                xa = t++;
                G[a] = xa;
            }
            it = G.find(b);
            if (it != G.end())
            {
                xb = it->second;
            }
            else
            {
                xb = t++;
                G[b] = xb;
            }
            MAP[xa].push_back(xb);
        }
        for (int i = 0; i < t; ++i)
        {
            if (MAP[i].size() == 0)
                continue;
            memset(visited, false, sizeof(visited));
            TEMP = 0;
            DFS(i);
        }
        cout << ANS;
    }
}