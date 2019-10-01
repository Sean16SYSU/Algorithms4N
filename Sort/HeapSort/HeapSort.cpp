#include <iostream>
using namespace std;
#define MAX 100

void maintian_heap(double *arr, int n, int i)
{
    int j = 2 * i + 1;
    double tmp = arr[i];
    while (j < n)
    {
        if (j + 1 < n && arr[j] < arr[j + 1])
            j++;
        if (tmp >= arr[j])
            break;
        else
        {
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    arr[i] = tmp;
}

void build_heap(double *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        maintian_heap(arr, n, i);
    }
}

void HeapSort(double *arr, int n)
{
    build_heap(arr, n); // 构建最大堆
    for (int i = n - 1; i > 0; --i)
    {
        double temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        maintian_heap(arr, i, 0);
    }
}
int main()
{
    int N;
    double a[MAX];
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    HeapSort(a, N);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}