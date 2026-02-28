class Solution
{
public:
    int getNextValidIndex(const string &s, int i)
    {
        int skip = 0;
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skip++;
                i--;
            }
            else if (skip > 0)
            {
                skip--;
                i--;
            }
            else
            {
                break;
            }
        }
        return i;
    }

    bool backspaceCompare(string s, string t)
    {
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0)
        {
            i = getNextValidIndex(s, i);
            j = getNextValidIndex(t, j);

            char ch1 = i >= 0 ? s[i] : '\0'; // sentinel for empty
            char ch2 = j >= 0 ? t[j] : '\0';

            if (ch1 != ch2)
                return false;

            i--; // move to previous char for next iteration
            j--;
        }

        return true;
    }
};