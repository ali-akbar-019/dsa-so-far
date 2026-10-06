class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int n = s.length();
        int depth = 0;
        int score = 0;

        for (int i = 0; i < n; i++)
        {
            char brk = s[i];
            if (brk == '(')
            {
                depth++;
            }
            else
            {
                depth--;
                if (s[i - 1] == '(')
                {
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
};