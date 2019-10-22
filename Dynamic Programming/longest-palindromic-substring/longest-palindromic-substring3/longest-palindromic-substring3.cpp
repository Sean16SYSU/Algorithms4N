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
        int *map;
        map = new int[s.size() + 1];
        int total = 1, start = 0;

        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                map[i] = 2;
                total = 2;
                start = i;
            }
            else
            {
                map[i] = 0;
            }
        }

        for (int j = 4; j <= s.size(); j += 2)
        {
            for (int i = 0; i <= s.size() - j; ++i)
            {
                if (map[i + 1] != 0 && s[i] == s[i + j - 1])
                {
                    map[i] = j;
                    if (total < map[i])
                    {
                        total = map[i];
                        start = i;
                    }
                }
                else
                    map[i] = 0;
            }
        }

        for (int i = 0; i < s.size(); ++i)
            if (!map[i])
                map[i] = 1;

        for (int j = 3; j <= s.size(); j += 2)
        {
            for (int i = 0; i <= s.size() - j; ++i)
            {
                if (map[i + 1] != 0 && s[i] == s[i + j - 1])
                {
                    map[i] = j;
                    if (total < map[i])
                    {
                        total = map[i];
                        start = i;
                    }
                }
                else
                    map[i] = 0;
            }
        }

        delete[] map;
        return s.substr(start, total);
    }
};
