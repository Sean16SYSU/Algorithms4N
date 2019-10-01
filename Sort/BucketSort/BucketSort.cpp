#include <iostream>
using namespace std;
#define MAX 100

void maintian_heap(int *arr, int n, int i)
{
    int j = 2 * i + 1;
    int tmp = arr[i];
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

void build_heap(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        maintian_heap(arr, n, i);
    }
}

void HeapSort(int *arr, int n)
{
    build_heap(arr, n); // 构建最大堆
    for (int i = n - 1; i > 0; --i)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        maintian_heap(arr, i, 0);
    }
}

void BucketSort(int *arr, int n)
{
    int *mat = new int[n];
    int count, i, j;
    for (j = 0; j < 10; ++j)
    {
        count = 0;
        for (i = 0; i < n; ++i)
            if (arr[i] / 10 == (j + 1))
                mat[count++] = arr[i];
        HeapSort(mat, count);
        for (i = 0; i < count; ++i)
            cout << mat[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N;
    int a[MAX];
    cin >> N; // input number N, 都是二位的数字，比如12， 10 ， 99等。
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    BucketSort(a, N);
    system("pause");
}