#include <algorithm>
using namespace std;
#include <vector>


class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> map = grid;
        int i, j;
        for (i = 0; i < map.size(); ++i)
        {
            for (j = 0; j < map[i].size(); ++j)
            {
                if (i != 0 && j != 0)
                    map[i][j] += min(map[i - 1][j], map[i][j - 1]);
                else if (i == 0 && j != 0)
                    map[i][j] += map[i][j - 1];
                else if (i != 0 && j == 0)
                    map[i][j] += map[i - 1][j];
            }
        }
        return map[i - 1][j - 1];
    }
};