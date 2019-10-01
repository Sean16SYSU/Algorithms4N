#include <iostream>
using namespace std;
#define MAX 100

int binary_search(int *arr, int n, int target)
{
    int m, i = 0, j = n - 1, t = -1;
    while (i <= j && t < 0)
    {
        m = (i + j) / 2;
        if (target == arr[m])
        {
            t = m;
            break;
        }
        else if (target < arr[m])
        {
            j = m - 1;
        }
        else
        {
            i = m + 1;
        }
    }
    return t;
}

int main()
{
    int N;
    int a[MAX];
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    int target;
    cin >> target;
    int t = binary_search(a, N, target);
    if (t == -1)
        cout << target << " 不存在\n";
    else
        cout << target << " 在" << t << "位置\n";
    system("pause");
}