#include <iostream>
using namespace std;
#define MAX 100

void ShellSort(double *arr, int n)
{
    if (n <= 1)
        return;
    double tmp;
    int gap = n, i, j;
    do
    {
        gap = gap / 3 + 1;
        for (i = gap; i < n; ++i)
        {
            if (arr[i] < arr[i - gap])
            {
                tmp = arr[i];
                j = i - gap;
                do
                {
                    arr[j + gap] = arr[j];
                    j -= gap;
                } while (j >= 0 && tmp < arr[j]);
                arr[j + gap] = tmp;
            }
        }
    } while (gap > 1);
}
int main()
{
    int N;
    double a[MAX];
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    ShellSort(a, N);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}