class Solution
{
public:
    bool check(string word, char start, char end)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] < start || word[i] > end)
            {
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word)
    {
        // three checks
        if (check(word, 'A', 'Z') || check(word, 'a', 'z') || ((word[0] >= 'A' && word[0] <= 'Z') && check(word.substr(1), 'a', 'z')))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};