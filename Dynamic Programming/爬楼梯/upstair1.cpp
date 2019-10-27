class Solution
{
  public:
    int climbStairs(int n)
    {
        int *map = new int[n + 5];

        map[1] = 1;
        map[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            map[i] = map[i - 1] + map[i - 2];
        }
        int ans = map[n];
        delete[] map;
        return ans;
    }
};