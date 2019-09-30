#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;
#define RAND(b, e) (rand() % (e - b) + b)
// 左闭右开
#define RANDFLOAT() ((double)rand() / double(RAND_MAX))
// 0-1浮点数

double **Mat;
int *Path, *tempPath;
double Value, tempValue;
int N = 0;

double CalValue(int *p)
{
    double t = 0;
    for (int i = 1; i < N; ++i)
    {
        t += Mat[p[i - 1]][p[i]];
    }
    t += Mat[p[N - 1]][0];
    return t;
}

// 将temp重置为path
void refresh()
{
    for (int i = 0; i < N; ++i)
    {
        tempPath[i] = Path[i];
    }
    tempValue = Value;
}

// 覆盖修改Path
void change()
{
    for (int i = 0; i < N; ++i)
    {
        Path[i] = tempPath[i];
    }
    Value = tempValue;
}

void initialPath()
{
    for (int i = 0; i < N; ++i)
    {
        Path[i] = i;
    }
    // Path[i]表示路上第i个点的标记为Path[i]
    // Path[0] = 0
    int tx, t;
    for (int i = 1; i < N - 1; ++i)
    {
        tx = RAND(i, N);
        if (tx != i)
        { // swap
            t = Path[i];
            Path[i] = Path[tx];
            Path[tx] = t;
        }
    }
    Value = CalValue(Path);
}

int main()
{
    srand((unsigned)time(NULL));
    ifstream cin("data.txt");

    cin >> N;
    // initialize
    Mat = new double *[N];
    for (int i = 0; i < N; ++i)
        Mat[i] = new double[N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> Mat[i][j];
        }
    }
    Path = new int[N];
    tempPath = new int[N];

    double T = 1000;        // 起始温度
    double alpha = 0.99;    // T_{ k + 1 } = alpha * T_k方式更新温度
    double limitedT = 1e-9; // 最小值的T
    int iterTime = 1000;    // 每个温度下迭代的次数
    double K = 1;           // 系数K
    double p = 0;
    initialPath();
    int tx, ty, t;
    while (T >= limitedT)
    {
        for (int i = 0; i < iterTime; ++i)
        {
            // 任意交换两点的顺序
            refresh();
            tx = RAND(1, N);
            ty = RAND(1, N);
            if (tx != ty)
            {
                t = tempPath[tx];
                tempPath[tx] = tempPath[ty];
                tempPath[ty] = t;
                tempValue = CalValue(tempPath);

                if (tempValue <= Value)
                {
                    change();
                }
                else
                {
                    p = exp((Value - tempValue) / (K * T));
                    if (RANDFLOAT() < p)
                    {
                        change();
                    }
                }
            }
        }
        T *= alpha;
    }
    cout << "Value:" << Value << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << Path[i] << " -> ";
    }
    cout << 0 << endl;
    // release
    delete[] tempPath;
    delete[] Path;
    for (int i = 0; i < N; ++i)
        delete[] Mat[i];
    delete[] Mat;
    system("pause");
}
