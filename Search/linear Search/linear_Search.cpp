#include <iostream>
using namespace std;
#define MAX 100

int linear_search(int *arr, int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
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
    int t = linear_search(a, N, target);
    if (t == -1)
        cout << target << " 不存在\n";
    else
        cout << target << " 在" << t << "位置\n";
    system("pause");
}