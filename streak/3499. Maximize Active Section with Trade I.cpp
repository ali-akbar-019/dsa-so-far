class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.length();
        //
        vector<int> sections;
        int oneCount = 0;
        int zeroCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                zeroCount++;
            }
            if (s[i] == '1')
            {
                oneCount++;
            }
            if (s[i] == '1' && zeroCount > 0)
            {
                sections.push_back(zeroCount);
                zeroCount = 0;
            }
        }
        if (zeroCount > 0)
            sections.push_back(zeroCount);
        //
        if (sections.size() < 2)
        {
            return oneCount;
        }
        // find the best
        int best = 0;
        for (int i = 1; i < sections.size(); i++)
        {
            best = max(best, sections[i] + sections[i - 1]);
        }
        return best + oneCount;
    }
};