class Solution
{
public:
    char processStr(string s, long long k)
    {
        // sab se pehle Length nikal lo final string ki
        int n = s.size();
        long long L = 0;
        for (auto &ch : s)
        {
            if (ch == '*')
            {
                if (L > 0)
                {
                    L--;
                }
            }
            else if (ch == '#')
            {
                L = L * 2;
            }
            else if (ch == '%')
            {
                continue;
            }
            else
            {
                // a - z
                L++;
            }
        }
        // check karo jo manga ha kahi wo zyada to nahi Length se
        if (k >= L)
        {
            return '.';
        }
        // ulta iterate karo
        for (int i = n - 1; i >= 0; i++)
        {
            if (s[i] == '*')
            {
                L++;
            }
            else if (s[i] == '#')
            {
                L = L / 2;
                k = k >= L ? k - L : k;
            }
            else if (s[i] == '%')
            {
                // rev
                k = L - k - 1;
            }
            else
            {
                // a to z
                L--;
            }
            if (L == k)
            {
                return s[i];
            }
        }
        return '.';
    }
};