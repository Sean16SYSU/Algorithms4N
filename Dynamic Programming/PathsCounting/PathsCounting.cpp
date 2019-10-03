#include <iostream>
using namespace std;
int main()
{
    int map[51][51] = {0};
    int dp[51][51] = {0};

    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cin >> map[i][j];
        }
    }
    //===finish input
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            if (map[i][j] == 0)
            {
                if (i == 0 && j == 0)
                {
                    dp[0][0] = 1;
                }
                else if (i == 0 && j != 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (i != 0 && j == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
    }
    cout << dp[x - 1][y - 1] << endl;
}
