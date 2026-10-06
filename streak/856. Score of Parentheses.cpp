class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int n = s.length();
        int score = 0;
        vector<int> prev;
        for (int i = 0; i < n; i++)
        {

            char brk = s[i];
            if (brk == '(')
            {
                prev.push_back(score);
                score = 0;
            }
            else
            {
                // closing ha
                // agar to simple case 1
                if (s[i - 1] == '(')
                {
                    score = prev.back() + 1;
                }
                else
                {
                    score = (2 * score) + prev.back();
                }
                prev.pop_back();
            }
        }
        return score;
    }
};