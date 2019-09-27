#include <iostream>
using namespace std;
#define MAX 100

double a[MAX];

int main()
{
    int N;
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N + 1; ++i)
        cin >> a[i]; // N+1 term
    double x, ans;
    while (cin >> x)
    {
        ans = a[0];
        for (int i = 1; i < N + 1; ++i)
        {
            ans = ans * x + a[i];
        }
        printf("ans = %.10lf\n", ans);
    }
}