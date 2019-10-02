#include <iostream>
using namespace std;

int cal(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    if (m > n)
        return cal(n, n);
    if (n == m)
        return 1 + cal(n, m - 1);
    return cal(n - m, m) + cal(n, m - 1);
}

int main()
{
    int n;
    while (cin >> n && n >= 1)
        cout << cal(n, n) << endl;
}
