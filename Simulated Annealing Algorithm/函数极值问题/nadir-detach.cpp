#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
#define FUN(x) ((x - 1) * (x - 1) + x + 100 * sin(x) * sin(x))
#define RAND() ((double)rand() / double(RAND_MAX))

int main()
{
    srand((unsigned)time(NULL));
    double T = 1000;     // 起始温度
    double alpha = 0.99; // T_{ k + 1 } = alpha * T_k方式更新温度
    double limitedT = 1; // 最小值的T
    int iterTime = 1000; // 每个温度下迭代的次数
    double sigmaX = 3;   // 每次的搜索半径
    double K = 1;        // 系数K
    double X = 20 * RAND() - 10;
    double Y = FUN(X);
    double xnew, ynew, rest, p;
    while (T > limitedT)
    {
        for (int i = 0; i < iterTime; ++i)
        {
            xnew = X + sigmaX * (2 * RAND() - 1);
            if (xnew >= -10. && xnew <= 10)
            {
                ynew = FUN(xnew);
                if (ynew <= Y)
                {
                    X = xnew;
                    Y = ynew;
                }
                else
                {
                    rest = Y - ynew;
                    p = exp(rest / (K * T));
                    if (RAND() < p)
                    {
                        X = xnew;
                        Y = ynew;
                    }
                }
            }
        }
        T *= alpha;
    }
    cout << X << " " << Y << endl;
    system("pause");
}
