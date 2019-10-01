#include <iostream>
using namespace std;
#define MAX 100

void InsertSort(double *arr, int n)
{
    double tmp;
    int i, j;
    for (i = 1; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            tmp = arr[i];
            j = i - 1;
            do
            {
                arr[j + 1] = arr[j--];
            } while (j >= 0 && tmp < arr[j]);
            arr[j + 1] = tmp;
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