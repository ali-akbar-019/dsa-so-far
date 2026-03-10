class Solution
{
public:
    bool check(stack<char> st, string &part, int n)
    {
        for (int idx = n - 1; idx >= 0; idx--)
        {
            if (part[idx] != st.top())
            {
                return false;
            }
            st.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part)
    {
        int n = part.size();
        int m = s.size();
        string result = "";
        stack<char> st;
        for (int i = 0; i < m; i++)
        {
            st.push(s[i]);
            if (st.size() >= n && check(st, part, n))
            {
                for (int i = 0; i < n; i++)
                {
                    st.pop();
                }
            }
        }
        //
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};