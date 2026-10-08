class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        // outer bracket ko just identify karo
        int count = 0;
        string result = "";
        for (char &ch : s)
        {
            if (ch == '(')
            {
                if (count != 0)
                {
                    result.push_back(ch);
                }
                count++;
            }
            else
            {
                // closing mil gaya
                count--;
                if (count != 0)
                {
                    result.push_back(ch);
                }
            }
        }
        return result;
    }
};