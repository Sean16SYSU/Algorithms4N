#include <iostream>
using namespace std;
#define MAX 100

void merge(double *arr, int s, int m, int t)
{
    double *tmp = new double[t - s + 1];

    int i = s, j = m + 1, c = 0;
    while (i <= m && j <= t)
    {
        if (arr[i] <= arr[j])
            tmp[c++] = arr[i++];
        else
            tmp[c++] = arr[j++];
    }
    while (i <= m)
        tmp[c++] = arr[i++];
    while (j <= t)
        tmp[c++] = arr[j++];

    for (i = 0; i < t - s + 1; ++i)
        arr[i + s] = tmp[i];
    delete[] tmp;
}

void MergeSort(double *arr, int s, int e)
{
    if (s >= e)
        return;
    int m = (s + e) / 2;
    MergeSort(arr, s, m);
    MergeSort(arr, m + 1, e);
    merge(arr, s, m, e);
}

int main()
{
    int N;
    double a[MAX];
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    MergeSort(a, 0, N - 1);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}