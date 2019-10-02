#include <iostream>
using namespace std;

double power(double x, unsigned int n)
{
    double y = 1;
    while (n != 0)
    {
        if (n % 2)
            y *= x;
        x *= x;
        n /= 2;
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