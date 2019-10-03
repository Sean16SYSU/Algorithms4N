#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
struct Node
{
    double first, second;
    Node(double f = -1, double s = -1) : first(f), second(s){};
};
double Distance(Node p, Node q)
{
    return sqrt((p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second));
}

int ans = 0, n, final_ans = 1 << 30;
int color[14]; // 在color中0表示无颜色
vector<Node> v;
bool array_[14][14]; // 地图，array[i][j] == true，表示i,j间有通路，就是在说这两不应该是一样的

void DFS(int now)
{   //now表示的是当前点的位置
    //关于点的编号进行迭代 //边界条件还没有处理好
    if (now >= n)
        return;
    // 设置边界判断，这个只是为了增加函数的健壮性而添加的

    if (now == 0)
    {
        ans = 1;
        color[0] = 1; // 将第一个设置好
    }                 // 起始条件，当这个点是起始点的时候
    if (now < n - 1)
    { //说明你可以选下一个的情况
        bool canChooseColor[14];
        memset(canChooseColor, false, sizeof(canChooseColor)); //可选色表的初始化
        for (int i = 0; i < v.size(); ++i)
        {
            if (array_[i][now + 1] && color[i] != 0)
            {                                    // 第i个点和第now+1个值相连，并且第i个点没有着色
                canChooseColor[color[i]] = true; //这里，如果是true意味着这个点不能选了
            }
        }
        bool flag = false;
        for (int i = 1; i <= ans; ++i)
        {
            if (!canChooseColor[i])
            { //用可以着色的已有的颜色着色
                color[now + 1] = i;
                DFS(now + 1);
                flag = true;
                color[now + 1] = 0; // 深搜回溯
            }
        }
        //再新建一个颜色着色
        if (ans <= n)
        {
            ans++;
            color[now + 1] = ans;
            DFS(now + 1);
            ans--;
        }
    }
    else if (ans < final_ans)
    {
        final_ans = ans;
    }
    //这样，就只需要在边界条件上考虑下那个最大或者是最小的问题
}

int main()
{
    int caseNum = 1;
    while (cin >> n && n)
    { // 确保是n个点
        v.clear();
        memset(color, 0, sizeof(color));
        double x, y;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            v.push_back(Node(x, y));
        } // 存储点

        memset(array_, false, sizeof(array_));
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = i + 1; j < v.size(); ++j)
            {
                if (Distance(v[i], v[j]) - 20 < 1e-6)
                {
                    array_[i][j] = array_[j][i] = true;
                }
            }
        }
        // 存储好了两点间的关系存在，正确
        final_ans = 1 << 30;
        DFS(0); //从0编号的点开始遍历
        cout << "The towers in case " << caseNum++ << " can be covered in " << final_ans << " frequencies.\n";
    }
}