class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char &ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
                continue;
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }

                if (ch == ')')
                {
                    if (st.top() != '(')
                    {
                        return false;
                    }
                }
                if (ch == ']')
                {
                    if (st.top() != '[')
                    {
                        return false;
                    }
                }
                if (ch == '}')
                {
                    if (st.top() != '{')
                    {
                        return false;
                    }
                }
                st.pop();
            }
        }
        return st.empty();
    }
};