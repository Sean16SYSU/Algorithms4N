#include <iostream>
using namespace std;
#define MAX 100

void BinaryInsertSort(double *arr, int n)
{
    double tmp;
    int i, s, t, m, k;
    for (i = 1; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            tmp = arr[i];
            s = 0;
            t = i - 1;
            while (s < t)
            {
                m = (s + t) / 2;
                if (tmp < arr[m])
                    t = m - 1;
                else
                    s = m + 1;
            }
            for (k = i - 1; k >= s; k--)
                arr[k + 1] = arr[k];
            arr[s] = tmp;
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
    BinaryInsertSort(a, N);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}