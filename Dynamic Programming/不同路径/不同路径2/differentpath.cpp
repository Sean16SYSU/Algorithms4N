#include <vector>
using namespace std;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        long map[105][105];
        int i, j;
        for (i = 0; i < obstacleGrid.size(); ++i)
        {
            for (j = 0; j < obstacleGrid[0].size(); ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    map[i][j] = 0;
                else if (i == 0 && j == 0)
                    map[i][j] = 1;
                else if (i == 0)
                    map[i][j] = map[i][j - 1];
                else if (j == 0)
                    map[i][j] = map[i - 1][j];
                else
                    map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        return map[i - 1][j - 1];
    }
};