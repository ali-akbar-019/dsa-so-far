class Solution
{
public:
    int removeStr(string &s, string sub, int score)
    {
        int res = 0;
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && st.top() == sub[0] && s[i] == sub[1])
            {
                st.pop();
                ///
                res += score;
            }
            else
            {
                st.push(s[i]);
            }
        }
        //
        string updatedS = "";
        while (!st.empty())
        {
            updatedS.push_back(st.top());
            st.pop();
        }
        reverse(updatedS.begin(), updatedS.end());
        s = updatedS;
        return res;
    }
    int maximumGain(string s, int x, int y)
    {
        int n = s.size();
        string s1 = s;
        string s2 = s;
        int score1 = removeStr(s1, "ab", x) + removeStr(s1, "ba", y);
        int score2 = removeStr(s2, "ba", y) + removeStr(s2, "ab", x);
        return max(score1, score2);
    }
};