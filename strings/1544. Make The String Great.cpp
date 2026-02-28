class Solution
{
public:
    string makeGood(string s)
    {
        string result = "";
        for (char &ch : s)
        {
            if (!result.empty() && (result.back() - 32 == ch || result.back() + 32 == ch))
            {
                // one is capital, one is lowercase
                result.pop_back();
            }
            else
            {
                result.push_back(ch);
            }
        }
        return result;
    }
};