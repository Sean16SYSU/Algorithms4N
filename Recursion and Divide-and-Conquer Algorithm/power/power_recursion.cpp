#include <iostream>
using namespace std;

double power(double x, unsigned int n)
{
    double y;
    if (n == 0)
        y = 1;
    else
    {
        y = power(x, n / 2);
        y = y * y;
        if (n % 2 == 1)
            y *= x;
    }
    return y;
}

int main()
{
    double x;
    unsigned int n;
    cin >> x >> n;
    cout << power(x, n) << endl;
    system("pause");
}