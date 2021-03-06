#include <iostream>
using namespace std;
#define MAX 100

void QuickSort(double *arr, int s, int e)
{
    if (s >= e)
        return;
    int i = s, j = e;
    double key = arr[s];
    while (i < j)
    {
        while (arr[j] >= key && i < j)
            j--;
        if (arr[j] < key && i < j)
            arr[i++] = arr[j];
        while (arr[i] <= key && i < j)
            i++;
        if (arr[i] > key && i < j)
            arr[j--] = arr[i];
    }
    arr[i] = key;
    QuickSort(arr, s, i - 1);
    QuickSort(arr, i + 1, e);
}
int main()
{
    int N;
    double a[MAX];
    cin >> N; // input number N, less than 99, N是最大指数
    for (int i = 0; i < N; ++i)
        cin >> a[i]; // N terms
    QuickSort(a, 0, N - 1);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}