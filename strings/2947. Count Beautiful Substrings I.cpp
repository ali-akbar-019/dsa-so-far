class Solution
{
public:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    int beautifulSubstrings(string s, int k)
    {
        int n = s.length();

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int vowelCount = 0;
            int consCount = 0;
            for (int j = i; j < n; j++)
            {
                if (isVowel(s[j]))
                {
                    vowelCount++;
                }
                else
                {
                    consCount++;
                }
                if (vowelCount == consCount && (vowelCount * consCount) % k == 0)
                {
                    result += 1;
                }
            }
        }
        return result;
    }
};