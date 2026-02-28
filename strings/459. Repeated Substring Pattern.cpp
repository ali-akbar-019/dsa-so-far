class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        for (int l = n / 2; l >= 1; l--)
        {
            if (n % l == 0)
            {
                string pattern = s.substr(0, l);
                string newString = "";
                int times = n / l; // kitni bar add karna h
                while (times--)
                {
                    newString += pattern;
                }
                if (newString == s)
                {
                    return true;
                }
            }
        }
        return false;
    }
};