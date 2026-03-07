class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;
        int n = s.size();
        string result = "";
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')')
            {
                // it means that we have the string in the stack and we have to reverse it and rmeove the brackets
                while (!st.empty() && st.top() != '(')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                // now there could be more
                for (int j = 0; j < temp.size(); j++)
                {
                    st.push(temp[j]);
                }
                temp = "";
            }
            else
            {
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// class Solution {
public:
string reverseParentheses(string s)
{
    int n = s.size();
    stack<int> lastSkipIndex;
    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            lastSkipIndex.push(result.length());
        }
        else if (s[i] == ')')
        {
            int l = lastSkipIndex.top();
            lastSkipIndex.pop();
            reverse(result.begin() + l, result.end());
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}
}
;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int n = s.size();
        stack<int> openBracketIndex;
        vector<int> door(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                openBracketIndex.push(i);
            }
            else if (s[i] == ')')
            {
                int j = openBracketIndex.top();
                openBracketIndex.pop();
                door[i] = j;
                door[j] = i;
            }
        }
        string result = "";
        int flag = 1;
        for (int i = 0; i < n; i += flag)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                // change direction
                i = door[i];
                flag = flag * -1;
            }
            else
            {

                result += s[i];
            }
        }
        return result;
    }
};