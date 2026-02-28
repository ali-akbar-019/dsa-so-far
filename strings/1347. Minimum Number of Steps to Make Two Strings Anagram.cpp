class Solution
{
public:
    int minSteps(string s, string t)
    {
        if (s.size() != t.size())
        {
            return -1;
        }
        int n = s.size();
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (int i = 0; i < n; i++)
        {
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }
        //
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] > freq2[i])
            {
                result += freq1[i] - freq2[i];
            }
        }
        return result;
    }
};