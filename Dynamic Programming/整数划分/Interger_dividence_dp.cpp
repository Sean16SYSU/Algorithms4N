#include <iostream>
using namespace std;

unsigned int **arr;

void cal(int n)
{
    arr = new unsigned *[n + 1];
    for (int i = 0; i <= n; ++i)
        arr[i] = new unsigned[n + 1];

    for (int i = 1; i <= n; ++i)
        arr[i][1] = 1; // max number equal to  1
    // arr[i][j] 表示i这个数被划分时，最大可能的数为j的所有可能。
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i < j)
                arr[i][j] = arr[i][i];
            else if (i == j)
                arr[i][j] = 1 + arr[i][j - 1];
            else
                arr[i][j] = arr[i][j - 1] + arr[i - j][j];

    cout << arr[n][n] << endl;

    for (int i = 0; i <= n; ++i)
        delete[] arr[i];
    delete[] arr;
}

int main()
{
    int n;
    while (cin >> n && n >= 1)
        cal(n);
}
