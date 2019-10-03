#include <iostream>
#include <algorithm>
using namespace std;
int select(int *arr, int n, int k);
int main()
{
    int n, *arr, k;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> k;
    cout << select(arr, n, k) << endl;
    delete[] arr;
    system("pause");
}

int select(int *arr, int n, int k)
{

    if (n <= 5)
    {
        sort(arr, arr + n);
        return arr[k - 1]; // 返回第k个元素
    }

    // 满五个才凑成一组
    int *mid_ = new int[n / 5];
    for (int i = 0; i < n / 5; ++i)
    {
        sort(arr + i * 5, arr + i * 5 + 5);
        mid_[i] = arr[5 * i + 2];
    }
    int m = select(mid_, n / 5, n / 10 + (n / 5) % 2);
    int *bigger = new int[3 * n / 4];
    int *smaller = new int[3 * n / 4];
    int *equal = new int[3 * n / 4];
    int i = 0, j = 0, s = 0, t = 0;
    for (t = 0; t < n; ++t)
    {
        if (arr[t] > m)
            bigger[i++] = arr[t];
        else if (arr[t] == m)
            equal[j++] = arr[t];
        else
            smaller[s++] = arr[t];
    }
    int ans;
    if (s > k)
        ans = select(smaller, s, k);
    else if (s + j > k)
        ans = m;
    else
        ans = select(bigger, i, k - s - j);

    delete[] mid_;
    delete[] bigger;
    delete[] smaller;
    delete[] equal;
    return ans;
}
