#include <iostream>
using namespace std;
#define INF 0x7fffffff
int map[501][501];
int localhost[501];
int main()
{
    int T, n;
    cin >> T;
    for (int time = 0; time < T; ++time)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> map[i][j];
            }
        }
        int ans = 0;
        // prim 算法
        for (int i = 0; i < n; ++i)
        {
            // 将第一个点拿到集群中
            localhost[i] = map[0][i];
        }
        // localhost[i] 存储的是外面的点i和已选集群内部的点的距离最小长度

        for (int i = 1; i < n; ++i)
        {
            // 进行 n-1次拿点
            int minid = INF, minlen = INF;
            for (int j = 1; j < n; ++j)
            {
                if (localhost[j] != 0 && localhost[j] < minlen)
                {
                    minid = j;
                    minlen = localhost[j];
                }
            }
            if (minlen > ans)
            {
                ans = minlen; // 更新
            }
            // 接下来将minid 拿到集群中
            for (int j = 1; j < n; ++j)
            {
                if (localhost[j] != 0 && map[minid][j] < localhost[j])
                {
                    localhost[j] = map[minid][j];
                }
            }
        }
        cout << ans;
        if (time + 1 != T)
        {
            cout << endl
                 << endl;
        }
        else
        {
            cout << endl;
        }
    }
}