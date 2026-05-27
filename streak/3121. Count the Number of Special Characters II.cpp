class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        vector<int> lastlower(26, -1);
        vector<int> firstupper(26, -1);

        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            if (islower(ch))
            {
                lastlower[ch - 'a'] = i;
            }
            else
            {
                if (firstupper[ch - 'A'] == -1)
                {
                    firstupper[ch - 'A'] = i;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++)
        {
            if (lastlower[i] != -1 && firstupper[i] != -1 && lastlower[i] < firstupper[i])
            {
                result += 1;
            }
        }
        //
        return result;
    }
};