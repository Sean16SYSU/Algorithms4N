#include <iostream>
using namespace std;
#include <string>

void cal(int n, int m, string s)
{
    if (n == 0 || m == 0)
        return;
    if (n == 1 || m == 1)
    {
        for (int i = 0; i < n - 1; ++i)
            s += string("1+");
        cout << s << "1\n";
        return;
    }
    if (m > n)
    {
        return cal(n, n, s);
    }
    if (n == m)
    {
        cout << s << n << endl;
        return cal(n, m - 1, s);
    }
    if (n - m != 0)
        cal(n - m, m, s + to_string(m) + string("+"));
    else
    {
        cout << s << m << endl;
    }
    cal(n, m - 1, s);
}

int main()
{
    int n;
    string s;
    while (cin >> n && n >= 1)
        cal(n, n, s);
}
