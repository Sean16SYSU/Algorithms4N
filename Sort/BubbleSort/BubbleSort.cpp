#include <iostream>
using namespace std;
#define MAX 100

void BubbleSort(double *arr, int n)
{
    int i, j;
    double temp;
    for (j = n - 1; j > 0; --j)
    {
        for (i = 0; i < j; ++i)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
    BubbleSort(a, N);
    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;
    system("pause");
}