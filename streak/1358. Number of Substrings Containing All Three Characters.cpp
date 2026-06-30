class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        // we'll solve this using the sliding window logic
        int n = s.length();
        int result = 0;
        // freq map
        vector<int> mp(3, 0);

        // sliding window logic
        int i = 0;
        int j = 0;
        while (j < n)
        {
            // first freq add karo j wale ki
            mp[s[j] - 'a']++;
            // i ko barhao age
            // handle cases properly like aaaaabc
            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0)
            {
                result += (n - j);
                // remove karo i wale ko
                mp[s[i] - 'a']--;
                i++;
            }
            // j aage jata rahe ga
            j++;
        }
        return result;
    }
};