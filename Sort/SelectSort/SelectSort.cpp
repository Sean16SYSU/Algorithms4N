#include <iostream>
using namespace std;
#define MAX 100

void SelectSort(double *arr, int n)
{
    double tmp;
    int i, j, m;
    for (i = 0; i < n - 1; ++i)
    {
        m = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[m] > arr[j])
            {
                m = j;
            }
        }
        if (m != i)
        {
            tmp = arr[m];
            arr[m] = arr[i];
            arr[i] = tmp;
        }
    }
}
int main()
{
    int N;
    double a[MAX];
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    SelectSort(a, N);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}