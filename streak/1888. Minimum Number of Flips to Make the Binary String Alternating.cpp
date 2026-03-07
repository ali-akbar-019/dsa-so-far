class Solution
{
public:
    int minFlips(string s)
    {
        int n = s.size();
        s = s + s;
        string s1;
        string s2;
        for (int i = 0; i < 2 * n; i++)
        {
            s1 += i % 2 == 0 ? "0" : "1";
            s2 += i % 2 == 0 ? "1" : "0";
        }
        int flip1 = 0;
        int flip2 = 0;
        int result = INT_MAX;
        int i = 0;
        int j = 0;
        while (j < 2 * n)
        {
            if (s[j] != s1[j])
            {
                flip1++;
            }
            if (s[j] != s2[j])
            {
                flip2++;
            }
            if (j - i + 1 > n)
            {
                // shrink window
                if (s[i] != s1[i])
                {
                    flip1--;
                }
                if (s[i] != s2[i])
                {
                    flip2--;
                }
                i++;
            }
            if (j - i + 1 == n)
            {
                // complete window
                result = min({result, flip1, flip2});
            }
            j++;
        }
        return result;
    }
};