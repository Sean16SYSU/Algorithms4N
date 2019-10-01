#include <iostream>
using namespace std;
#define MAX 100

void InsertSort(double *arr, int n)
{
    double tmp;
    for (int i = 1; i < n; ++i)
    {
        tmp = arr[i];
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] < tmp)
            {
                arr[j + 1] = tmp;
                break;
            }
            else
            {
                arr[j + 1] = arr[j];
                if (j == 0)
                    arr[j] = tmp;
            }
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
    InsertSort(a, N);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}