class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        int n = s.size();
        unordered_set<int> to_remove_idx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    to_remove_idx.insert(i);
                }
                else
                {
                    st.pop();
                }
            }
        }
        //
        while (!st.empty())
        {
            to_remove_idx.insert(st.top());
            st.pop();
        }
        //
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (to_remove_idx.find(i) == to_remove_idx.end())
            {
                res += s[i];
            }
        }
        return res;
    }
};