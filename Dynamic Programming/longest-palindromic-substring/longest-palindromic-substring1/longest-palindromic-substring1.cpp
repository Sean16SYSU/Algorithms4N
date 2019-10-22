#include <iostream>
using namespace std;
#include <string>


class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        int map[2000][2001];
        int total = 1, start = 0;
        for (int i = 0; i < s.size(); ++i)
            map[i][1] = 1;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                map[i][2] = 2;
                total = 2;
                start = i;
            }
            else
            {
                map[i][2] = 0;
            }
        }
        for (int j = 3; j <= s.size(); ++j)
        {
            for (int i = 0; i <= s.size() - j; ++i)
            {
                if (map[i + 1][j - 2] != 0 && s[i] == s[i + j - 1])
                {
                    map[i][j] = j;
                    if (total < map[i][j])
                    {
                        total = map[i][j];
                        start = i;
                    }
                }
                else
                    map[i][j] = 0;
            }
        }
        return s.substr(start, total);
    }
};
