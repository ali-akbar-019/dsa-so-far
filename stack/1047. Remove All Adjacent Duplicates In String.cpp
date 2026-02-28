class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string result;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && st.top() == s[i])
            {
                st.pop();
                continue;
            }
            //
            st.push(s[i]);
        }
        while (!st.empty())
        {
            char ch = st.top();
            st.pop();
            result += ch;
        }
        reverse(begin(result), end(result));
        return result;
    }
};