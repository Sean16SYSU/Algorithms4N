#include <iostream>
#include <algorithm>
using namespace std;
int select(int n, int *arr, int begin, int k);
int partition(int *arr, int begin, int end);
int main()
{
    int n, *arr, k;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> k;
    cout << select(n, arr, 0, k) << endl;
    delete[] arr;
}

int partition(int *arr, int begin, int end)
{
    if (begin >= end)
        return arr[begin];
    int i = begin, j = end;
    int flag = arr[begin];
    while (i < j)
    {
        while (i < j && flag < arr[j])
            j--;
        if (i < j)
            arr[i] = arr[j];
        while (i < j && arr[i] < flag)
            i++;
        if (i < j)
            arr[j] = arr[i];
    }
    arr[i] = flag;
    return i - begin;
}

int select(int n, int *arr, int begin, int k)
{
    if (n == 1)
        return arr[begin];
    int end_ = 0;
    for (int i = 0; i < n; i += 5)
    {
        end_ = (i + 5 <= n ? i + 5 : n);
        sort(arr + begin + i, arr + begin + end_);
    }

    int mid_len = n / 5 + (n % 5 != 0), mid_index;
    int *arr_ = new int[mid_len];

    for (int i = 0; i < mid_len; ++i)
    {
        if (n - 5 * i - 2 > 0)
            arr_[i] = arr[begin + 5 * i + 2];
        else
            arr_[i] = arr[begin + 5 * i + 1];
    }
    int mid_k = select(mid_len, arr_, 0, mid_len / 2 + (mid_len % 2 != 0));

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid_k == arr[begin + i])
        {
            index = i;
            break;
        }
    }
    int temp = arr[begin];
    arr[begin] = mid_k;
    arr[begin + index] = temp;
    temp = partition(arr, begin, begin + n - 1);
    delete[] arr_;
    if (temp == k)
        return mid_k;
    else if (temp > k)
        select(temp, arr, begin, k);
    else if (temp < k)
        select(n - temp - 1, arr, temp + 1, k - temp - 1);
}
