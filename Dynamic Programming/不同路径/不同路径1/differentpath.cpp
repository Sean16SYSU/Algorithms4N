class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        int map[105][105];
        map[1][1] = 1;
        map[1][2] = 1;
        map[2][1] = 1;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == 1 || j == 1)
                    map[i][j] = 1;
                else
                    map[i][j] = map[i][j - 1] + map[i - 1][j];
            }
        }
        return map[m][n];
    }
};