#include <string>
using namespace std;

#define min(x, y) ((x) > (y) ? (y) : (x))

class Solution
{
  public:
    string regenerate_str(string s)
    {
        string t("#");
        int count = 0;
        for (int i = 0; i < s.size() * 2 + 1; ++i)
        {
            if (i % 2 == 0)
            {
                t += s[count++];
            }
            else
                t += "#";
        }
        return t;
    }

    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        s = regenerate_str(s);

        int p[2002], start = 0, maxlen = 0;
        int mx = 0, loc = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (i < mx && 2 * loc - i < s.size())
            {
                p[i] = min(mx - i, p[2 * loc - i]);
            }
            else
            {
                p[i] = 1;
            }

            while (p[i] + i < s.size() && i - p[i] >= 0 && s[i - p[i]] == s[i + p[i]])
                p[i]++;

            if (i + p[i] > mx)
            {
                mx = i + p[i];
                loc = i;
            }

            if (p[i] > maxlen)
            {
                maxlen = p[i];
                start = i;
            }
        }
        s = s.substr(start - p[start] + 1, 2 * p[start] - 1);
        string t;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '#')
                t.push_back(s[i]);
        }
        return t;
    }
};