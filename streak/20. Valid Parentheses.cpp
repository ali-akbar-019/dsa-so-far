class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            char brk = s[i];
            if (brk == '(' || brk == '{' || brk == '[')
            {
                st.push(brk);
            }
            else
            {
                char currBracket = s[i];
                char onTop = !st.empty() ? st.top() : '#';
                if (onTop == '(' && currBracket == ')' || onTop == '[' && currBracket == ']' || onTop == '{' && currBracket == '}')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};