class Solution
{
  public:
    int climbStairs(int n)
    {
        int map[3];
        map[0] = 1;
        map[1] = 2;
        for (int i = 2; i < n; ++i)
        {
            map[i % 3] = map[(i - 1) % 3] + map[(i - 2) % 3];
        }
        return map[(n - 1) % 3];
    }
};